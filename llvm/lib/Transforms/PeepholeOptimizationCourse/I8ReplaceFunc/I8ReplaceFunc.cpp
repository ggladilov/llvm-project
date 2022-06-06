#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/I8ReplaceFunc.h"
#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

namespace llvm {

 void replaceInstruction(Instruction* instruction) {
    auto const& lhs = instruction->getOperand(0);
    auto const& rhs = instruction->getOperand(1);
    auto const& type = instruction->getType();
    IRBuilder<> Builder(instruction);
    Instruction* newInstruction = BinaryOperator::CreateAdd(Builder.CreateMul(Builder.CreateMul(ConstantInt::get(type, 39), Builder.CreateAdd(Builder.CreateAdd(Builder.CreateAnd(lhs, rhs), Builder.CreateMul(ConstantInt::get(type, 2),Builder.CreateXor(lhs, rhs))), ConstantInt::get(type,23))), ConstantInt::get(type,151)), ConstantInt::get(type,111));
    ReplaceInstWithInst(instruction, newInstruction);    
 }

bool isBinaryAdd(Instruction const* instruction) {
        return instruction->getOpcode() == Instruction::Add &&
               instruction->getNumOperands() == 2;
}

bool is8int(Value const* operand){
        return operand->getType()->isIntegerTy(8);
}

bool is8intAll(Instruction const* instruction) {
       auto const& operands = instruction->operands();
        return std::all_of(operands.begin(), operands.end(),
                           [](auto const& operand) { return is8int(operand); });
}

 bool I8Add(Instruction const* instruction){
        return isBinaryAdd(instruction) && is8intAll(instruction);

 }


}