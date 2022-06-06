#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8ByteAdditionNewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/CheckAndObfuscate.h"

using namespace llvm;

PreservedAnalyses Obfuscate8ByteAdditionNewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** OBFUSCATE 8BYTE ADDITION **********\n";
    errs() << "********** Function: " << function.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();
    for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
        auto instruction = &*ii;
        ++ii;

        if (!is8ByteAddition(instruction)) {
            continue;
        }

        ReplaceInstWithInst(instruction, obfuscate8ByteAddition(instruction));
        changed = PreservedAnalyses::none();
    }

    return changed;
}

