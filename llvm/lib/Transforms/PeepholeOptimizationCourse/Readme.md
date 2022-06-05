# Peephole Optimization Course

## Description

Gives an overview how to write transformation passes in LLVM using legacy and new pass managers. Source code of passes is located in [llvm/lib/Transforms/PeepholeOptimizationCourse](https://github.com/ggladilov/llvm-project/tree/peephole-optimization-course/llvm/lib/Transforms/PeepholeOptimizationCourse).

## Homework

### Task defintion

Considering following C++ program:

```cpp
#include <string>
#include <cstdlib>

int8_t sum_to_obfuscate(int8_t a, int8_t b, int8_t c, int8_t d) {
    return a + b + c + d;
}

int main(int argc, char* argv[]) {
    auto a = std::stoi(argv[1]);
    auto b = std::stoi(argv[2]);
    auto c = std::stoi(argv[3]);
    auto d = std::stoi(argv[4]);
    return sum_to_obfuscate(a, b, c, d);
}

```

Write a pass to obfuscate signed 8-byte addition with following formula:

a + b -> (39 * ((a $\bigoplus$ b) + 2 * (a $\bigwedge$ b)) + 23) * 151 + 111, where

$\bigoplus$ is logical AND

$\bigwedge$ is XOR

Pass has to be written using both legacy and new pass managers.

### Acceptance Format

The solution must be submitted in a form of a pull request to this repository.

It is important to:

* Mention [me](https://github.com/ggladilov) in a comment of the pull request to notify about it. You will **not** be able to request me as an reviewer.
* Use [peephole-optimization-course](https://github.com/ggladilov/llvm-project/tree/peephole-optimization-course) (**not** [main](https://github.com/ggladilov/llvm-project/tree/main)) as a target branch, otherwise the pull request will contain my commits which is prohibited.
* Attach assembly files with outputs (those that are with .ll extension) to pull request.
* Attach command lines used to get assembly files from point above.

If I approved the pull request it means the solution is accepted.

### Functions & classes to use

* [llvm::Function::begin](https://llvm.org/doxygen/classllvm_1_1Function.html#a88a5e60837674780a9d812d661897ac5) - iterator to the first basic block inside the function
* [llvm::Function::end](https://llvm.org/doxygen/classllvm_1_1Function.html#ae4ca2261b8b901e415fda7feac5051ea) - iterator just after the last basic block inside the function
* [llvm::BasicBlock::begin](https://llvm.org/doxygen/classllvm_1_1BasicBlock.html#a0ed5f3ab3c2e4196ee0cffffa080c062) - iterator to the first instruction inside the basic block
* [llvm::BasicBlock::end](https://llvm.org/doxygen/classllvm_1_1BasicBlock.html#a0b4e7bee9b8575cc7db73329f1a561bd) - iterator just after the last instruction inside the basic block
* [dyn_cast](https://llvm.org/docs/ProgrammersManual.html#the-isa-cast-and-dyn-cast-templates) - dynamic cast operator which is used inside LLVM instead of [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast)
* [llvm::BinaryOperator](https://llvm.org/doxygen/classllvm_1_1BinaryOperator.html) - binary operator class
* [llvm::Instruction::getOpcode](https://llvm.org/doxygen/classllvm_1_1Instruction.html#ab4e05d690df389b8b1477c90387b575f) - get operation code of the instruction
* [llvm::Value::getType](https://llvm.org/doxygen/Value_8h_source.html#l00255) - get type of the Value
* [llvm::Type::isIntegerTy](https://llvm.org/doxygen/classllvm_1_1Type.html#ac6d28a9b11139182134a9618028a0d07) - returns true if the instance is IntegerType
* [llvm::Type::getIntegerBitWidth](https://llvm.org/doxygen/classllvm_1_1Type.html#a13e877ef779ba7a0688081079f4f9b03) - returns bitwidth of the type
* [llvm::ConstantInt::get](https://llvm.org/doxygen/Constants_8cpp_source.html#l00919) - creates an instance of ConstantInt with given type and value
* [llvm::IRBuilder](https://llvm.org/doxygen/classllvm_1_1IRBuilder.html) - builder class for creating operations
* [llvm::IRBuilder::CreateAdd](https://llvm.org/doxygen/IRBuilder_8h_source.html#l01201) - creates Add operation with given operands
* [llvm::IRBuilder::CreateMul](https://llvm.org/doxygen/classllvm_1_1IRBuilderBase.html#a4d748f0a6d8a5086dbf568d39c03b674) - creates Mul operation with given operands
* [llvm::IRBuilder::CreateXor](https://llvm.org/doxygen/classllvm_1_1IRBuilderBase.html#a84652ca512637318e6729c659cf4541d) - creates Xor operation with given operands
* [llvm::IRBuilder::CreateAnd](https://llvm.org/doxygen/IRBuilder_8h_source.html#l01350) - creates And operation with given operands
* [llvm::BasicBlock::getInstList](https://llvm.org/doxygen/classllvm_1_1BasicBlock.html#a76099f3fde625e6e75431b6afd7081ce) - returns the underlying instruction list container of the basic block
* [llvm::ReplaceInstWithInst](https://llvm.org/doxygen/namespacellvm.html#aa6aa39b86007ee97f50248d2fb1b7220) - replaces the instruction specified by BI with the instruction specified by I

### Notes

* In C/C++ there are rules which allow compiler to **promote** integral types before operation is performed: [integral promotion](https://en.cppreference.com/w/cpp/language/implicit_conversion#Integral_promotion) (this is the case for `uint8_t` additions). It means that if you compile your program with byte additions without optimizations (using `-O0` option) you may see resulting IR with `int` additions instead of original ones. Such an IR would not be the subject for a pass which obfuscates only byte additions. To resolve that issue use `-O1` optimization level instead of `-O0`. As a result you would have an IR with original byte additions.
* Do not forget to check an IR after modification is still valid.
* You can reset/add new remote instead of cloning new repository if you already have llvm's clone on your machine (check [Commands from session](https://github.com/ggladilov/llvm-project/blob/peephole-optimization-course/llvm/lib/Transforms/PeepholeOptimizationCourse/commands.txt)).

### Deadline

06-06-2022 23:59:59

## Useful links

* [Commands from session](https://github.com/ggladilov/llvm-project/blob/peephole-optimization-course/llvm/lib/Transforms/PeepholeOptimizationCourse/commands.txt)
* [Getting started with the LLVM system](https://llvm.org/docs/GettingStarted.html)
* [LLVM programmer's manual](https://llvm.org/docs/ProgrammersManual.html)
* [Writing an LLVM Pass](https://llvm.org/docs/WritingAnLLVMPass.html) (with legacy pass manager)
* [Writing an LLVM Pass](https://llvm.org/docs/WritingAnLLVMNewPMPass.html) (with new pass manager)
* [Using the new pass manager](https://llvm.org/docs/NewPassManager.html)
* [2019 LLVM Developers’ Meeting: A. Warzynski “Writing an LLVM Pass: 101”](https://www.youtube.com/watch?v=ar7cJl2aBuU)
