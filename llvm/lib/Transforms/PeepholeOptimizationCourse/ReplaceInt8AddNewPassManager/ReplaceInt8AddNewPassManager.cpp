#include "llvm/Transforms/PeepholeOptimizationCourse/ReplaceInt8AddNewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/Functions.h"
#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

PreservedAnalyses ReplaceInt8AddNewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE ADD **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool replaced = false;

        for (auto ii = inst_begin(function), ie = inst_end(function); ii !=ie;) {
			auto instruction = &*ii;
			++ii;
			
			if (!isBinaryAddInt8(instruction)) {
                continue;
            }
			
			ReplaceInt8Instruction(instruction);
			replaced = true;
		}
    return replaced ? PreservedAnalyses::none()  : PreservedAnalyses::all();
}
