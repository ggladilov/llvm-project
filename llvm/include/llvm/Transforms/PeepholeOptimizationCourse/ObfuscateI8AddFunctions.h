#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION

#include "llvm/IR/Instruction.h"
#include "llvm/IR/Type.h"

namespace llvm {

inline bool isBinaryAdd(Instruction const* instruction){
	return instruction->getOpcode() == Instruction::Add &&
           instruction->getNumOperands() == 2;
}

inline bool isI8Instruction(Instruction const* instruction){
	return instruction->getType()->isIntegerTy() && 
	   instruction->getType()->getIntegerBitWidth() == 8;
}

bool isAddI8(Instruction const* instruction);
void doObfuscateI8Add(Instruction* instruction);

}

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_I8_ADD_FUNCTION