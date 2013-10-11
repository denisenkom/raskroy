// ActiveXCutting.cpp : Implementation of DLL Exports.


#include "stdafx.h"
#include "resource.h"
#include "CuttingOptimizer.h"

GUID LibID = {0xC8A15DB7UL, 0x3875, 0x4DC4, {0xAA, 0x51, 0xE7, 0xCA, 0x20, 0x74, 0x3A, 0xB8}};

// The module attribute causes DllMain, DllRegisterServer and DllUnregisterServer to be automatically implemented for you
[ module(dll, uuid = "{C8A15DB7-3875-4DC4-AA51-E7CA20743AB8}", 
		 name = "ActiveXCutting", 
		 helpstring = "ActiveXCutting 1.0 Type Library",
		 resource_name = "IDR_ACTIVEXCUTTING") ]
class CActiveXCuttingModule
{
public:
// Override CAtlDllModuleT members
};
		 
