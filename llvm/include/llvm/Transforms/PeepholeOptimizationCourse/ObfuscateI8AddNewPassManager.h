#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_H
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_H

#include "llvm/IR/PassManager.h"

namespace llvm {

    class ObfuscateI8AddNewPassManager :
        public PassInfoMixin<ObfuscateI8AddNewPassManager>{
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
        };
}

#endif //LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_H