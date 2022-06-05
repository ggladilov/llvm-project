#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddNewPassManager.h"
#include "llvm/Transforms/PeppholeOptimizationCourse/ObfuscateI8AddFunction.h"

using namespace llvm;

PreservedAnalyses ObfuscateI8AddNewPassManager::run(Function& F, FunctionAnalysisManager& analysisManager) {

    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** Obfuscate I8 Add **********\n";
    errs() << "********** Function: " << function.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

       for (auto basicBlock = function.begin(), basicBlockEnd = function.end(); basicBlock != basicBlockEnd; ++basicBlock) {
            for (auto instruction = basicBlock->begin(), ie = basicBlock->end(); instruction != ie; ++instruction) {
                auto binOp = dyn_cast<BinaryOperator>(instruction);
                if (!binOp) {
                    continue;
                }
                if (binOp->getOpcode() != Instruction::Add) {
                    continue;
                }

                if (!binOp->getType()->isIntegerTy() || binOp->getType()->getIntegerBitWidth() != 8) {
                    continue;
                }


            doI8Add(instruction);


            changed = PreservedAnalyses::none();
            }
       }
       return changed;
}