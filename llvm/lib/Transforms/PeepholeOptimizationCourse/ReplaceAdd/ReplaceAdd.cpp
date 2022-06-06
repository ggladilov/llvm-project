#include "llvm/Transforms/PeepholeOptimizationCourse/Functions.h"

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

struct ReplaceAdd : public FunctionPass {
    static char ID;
    ReplaceAdd() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE INT8 ADD **********\n";
        errs() << "********** Function: " << F.getName() << '\n';

        bool changed = false;

        for (BasicBlock& BB : F.getBasicBlockList()) {
            for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
                auto *binOp = dyn_cast<BinaryOperator>(I);

                if (!binOp || binOp->getOpcode() != Instruction::Add) {
                    continue;
                }

                if (!(binOp->getType()->isIntegerTy() && binOp->getType()->getIntegerBitWidth() == 8)) {
                    continue;
                }

                Instruction *replacement = ReplaceInstruction(binOp);

                ReplaceInstWithInst(BB.getInstList(), I, replacement);
                changed = true;
            }
        }

        return changed;
    }
};

}  // namespace

char ReplaceAdd::ID = 0;
static RegisterPass<ReplaceAdd> X(
    "replace-int8-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Replace Int8 Add", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ReplaceAdd());
    }
);