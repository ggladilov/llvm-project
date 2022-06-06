#ifndef LLVM_TRANSFORMS_PEEPHOLE_ADD_INT8_FUNC_H
#define LLVM_TRANSFORMS_PEEPHOLE_ADD_INT8_FUNC_H

#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* GetNewInstruction(BinaryOperator* binary_operator);

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_ADD_INT8_FUNC_H
