#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscI8Func.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

bool checkI8(BinaryOperator* binary_op) {

    if (!binary_op) {
        return true;
    }

    if (binary_op->getOpcode() != Instruction::Add) {
        return true;
    }

    if (!(binary_op->getType()->isIntegerTy() && binary_op->getType()->getIntegerBitWidth() == 8)) {
        return true;
    }

    return false;
}

Instruction* obfuscInstruction(BinaryOperator* binary_op) {
                
    IRBuilder<> B(binary_op);

    auto const& lhs = binary_op->getOperand(0);
    auto const& rhs = binary_op->getOperand(1);
    auto const& i8 = binary_op->getType();

    return BinaryOperator::CreateAdd(
        B.CreateMul(
            B.CreateMul(
                ConstantInt::get(i8, 39),
                B.CreateAdd(
                    B.CreateAnd(lhs, rhs),
                    B.CreateAdd(
                        B.CreateMul(
                            ConstantInt::get(i8, 2),
                            B.CreateXor(lhs, rhs)
                        ),
                        ConstantInt::get(i8, 23)
                    )
                )
            ),
            ConstantInt::get(i8, 151)
        ),
        ConstantInt::get(i8, 111)
    );;
}

}