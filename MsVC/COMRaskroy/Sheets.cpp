// Sheets.cpp : Implementation of CSheets
#include "stdafx.h"
#include "COMRaskroy.h"
#include "Sheets.h"

/////////////////////////////////////////////////////////////////////////////
// CSheets

CSheets::~CSheets()
{
	//MessageBox(0, "~CSheets()", 0, 0);
	for (t_sheets::iterator i = sheets.begin(); i != sheets.end(); i++)
		(*i)->Release();
}

STDMETHODIMP CSheets::Add(ISheet* pSheet)
{
	if (!pSheet)
		return E_INVALIDARG;

	sheets.push_back(pSheet);
	pSheet->AddRef();

	return S_OK;
}

STDMETHODIMP CSheets::get_Count(long *pVal)
{
	if (!pVal)
		return E_INVALIDARG;

	*pVal = sheets.size();

	return S_OK;
}

STDMETHODIMP CSheets::get_Item(long Index, ISheet **pVal)
{
	if (Index >= sheets.size() || Index < 0 || pVal == 0)
		return E_INVALIDARG;

	*pVal = sheets[Index];
	sheets[Index]->AddRef();

	return S_OK;
}

STDMETHODIMP CSheets::put_Item(long Index, ISheet *pnewVal)
{
	if (Index >= sheets.size() || Index < 0 || pnewVal == 0)
		return E_INVALIDARG;

	if (pnewVal != sheets[Index])
	{
		ISheet* poldVal = sheets[Index];
		sheets[Index] = pnewVal;
		pnewVal->AddRef();
		poldVal->Release();
	}

	return S_OK;
}
