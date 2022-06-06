#ifndef LLVM_TRANSFORMS_PEEPHOLE_I8_NEW_PASS_MANAGER_H
#define LLVM_TRANSFORMS_PEEPHOLE_I8_NEW_PASS_MANAGER_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class ObfuscI8NewPassManager :
    public PassInfoMixin<ObfuscI8NewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_I8_NEW_PASS_MANAGER_H