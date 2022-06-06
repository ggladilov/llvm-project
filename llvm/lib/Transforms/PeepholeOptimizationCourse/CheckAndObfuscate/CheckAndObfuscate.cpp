#include "llvm/Transforms/PeepholeOptimizationCourse/CheckAndObfuscate.h"

namespace llvm {

    bool isBinaryAdd(Instruction const* instruction) {
        return instruction->getOpcode() == Instruction::Add && instruction->getNumOperands() == 2;
    }

    bool is8Byte(Instruction const* instruction) {
        return instruction->getType()->isIntegerTy() && instruction->getType()->getIntegerBitWidth() == 8;
    }

    bool is8ByteAddition(Instruction const* instruction) {
        return isBinaryAdd(instruction) && is8Byte(instruction);
    }

    Instruction* obfuscate8ByteAddition(Instruction* instruction) {
        auto const& lhs = instruction->getOperand(0);
        auto const& rhs = instruction->getOperand(1);
        IRBuilder<> build(instruction);
        std::vector<Constant*> cnst;
        cnst.push_back(ConstantInt::get(instruction->getType(), 39));
        cnst.push_back(ConstantInt::get(instruction->getType(), 2));
        cnst.push_back(ConstantInt::get(instruction->getType(), 23));
        cnst.push_back(ConstantInt::get(instruction->getType(), 151));
        cnst.push_back(ConstantInt::get(instruction->getType(), 111));

        Value* a_and_b = build.CreateAnd(lhs, rhs);
        Value* a_xor_b_2 = build.CreateMul(build.CreateXor(lhs, rhs), cnst[1]);

        return BinaryOperator::CreateAdd(
            build.CreateMul(
                build.CreateAdd(
                    build.CreateMul(build.CreateAdd(a_and_b, a_xor_b_2), cnst[0]),
                    cnst[2]
                ),
                cnst[3]
            ),
            cnst[4]
        );         
    }

} // namespace llvm