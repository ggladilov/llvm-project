#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateIntPassFunctions.h"

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

struct ObfuscateIntPass : public FunctionPass {
    static char ID;
    ObfuscateIntPass() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** OBFUSC INT8 ADD **********\n";
        errs() << "********** Function: " << F.getName() << '\n';

        bool changed = false;

        for (BasicBlock& BB : F.getBasicBlockList()) {
            for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
                auto *binary_operator = dyn_cast<BinaryOperator>(I);

                if (!binary_operator || binary_operator->getOpcode() != Instruction::Add) {
                    continue;
                }

                if (!(binary_operator->getType()->isIntegerTy() && binary_operator->getType()->getIntegerBitWidth() == 8)) {
                    continue;
                }

                Instruction *replacement = PassInstruction(binary_operator);

                ReplaceInstWithInst(BB.getInstList(), I, replacement);
                changed = true;
            }
        }

        return changed;
    }
};

}

char ObfuscateIntPass::ID = 0;
static RegisterPass<ObfuscateIntPass> X(
    "obfuscate-int-pass",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Obfusc Int8 Add", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ObfuscateIntPass());
    }
);