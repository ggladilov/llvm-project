
add_llvm_library(
    LLVMSwapInt8Add
        MODULE SwapInt8Add.cpp
        PLUGIN_TOOL opt
)