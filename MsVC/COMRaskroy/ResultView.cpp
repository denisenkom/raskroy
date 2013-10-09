// ResultView.cpp : Implementation of CResultView

#include "stdafx.h"
#include "COMRaskroy.h"
#include "ResultView.h"
#include "convertors.h"

/////////////////////////////////////////////////////////////////////////////
// CResultView


STDMETHODIMP CResultView::get_Result(IResult **pVal)
{
	*pVal = iresult;

	if (iresult)
		iresult->AddRef();

	return S_OK;
}

STDMETHODIMP CResultView::putref_Result(IResult *newVal)
{
	if (iresult == newVal)
		return S_OK;

	if (iresult)
		iresult->Release();
	iresult = newVal;
	if (iresult)
	{
		iresult->AddRef();
		result = convert(*newVal);
	}
	return S_OK;
}
