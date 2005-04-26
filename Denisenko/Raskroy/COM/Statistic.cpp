// Statistic.cpp : Implementation of CStatistic
#include "stdafx.h"
#include "COMRaskroy.h"
#include "Statistic.h"

/////////////////////////////////////////////////////////////////////////////
// CStatistic


STDMETHODIMP CStatistic::get_SumRemain(double *pVal)
{
	*pVal = sum_remain;

	return S_OK;
}

STDMETHODIMP CStatistic::put_SumRemain(double newVal)
{
	sum_remain = newVal;

	return S_OK;
}

STDMETHODIMP CStatistic::get_SumCutLength(double *pVal)
{
	*pVal = sum_cut_length;

	return S_OK;
}

STDMETHODIMP CStatistic::put_SumCutLength(double newVal)
{
	sum_cut_length = newVal;

	return S_OK;
}

