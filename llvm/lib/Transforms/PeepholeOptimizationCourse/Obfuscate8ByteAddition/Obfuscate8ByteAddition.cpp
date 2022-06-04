#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

namespace {

struct Obfuscate8ByteAddition : public FunctionPass {
    static char ID;
    Obfuscate8ByteAddition() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** OBFUSCATE 8BYTE ADDITION **********\n";
        errs() << "********** Function: " << function.getName() << '\n';
        
        bool changed = false;
        for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
            auto instruction = &*ii;
            ++ii;

            if (!is8ByteAddition(instruction)) {
                continue;
            }

            ReplaceInstWithInst(instruction, obfuscate8ByteAddition(instruction));
            changed = true;
        }

        return changed;
    }

private:

    bool is8ByteAddition(Instruction const* instruction) const {
        return isBinaryAdd(instruction) && is8Byte(instruction);
    }

    bool isBinaryAdd(Instruction const* instruction) const {
        return instruction->getOpcode() == Instruction::Add && instruction->getNumOperands() == 2;
    }

    bool is8Byte(Instruction const* instruction) const {
        return instruction->getType()->isIntegerTy() && instruction->getType()->getIntegerBitWidth() == 8;
    }

    Instruction* obfuscate8ByteAddition(Instruction* instruction) const {
        auto const& lhs = instruction->getOperand(0);
        auto const& rhs = instruction->getOperand(1);
        IRBuilder<> build(instruction);
        std::vector<Constant*> cnst;
        cnst.push_back(ConstantInt::get(instruction->getType(), 39));
        cnst.push_back(ConstantInt::get(instruction->getType(), 2));
        cnst.push_back(ConstantInt::get(instruction->getType(), 23));
        cnst.push_back(ConstantInt::get(instruction->getType(), 151));
        cnst.push_back(ConstantInt::get(instruction->getType(), 111));

        Value* a_and_b = build.CreateAnd(lhs, rhs);
        Value* a_xor_b_2 = build.CreateMul(build.CreateXor(lhs, rhs), cnst[1]);

        return BinaryOperator::CreateAdd(
            build.CreateMul(
                build.CreateAdd(
                    build.CreateMul(build.CreateAdd(a_and_b, a_xor_b_2), cnst[0]),
                    cnst[2]
                ),
                cnst[3]
            ),
            cnst[4]
        );         
    }
};

}  // namespace

char Obfuscate8ByteAddition::ID = 0;
static RegisterPass<Obfuscate8ByteAddition> X(
    "obfuscate-8byte-addition",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Obfuscate 8Byte Addition", /* Help string */
    false                                                          /* Changes the CFG */,
    false                                                          /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new Obfuscate8ByteAddition());
    }
);