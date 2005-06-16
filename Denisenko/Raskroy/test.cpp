// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "raskroy.h"
#include "parser.h"
#include "drawer.h"

using namespace Denisenko::Raskroy;
using namespace std;

void test_perebor()
{
	// testing perebor
	t_size sz;
	sz.size = 100;

	t_other_size os;
	os.offset = 0;
	os.size = 100;
	sz.other_sizes.push_back(os);

	os.offset = 2;
	os.size = 200;
	sz.other_sizes.push_back(os);

	os.offset = 1;
	os.size = 30;
	sz.other_sizes.push_back(os);
	sz.other_sizes.prepare();

	t_amounts rem;
	rem.push_back(1);
	rem.push_back(2);
	rem.push_back(3);

	Perebor p(rem, 4);
	t_stat stat;
	t_raskroy::t_details det;
	t_amounts rash;
	scalar size = 260+4*4;
	bool res = p.make(sz, size, det, rash);
	if (res == true)
	{
		cout << "On size " << size << " was allocated:" << endl;
		for (t_raskroy::t_details::const_iterator i = det.begin(); i != det.end(); i++)
		{
			cout << i->size << ":" << i->num << endl;
		}
		cout << "The remain is:" << p.remain << endl;
	}
}

void display_sizes(t_sizes sizes[])
{
	for (int s = 0; s != 2; s++)
	{
		cout << "s=" << s << endl;
		for (t_sizes::const_iterator i = sizes[s].begin(); i != sizes[s].end(); i++)
		{
			cout << i->size << ": ";
			for (t_other_sizes::const_iterator j = i->other_sizes.begin(); j != i->other_sizes.end(); j++)
				cout << j->size << " ";
			cout << endl;
		}
	}
}

std::ostream& operator << (std::ostream &os, const std::string &str)
{
	return os << str.c_str();
}

void print_raskroy(int level, const t_raskroy &ras)
{
	string spaces(level, ' ');
	cout << spaces << "begin {\n";
	cout << spaces << "Cutting by s=" << ras.s << " cut=" << ras.cut;
#ifdef COUNT_KRATNOSTJ
	cout << " kratnostj=" << ras.kratnostj;
#endif
	cout << endl;
	cout << spaces << "details: ";
	for (t_raskroy::t_details::const_iterator i = ras.details.begin(); i != ras.details.end(); i++)
		cout << i->size << " " << i->num << ", ";
	cout << endl;
	if (ras.watchRemain())
	{
		cout << spaces << "remain raskroy\n";
		print_raskroy(level + 1, *ras.watchRemain());
	}
	if (ras.watchRecurse())
	{
		cout << spaces << "recurse raskroy\n";
		print_raskroy(level + 1, *ras.watchRecurse());
	}
	cout << spaces << "} end\n";
}

void test_gilotine()
{
	Raskroy g;
	t_parts p;

	p.push_back(t_part(900, 605, true, 2));
	p.push_back(t_part(630, 600, true, 2));

	//p.push_back(t_part(480, 625, true, 5));
	//p.push_back(t_part(150, 395, true, 1));

	//p.push_back(t_part(480, 625, true, 6));
	//p.push_back(t_part(867, 70, true, 2));

	//p.push_back(t_part(480, 625, true, 5));
	//p.push_back(t_part(400, 565, true, 1));

	//p.push_back(t_part(590, 515, true, 1));
	//p.push_back(t_part(625, 515, true, 2));
	//p.push_back(t_part(640, 515, true, 2));
	//p.push_back(t_part(790, 290, true, 4));
	//p.push_back(t_part(480, 290, true, 2));
	//p.push_back(t_part(605, 290, true, 4));
	//p.push_back(t_part(790, 333, true, 1));
	//p.push_back(t_part(331, 274, true, 4));

	//p.push_back(t_part(625, 600, false, 1));
	//p.push_back(t_part(625, 769, false, 1));
	//p.push_back(t_part(625, 752, false, 1));
	t_parts s;

	t_sizes sizes[2];
	t_amounts am;
	t_sizes::make_list(sizes, p, am);
	/*cout << "displayng not sorted sizes\n";
	display_sizes(sizes);
	std::sort(sizes[0].begin(), sizes[0].end());
	std::sort(sizes[1].begin(), sizes[1].end());*/
	cout << "displayng sorted sizes\n";
	display_sizes(sizes);

	s.push_back(t_part(1810, 1210));
	//s.push_back(t_part(1000, 1000));
	t_result res;
	bool bres = g.First(p, s, res);
	//int index = 1;
	while (bres)
	{
		cout << "Raskroy.\n";
		print_raskroy(0, res.raskroy);
		Parser pr;
		t_parsed_result pres;
		pr.parse(res, pres, g.GetCutWidth());
		assert(pr.details_summary_square == s.begin()->rect.square()-res.stat.opilki-res.stat.unuseful_remain-res.stat.useful_remain);
		//stringstream fname;
		//fname << "raskroy" << index++ << ".emf";
		HDC hdcemf;
		hdcemf = ::CreateEnhMetaFile(NULL, /*fname.str().c_str()*/NULL, NULL, 0);
		assert(hdcemf);
		Drawer d(hdcemf);
		int horzsize = ::GetDeviceCaps(hdcemf, HORZSIZE);
		d.Draw(::GetDeviceCaps(hdcemf, HORZRES), ::GetDeviceCaps(hdcemf, VERTRES),
			pres.parts, pres.cuts, pres.sheet);

		HENHMETAFILE hemf;
		hemf = CloseEnhMetaFile(hdcemf);
		assert(hemf);
		BOOL bres2 = OpenClipboard(NULL);
		assert(bres2);
		HANDLE hres = SetClipboardData(CF_ENHMETAFILE, hemf);
		assert(hres);
		bres2 = CloseClipboard();
		assert(bres2);
		bres2 = DeleteEnhMetaFile(hemf);
		assert(bres2);
		bres = g.Next(res);
	}
}

int main()
{
	test_gilotine();
	return 0;
}