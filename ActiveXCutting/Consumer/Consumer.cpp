// Consumer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


typedef HRESULT (STDAPICALLTYPE *DllGetClassObjectType)(

REFCLSID rclsid,

REFIID riid,

LPVOID * ppv

);

GUID CLSID_Sheet = {0x6260DA6D,0x9679,0x4CE4,{0xB8,0xA4,0x10,0x3B,0x0C,0x45,0xDD,0x36}};

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	HMODULE hmod = LoadLibrary(_T("D:\\!MyData\\Denisenko\\Raskroy\\ActiveXCutting\\Debug\\ActiveXCutting.dll"));
	DWORD lastError = GetLastError();
	DllGetClassObjectType dllGetClassObject = (DllGetClassObjectType)GetProcAddress(hmod, "GetClassObject");
	CComPtr<IUnknown> unk;
	dllGetClassObject(CLSID_Sheet, IID_IUnknown, (void**)&unk);
	return 0;
}

