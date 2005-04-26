// ResultView.cpp : Implementation of CResultView

#include "stdafx.h"
#include "COMRaskroy.h"
#include "ResultView.h"
#include "convertors.h"

/////////////////////////////////////////////////////////////////////////////
// CResultView


/*STDMETHODIMP CResultView::get_Result(IResult **pVal)
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
}*/

HRESULT CResultView::OnDraw(ATL_DRAWINFO& di)
{		
	if (!m_Value)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		LPCTSTR pszText = _T("No data");
		TextOut(di.hdcDraw, 
			(rc.left + rc.right) / 2, 
			(rc.top + rc.bottom) / 2, 
			pszText, 
			lstrlen(pszText));
	}
	else
	{
		reset_dc(di.hdcDraw);
		draw(di.prcBounds->right, di.prcBounds->bottom, result.parts, result.cuts, result.sheet);
	}

	return S_OK;
}

STDMETHODIMP CResultView::get_Value(BSTR* pVal)
{
	if (!pVal)
		return E_INVALIDARG;
	*pVal = m_Value;
	return S_OK;
}

STDMETHODIMP CResultView::put_Value(BSTR newVal)
{
	if (m_Value)
		::SysFreeString(m_Value);
	m_Value = ::SysAllocString(newVal);
	try
	{
		this->result = convert(newVal);
	}
	catch (...)
	{
		return E_UNEXPECTED;
	}
	if (this->m_hWnd)
		this->RedrawWindow();
	return S_OK;
}
