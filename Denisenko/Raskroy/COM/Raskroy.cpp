// Raskroy.cpp : Implementation of CRaskroy
#include "stdafx.h"
#include "COMRaskroy.h"
#include "Raskroy.h"
#include "convertors.h"

/////////////////////////////////////////////////////////////////////////////
// CRaskroy
CRaskroy::CRaskroy()
{
	set_monitor(monitor);
}

STDMETHODIMP CRaskroy::get_RecursionDepth(short *pVal)
{
	assert(pVal);
	*pVal = this->get_recursion_max_depth();
	return S_OK;
}

STDMETHODIMP CRaskroy::put_RecursionDepth(short newVal)
{
	this->set_recursion_max_depth(newVal);
	return S_OK;
}

class FirstNextClass
{
protected:
	raskroy::gilotine &r;
	FirstNextClass(raskroy::gilotine &r) : r(r) {};
public:
	virtual bool CheckArgs() throw () = 0;
	virtual bool Work(raskroy::t_result &res) = 0;
};

class FirstClass : public FirstNextClass
{
	ISheets * Parts;
	ISheets * Sheets;
public:
	FirstClass(raskroy::gilotine &r, ISheets * Parts, ISheets * Sheets)
		: FirstNextClass(r),
		Parts(Parts),
		Sheets(Sheets)
	{}

	virtual bool CheckArgs() throw () {
		return !(Parts == 0 || Sheets == 0);
	}

	virtual bool Work(raskroy::t_result &res)
	{
		raskroy::t_parts parts = convert(*Parts), sheets = convert(*Sheets);
		return r.first(parts, sheets, res);
	}
};

class NextClass : public FirstNextClass
{
public:
	NextClass(raskroy::gilotine &r) : FirstNextClass(r) {}

	virtual bool CheckArgs() throw () {
		return true;
	}

	virtual bool Work(raskroy::t_result &res)
	{
		return r.next(res);
	}
};

HRESULT CRaskroy::FirstNextProc(FirstNextClass &cls, /*[out]*/ IResult **pRes, 
								/*[out, retval]*/ BOOL * bRes) throw ()
{
	if (!cls.CheckArgs() || !bRes)
		return E_INVALIDARG;	// неправильные параметры
	raskroy::t_result res;
	try
	{
		if (!cls.Work(res))
			*bRes = FALSE;
		else
		{
			raskroy::parser parser;
			raskroy::t_parsed_result parsed_res;
			parser.parse(res, parsed_res, get_cut_width());
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
	catch (raskroy::err_cannot_set_parts &e)
	{
		std::stringstream ss;
		ss << "На листах:\n";
		for (raskroy::t_parts::const_iterator i = e.sheets.begin(); i != e.sheets.end(); i++)
		{
			ss << i->rect.size[0] << 'x' << i->rect.size[1] << ' ';
		}
		ss << "\nнельзя расположить детали с длиной:\n";
		for (raskroy::t_sizes::const_iterator i = e.sizes[0].begin(); i != e.sizes[0].end(); i++)
		{
			ss << i->size << ' ';
		}
		ss << "\nи шириной:\n";
		for (raskroy::t_sizes::const_iterator i = e.sizes[1].begin(); i != e.sizes[1].end(); i++)
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
	/*catch (...)
	{
		return E_UNEXPECTED;
	}*/
	
	return S_OK;
}

STDMETHODIMP CRaskroy::First(/*[in]*/ ISheets *Parts,/*[in]*/  ISheets *Sheets,
							 /*[out]*/ IResult **pRes,/*[out, res]*/  BOOL *bRes)
{
	return FirstNextProc(FirstClass(*this, Parts, Sheets), pRes, bRes);
}

STDMETHODIMP CRaskroy::Next(/*[out]*/ IResult **pRes,/*[out, res]*/ BOOL *bRes)
{
	return FirstNextProc(NextClass(*this), pRes, bRes);
}

STDMETHODIMP CRaskroy::get_CutWidth(/*[out, res]*/ DOUBLE* pVal)
{
	assert(pVal);
	*pVal = get_cut_width();
	return S_OK;
}

STDMETHODIMP CRaskroy::put_CutWidth(DOUBLE newVal)
{
	set_cut_width(newVal);
	return S_OK;
}

int main()
{
	return 0;
}
