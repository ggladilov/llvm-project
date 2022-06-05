#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD

#include "llvm/IR/PassManager.h"

namespace llvm {

class ReplaceInt8SumNewPassManager :
    public PassInfoMixin<ReplaceInt8SumNewPassManager> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD
