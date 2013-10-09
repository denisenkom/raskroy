#include "StdAfx.h"
#include "oldraskroy.h"
#include "Raskroy.h"
#include "Result1.h"
#include "common.h"
#include "..\..\perebor.cpp"
#include "..\..\perebor_2d.cpp"
#include "..\..\raskroy.cpp"

raskroy_api::CRaskroy1::CRaskroy1(void)
	: factory(4, 2000)
{
	set_monitor(default_monitor);
	set_criteria(default_criteria);
	set_factory(factory);
}

raskroy_api::CRaskroy1* raskroy_api::CRaskroy1::Create(void)
{
	CRaskroy1* pRaskroy = new CRaskroy1();
	if (pRaskroy == 0)
		throw raskroy_error("CRaskroy1::Create", E_OUTOFMEMORY);
	assert(pRaskroy);
	//pRaskroy->AddRef();
	return pRaskroy;
}

STDMETHODIMP raskroy_api::CRaskroy1::SetRecursionDepth(long new_depth)
{
	set_recursion_max_depth(new_depth);
	return NOERROR;
}

STDMETHODIMP raskroy_api::CRaskroy1::SetFactory(const raskroy::t_factory* pfactory)
{
	if (!pfactory || pfactory->saw_thickness <= 0)
		return E_INVALIDARG;
	factory = *pfactory;
	set_factory(*pfactory);
	return NOERROR;
}

STDMETHODIMP raskroy_api::CRaskroy1::SetCriteria(const raskroy::criteria* pcriteria)
{
	if (!pcriteria)
		return E_INVALIDARG;
	set_criteria(*pcriteria);
	return NOERROR;
}

STDMETHODIMP raskroy_api::CRaskroy1::SetMonitor(raskroy::monitor* pmonitor)
{
	if (!pmonitor)
		return E_INVALIDARG;
	set_monitor(*pmonitor);
	return NOERROR;
}

/*template <class Ty>
static inline HMEM allocate_and_copy(Ty &first, size_t num)
{
	if (num == 0)
		return NULL;
	size_t size = num*sizeof(Ty);
	HLOCAL hmem = ::LocalAlloc(HMEM_FIXED, size);
	if (!hmem)
		throw windows_error("При выделении памяти LocalAlloc");
	assert(hmem);
	void* ptr = LocalLock(hmem);
	assert(ptr);
	memcpy(ptr, &first, size);
	BOOL bres = LocalUnlock(hmem);
	assert(bres);
}*/

/*static inline void convert(raskroy::t_parsed_result& in, raskroy_api::t_result& out)
{
	out.amount = in.amount;

	out.parts = allocate_and_copy(*in.parts.begin(), in.parts.size());
	out.cuts = allocate_and_copy(in.cuts.begin(), in.cuts.size());
	out.sheet = in.sheet;
	out.stat = in.stat;
}

static inline void convert(raskroy::t_result& in, raskroy_api::t_result& out, raskroy::scalar saw_thickness)
{
	raskroy::parser parser;
	raskroy::t_parsed_result tmp;
	parser.parse(in, tmp, saw_thickness);
	convert(tmp, out);
}*/

STDMETHODIMP raskroy_api::CRaskroy1::First(const raskroy::t_part* Parts, WORD parts_num,
			const raskroy::t_part* Sheets, WORD sheets_num,
			IResult1** ppResult, bool *pRet)
{
	if (parts_num == 0)
		return NOERROR;	// нет деталей - ничего не происходит
	if (sheets_num == 0)
		return E_INVALIDARG;	// нет листов - нельзя разложить
	if (Parts == 0 || Sheets == 0 || ppResult == 0 || pRet == 0)
		return E_INVALIDARG;	// неправильные параметры
	try
	{
		//monitor_dispatch monitor_dispatch(*pmonitor, factory.saw_thickness);
		raskroy::t_result res1;
		if (!first(raskroy::t_parts(Parts, Parts + parts_num),
			raskroy::t_parts(Sheets, Sheets + sheets_num), res1))
		{
			*pRet = false;
			*ppResult = 0;
			return S_OK;
		}

		raskroy::parser parser;
		raskroy::t_parsed_result res;
		parser.parse(res1, res, factory.saw_thickness);
		*ppResult = CResult1::Create(res.parts, res.cuts, res.sheet, res.amount, res.stat);
		//convert(res1, *pResult, factory.saw_thickness);
		*pRet = true;
	}
	catch (raskroy::err_cannot_set_parts)
	{
		return E_CANNOTSETPARTS;
	}
	catch (std::exception& ex)
	{
		MessageBox(NULL, ex.what(), 0, MB_ICONSTOP);
		return E_UNEXPECTED;
	}
	catch (...)
	{
		MessageBox(NULL, "неизвестное исключение", 0, MB_ICONSTOP);
		return E_UNEXPECTED;
	}
	
	return NOERROR;
}

STDMETHODIMP raskroy_api::CRaskroy1::Next(IResult1 **ppResult, bool *pRet)
{
	if (ppResult == 0 || pRet == 0)
		return E_INVALIDARG;	// неправильные параметры
	try
	{
		//monitor_dispatch monitor_dispatch(*pmonitor, factory.saw_thickness);
		raskroy::t_result res1;
		if (!next(res1))
		{
			*pRet = false;
			*ppResult = 0;
			return S_OK;
		}
		//convert(res1, *pResult, factory.saw_thickness);
		raskroy::parser parser;
		raskroy::t_parsed_result res;
		parser.parse(res1, res, factory.saw_thickness);
		*ppResult = CResult1::Create(res.parts, res.cuts, res.sheet, res.amount, res.stat);
		*pRet = true;
	}
	catch (raskroy::err_cannot_set_parts)
	{
		return E_CANNOTSETPARTS;
	}
	catch (std::exception& ex)
	{
		MessageBox(NULL, ex.what(), 0, MB_ICONSTOP);
		return E_UNEXPECTED;
	}
	catch (...)
	{
		MessageBox(NULL, "неизвестное исключение", 0, MB_ICONSTOP);
		return E_UNEXPECTED;
	}
	
	return NOERROR;
}
