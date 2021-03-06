#include "StdAfx.h"
#include "COMRaskroy.h"
#include "ParsedCut.h"
#include "ParsedCuts.h"
#include "ParsedPart.h"
#include "ParsedParts.h"
#include "Sheet.h"
#include "convertors.h"
#include "Result.h"

using namespace Denisenko::Raskroy;

ParsedCut convert(IParsedCut &Cut)
{
	ParsedCut cut;
	Cut.get_Length(&cut.length);
	long x;
	Cut.get_S(&x);
	cut.s = x;
	Cut.get_X(&cut.pos[0]);
	Cut.get_Y(&cut.pos[1]);
	return cut;
}

ParsedPart convert(IParsedPart &Part)
{
	ParsedPart part;
	Part.get_X(&part.pos[0]);
	Part.get_Y(&part.pos[1]);
	Part.get_Length(&part.rect.Size[0]);
	Part.get_Width(&part.rect.Size[1]);
	return part;
}

ParsedCuts convert(IParsedCuts &Cuts)
{
	long count;
	Cuts.get_Count(&count);
	ParsedCuts cuts(count);
	for (long i = 0; i < count; i++)
	{
		IParsedCut *Cut;
		Cuts.get_Item(i, &Cut);
		cuts[i] = convert(*Cut);
		Cut->Release();
	}
	return cuts;
}

ParsedParts convert(IParsedParts &Parts)
{
	long count;
	Parts.get_Count(&count);
	ParsedParts parts(count);
	for (long i = 0; i < count; i++)
	{
		IParsedPart *Part;
		Parts.get_Item(i, &Part);
		parts[i] = convert(*Part);
		Part->Release();
	}
	return parts;
}

Part convert(ISheet &Sheet)
{
	Part part;
	Sheet.get_Length(&part.Rect.Size[0]);
	Sheet.get_Width(&part.Rect.Size[1]);

	BOOL rotate;
	Sheet.get_Rotate(&rotate);
	part.Rotate = rotate == -1 ? true : false;

	long amount;
	Sheet.get_Amount(&amount);
	part.Amount = amount;

	return part;
}

Parts convert(ISheets &Sheets)
{
	long count;
	Sheets.get_Count(&count);
	Parts parts;
	for (long i = 0; i < count; i++)
	{
		CComVariant varSheet;
		Sheets.get_Item(i, &varSheet);
		CComPtr<ISheet> sheet;
		varSheet.pdispVal->QueryInterface(IID_ISheet, (void**)&sheet);
		parts.push_back(convert(*sheet));
	}
	return parts;
}

ParsedResult convert(IResult &Result)
{
	ParsedResult result;

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

	return result;
}

void _CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID *ppv)
{
	HRESULT hres = ::CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
	if (FAILED(hres))
		throw error_COM("CoCreateInstance", hres);
}

IParsedCut* convert(const ParsedCut &in)
{
	IParsedCut *out;
	_CoCreateInstance(CLSID_ParsedCut, NULL, CLSCTX_ALL, IID_IParsedCut, (void**)&out);
	scalar x = in.pos[0];
	out->put_X(x);
	scalar y = in.pos[1];
	out->put_Y(y);
	long s = in.s;
	out->put_S(s);
	scalar length = in.length;
	out->put_Length(length);
	return out;
}

IParsedPart* convert(const ParsedPart &in)
{
	IParsedPart *out;
	HRESULT hres;
	if (FAILED(hres = CParsedPart::CreateInstance<IParsedPart>(NULL, &out)))
		throw error_COM("Cannot create ParsedPart", hres);
	out->put_X(in.pos[0]);
	out->put_Y(in.pos[1]);
	out->put_Width(in.rect.Size[0]);
	out->put_Length(in.rect.Size[1]);
	return out;
}

class fn_add_cut {
	IParsedCuts &Cuts;
public:
	fn_add_cut(IParsedCuts &Cuts) :	Cuts(Cuts) {}
	void operator () (ParsedCut x)	{
		IParsedCut *Cut = convert(x); Cuts.Add(Cut); Cut->Release();
	}
};

class fn_add_part {
	IParsedParts &Parts;
public:
	fn_add_part(IParsedParts &Parts) :	Parts(Parts) {}
	void operator () (ParsedPart x) {
		IParsedPart *Part = convert(x); Parts.Add(Part); Part->Release();
	}
};

IParsedCuts* convert(const ParsedCuts &cuts)
{
	IParsedCuts *res;
	HRESULT hres;
	if (FAILED(hres = CParsedCuts::CreateInstance<IParsedCuts>(NULL, &res)))
		throw error_COM("Cannot create ParsedCuts", hres);
	fn_add_cut fn_add_cut(*res);
	std::for_each(cuts.begin(), cuts.end(), fn_add_cut);
	return res;
}

IParsedParts* convert(const ParsedParts &parts)
{
	IParsedParts *res;
	HRESULT hres;
	if (FAILED(hres = CParsedParts::CreateInstance<IParsedParts>(NULL, &res)))
		throw error_COM("Cannot create ParsedParts", hres);
	fn_add_part fn_add_part(*res);
	std::for_each(parts.begin(), parts.end(), fn_add_part);
	return res;
}

ISheet* convert(const Part &part)
{
	ISheet *Sheet;
	HRESULT hres;
	if (FAILED(hres = CSheet::CreateInstance<ISheet>(NULL, &Sheet)))
		throw error_COM("Cannot create Sheet", hres);

	Sheet->put_Length(part.Rect.Size[0]);
	Sheet->put_Width(part.Rect.Size[1]);
	Sheet->put_Rotate(part.Rotate);
	Sheet->put_Amount(part.Amount);

	return Sheet;
}

// ������ ���������� � ������� ������� ����
template <class Var> void writefn(std::wstring &ss, const Var &var)
{
	assert(sizeof(Var)%2 == 0);
	const wchar_t* begin = (const wchar_t*)&var;
	for (const wchar_t* i = begin; i != begin + sizeof(Var)/2; i++)
	{
		if (*i == 0 || *i == wchar_t(0xffff))
		{
			wchar_t x = *i - wchar_t(0xffff);
			ss.push_back(wchar_t(0xffff));
			ss.push_back(x != 0 ? x : wchar_t(0x1234));
		}
		else
			ss.push_back(*i);
	}
}

template <class Var> void readfn(BSTR &ss, Var &var)
{
	assert(sizeof(Var)%2 == 0);
	wchar_t* begin = (wchar_t*)&var;
	for (wchar_t* i = begin; i != begin + sizeof(Var)/2; i++, ss++)
	{
		if (*ss == wchar_t(0xffff))
		{
			wchar_t x = *ss + *(ss+1);
			*i = x == 0 ? x : wchar_t(0xffff);
			ss++;
		}
		else
			*i = *ss;
	}
}

IResult* convert(const ParsedResult &res)
{
	HRESULT hres;
	IResult *Result;
	if (FAILED(hres = CResult::CreateInstance<IResult>(NULL, &Result)))
		throw error_COM("Cannot create Result class", hres);

	std::wstring ss;
	//std::wstringstream ss2;
	try
	{
		Result->put_ParsedParts(convert(res.parts));
		Result->put_ParsedCuts(convert(res.cuts));

		//Result->put_Statistic(convert(res.stat));
		Result->put_Sheet(convert(res.sheet));

		long amount = res.amount;
		Result->put_Amount(amount);

		//ss.exceptions(std::ios::eofbit | std::ios::badbit);
		writefn(ss, res.sheet.Rect.Size[0]);	// �����
		writefn(ss, res.sheet.Rect.Size[1]);	// ������
		writefn(ss, res.amount);	// ���������� ������
		short x = res.parts.size();
		writefn(ss, x);	// ���������� �������
		for (ParsedParts::const_iterator i = res.parts.begin(); i != res.parts.end(); i++)
		{
			writefn(ss, i->pos[0]);	// X
			writefn(ss, i->pos[1]);	// Y
			writefn(ss, i->rect.Size[0]);	// �����
			writefn(ss, i->rect.Size[1]);	// ������
		}
		x = res.cuts.size();
		writefn(ss, x);	// ���������� �����
		for (ParsedCuts::const_iterator i = res.cuts.begin(); i != res.cuts.end(); i++)
		{
			writefn(ss, i->pos[0]);	// X
			writefn(ss, i->pos[1]);	// Y
			writefn(ss, i->length);	// �����
			writefn(ss, i->s);	// �����������
		}
		/*bool even = true;
		for (const char* i = ss.str().c_str(); i != ss.str().c_str() + ss.str().length(); i++, even = !even)
		{
			if (!even) continue;
			if (*i == char(0) && *(i+1) == char(0))
				ss2 << wchar_t(0xffff) << wchar_t(0x0001);
			else if (*i == char(0xff) && *(i+1) == char(0xff))
				ss2 << wchar_t(0xffff) << wchar_t(0x1234);
			else
				ss2 << wchar_t(*i) << wchar_t(*(i+1));
		}*/
		Result->put_String((BSTR)ss.c_str());
		Result->put_UsefulScrap(res.stat.UsefulRemain);
		Result->put_UsefulNum(res.stat.UsefulNum);
		Result->put_UnUsefulScrap(res.stat.UnusefulRemain);
		Result->put_Opilki(res.stat.Opilki);
	}
	catch (...)
	{
		Result->Release();
		Result = 0;
		throw;
	}
	return Result;
}

ParsedResult convert(BSTR str)
{
	ParsedResult res;
	readfn(str, res.sheet.Rect.Size[0]);
	readfn(str, res.sheet.Rect.Size[1]);
	readfn(str, res.amount);	// ���������� ������
	short x;
	readfn(str, x);	// ���������� �������
	res.parts.resize(x);
	for (ParsedParts::const_iterator i = res.parts.begin(); i != res.parts.end(); i++)
	{
		readfn(str, i->pos[0]);	// X
		readfn(str, i->pos[1]);	// Y
		readfn(str, i->rect.Size[0]);
		readfn(str, i->rect.Size[0]);
	}
	readfn(str, x);	// ���������� �����
	res.cuts.resize(x);
	for (ParsedCuts::const_iterator i = res.cuts.begin(); i != res.cuts.end(); i++)
	{
		readfn(str, i->pos[0]);	// X
		readfn(str, i->pos[1]);	// Y
		readfn(str, i->length);	// �����
		readfn(str, i->s);	// �����������
	}
	return res;
}
