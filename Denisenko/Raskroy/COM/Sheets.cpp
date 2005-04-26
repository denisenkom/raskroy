// Sheets.cpp : Implementation of CSheets
#include "stdafx.h"
#include "COMRaskroy.h"
#include "Sheets.h"
#include "Sheet.h"

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
	if (Index >= long(sheets.size()) || Index < 0 || pVal == 0)
		return E_INVALIDARG;

	*pVal = sheets[Index];
	sheets[Index]->AddRef();

	return S_OK;
}

STDMETHODIMP CSheets::put_Item(long Index, ISheet *pnewVal)
{
	if (Index >= long(sheets.size()) || Index < 0 || pnewVal == 0)
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

STDMETHODIMP CSheets::Add2(DOUBLE Length, DOUBLE Width, long Amount, BOOL Rotate)
{
	HRESULT hres;
	ISheet * x;
	if (FAILED(hres = CSheet::CreateInstance<ISheet>(NULL, &x)))
		return hres;
	if (FAILED(hres = x->put_Width(Width)))
		return hres;
	if (FAILED(hres = x->put_Length(Length)))
		return hres;
	if (FAILED(hres = x->put_Amount(Amount)))
		return hres;
	if (FAILED(hres = x->put_Rotate(Rotate)))
		return hres;
	try
	{
		sheets.push_back(x);
	}
	catch (...)
	{
		return E_UNEXPECTED;
	}
	//pSheet->AddRef();

	return S_OK;
}
