#include "StdAfx.h"
#include "Result1.h"
#include "common.h"

raskroy_api::CResult1::CResult1(t_parts_vector &parts, t_cuts_vector &cuts, raskroy::t_part &sheet, unsigned amount, raskroy::t_stat &stat)
	: parts(parts), cuts(cuts), sheet(sheet), amount(amount), stat(stat)
{
}

raskroy_api::CResult1* raskroy_api::CResult1::Create(t_parts_vector &parts, t_cuts_vector &cuts, raskroy::t_part &sheet, unsigned amount, raskroy::t_stat &stat)
{
	CResult1 *pResult = new CResult1(parts, cuts, sheet, amount, stat);
	if (!pResult)
		throw raskroy_error("CResult1::Create", E_OUTOFMEMORY);
	assert(pResult);
	//pResult->AddRef();
	return pResult;
}

STDMETHODIMP raskroy_api::CResult1::get_CutsCount(long *pRet)
{
	if (pRet == 0)
		return E_INVALIDARG;
	*pRet = cuts.size();
	return S_OK;
}

STDMETHODIMP raskroy_api::CResult1::get_CutsItem(long Index, raskroy::t_parsed_cut *pRet)
{
	if (pRet == 0 || Index < 0 || Index >= cuts.size())
		return E_INVALIDARG;

	*pRet = cuts[Index];

	return S_OK;
}

STDMETHODIMP raskroy_api::CResult1::get_DetailsCount(long *pRet)
{
	if (pRet == 0)
		return E_INVALIDARG;
	*pRet = parts.size();
	return S_OK;
}

STDMETHODIMP raskroy_api::CResult1::get_DetailsItem(long Index, raskroy::t_parsed_part *pRet)
{
	if (pRet == 0 || Index < 0 || Index >= parts.size())
		return E_INVALIDARG;

	*pRet = parts[Index];

	return S_OK;
}

STDMETHODIMP raskroy_api::CResult1::get_Sheet(raskroy::t_part* pRet)
{
	if (pRet == 0)
		return E_INVALIDARG;
	*pRet = sheet;
	return S_OK;
}

STDMETHODIMP raskroy_api::CResult1::get_RepetitionFactor(long* pRet)
{
	if (pRet == 0)
		return E_INVALIDARG;
	*pRet = amount;
	return S_OK;
}

STDMETHODIMP raskroy_api::CResult1::get_Statistic(raskroy::t_stat* pRet)
{
	if (pRet == 0)
		return E_INVALIDARG;
	*pRet = stat;
	return S_OK;
}