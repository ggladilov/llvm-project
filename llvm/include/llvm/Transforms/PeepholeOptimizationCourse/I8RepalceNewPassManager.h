#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD

#include "llvm/IR/PassManager.h"

namespace llvm {

class RemoveI8AddNewPassManager :
    public PassInfoMixin<RemoveI8AddNewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD 