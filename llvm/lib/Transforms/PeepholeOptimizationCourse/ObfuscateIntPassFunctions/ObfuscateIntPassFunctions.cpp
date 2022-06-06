#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateIntPassFunctions.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* PassInstruction(BinaryOperator* binary_operator) {
                IRBuilder<> B(binary_operator);
                auto const& lhs = binary_operator->getOperand(0);
                auto const& rhs = binary_operator->getOperand(1);
                auto const& i8 = binary_operator->getType();

                Instruction *replacement = BinaryOperator::CreateAdd(
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

                return replacement;
}

}