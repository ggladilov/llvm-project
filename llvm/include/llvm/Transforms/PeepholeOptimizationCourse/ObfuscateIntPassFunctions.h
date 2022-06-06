#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_INT_PASS_FUNCTIONS_H
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_INT_PASS_FUNCTIONS_H

#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* PassInstruction(BinaryOperator* binary_operator);

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_INT_PASS_FUNCTIONS_H
