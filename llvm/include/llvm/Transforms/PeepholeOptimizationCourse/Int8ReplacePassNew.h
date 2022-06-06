#ifndef LLVM_TRANSFORMS_PEEPHOLE_INT8_REPLACE_PASS_NEW_H
#define LLVM_TRANSFORMS_PEEPHOLE_INT8_REPLACE_PASS_NEW_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class Int8ReplacePassNew :
    public PassInfoMixin<Int8ReplacePassNew> {
public:
    PreservedAnalyses run(Function& function, FunctionAnalysisManager& analysisManager);
    static bool isRequired() { return true; }
};

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_INT8_REPLACE_PASS_NEW_H