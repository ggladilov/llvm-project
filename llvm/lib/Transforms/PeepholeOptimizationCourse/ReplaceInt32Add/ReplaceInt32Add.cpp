#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {

struct ReplaceInt32Add : public FunctionPass {
    static char ID;
    ReplaceInt32Add() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE INT32 ADD **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;
        for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
            auto instruction = &*ii;
            ++ii;

            if (!isInt32Add(instruction)) {
                continue;
            }

            if (!instruction->use_empty()) {
                replaceAdd(instruction);
            }

            instruction->eraseFromParent();
            changed = true;
        }

        return changed;
    }

private:

    bool isInt32Add(Instruction const *instruction) const {
        return instruction->getOpcode() == Instruction::Add &&
           instruction->getNumOperands() == 2 && isInt32(instruction);
    }

    bool isInt32(Instruction const *instruction) const {
        auto const &operands = instruction->operands();
        return std::all_of(operands.begin(), operands.end(),
               [this](auto const &operand) { return isInt32Operand(operand); });
    }

    bool isInt32Operand((Value const* operand) const {
        return operand->getType()->isIntegerTy() &&
           operand->getType()->getIntegerBitWidth() == 32;
    }

    void replaceAdd(Instruction* instruction) const {
        auto const& lhs = instruction->getOperand(0);
        auto const& rhs = instruction->getOperand(1);
        IRBuilder<> B(&I);
        ReplaceInstWithInst(instruction,
            B.CreateAdd(
                B.CreateMul(
                    B.CreateMul(
                        ConstantInt::get(lhs->getType(), 39),
                        B.CreateAdd(
                            B.CreateAnd(lhs, rhs),
                            B.CreateAdd(
                                B.CreateMul(
                                    ConstantInt::get(lhs->getType(), 2),
                                    B.createXor(lhs, rhs))
                                ConstantInt::get(lhs->getType(), 23))),
                    ConstantInt::get(lhs->getType(), 151)),
                ConstantInt::get(lhs->getType(), 111)));
    }
};

}  // namespace

char ReplaceInt32Add::ID = 0;
static RegisterPass<ReplaceInt32Add> X(
    "replace-int32-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Replace Int32 Add", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ReplaceInt32Add());
    }
);
