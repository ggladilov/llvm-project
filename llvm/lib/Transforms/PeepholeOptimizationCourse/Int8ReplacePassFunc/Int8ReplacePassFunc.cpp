#include "llvm/Transforms/PeepholeOptimizationCourse/Int8ReplacePassFunc.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* ReplacePass(BinaryOperator* bin_op) {
                
                IRBuilder<> B(bin_op);

                auto const& lhs = bin_op->getOperand(0);
                auto const& rhs = bin_op->getOperand(1);
                auto const& i8 = bin_op->getType();

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