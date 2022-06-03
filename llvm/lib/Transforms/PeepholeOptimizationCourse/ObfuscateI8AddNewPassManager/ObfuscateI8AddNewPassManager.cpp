#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddNewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddFunctions.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

PreservedAnalyses ObfuscateI8AddNewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** OBFUSCATE INT8 ADD WITH NEW PASS MANAGER **********\n";
    errs() << "********** Function: " << function.getName() << '\n';

    auto changed = PreservedAnalyses::all();
	
    for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
        auto instruction = &*ii;
        ++ii;

        if (!isAddI8(instruction)) {
                continue;
        }
				
		//errs() << "I8 check complite in new pass \n";
		doObfuscateI8Add(instruction);

        changed = PreservedAnalyses::none();
	}
	
    return changed;
}