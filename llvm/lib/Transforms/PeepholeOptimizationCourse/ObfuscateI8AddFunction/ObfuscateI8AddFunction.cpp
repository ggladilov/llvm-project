#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddFunction.h"

namespace llvm {

    void doI8Add(Instruction* instruction){
        auto const& a = instruction->getOperand(0);
        auto const& b = instruction->getOperand(1);
        auto Const39 = ConstantInt::get(instruction->getType(), 39);
        auto Const2 = ConstantInt::get(instruction->getType(), 2);
        auto Const23 = ConstantInt::get(instruction->getType(), 23);
        auto Const151 = ConstantInt::get(instruction->getType(), 151);
        auto Const111 = ConstantInt::get(instruction->getType(), 111);

        IRBuilder<> builder(instruction);

        auto And = builder.CreateAnd(a,b);
        auto Xor = builder.CreateXor(a,b);
        auto MulW2 = builder.CreateMul(Xor,Const2);
        auto Add = builder.CreateAdd(And,MulW2);
        auto MulW39 = builder.CreateMul(Add,Const39);
        auto AddW23 = builder.CreateAdd(MulW39,Const23);
        auto MulW151 = builder.CreateMul(AddW23,Const151);

        Instruction *obfuscated = BinaryOperator::CreateAdd(MulW151,Const111);
        ReplaceInstWithInst(instruction, obfuscated);
        
    }

    bool isAddI8(Instruction const* instruction) {  
    return isBinaryAdd(instruction) && isI8Instruction(instruction);
}

}