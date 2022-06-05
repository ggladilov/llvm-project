add_llvm_library(
    LLVMObfuscate8ByteAddition
        MODULE Obfuscate8ByteAddition.cpp
        PLUGIN_TOOL opt
)
