#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {

struct RemoveAddWithZero : public FunctionPass {
    static char ID;
    RemoveAddWithZero() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REMOVE ADD WITH ZERO **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;
        for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
            auto instruction = &*ii;
            ++ii;

            if (!isAddWithZero(instruction)) {
                continue;
            }

            if (!instruction->use_empty()) {
                replaceWithArgument(instruction);
            }

            instruction->eraseFromParent();
            changed = true;
        }

        return changed;
    }

private:
    bool isAddWithZero(Instruction const* instruction) const {
        return isBinaryAdd(instruction) && withZero(instruction);
    }

    bool isBinaryAdd(Instruction const* instruction) const {
        return instruction->getOpcode() == Instruction::Add &&
               instruction->getNumOperands() == 2;
    }

    bool withZero(Instruction const* instruction) const {
        auto const& operands = instruction->operands();
        return std::any_of(operands.begin(), operands.end(),
                           [this](auto const& operand) { return isZero(operand); });
    }

    bool isZero(Value const* operand) const {
        auto const constant = dyn_cast<ConstantInt>(operand);
        return constant && constant->isZero();
    }

    void replaceWithArgument(Instruction* instruction) const {
        auto const& lhs = instruction->getOperand(0);
        auto const& rhs = instruction->getOperand(1);
        instruction->replaceAllUsesWith(isZero(lhs) ? rhs : lhs);
    }
};

}  // namespace

char RemoveAddWithZero::ID = 0;
static RegisterPass<RemoveAddWithZero> X(
    "remove-add-with-zero",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Remove Add With Zero", /* Help string */
    false                                                      /* Changes the CFG */,
    false                                                      /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new RemoveAddWithZero());
    }
);
