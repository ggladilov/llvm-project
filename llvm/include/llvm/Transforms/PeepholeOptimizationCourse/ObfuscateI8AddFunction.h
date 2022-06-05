#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION_H
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION_H

#include "llvm/IR/Instruction.h"

namespace llvm {
    
    void doI8Add(Instruction* instruction);

}

#endif //LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION_H