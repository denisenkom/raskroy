// COMRaskroy.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f COMRaskroyps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "COMRaskroy.h"

#include "COMRaskroy_i.c"
#include "Sheet.h"
#include "Raskroy.h"
#include "Sheets.h"
#include "Result.h"
#include "ResultView.h"
#include "ParsedPart.h"
#include "ParsedCut.h"
#include "ParsedParts.h"
#include "ParsedCuts.h"
#include "Statistic.h"


CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_Raskroy, CRaskroy)
OBJECT_ENTRY(CLSID_Sheets, CSheets)
OBJECT_ENTRY(CLSID_Result, Result)
OBJECT_ENTRY(CLSID_Sheet, CSheet)
OBJECT_ENTRY(CLSID_ResultView, CResultView)
OBJECT_ENTRY(CLSID_ParsedPart, CParsedPart)
OBJECT_ENTRY(CLSID_ParsedCut, CParsedCut)
OBJECT_ENTRY(CLSID_ParsedParts, CParsedParts)
OBJECT_ENTRY(CLSID_ParsedCuts, CParsedCuts)
OBJECT_ENTRY(CLSID_Statistic, CStatistic)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_COMRASKROYLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}