// Result.cpp : Implementation of CCOMRaskroyApp and DLL registration.

#include "stdafx.h"
#include "COMRaskroy.h"
#include "Result.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CResult::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IResult,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CResult::get_Sheet(ISheet **pVal)
{
	assert(pVal);
	*pVal = isheet;
	return S_OK;
}

STDMETHODIMP CResult::put_Sheet(ISheet *newVal)
{
	if (isheet == newVal)
		return S_OK;
	if (isheet)
		isheet->Release();
	isheet = newVal;
	if (isheet)
		isheet->AddRef();
	return S_OK;
}

STDMETHODIMP CResult::get_Amount(long *pVal)
{
	assert(pVal);
	*pVal = amount;
	return S_OK;
}

STDMETHODIMP CResult::put_Amount(long newVal)
{
	amount = newVal;
	return S_OK;
}

STDMETHODIMP CResult::get_ParsedParts(IParsedParts **pVal)
{
	assert(pVal);
	*pVal = iparts;
	return S_OK;
}

STDMETHODIMP CResult::put_ParsedParts(IParsedParts *newVal)
{
	if (iparts == newVal)
		return S_OK;
	if (iparts)
		iparts->Release();
	iparts = newVal;
	if (iparts)
		iparts->AddRef();

	return S_OK;
}

STDMETHODIMP CResult::get_ParsedCuts(IParsedCuts **pVal)
{
	assert(pVal);
	*pVal = icuts;
	return S_OK;
}

STDMETHODIMP CResult::put_ParsedCuts(IParsedCuts *newVal)
{
	if (icuts == newVal)
		return S_OK;
	if (icuts)
		icuts->Release();
	icuts = newVal;
	if (icuts)
		icuts->AddRef();

	return S_OK;
}

STDMETHODIMP CResult::get_String(BSTR* pVal)
{
	*pVal = str;
	return S_OK;
}

STDMETHODIMP CResult::put_String(BSTR newVal)
{
	SysFreeString(str);
	str = SysAllocString(newVal);
	return S_OK;
}

STDMETHODIMP CResult::get_UsefulScrap(DOUBLE* pVal)
{
	if (!pVal)
		return E_INVALIDARG;
	*pVal = stat.useful_remain;
	return S_OK;
}

STDMETHODIMP CResult::put_UsefulScrap(DOUBLE newVal)
{
	stat.useful_remain = newVal;
	return S_OK;
}

STDMETHODIMP CResult::get_UnUsefulScrap(DOUBLE* pVal)
{
	*pVal = stat.unuseful_remain;

	return S_OK;
}

STDMETHODIMP CResult::put_UnUsefulScrap(DOUBLE newVal)
{
	stat.unuseful_remain = newVal;
	return S_OK;
}

STDMETHODIMP CResult::get_UsefulNum(long* pVal)
{
	*pVal = stat.useful_num;
	return S_OK;
}

STDMETHODIMP CResult::put_UsefulNum(long newVal)
{
	stat.useful_num = newVal;
	return S_OK;
}

STDMETHODIMP CResult::get_Opilki(DOUBLE* pVal)
{
	*pVal = stat.opilki;
	return S_OK;
}

STDMETHODIMP CResult::put_Opilki(DOUBLE newVal)
{
	stat.opilki = newVal;
	return S_OK;
}
