#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddNewPassManager.h"

using namespace llvm;

PreservedAnalyses ObfuscateI8AddNewPassManager::run(Function& F, FunctionAnalysisManager& analysisManager) {

    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** Obfuscate I8 Add **********\n";
    errs() << "********** Function: " << function.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

       for (auto basicBlock = function.begin(), basicBlockEnd = function.end(); basicBlock != basicBlockEnd; ++basicBlock) {
            for (auto instruction = basicBlock->begin(), ie = basicBlock->end(); instruction != ie; ++instruction) {
                auto binOp = dyn_cast<BinaryOperator>(instruction);
                if (!binOp) {
                    continue;
                }
                if (binOp->getOpcode() != Instruction::Add) {
                    continue;
                }

                if (!binOp->getType()->isIntegerTy() || binOp->getType()->getIntegerBitWidth() != 8) {
                    continue;
                }

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

            changed = PreservedAnalyses::none();
            }
       }
       return changed;
}