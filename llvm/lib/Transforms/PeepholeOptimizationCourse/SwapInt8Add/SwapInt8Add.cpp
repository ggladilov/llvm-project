#include "llvm/Pass.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/Func.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

namespace {

struct SwapInt8Add : public FunctionPass {
    static char ID;
    SwapInt8Add() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE INT8 ADD **********\n";
        errs() << "********** Function: " << F.getName() << '\n';

        bool changed = false;

        for (BasicBlock& BB : F.getBasicBlockList()) {
            for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
                auto *binOp = dyn_cast<BinaryOperator>(I);

                // Check op is binary
                if (!binOp) {
                    continue;
                }

                // Check op is add
                if (binOp->getOpcode() != Instruction::Add) {
                    continue;
                }

                // Check precision is i8
                if (!(binOp->getType()->isIntegerTy() && binOp->getType()->getIntegerBitWidth() == 8)) {
                    continue;
                }

                Instruction *replacement = SwapInt8Instruction(binOp);

                ReplaceInstWithInst(BB.getInstList(), I, replacement);
                changed = true;
            }
        }

        return changed;
    }
};

}  // namespace

char SwapInt8Add::ID = 0;
static RegisterPass<SwapInt8Add> X(
    "swap-int8-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Swap Int8 Add", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new SwapInt8Add());
    }
);