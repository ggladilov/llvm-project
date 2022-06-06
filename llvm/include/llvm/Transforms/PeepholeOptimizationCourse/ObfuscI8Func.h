#ifndef LLVM_TRANSFORMS_PEEPHOLE_I8_FUNC_H
#define LLVM_TRANSFORMS_PEEPHOLE_I8_FUNC_H

#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

bool checkI8(BinaryOperator* binary_op);
Instruction* obfuscInstruction(BinaryOperator* binary_op);

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_I8_FUNC_H
