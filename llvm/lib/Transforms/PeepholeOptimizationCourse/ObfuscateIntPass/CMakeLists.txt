add_llvm_library(
    LLVMObfuscateIntPass
        MODULE ObfuscateIntPass.cpp
        PLUGIN_TOOL opt
) 