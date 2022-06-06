#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION

#include "llvm/IR/Instruction.h"
#include "llvm/IR/Type.h"

namespace llvm {

void removeInstruction(Instruction* instruction);
bool IsItI8add(Instruction const* instruction);

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION