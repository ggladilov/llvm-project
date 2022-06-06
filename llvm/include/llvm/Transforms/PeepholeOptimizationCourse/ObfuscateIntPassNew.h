#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_INT_PASS_NEW_H
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_INT_PASS_NEW_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class ObfuscateIntPassNew :
    public PassInfoMixin<ObfuscateIntPassNew> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_INT_PASS_NEW_H