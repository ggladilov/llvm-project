#include "llvm/Transforms/PeepholeOptimizationCourse/ReplaceAddInt8NewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/ReplaceAddInt8Functions.h"
#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

PreservedAnalyses ReplaceAddInt8NewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE ADD INT 8**********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;

        for (auto ii = inst_begin(function), ie = inst_end(function); ii !=ie;) {
			auto instruction = &*ii;
			++ii;

			if (!isAddInt8(instruction)) continue;
           
			ReplaceAddInt8Instruction(instruction);
			changed = true;
		}
		if(changed) return PreservedAnalyses::none();
		
    return PreservedAnalyses::all();
} 
