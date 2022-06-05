add_llvm_library(
    LLVMObfuscateI8Add
        MODULE ObfuscateI8Add.cpp
        PLUGIN_TOOL opt
		
	LINK_COMPONENTS
	ObfuscateI8AddFunctions
	Core
	Support
)
