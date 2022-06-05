#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUnils.h"

#include "llvm/Transforms/PeepholeOptimizationCourse/ObufscateI8AddFunction.h"

namespace llvm {

    void doI8Add(Instruction* instruction){
        auto const& a = binOp->getOperand(0);
        auto const& b = binOp->getOperand(1);
        auto Const39 = ConstantInt::get(binOp->getType(), 39);
        auto Const2 = ConstantInt::get(binOp->getType(), 2);
        auto Const23 = ConstantInt::get(binOp->getType(), 23);
        auto Const151 = ConstantInt::get(binOp->getType(), 151);
        auto Const111 = ConstantInt::get(binOp->getType(), 111);

        IRBuidler<> builder(binOp);

        auto And = builder.CreateAnd(a,b);
        auto Xor = builder.CreateXor(a,b);
        auto MulW2 = builder.CreateMul(Xor,Const2);
        auto Add = builder.CreateAdd(And,MulW2);
        auto MulW39 = builder.CreateMul(Add,Const39);
        auto AddW23 = builder.CreateAdd(MulW39,Const23)
        auto MulW151 = builder.CreateMul(Sum,Const151);

        auto obfuscated = BinaryOperator::CreateAdd(MulW151,Const111);
        ReplaceInstWithInst(basicBlock->getInstList(), instruction, obfuscated);
        
    }

}