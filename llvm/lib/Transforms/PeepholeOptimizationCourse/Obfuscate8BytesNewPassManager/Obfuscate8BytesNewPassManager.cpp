#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8BytesNewPassManager.h"

#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"


#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;
PreservedAnalyses ObfuscateI8AddNewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** OBFUSCATE 8 BYTES ADD WITH NEW PASS MANAGER **********\n";
    errs() << "********** Function: " << function.getName() << '\n';

    auto changed = PreservedAnalyses::all();
	
    for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
        auto instruction = &*ii;
        ++ii;
        if (!isAddWithI8(instruction)) {
                continue;
        }
		doObfuscateI8Add(instruction);
        changed = PreservedAnalyses::none();
	}
	
    return changed;
}