#include "llvm/Transforms/PeepholeOptimizationCourse/PassForI8AddNPM.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/PassForI8AddFuncs.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

PreservedAnalyses PassForI8AddNPM::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** OBFUSCATE INT8 ADD WITH NEW PASS MANAGER **********\n";
    errs() << "********** Function: " << function.getName() << '\n';

    auto changed = PreservedAnalyses::all();
	
    for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
        auto instruction = &*ii;
        ++ii;

        if (!IsItI8add(instruction)) {
                continue;
        }
				
	removeInstruction(instruction);

        changed = PreservedAnalyses::none();
	}
	
    return changed;
}