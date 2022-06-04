#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8ByteAdditionNewPassManager.h"

#include "llvm/Pass.h"

#include "llvm/IR/InstIterator.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses Obfuscate8ByteAdditionNewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** OBFUSCATE 8BYTE ADDITION **********\n";
    errs() << "********** Function: " << function.getName() << '\n';
    
    PreservedAnalyses changed = PreservedAnalyses::all();
    for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
        auto instruction = &*ii;
        ++ii;
        
        bool isBinaryAdd = (instruction->getOpcode() == Instruction::Add && instruction->getNumOperands() == 2);
        bool is8Byte = (instruction->getType()->isIntegerTy() && instruction->getType()->getIntegerBitWidth() == 8);
        bool is8ByteAddition = (isBinaryAdd && is8Byte);
        if (!is8ByteAddition) {
            continue;
        }

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

        Instruction* obfuscate = BinaryOperator::CreateAdd(
            build.CreateMul(
                build.CreateAdd(
                    build.CreateMul(build.CreateAdd(a_and_b, a_xor_b_2), cnst[0]),
                    cnst[2]
                ),
                cnst[3]
            ),
            cnst[4]
        );        

        ReplaceInstWithInst(instruction, obfuscate);
        changed = PreservedAnalyses::none();
    }

    return changed;
}

