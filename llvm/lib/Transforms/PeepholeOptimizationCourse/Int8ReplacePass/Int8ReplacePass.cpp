#include "llvm/Transforms/PeepholeOptimizationCourse/Int8ReplacePassFunc.h"

#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

namespace {

struct Int8ReplacePass : public FunctionPass {
    static char ID;
    Int8ReplacePass() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE INT8 ADD OLD MANAGER **********\n";
        errs() << "********** Function: " << F.getName() << '\n';

        bool changed = false;

        for (BasicBlock& BB : F.getBasicBlockList()) {
            for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
                auto *bin_op = dyn_cast<BinaryOperator>(I);

                if (!bin_op ||
                    bin_op->getOpcode() != Instruction::Add ||
                    !(bin_op->getType()->isIntegerTy() && bin_op->getType()->getIntegerBitWidth() == 8)
                ) {
                    continue;
                }

                ReplaceInstWithInst(BB.getInstList(), I, ReplacePass(bin_op));
                changed = true;
            }
        }

        return changed;
    }
};

}

char Int8ReplacePass::ID = 0;
static RegisterPass<Int8ReplacePass> X(
    "int8-replace-pass",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Replace Int8 Add Pass", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new Int8ReplacePass());
    }
);