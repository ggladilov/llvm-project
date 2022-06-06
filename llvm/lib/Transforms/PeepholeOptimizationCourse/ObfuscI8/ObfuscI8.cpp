#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscI8Func.h"

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

struct obfuscI8Pass : public FunctionPass {
    static char ID;
    obfuscI8Pass() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** INT8 OBFUSC **********\n";
        errs() << "********** Function: " << F.getName() << '\n';

        bool changed = false;

        for (BasicBlock& BB : F.getBasicBlockList()) {
            for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
                auto *binary_op = dyn_cast<BinaryOperator>(I);

                if (checkI8(binary_op)) {
                    continue;
                }
                ReplaceInstWithInst(BB.getInstList(), I, obfuscInstruction(binary_op));
                changed = true;
            }
        }

        return changed;
    }
};

}

char obfuscI8Pass::ID = 0;
static RegisterPass<obfuscI8Pass> X(
    "obfucs-i8",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Int8 Add Pass", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new obfuscI8Pass());
    }
);