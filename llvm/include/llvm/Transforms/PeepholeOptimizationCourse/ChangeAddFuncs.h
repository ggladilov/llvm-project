#ifndef LLVM_TRANSFORMS_PEEPHOLE_CHANGE_ADD_FUNC_H
#define LLVM_TRANSFORMS_PEEPHOLE_CHANGE_ADD_FUNC_H

#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

bool checkForInt8Op(BinaryOperator* binOp);
Instruction* changeAddNewInstruction(BinaryOperator* binOp);

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_CHANGE_ADD_FUNC_H
