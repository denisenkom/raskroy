#include "StdAfx.h"
#include "COMRaskroy.h"
#include "ParsedCut.h"
#include "ParsedCuts.h"
#include "ParsedPart.h"
#include "ParsedParts.h"
#include "Sheet.h"
#include "Statistic.h"
#include "convertors.h"

raskroy::t_parsed_cut convert(IParsedCut &Cut)
{
	raskroy::t_parsed_cut cut;
	Cut.get_Length(&cut.length);
	long x;
	Cut.get_S(&x);
	cut.s = x;
	Cut.get_X(&cut.pos[0]);
	Cut.get_Y(&cut.pos[1]);
	return cut;
}

raskroy::t_parsed_part convert(IParsedPart &Part)
{
	raskroy::t_parsed_part part;
	Part.get_X(&part.pos[0]);
	Part.get_Y(&part.pos[1]);
	Part.get_Length(&part.rect.size[0]);
	Part.get_Width(&part.rect.size[1]);
	return part;
}

raskroy::t_parsed_cuts convert(IParsedCuts &Cuts)
{
	long count;
	Cuts.get_Count(&count);
	raskroy::t_parsed_cuts cuts(count);
	for (long i = 0; i < count; i++)
	{
		IParsedCut *Cut;
		Cuts.get_Item(i, &Cut);
		cuts[i] = convert(*Cut);
		Cut->Release();
	}
	return cuts;
}

raskroy::t_parsed_parts convert(IParsedParts &Parts)
{
	long count;
	Parts.get_Count(&count);
	raskroy::t_parsed_parts parts(count);
	for (long i = 0; i < count; i++)
	{
		IParsedPart *Part;
		Parts.get_Item(i, &Part);
		parts[i] = convert(*Part);
		Part->Release();
	}
	return parts;
}

raskroy::t_stat convert(IStatistic &Statistic)
{
	raskroy::t_stat stat;
	Statistic.get_SumRemain(&stat.sum_remain);
	Statistic.get_SumCutLength(&stat.sum_cut_length);
	return stat;
}

raskroy::t_part convert(ISheet &Sheet)
{
	raskroy::t_part part;
	Sheet.get_Length(&part.rect.size[0]);
	Sheet.get_Width(&part.rect.size[1]);

	BOOL rotate;
	Sheet.get_Rotate(&rotate);
	part.rotate = rotate == TRUE ? true : false;

	long amount;
	Sheet.get_Amount(&amount);
	part.amount = amount;

#ifndef NDEBUG
		char buf[256];
		std::string str = "convert:\n";
		str += gcvt(part.rect.size[0], 5, buf);
		str += gcvt(part.rect.size[1], 5, buf);
		str += ultoa(part.amount, buf, 10);
		str += part.rotate ? "true" : "false";
		MessageBox(0, str.c_str(), 0, 0);
#endif

	return part;
}

raskroy::t_parts_vector convert(ISheets &Sheets)
{
	long count;
	Sheets.get_Count(&count);
	raskroy::t_parts_vector parts(count);
	for (long i = 0; i < count; i++)
	{
		ISheet* Sheet;
		Sheets.get_Item(i, &Sheet);
		parts[i] = convert(*Sheet);
		Sheet->Release();
	}
	return parts;
}

raskroy::t_parsed_result convert(IResult &Result)
{
	raskroy::t_parsed_result result;

	long amount;
	Result.get_Amount(&amount);
	result.amount = amount;

	IParsedCuts *Cuts;
	Result.get_ParsedCuts(&Cuts);
	result.cuts = convert(*Cuts);
	Cuts->Release();

	IParsedParts *Parts;
	Result.get_ParsedParts(&Parts);
	result.parts = convert(*Parts);
	Parts->Release();

	ISheet *Sheet;
	Result.get_Sheet(&Sheet);
	result.sheet = convert(*Sheet);
	Sheet->Release();

	IStatistic *Statistic;
	Result.get_Statistic(&Statistic);
	result.stat = convert(*Statistic);
	Statistic->Release();

	return result;
}

void _CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID *ppv)
{
	HRESULT hres = ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
	if (FAILED(hres))
		throw error_COM("CoCreateInstance", hres);
}

IParsedCut* convert(const raskroy::t_parsed_cut &in)
{
	IParsedCut *out;
	_CoCreateInstance(CLSID_ParsedCut, NULL, CLSCTX_ALL, IID_IParsedCut, (void**)&out);
	double x = in.pos[0];
	out->put_X(x);
	double y = in.pos[1];
	out->put_Y(y);
	long s = in.s;
	out->put_S(s);
	double length = in.length;
	out->put_Length(length);
}

class fn_add_cut {
	IParsedCuts &Cuts;
public:
	fn_add_cut(IParsedCuts &Cuts) :	Cuts(Cuts) {}
	void operator () (raskroy::t_parsed_cuts::const_iterator i)	{
		IParsedCut *Cut = convert(*i); Cuts.Add(Cut); Cut->Release();
	}
};

class fn_add_part {
	IParsedParts &Parts;
public:
	fn_add_part(IParsedParts &Parts) :	Parts(Parts) {}
	void operator () (raskroy::t_parsed_parts::const_iterator i) {
		IParsedPart *Part = convert(*i); Parts.Add(Part); Part->Release();
	}
};

IParsedCuts* convert(const raskroy::t_parsed_cuts &cuts)
{
	IParsedCuts *ParsedCuts;
	_CoCreateInstance(CLSID_ParsedCuts, NULL, CLSCTX_ALL, IID_IParsedCuts, (void**)&ParsedCuts);
	fn_add_cut fn_add_cut(*ParsedCuts);
	std::for_each(cuts.begin(), cuts.end(), fn_add_cut);
}

IParsedParts* convert(const raskroy::t_parsed_parts &parts)
{
	IParsedParts *ParsedParts;
	_CoCreateInstance(CLSID_ParsedParts, NULL, CLSCTX_ALL, IID_IParsedParts, (void**)&ParsedParts);
	fn_add_part fn_add_part(*ParsedParts);
	std::for_each(parts.begin(), parts.end(), fn_add_part);
}

IStatistic* convert(const raskroy::t_stat &stat)
{
	IStatistic *Statistic;
	_CoCreateInstance(CLSID_Statistic, NULL, CLSCTX_ALL, IID_IStatistic, (void**)&Statistic);

	double sum_remain = stat.sum_remain;
	Statistic->put_SumRemain(sum_remain);

	double sum_cut_length = stat.sum_cut_length;
	Statistic->put_SumCutLength(sum_cut_length);

	return Statistic;
}

ISheet* convert(const raskroy::t_part &part)
{
	ISheet *Sheet;
	_CoCreateInstance(CLSID_Sheet, NULL, CLSCTX_ALL, IID_ISheet, (void**)&Sheet);

	double length = part.rect.size[0];
	Sheet->put_Length(length);
	double width = part.rect.size[1];
	Sheet->put_Width(width);
	BOOL rotate = part.rotate;
	Sheet->put_Rotate(rotate);
	long amount = part.amount;
	Sheet->put_Amount(amount);

	return Sheet;
}

IResult* convert(const raskroy::t_parsed_result &res)
{
	IResult *Result;
	_CoCreateInstance(CLSID_Result, NULL, CLSCTX_ALL, IID_IResult, (void**)&Result);

	try
	{
		Result->put_ParsedParts(convert(res.parts));
		Result->put_ParsedCuts(convert(res.cuts));

		Result->put_Statistic(convert(res.stat));
		Result->put_Sheet(convert(res.sheet));

		long amount = res.amount;
		Result->put_Amount(amount);
	}
	catch (...)
	{
		Result->Release();
		Result = 0;
		throw;
	}
	return Result;
}