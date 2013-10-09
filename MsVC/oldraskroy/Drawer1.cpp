#include "StdAfx.h"
#include "oldraskroy.h"
#include "common.h"
#include "wrappers.h"
#include "Drawer1.h"

raskroy_api::CDrawer1* raskroy_api::CDrawer1::Create(void)
{
	CDrawer1* pDrawer = new CDrawer1();
	if (pDrawer == 0)
		throw raskroy_error("CDrawer1::Create", E_OUTOFMEMORY);
	assert(pDrawer);
	//pDrawer->AddRef();
	return pDrawer;
}

STDMETHODIMP raskroy_api::CDrawer1::Draw(HDC hDC, long Width, long Height,
							IResult1* pResult)
{
	if (hDC == NULL || pResult == NULL)
		return E_INVALIDARG;
	Result1 Result;
	Result.reset(pResult);
	try
	{
		long cuts_count = Result.get_CutsCount();
		long parts_count = Result.get_DetailsCount();
		typedef std::vector<raskroy::t_parsed_part> t_parts_vector;
		typedef std::vector<raskroy::t_parsed_cut> t_cuts_vector;
		t_parts_vector parts(parts_count);
		t_cuts_vector cuts(cuts_count);

		long Index;
		t_cuts_vector::iterator cuti;
		for (cuti = cuts.begin(), Index = 0; cuti != cuts.end(); cuti++, Index++)
			*cuti = Result.get_CutsItem(Index);

		t_parts_vector::iterator parti;
		for (parti = parts.begin(), Index = 0; parti != parts.end(); parti++, Index++)
			*parti = Result.get_DetailsItem(Index);

		drawer.reset_dc(hDC);
		drawer.draw(Width, Height, parts, cuts, Result.get_Sheet());
	}
	catch (raskroy::err_part_invalid &err)
	{
		std::string str("Неправильная деталь, свойство ");
		str += err.member;
		str += "=";
		str += err.value;
		MessageBox(NULL, str.c_str(), 0, MB_ICONSTOP);
	}
	catch (...)
	{
		return E_UNEXPECTED;
	}
	Result.reset();
	return NOERROR;
}
