#include "llvm/Transforms/PeepholeOptimizationCourse/ChangeAddFuncs.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

bool checkForInt8Op(BinaryOperator* binOp) {

    if (!binOp || binOp->getOpcode() != Instruction::Add) {
        if (!(binOp->getType()->isIntegerTy() && binOp->getType()->getIntegerBitWidth() == 8)) {
                return true;
        }
    }

    return false;
}

Instruction* changeAddNewInstruction(BinaryOperator* binOp) {
                
    IRBuilder<> B(binOp);
    auto const& lhs = binOp->getOperand(0);
    auto const& rhs = binOp->getOperand(1);
    auto const& i8 = binOp->getType();

    Instruction* new_instruction = BinaryOperator::CreateAdd(
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
    );

    return new_instruction;
}

}