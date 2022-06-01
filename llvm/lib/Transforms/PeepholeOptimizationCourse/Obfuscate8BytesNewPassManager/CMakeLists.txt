add_llvm_library(
    LLVMObfuscate8BytesAdd
        MODULE Obfuscate8BytesNewPassManager.cpp
        PLUGIN_TOOL opt
)
