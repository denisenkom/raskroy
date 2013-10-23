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
	ResultsGenerator::Begin(convert(*parts), convert(*sheets));
	return S_OK;
}

STDMETHODIMP CRaskroy::NextResult(IResult **pResult, BOOL *bRes)
{
	assert(pResult && bRes);
	try
	{
		Result res;
		*bRes = ResultsGenerator::NextResult(res);
		if(*bRes) {
			Parser parser;
			ParsedResult parsedResult;
			parser.Parse(res, parsedResult, get_SawThickness());
			*pResult = convert(parsedResult);
		}
		else
			*pResult = 0;
		return S_OK;
	}
	catch (CannotSetPartsException &ex)
	{
		wstringstream ss;
		ss << L"На листах:\n";
		for (Parts::const_iterator pPart = ex.sheets->begin(); pPart != ex.sheets->end(); pPart++)
		{
			ss << pPart->Rect.Size[0] << L'x' << pPart->Rect.Size[1] << L' ';
		}
		ss << L"\nнельзя расположить детали с длиной:\n";
		for (Sizes::const_iterator pSize = ex.sizes[0].begin(); pSize != ex.sizes[0].end(); pSize++)
		{
			ss << pSize->Value << L' ';
		}
		ss << L"\nи шириной:\n";
		for (Sizes::const_iterator pSize = ex.sizes[1].begin(); pSize != ex.sizes[1].end(); pSize++)
		{
			ss << pSize->Value << L' ';
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
