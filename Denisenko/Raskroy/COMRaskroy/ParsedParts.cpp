// ParsedParts.cpp : Implementation of CParsedParts
#include "stdafx.h"
#include "COMRaskroy.h"
#include "ParsedParts.h"
#include "convertors.h"

/////////////////////////////////////////////////////////////////////////////
// CParsedParts


STDMETHODIMP CParsedParts::get_Count(long *pVal)
{
	assert(pVal);
	*pVal = size();

	return S_OK;
}

STDMETHODIMP CParsedParts::get_Item(long Index, IParsedPart **pVal)
{
	assert(pVal);
	if (Index >= long(size()))
		return E_INVALIDARG;

	*pVal = convert(*(begin() + Index));

	return S_OK;
}

STDMETHODIMP CParsedParts::put_Item(long Index, IParsedPart *newVal)
{
	assert(newVal);
	if (Index >= long(size()))
		return E_INVALIDARG;

	*(begin() + Index) = convert(*newVal);

	return S_OK;
}

STDMETHODIMP CParsedParts::Add(IParsedPart *Part)
{
	assert(Part);
	push_back(convert(*Part));
	return S_OK;
}
