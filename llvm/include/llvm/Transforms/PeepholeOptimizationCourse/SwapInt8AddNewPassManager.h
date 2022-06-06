#ifndef LLVM_TRANSFORMS_PEEPHOLE_SWAP_INT8_ADD_H
#define LLVM_TRANSFORMS_PEEPHOLE_SWAP_INT8_ADD_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class SwapInt8AddNewPassManager :
    public PassInfoMixin<SwapInt8AddNewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_SWAP_INT8_ADD_H