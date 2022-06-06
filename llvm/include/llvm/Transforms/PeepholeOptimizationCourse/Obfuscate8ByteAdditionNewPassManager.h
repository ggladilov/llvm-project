#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8BYTE_ADDITION_H
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8BYTE_ADDITION_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class Obfuscate8ByteAdditionNewPassManager :
    public PassInfoMixin<Obfuscate8ByteAdditionNewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8BYTE_ADDITION_H 