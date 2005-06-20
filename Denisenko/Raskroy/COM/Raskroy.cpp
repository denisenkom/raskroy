#include "stdafx.h"
#include "COMRaskroy.h"
#include "Raskroy.h"
#include "convertors.h"
#include "..\errors.h"

using namespace std;
using namespace ATL;
using namespace Denisenko::Raskroy;

CRaskroy::CRaskroy()
{
}

STDMETHODIMP CRaskroy::Begin(ISheets *parts, ISheets *sheets)
{
	assert(parts && sheets);
	Raskroy::Begin(convert(*parts), convert(*sheets));
	return S_OK;
}

STDMETHODIMP CRaskroy::NextResult(IResult **pResult, BOOL *bRes)
{
	assert(pResult && bRes);
	try
	{
		t_result res;
		*bRes = Raskroy::NextResult(res);
		if(*bRes) {
			Parser parser;
			t_parsed_result parsedResult;
			parser.Parse(res, parsedResult, get_SawThickness());
			*pResult = convert(parsedResult);
		}
		else
			*pResult = 0;
		return S_OK;
	}
	catch (err_cannot_set_parts &ex)
	{
		wstringstream ss;
		ss << L"На листах:\n";
		for (t_parts::const_iterator i = ex.sheets.begin(); i != ex.sheets.end(); i++)
		{
			ss << i->Rect.Size[0] << L'x' << i->Rect.Size[1] << L' ';
		}
		ss << L"\nнельзя расположить детали с длиной:\n";
		for (t_sizes::const_iterator i = ex.sizes[0].begin(); i != ex.sizes[0].end(); i++)
		{
			ss << i->size << L' ';
		}
		ss << L"\nи шириной:\n";
		for (t_sizes::const_iterator i = ex.sizes[1].begin(); i != ex.sizes[1].end(); i++)
		{
			ss << i->size << L' ';
		}
		return AtlReportError(GetObjectCLSID(), ss.str().c_str());
	}
	catch (exception& ex)
	{
		return AtlReportError(GetObjectCLSID(), ex.what());
	}
}

STDMETHODIMP CRaskroy::get_CutWidth(DOUBLE* pVal)
{
	assert(pVal);
	*pVal = get_SawThickness();
	return S_OK;
}

STDMETHODIMP CRaskroy::put_CutWidth(DOUBLE newVal)
{
	put_SawThickness(newVal);
	return S_OK;
}