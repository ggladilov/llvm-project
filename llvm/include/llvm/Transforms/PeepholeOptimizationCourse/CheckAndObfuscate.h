#ifndef LLVM_TRANSFORMS_PEEPHOLE_CHECK_AND_OBFUSCATE_H
#define LLVM_TRANSFORMS_PEEPHOLE_CHECK_AND_OBFUSCATE_H

#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

namespace llvm {

    bool isBinaryAdd(Instruction const* instruction);

    bool is8Byte(Instruction const* instruction);

    bool is8ByteAddition(Instruction const* instruction);

    Instruction* obfuscate8ByteAddition(Instruction* instruction);

} // namespace llvm


#endif  // LLVM_TRANSFORMS_PEEPHOLE_CHECK_AND_OBFUSCATE_H