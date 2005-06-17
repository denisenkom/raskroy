#include "stdafx.h"
#include "COMRaskroy.h"
#include "Raskroy.h"
#include "convertors.h"

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
	catch (error_COM& err)
	{
		MessageBox(NULL, err.what(), 0, MB_ICONSTOP);
		return E_UNEXPECTED;
	}
	catch (err_part_invalid& err)
	{
		std::string str;
		str = "Неправильная деталь: ";
		str += err.member;
		str += "=";
		str += err.value;
		MessageBox(NULL, str.c_str(), 0, MB_ICONSTOP);
		return E_INVALIDARG;
	}
	catch (err_cannot_set_parts &e)
	{
		std::stringstream ss;
		ss << "На листах:\n";
		for (t_parts::const_iterator i = e.sheets.begin(); i != e.sheets.end(); i++)
		{
			ss << i->rect.size[0] << 'x' << i->rect.size[1] << ' ';
		}
		ss << "\nнельзя расположить детали с длиной:\n";
		for (t_sizes::const_iterator i = e.sizes[0].begin(); i != e.sizes[0].end(); i++)
		{
			ss << i->size << ' ';
		}
		ss << "\nи шириной:\n";
		for (t_sizes::const_iterator i = e.sizes[1].begin(); i != e.sizes[1].end(); i++)
		{
			ss << i->size << ' ';
		}
		MessageBox(NULL, ss.str().c_str(), 0, MB_ICONSTOP);
		return E_INVALIDARG;
	}
	catch (std::exception& ex)
	{
		MessageBox(NULL, ex.what(), 0, MB_ICONSTOP);
		return E_UNEXPECTED;
	}
}

STDMETHODIMP CRaskroy::get_CutWidth(/*[out, res]*/ DOUBLE* pVal)
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