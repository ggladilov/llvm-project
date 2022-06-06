#ifndef LLVM_TRANSFORMS_PEEPHOLE_REPLACE_ADD_H
#define LLVM_TRANSFORMS_PEEPHOLE_REPLACE_ADD_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class ReplaceAddNewPassManager :
    public PassInfoMixin<ReplaceAddNewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_REPLACE_ADD_H