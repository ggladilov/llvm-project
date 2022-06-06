#ifndef LLVM_TRANSFORMS_PEEPHOLE_FUNCTIONS_H
#define LLVM_TRANSFORMS_PEEPHOLE_FUNCTIONS_H

#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* SwapInt8Instruction(BinaryOperator* binOp);

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_FUNCTIONS_H