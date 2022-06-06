
add_llvm_library(
    LLVMReplaceInt8Add
        MODULE RemoveInt8Add.cpp
        PLUGIN_TOOL opt
)