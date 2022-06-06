#ifndef LLVM_TRANSFORMS_PEEPHOLE_CHANGE_ADD_NEW_PASS_MANAGER_H
#define LLVM_TRANSFORMS_PEEPHOLE_CHANGE_ADD_NEW_PASS_MANAGER_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class ChangeAddNewPassManager :
    public PassInfoMixin<ChangeAddNewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_CHANGE_ADD_NEW_PASS_MANAGER_H