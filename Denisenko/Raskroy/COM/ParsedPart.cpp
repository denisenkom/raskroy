// ParsedPart.cpp : Implementation of CParsedPart
#include "stdafx.h"
#include "COMRaskroy.h"
#include "ParsedPart.h"

/////////////////////////////////////////////////////////////////////////////
// CParsedPart


STDMETHODIMP CParsedPart::get_X(double *pVal)
{
	assert(pVal);
	*pVal = pos[0];

	return S_OK;
}

STDMETHODIMP CParsedPart::put_X(double newVal)
{
	pos[0] = newVal;

	return S_OK;
}

STDMETHODIMP CParsedPart::get_Y(double *pVal)
{
	assert(pVal);
	*pVal = pos[1];

	return S_OK;
}

STDMETHODIMP CParsedPart::put_Y(double newVal)
{
	pos[1] = newVal;

	return S_OK;
}

STDMETHODIMP CParsedPart::get_Length(double *pVal)
{
	assert(pVal);
	*pVal = rect.Length;

	return S_OK;
}

STDMETHODIMP CParsedPart::put_Length(double newVal)
{
	rect.Length = newVal;

	return S_OK;
}

STDMETHODIMP CParsedPart::get_Width(double *pVal)
{
	assert(pVal);
	*pVal = rect.Width;

	return S_OK;
}

STDMETHODIMP CParsedPart::put_Width(double newVal)
{
	rect.Width = newVal;

	return S_OK;
}
