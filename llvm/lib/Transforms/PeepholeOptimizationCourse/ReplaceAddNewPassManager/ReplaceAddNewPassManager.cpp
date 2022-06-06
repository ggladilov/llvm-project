#include "llvm/Transforms/PeepholeOptimizationCourse/ReplaceAddNewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/Functions.h"

#include "llvm/Pass.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses ReplaceAddNewPassManager::run(Function& F, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** REPLACE INT8 ADD **********\n";
    errs() << "********** Function: " << F.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

    for (BasicBlock& BB : F.getBasicBlockList()) {
        for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
            auto* binOp = dyn_cast<BinaryOperator>(I);

            if (!binOp || binOp->getOpcode() != Instruction::Add) {
                continue;
            }

            if (!(binOp->getType()->isIntegerTy() && binOp->getType()->getIntegerBitWidth() == 8)) {
                continue;
            }

            Instruction* replacement = ReplaceInstruction(binOp);

            ReplaceInstWithInst(BB.getInstList(), I, replacement);
            changed = PreservedAnalyses::none();
        }
    }

    return changed;
}