#ifndef LLVM_TRANSFORMS_PEEPHOLE_FUNCTIONS_H
#define LLVM_TRANSFORMS_PEEPHOLE_FUNCTIONS_H

#include "llvm/IR/Instruction.h"

namespace llvm {
	
bool isBinaryAddInt8(Instruction const* instruction);
void ReplaseInstruction(Instruction* instruction);


}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_FUNCTIONS_H