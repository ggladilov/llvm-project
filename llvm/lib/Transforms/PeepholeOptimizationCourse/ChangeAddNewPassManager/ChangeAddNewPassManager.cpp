#include "llvm/Transforms/PeepholeOptimizationCourse/ChangeAddFuncs.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/ChangeAddNewPassManager.h"

#include "llvm/Pass.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses ChangeAddNewPassManager::run(Function& F, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** REPLACE INT8 ADD NEW MANAGER **********\n";
    errs() << "********** Function: " << F.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

    for (BasicBlock& BB : F.getBasicBlockList()) {
        for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
            auto* bin_op = dyn_cast<BinaryOperator>(I);

                if (!bin_op ||
                    bin_op->getOpcode() != Instruction::Add ||
                    !(bin_op->getType()->isIntegerTy() && bin_op->getType()->getIntegerBitWidth() == 8)
                ) {
                    continue;
                }

                ReplaceInstWithInst(BB.getInstList(), I, GetNewInstruction(bin_op));
                changed = PreservedAnalyses::none();
        }
    }

    return changed;
}