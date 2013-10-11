// ParsedCuts.cpp : Implementation of CParsedCuts
#include "stdafx.h"
#include "COMRaskroy.h"
#include "ParsedCut.h"
#include "ParsedCuts.h"
#include "convertors.h"
#include "..\Types.h"

using namespace Denisenko::Raskroy;

/////////////////////////////////////////////////////////////////////////////
// CParsedCuts


STDMETHODIMP CParsedCuts::get_Count(long *pVal)
{
	assert(pVal);
	*pVal = size();

	return S_OK;
}

STDMETHODIMP CParsedCuts::Add(IParsedCut *Cut)
{
	assert(Cut);
	push_back(convert(*Cut));

	return S_OK;
}

STDMETHODIMP CParsedCuts::put_Item(long Index, IParsedCut *Cut)
{
	assert(Cut);
	if (Index >= long(size()))
		return E_INVALIDARG;

	*(begin() + Index) = convert(*Cut);
	
	return S_OK;
}

STDMETHODIMP CParsedCuts::get_Item(long Index, IParsedCut **Cut)
{
	assert(Cut);
	if (Index >= long(size()))
		return E_INVALIDARG;
	
	*Cut = new CComObject<CParsedCut>();
	if (*Cut)
	{
		t_parsed_cut &cut = *(begin()+Index);
		(*Cut)->put_X(cut.pos[0]);
		(*Cut)->put_Y(cut.pos[1]);
		(*Cut)->put_S(cut.s);
		(*Cut)->put_Length(cut.length);
	}

	return S_OK;
}
