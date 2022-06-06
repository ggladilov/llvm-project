#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscI8NewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscI8Func.h"

#include "llvm/Pass.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses ObfuscI8NewPassManager::run(Function& F, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** INT8 OBFUSC NEW **********\n";
    errs() << "********** Function: " << F.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

    for (BasicBlock& BB : F.getBasicBlockList()) {
        for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
            auto* binary_op = dyn_cast<BinaryOperator>(I);

                if (checkI8(binary_op)) {
                    continue;
                }
                ReplaceInstWithInst(BB.getInstList(), I, obfuscInstruction(binary_op));
                changed = PreservedAnalyses::none();
        }
    }

    return changed;
}