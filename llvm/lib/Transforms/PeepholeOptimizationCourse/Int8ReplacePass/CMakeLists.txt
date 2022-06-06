add_llvm_library(
    LLVMInt8ReplacePass
        MODULE Int8ReplacePass.cpp
        PLUGIN_TOOL opt
) 