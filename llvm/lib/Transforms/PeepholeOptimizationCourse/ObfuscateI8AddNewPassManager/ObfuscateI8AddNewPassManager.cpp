#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/InstIterator.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddNewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddFunction.h"

using namespace llvm;

PreservedAnalyses ObfuscateI8AddNewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {

    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** Obfuscate I8 Add **********\n";
    errs() << "********** Function: " << function.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

       for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) { 
        auto instruction = &*ii;
        ++ii;

        if (!isAddI8(instruction)) {
                continue;
        }
            
            doI8Add(instruction);


            changed = PreservedAnalyses::none();
            }
       
       return changed;
}