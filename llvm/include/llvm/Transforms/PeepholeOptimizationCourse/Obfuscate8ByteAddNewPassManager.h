#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8BYTE_ADD_H
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8BYTE_ADD_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class Obfuscate8ByteAddNewPassManager
    : public PassInfoMixin<Obfuscate8ByteAddNewPassManager> {
 public:
  PreservedAnalyses run(Function& function,
                        FunctionAnalysisManager& analysisManager);
  static bool isRequired() { return true; }
};

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_8BYTE_ADD_H
