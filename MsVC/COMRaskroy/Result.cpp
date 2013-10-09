// Result.cpp : Implementation of CCOMRaskroyApp and DLL registration.

#include "stdafx.h"
#include "COMRaskroy.h"
#include "Result.h"
#include "c:\gilotine\drawer.h"
#include "c:\gilotine\parser.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP Result::InterfaceSupportsErrorInfo(REFIID riid)
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

STDMETHODIMP Result::get_Sheet(ISheet **pVal)
{
	// TODO: Add your implementation code here
	*pVal = 0;

	return S_OK;
}

STDMETHODIMP Result::put_Sheet(ISheet *newVal)
{
	// TODO: Add your implementation code here
	if (isheet == newVal)
		return S_OK;

	if (isheet)
		isheet->Release();
	isheet = newVal;
	if (isheet)
		isheet->AddRef();

	return S_OK;
}

STDMETHODIMP Result::get_Amount(long *pVal)
{
	// TODO: Add your implementation code here
	assert(pVal);

	*pVal = amount;

	return S_OK;
}

STDMETHODIMP Result::put_Amount(long newVal)
{
	// TODO: Add your implementation code here
	amount = newVal;

	return S_OK;
}

STDMETHODIMP Result::get_ParsedParts(IParsedParts **pVal)
{
	// TODO: Add your implementation code here
	*pVal = 0;

	return S_OK;
}

/*STDMETHODIMP Result::put_ParsedParts(IParsedParts *newVal)
{
	// TODO: Add your implementation code here
	if (iparts == newVal)
		return S_OK;
	if (iparts)
		iparts->Release();
	iparts = newVal;
	if (iparts)
		iparts->AddRef();

	return S_OK;
}*/

STDMETHODIMP Result::get_ParsedCuts(IParsedCuts **pVal)
{
	// TODO: Add your implementation code here
	*pVal = 0;

	return S_OK;
}

STDMETHODIMP Result::get_Statistic(IStatistic **pVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP Result::put_Statistic(IStatistic *newVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}
