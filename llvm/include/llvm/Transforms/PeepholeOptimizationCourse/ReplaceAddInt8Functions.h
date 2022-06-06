#ifndef LLVM_TRANSFORMS_PEEPHOLE_PASSFUNCTIONS_H
#define LLVM_TRANSFORMS_PEEPHOLE_PASSFUNCTIONS_H

#include "llvm/IR/Instruction.h"

namespace llvm {

bool isAddInt8(Instruction const* instr);
void ReplaceAddInt8Instruction(Instruction* instr);


}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_PASSFUNCTIONS_H 
