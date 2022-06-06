#ifndef LLVM_TRANSFORMS_PEEPHOLE_REMOVE_ADD_WITH_ZERO_H
#define LLVM_TRANSFORMS_PEEPHOLE_REMOVE_ADD_WITH_ZERO_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class PassForI8AddNPM :
    public PassInfoMixin<PassForI8AddNPM> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_REMOVE_ADD_WITH_ZERO_H