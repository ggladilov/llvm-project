#include "llvm/Transforms/PeepholeOptimizationCourse/RemoveAddWithZeroNewPassManager.h"

using namespace llvm;

PreservedAnalyses RemoveAddWithZeroNewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << function.getName() << '\n';
    return PreservedAnalyses::all();
    // or PreservedAnalyses::none() if something is changed
}
