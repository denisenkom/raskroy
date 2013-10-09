// oldraskroy.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "oldraskroy.h"
#include "Raskroy.h"
#include "Drawer1.h"
#include "common.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

OLDRASKROY_API HRESULT __stdcall raskroy_api::RaskroyCreate(raskroy_api::IRaskroy1** ppapi)
{
	if (ppapi == 0)
		return E_INVALIDARG;

	try
	{
		assert(ppapi);
		*ppapi = raskroy_api::CRaskroy1::Create();
	}
	catch (raskroy_error &err)
	{
		return err;
	}
	catch (...)
	{
		return E_UNEXPECTED;
	}
	assert(*ppapi);
	return S_OK;
}

OLDRASKROY_API HRESULT __stdcall raskroy_api::DrawerCreate(raskroy_api::IDrawer1** ppapi)
{
	if (ppapi == 0)
		return E_INVALIDARG;

	try
	{
		assert(ppapi);
		*ppapi = raskroy_api::CDrawer1::Create();
	}
	catch (raskroy_error &err)
	{
		return err;
	}
	catch (...)
	{
		return E_UNEXPECTED;
	}
	assert(*ppapi);
	return S_OK;
}