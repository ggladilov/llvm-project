#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8B_ADD
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8B_ADD

#include "llvm/IR/PassManager.h"

namespace llvm {

class Obfuscate8BytesNewPassManager :
    public PassInfoMixin<Obfuscate8BytesNewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8B_ADD