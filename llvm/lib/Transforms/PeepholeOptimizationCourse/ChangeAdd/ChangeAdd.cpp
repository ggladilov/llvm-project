#include "llvm/Transforms/PeepholeOptimizationCourse/ChangeAddFuncs.h"

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

struct ChangeAddPass : public FunctionPass {
    static char ID;
    ChangeAddPass() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** CHANGE INT8 ADD **********\n";
        errs() << "********** Function: " << F.getName() << '\n';

        bool inst_changed = false;

        for (BasicBlock& BB : F.getBasicBlockList()) {
            for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
                auto *binOp = dyn_cast<BinaryOperator>(I);

                if (checkForInt8Op(binOp)) {
                    continue;
                }

                Instruction* new_instruction = changeAddNewInstruction(binOp);
                ReplaceInstWithInst(BB.getInstList(), I, new_instruction);
                inst_changed = true;
            }
        }

        return inst_changed;
    }
};

}

char ChangeAddPass::ID = 0;
static RegisterPass<ChangeAddPass> X(
    "change-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Change Add Pass", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ChangeAddPass());
    }
);