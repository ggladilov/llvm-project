#ifndef LLVM_TRANSFORMS_PEEPHOLE_ADD_INT8_NEW_H
#define LLVM_TRANSFORMS_PEEPHOLE_ADD_INT8_NEW_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class AddInt8New :
    public PassInfoMixin<AddInt8New> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_ADD_INT8_NEW_H