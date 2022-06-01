#ifndef LLVM_TRANSFORMS_PEEPHOLE_REPLASE_ADD_H
#define LLVM_TRANSFORMS_PEEPHOLE_REPLASE_ADD_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class ReplaseAddNewPassManager :
    public PassInfoMixin<ReplaseAddNewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_REPLASE_ADD_H