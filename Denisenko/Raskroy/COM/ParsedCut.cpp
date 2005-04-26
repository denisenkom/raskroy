// ParsedCut.cpp : Implementation of CParsedCut
#include "stdafx.h"
#include "COMRaskroy.h"
#include "ParsedCut.h"

/////////////////////////////////////////////////////////////////////////////
// CParsedCut


STDMETHODIMP CParsedCut::get_X(double *pVal)
{
	*pVal = pos[0];

	return S_OK;
}

STDMETHODIMP CParsedCut::put_X(double newVal)
{
	pos[0] = newVal;

	return S_OK;
}

STDMETHODIMP CParsedCut::get_Y(double *pVal)
{
	*pVal = pos[1];

	return S_OK;
}

STDMETHODIMP CParsedCut::put_Y(double newVal)
{
	pos[1] = newVal;

	return S_OK;
}

STDMETHODIMP CParsedCut::get_S(long *pVal)
{
	*pVal = s;

	return S_OK;
}

STDMETHODIMP CParsedCut::put_S(long newVal)
{
	s = newVal;

	return S_OK;
}

STDMETHODIMP CParsedCut::get_Length(double *pVal)
{
	*pVal = length;

	return S_OK;
}

STDMETHODIMP CParsedCut::put_Length(double newVal)
{
	length = newVal;

	return S_OK;
}
