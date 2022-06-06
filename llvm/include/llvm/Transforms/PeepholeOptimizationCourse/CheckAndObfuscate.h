#ifndef LLVM_TRANSFORMS_PEEPHOLE_CHECK_AND_OBFUSCATE_H
#define LLVM_TRANSFORMS_PEEPHOLE_CHECK_AND_OBFUSCATE_H
#include "llvm/Transforms/PeepholeOptimizationCourse/Headers.h"

namespace llvm {

    bool isBinaryAdd(Instruction const* instruction);

    bool is8Byte(Instruction const* instruction);

    bool is8ByteAddition(Instruction const* instruction);

    Instruction* obfuscate8ByteAddition(Instruction* instruction);

} // namespace llvm


#endif  // LLVM_TRANSFORMS_PEEPHOLE_CHECK_AND_OBFUSCATE_H