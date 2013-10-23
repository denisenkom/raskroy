// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <gtest/gtest.h>
#include "Raskroy.h"
#include "Parser.h"

using namespace Denisenko::Raskroy;
using namespace std;

TEST(OriginalTests, test_perebor)
{
	// testing perebor
	Size sz;
	sz.Value = 100;

	OtherSize os;
	os.Offset = 0;
	os.Value = 100;
	sz.other_sizes.push_back(os);

	os.Offset = 2;
	os.Value = 200;
	sz.other_sizes.push_back(os);

	os.Offset = 1;
	os.Value = 30;
	sz.other_sizes.push_back(os);
	sz.other_sizes.SetMin();

	Amounts rem(3);
	rem[0] = 1;
	rem[1] = 2;
	rem[2] = 3;

	Perebor p(&rem, 4);
	Stat stat;
	OldLayoutResult::Details det;
	Amounts rash(3);
	scalar size = 260+4*4;
	double opilki;
	scalar remain;
	EXPECT_TRUE(p.Make(sz, size, det, rash, remain, opilki));
	EXPECT_EQ(3 * 100 * 4, opilki);
	Amounts expected_use(3);
	expected_use[1] = 2;
	expected_use[2] = 1;
	EXPECT_EQ(expected_use, rash);
	EXPECT_EQ(4, remain);
}

void display_sizes(Sizes sizes[])
{
	for (int s = 0; s != 2; s++)
	{
		cout << "s=" << s << endl;
		for (Sizes::const_iterator i = sizes[s].begin(); i != sizes[s].end(); i++)
		{
			const Size &size = *i;
			cout << size.Value << ": ";
			for (OtherSizes::const_iterator j = size.other_sizes.begin(); j != size.other_sizes.end(); j++)
				cout << j->Value << " ";
			cout << endl;
		}
	}
}

std::ostream& operator << (std::ostream &os, const std::string &str)
{
	return os << str.c_str();
}

void prinOldLayoutResult(int level, const OldLayoutResult &ras)
{
	string spaces(level, ' ');
	cout << spaces << "begin {\n";
	cout << spaces << "Cutting by s=" << ras.s << " cut=" << ras.cut;
#ifdef COUNT_KRATNOSTJ
	cout << " kratnostj=" << ras.kratnostj;
#endif
	cout << endl;
	cout << spaces << "details: ";
	for (OldLayoutResult::Details::const_iterator i = ras.details.begin(); i != ras.details.end(); i++)
		cout << i->size << " " << i->num << ", ";
	cout << endl;
	if (ras.watchRemain())
	{
		cout << spaces << "remain raskroy\n";
		prinOldLayoutResult(level + 1, *ras.watchRemain());
	}
	if (ras.watchRecurse())
	{
		cout << spaces << "recurse raskroy\n";
		prinOldLayoutResult(level + 1, *ras.watchRecurse());
	}
	cout << spaces << "} end\n";
}

TEST(OriginalTests, test_gilotine)
{
	Raskroy g;
	Parts p;

	p.push_back(Part(900, 605, true, 2));
	p.push_back(Part(630, 600, true, 2));

	p.push_back(Part(480, 625, true, 5));
	p.push_back(Part(150, 395, true, 1));

	p.push_back(Part(480, 625, true, 6));
	p.push_back(Part(867, 70, true, 2));

	p.push_back(Part(480, 625, true, 5));
	p.push_back(Part(400, 565, true, 1));

	p.push_back(Part(590, 515, true, 1));
	p.push_back(Part(625, 515, true, 2));
	p.push_back(Part(640, 515, true, 2));
	p.push_back(Part(790, 290, true, 4));
	p.push_back(Part(480, 290, true, 2));
	p.push_back(Part(605, 290, true, 4));
	p.push_back(Part(790, 333, true, 1));
	p.push_back(Part(331, 274, true, 4));

	/*p.push_back(Part(625, 600, true, 1));
	p.push_back(Part(625, 769, true, 1));
	p.push_back(Part(625, 752, true, 1));*/
	Parts s;


	s.push_back(Part(1810, 1210));
	//s.push_back(Part(1000, 1000));
	Result res;
	g.Begin(p, s);
	//int index = 1;
	while (g.NextResult(res))
	{
		cout << "Raskroy.\n";
		prinOldLayoutResult(0, res.raskroy);
		Parser pr;
		t_parsed_result pres;
		pr.Parse(res, pres, g.get_SawThickness());
		assert(pr.get_DetailsSummarySquare() == s.begin()->rect.Size[0] * s.begin()->rect.Size[1] - res.Statistics.Opilki - res.Statistics.UnusefulRemain - res.Statistics.UsefulRemain);
		//stringstream fname;
		//fname << "raskroy" << index++ << ".emf";
		/*HDC hdcemf;
		hdcemf = ::CreateEnhMetaFile(NULL, NULL, NULL, 0);
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
		assert(bres2);*/
	}
}


TEST(OriginalTests, test_gilotine2)
{
    Raskroy g;
    Parts p;

    p.push_back(Part(9, 6, true, 1));
    p.push_back(Part(3, 3, true, 3));

    Parts s;
    g.put_SawThickness(1);
    s.push_back(Part(11, 11));
    Result res;
    g.Begin(p, s);
    int num = 0;
    while (g.NextResult(res))
    {
        Parser pr;
        t_parsed_result pres;
        pr.Parse(res, pres, g.get_SawThickness());
        ASSERT_EQ(pr.get_DetailsSummarySquare(),
            s.begin()->rect.Size[0] * s.begin()->rect.Size[1] - res.Statistics.Opilki - res.Statistics.UnusefulRemain - res.Statistics.UsefulRemain);
        num++;
    }
    ASSERT_EQ(1, num) << "Should produce single result";
    ASSERT_LE(6, res.Statistics.UnusefulRemain + res.Statistics.UsefulRemain);
}


TEST(OriginalTests, test_skiny_details)
{
    Raskroy g;
    Parts p;

    p.push_back(Part(9, 1, true, 1));
    p.push_back(Part(5, 5, true, 2));

    Parts s;
    g.put_SawThickness(0);
    Part sheet = Part(10, 6);
    s.push_back(sheet);
    g.Begin(p, s);
    Result res;
    int num = 0;
    while (g.NextResult(res))
    {
        Parser pr;
        ParsedResult pres;
        pr.Parse(res, pres, 0);
        Stat stat = res.Statistics;
        double remains = stat.Opilki + stat.UnusefulRemain + stat.UsefulRemain;
        ASSERT_EQ(pr.get_DetailsSummarySquare(),
                  sheet.rect.Size[0] * sheet.rect.Size[1] - remains);
        num++;
    }
    ASSERT_EQ(1, num) << "Should produce single result";
}


TEST(OriginalTests, Chorometrage)
{
	Raskroy g;
	Parts p;

	p.push_back(Part(900, 605, true, 2));
	p.push_back(Part(630, 600, true, 2));

	p.push_back(Part(480, 625, true, 5));
	p.push_back(Part(150, 395, true, 1));

	p.push_back(Part(480, 625, true, 6));
	p.push_back(Part(867, 70, true, 2));

	p.push_back(Part(480, 625, true, 5));
	p.push_back(Part(400, 565, true, 1));

	p.push_back(Part(590, 515, true, 1));
	p.push_back(Part(625, 515, true, 2));
	p.push_back(Part(640, 515, true, 2));
	p.push_back(Part(790, 290, true, 4));
	p.push_back(Part(480, 290, true, 2));
	p.push_back(Part(605, 290, true, 4));
	p.push_back(Part(790, 333, true, 1));
	p.push_back(Part(331, 274, true, 4));

	Parts s;


	s.push_back(Part(1810, 1210));
	//s.push_back(Part(1000, 1000));
	Result res;
	g.Begin(p, s);
	//int index = 1;
	while (g.NextResult(res))
	{
	}
}

TEST(OriginalTests, Chorometrage2)
{
	Raskroy g;
	Parts p;

	p.push_back(Part(900, 605, true, 2));
	p.push_back(Part(630, 600, true, 2));

	/*p.push_back(Part(480, 625, true, 5));
	p.push_back(Part(150, 395, true, 1));

	p.push_back(Part(480, 625, true, 6));
	p.push_back(Part(867, 70, true, 2));

	p.push_back(Part(480, 625, true, 5));
	p.push_back(Part(400, 565, true, 1));

	p.push_back(Part(590, 515, true, 1));
	p.push_back(Part(625, 515, true, 2));
	p.push_back(Part(640, 515, true, 2));
	p.push_back(Part(790, 290, true, 4));
	p.push_back(Part(480, 290, true, 2));
	p.push_back(Part(605, 290, true, 4));
	p.push_back(Part(790, 333, true, 1));
	p.push_back(Part(331, 274, true, 4));

	p.push_back(Part(625, 600, true, 1));
	p.push_back(Part(625, 769, true, 1));
	p.push_back(Part(625, 752, true, 1));*/
	Parts s;


	s.push_back(Part(1810, 1210));
	//s.push_back(Part(1000, 1000));
	Result res;
	g.Begin(p, s);
	//int index = 1;
	while (g.NextResult(res))
	{
	}
}

TEST(OriginalTests, RealKitchen)
{
	Raskroy g;
	Parts p;

	p.push_back(Part(810, 480, true, 1));
	p.push_back(Part(950, 480, true, 1));
	p.push_back(Part(790, 480, true, 1));
	p.push_back(Part(883, 510, true, 1));
	p.push_back(Part(705, 480, true, 7));
	p.push_back(Part(705, 510, true, 1));
	p.push_back(Part(480, 625, true, 5));
	p.push_back(Part(720, 495, true, 1));
	p.push_back(Part(790, 270, true, 1));
	p.push_back(Part(790, 290, true, 8));
	p.push_back(Part(790, 377, true, 1));
	p.push_back(Part(790, 280, true, 1));
	p.push_back(Part(377, 253, true, 1));
	p.push_back(Part(767, 290, true, 3));
	p.push_back(Part(580, 580, true, 4));
	p.push_back(Part(807, 290, true, 3));
	p.push_back(Part(767, 290, true, 2));

	p.push_back(Part(265, 235, true, 1));
	p.push_back(Part(765, 235, true, 2));
	p.push_back(Part(383, 400, true, 1));
	p.push_back(Part(915, 400, true, 1));
	/*p.push_back(Part(318, 120, true, 8));
	p.push_back(Part(395, 120, true, 8));
	p.push_back(Part(777, 70, true, 2));
	p.push_back(Part(917, 70, true, 2));
	p.push_back(Part(757, 70, true, 2));
	p.push_back(Part(867, 70, true, 2));
	p.push_back(Part(767, 70, true, 2));
	p.push_back(Part(758, 70, true, 3));
	p.push_back(Part(510, 70, true, 1));
	p.push_back(Part(563, 70, true, 1));
	p.push_back(Part(807, 70, true, 1));*/

	Parts s;


	s.push_back(Part(1810, 1210));
	//s.push_back(Part(1000, 1000));
	Result res;
	g.Begin(p, s);
	//int index = 1;
	while (g.NextResult(res))
	{
	}
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
