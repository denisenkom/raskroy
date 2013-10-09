// Raskroy.cpp : Implementation of CRaskroy
#include "stdafx.h"
#include "COMRaskroy.h"
#include "Raskroy.h"
#include "convertors.h"

#include "c:\gilotine\types.hpp"
#include "c:\gilotine\raskroy.h"
#include "c:\gilotine\raskroy.cpp"
#include "c:\gilotine\perebor_2d.cpp"
#include "c:\gilotine\perebor.cpp"
#include "c:\gilotine\parser.h"
#include "c:\gilotine\drawer.h"
#include "c:\gilotine\parser.cpp"
#include "c:\gilotine\drawer.cpp"

/////////////////////////////////////////////////////////////////////////////
// CRaskroy

STDMETHODIMP CRaskroy::get_RecursionDepth(short *pVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CRaskroy::put_RecursionDepth(short newVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CRaskroy::First(ISheets *Parts, ISheets *Sheets, IResult **pRes, BOOL *bRes)
{
	if (Parts == 0 || Sheets == 0 || pRes == 0)
		return E_INVALIDARG;	// неправильные параметры
	try
	{
		raskroy::monitor monitor;
		set_monitor(monitor);
		raskroy::criteria criteria;
		set_criteria(criteria);
		raskroy::t_result res;
		raskroy::t_parts parts = convert(*Parts), sheets = convert(*Sheets);
#ifndef NDEBUG
		char buf[256];
		std::string str("parts.size()=");
		str += ultoa(parts.size(), buf, 10);
		MessageBox(NULL, str.c_str(), NULL, 0);
#endif
		if (!first(parts, sheets, res))
			*bRes = FALSE;
		else
		{
			raskroy::parser parser;
			raskroy::t_parsed_result parsed_res;
			parser.parse(res, parsed_res, 4);
			*pRes = convert(parsed_res);
			*bRes = TRUE;
		}
	}
	catch (error_COM& err)
	{
		MessageBox(NULL, err.what(), 0, MB_ICONSTOP);
		return E_UNEXPECTED;
	}
	catch (raskroy::err_part_invalid& err)
	{
		std::string str;
		str = "Неправильная деталь: ";
		str += err.member;
		str += "=";
		str += err.value;
		MessageBox(NULL, str.c_str(), 0, MB_ICONSTOP);
		return E_INVALIDARG;
	}
	catch (raskroy::err_cannot_set_parts)
	{
		MessageBox(NULL, "Нельзя расположить детали", 0, MB_ICONSTOP);
		return E_INVALIDARG;
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
	
	return S_OK;
}

STDMETHODIMP CRaskroy::Next(IResult **pRes, BOOL *bRes)
{
	if (pRes == 0)
		return E_INVALIDARG;	// неправильные параметры
	try
	{
		raskroy::t_result res;
		if (!next(res))
			*bRes = FALSE;
		else
		{
			HRESULT hres = ::CoCreateInstance(CLSID_Result, 0, 0, IID_IResult, (void**)pRes);
			if (FAILED(hres))
				throw error_COM("CoCreateInstance", hres);
			*bRes = TRUE;
		}
	}
	catch (error_COM& err)
	{
		MessageBox(NULL, err.what(), 0, MB_ICONSTOP);
		return E_UNEXPECTED;
	}
	catch (raskroy::err_part_invalid& err)
	{
		std::string str;
		str = "Неправильная деталь: ";
		str += err.member;
		str += "=";
		str += err.value;
		MessageBox(NULL, str.c_str(), 0, MB_ICONSTOP);
		return E_INVALIDARG;
	}
	catch (raskroy::err_cannot_set_parts)
	{
		MessageBox(NULL, "Нельзя расположить дктали", 0, MB_ICONSTOP);
		return E_INVALIDARG;
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
	
	return S_OK;
}