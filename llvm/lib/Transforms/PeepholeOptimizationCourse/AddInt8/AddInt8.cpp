#include "llvm/Transforms/PeepholeOptimizationCourse/AddInt8Func.h"

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

struct AddInt8Pass : public FunctionPass {
    static char ID;
    AddInt8Pass() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** ADD INT8 PASS **********\n";
        errs() << "********** Function: " << F.getName() << '\n';

        bool changed = false;

        for (BasicBlock& BB : F.getBasicBlockList()) {
            for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
                auto *bin_op = dyn_cast<BinaryOperator>(I);

                if (!bin_op || bin_op->getOpcode() != Instruction::Add) {
                    continue;
                }
                if (!(bin_op->getType()->isIntegerTy() && bin_op->getType()->getIntegerBitWidth() == 8)) {
                    continue;
                }

                ReplaceInstWithInst(BB.getInstList(), I, GetNewInstruction(bin_op));
                changed = true;
            }
        }

        return changed;
    }
};

}

char AddInt8Pass::ID = 0;
static RegisterPass<AddInt8Pass> X(
    "add-int8-pass",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Replace Int8 Add Pass", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new AddInt8Pass());
    }
);