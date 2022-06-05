#include "llvm/Transforms/PeepholeOptimizationCourse/AddObfuscateNewPassManager.h"
#include "llvm/Pass.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses AddObfuscateNewPassManager::run(Function& F, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** REPLACE INT8 ADD **********\n";
    errs() << "********** Function: " << F.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

    for (BasicBlock& basic : F.getBasicBlockList()) {
        auto instructionBegin = basic.begin();
        auto instructionEnd = basic.end();
        for (; instructionBegin != instructionEnd; ++instructionBegin) {
            auto* binaryOp = dyn_cast<BinaryOperator>(instructionBegin);

            if (!binaryOp || (binaryOp->getOpcode() != Instruction::Add)) {
                continue;
            }

            if (!(binaryOp->getType()->isIntegerTy() && binaryOp->getType()->getIntegerBitWidth() == 8)) {
                continue;
            }

            auto const& lhs = binaryOp->getOperand(0);
            auto const& rhs = binaryOp->getOperand(1);
            auto const& type = binaryOp->getType();

            IRBuilder<> builder(binaryOp);

            auto and = builder.CreateAnd(lhs, rhs);
            auto xor = builder.CreateXor(lhs, rhs);
            auto mul_2 = builder.CreateMul(ConstantInt::get(type, 2), xor);
            auto add = builder.CreateAdd(and, mul_2);
            auto mul_39 = builder.CreateMul(ConstantInt::get(type, 39), add);
            auto add_23 = builder.CreateAdd(mul_39, ConstantInt::get(type, 23));
            auto mul_151 = builder.CreateMul(add_23, ConstantInt::get(type, 151));
            Instruction* replaceInst = BinaryOperator::CreateAdd(mul_151, ConstantInt::get(type, 111));

            ReplaceInstWithInst(basic.getInstList(), instructionBegin, replaceInst);
            changed = PreservedAnalyses::none();
        }
    }

    return changed;
}
