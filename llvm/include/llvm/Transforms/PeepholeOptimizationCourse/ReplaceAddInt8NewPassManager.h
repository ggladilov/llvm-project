#ifndef LLVM_TRANSFORMS_PEEPHOLE_REPLACE_ADD_INT8_H
#define LLVM_TRANSFORMS_PEEPHOLE_REPLACE_ADD_INT8_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class ReplaceAddInt8NewPassManager :
    public PassInfoMixin<ReplaceAddInt8NewPassManager> {
public:
    PreservedAnalyses run(Function& func, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_REPLACE_ADD_INT8_H 
