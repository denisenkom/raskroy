// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\..\raskroy.h"
#include "..\..\raskroy.cpp"
#include "..\..\drawer.h"
#include "..\..\drawer.cpp"
#include "..\..\parser.h"
#include "..\..\parser.cpp"
#include "..\..\perebor.cpp"
#include "..\..\perebor_2d.cpp"

class my_monitor : public raskroy::monitor
{
	float cut_thickness;
	HWND hwnd;
	raskroy::drawer drawer;
public:
	my_monitor(float cut_thickness)
		: cut_thickness(cut_thickness), hwnd(0)
	{
		WNDCLASS cls = {0};
		cls.hInstance = GetModuleHandle(NULL);
		cls.lpfnWndProc = DefWindowProc;
		cls.lpszClassName = "mycls";
		ATOM ares = RegisterClass(&cls);
		assert(ares);
		hwnd = CreateWindow("mycls", NULL, WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, GetModuleHandle(NULL), NULL);
		assert(hwnd);
		drawer.reset_wnd(hwnd);
	}

	~my_monitor(void)
	{
		drawer.reset_dc();
		BOOL bres = DestroyWindow(hwnd);
		assert(bres);
		bres = UnregisterClass("mycls", GetModuleHandle(NULL));
		assert(bres);
	}

	virtual void sheet_ready(raskroy::t_result& res1)
	{
		raskroy::parser parser;
		raskroy::t_parsed_result res2;
		parser.parse(res1, res2, cut_thickness);
		RECT rect;
		BOOL bres = GetClientRect(hwnd, &rect);
		assert(bres);
		drawer.draw(rect.right, rect.bottom, res2.parts, res2.cuts, *res1.sheet);
		Sleep(1000);
	}

	virtual void __stdcall update_progress(unsigned new_progress)
	{
		std::cout << new_progress << "%";
	}
};

void test1(raskroy::t_parts& parts, raskroy::t_parts& sheets)
{
	raskroy::t_part part, sheet;
	sheet.rect.size[0] = 2440-10;
	sheet.rect.size[1] = 1830-10;
	sheet.amount = 1000;
	sheets.push_back(sheet);

	part.rect.size[0] = 221;
	part.rect.size[1] = 60;
	part.amount = 3;
	part.rotate = true;
	parts.push_back(part);

	part.rect.size[0] = 475;
	part.rect.size[1] = 200;
	part.amount = 6;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 255;
	part.rect.size[1] = 480;
	part.amount = 3;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 712;
	part.rect.size[1] = 500;
	part.amount = 30;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 364;
	part.rect.size[1] = 420;
	part.amount = 10;
	part.rotate = true;
	parts.push_back(part);

	part.rect.size[0] = 395;
	part.rect.size[1] = 395;
	part.amount = 10;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 1200;
	part.rect.size[1] = 600;
	part.amount = 10;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 362;
	part.rect.size[1] = 400;
	part.amount = 10;
	part.rotate = true;
	parts.push_back(part);

	part.rect.size[0] = 408;
	part.rect.size[1] = 402;
	part.amount = 5;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 1068;
	part.rect.size[1] = 410;
	part.amount = 10;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 364;
	part.rect.size[1] = 110;
	part.amount = 5;
	part.rotate = true;
	parts.push_back(part);

	part.rect.size[0] = 130;
	part.rect.size[1] = 395;
	part.amount = 15;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 408;
	part.rect.size[1] = 420;
	part.amount = 5;
	part.rotate = true;
	parts.push_back(part);

	part.rect.size[0] = 306;
	part.rect.size[1] = 76;
	part.amount = 30;
	part.rotate = true;
	parts.push_back(part);

	part.rect.size[0] = 400;
	part.rect.size[1] = 76;
	part.amount = 30;
	part.rotate = true;
	parts.push_back(part);

	part.rect.size[0] = 1400;
	part.rect.size[1] = 700;
	part.amount = 5;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 408;
	part.rect.size[1] = 420;
	part.amount = 5;
	part.rotate = false;
	parts.push_back(part);

	part.rect.size[0] = 1268;
	part.rect.size[1] = 410;
	part.amount = 5;
	part.rotate = false;
	parts.push_back(part);
}

void test2(raskroy::t_parts& parts, raskroy::t_parts& sheets)
{
	raskroy::t_part part, sheet;
	sheet.rect.size[0] = 2440-10;
	sheet.rect.size[1] = 1830-10;
	sheet.amount = 0;
	sheets.push_back(sheet);

	part.rect.size[0] = 400;
	part.rect.size[1] = 600;
	part.amount = 100;
	part.rotate = true;
	parts.push_back(part);

	/*part.rect.size[0] = 300;
	part.rect.size[1] = 500;
	part.amount = 100;
	part.rotate = false;
	parts.push_back(part);*/
}

void test3(raskroy::t_parts& parts, raskroy::t_parts& sheets)
{
	raskroy::t_part part, sheet;
	sheet.rect.size[0] = 2440-10;
	sheet.rect.size[1] = 1830-10;
	sheet.amount = 100;
	sheets.push_back(sheet);

	part.rect.size[0] = 400;
	part.rect.size[1] = 600;
	part.amount = 100;
	part.rotate = true;
	parts.push_back(part);

	/*part.rect.size[0] = 300;
	part.rect.size[1] = 500;
	part.amount = 100;
	part.rotate = false;
	parts.push_back(part);*/
}

void test4(raskroy::t_parts &parts, raskroy::t_parts &sheets)
{
	raskroy::t_part part, sheet;
	part.rect.size[0] = 400;
	part.rect.size[1] = 300;
	part.amount = 30;
	part.rotate = true;
	parts.push_back(part);

	part.rect.size[0] = 400;
	part.rect.size[1] = 300;
	part.amount = 30;
	part.rotate = true;
	parts.push_back(part);

	sheet.rect.size[0] = 2800;
	sheet.rect.size[1] = 1200;
	sheet.amount = 200;
	sheet.rotate = true;
	sheets.push_back(sheet);
}

void test5(raskroy::t_parts &parts, raskroy::t_parts &sheets)
{
	raskroy::t_part part, sheet;
	part.rect.size[0] = 100;
	part.rect.size[1] = 100;
	part.amount = 2;
	part.rotate = false;
	parts.push_back(part);

	sheet.rect.size[0] = 2800;
	sheet.rect.size[1] = 1400;
	sheet.amount = 100;
	sheet.rotate = false;
	sheets.push_back(sheet);
}

int main(int argc, char* argv[])
{
	raskroy::t_parts parts, sheets;

	test1(parts, sheets);

	//raskroy::t_factory factory;
	//factory.saw_thickness = 4.2;
	
	raskroy::gilotine x;
	//x.set_recursion_max_depth(8);
	//raskroy::criteria criteria;
	//x.set_criteria(criteria);
	my_monitor monitor(4);
	//x.set_monitor(monitor);
	//x.set_factory(factory);

	std::cout << "Starting raskroy\n";
	DWORD starttime = timeGetTime();
	try
	{
		raskroy::t_result result;
		if (!x.first(parts, sheets, result))
			throw std::exception("no raskroy");
		do {
			monitor.sheet_ready(result);
		}
		while (x.next(result));
	}
	catch (raskroy::err_cannot_set_parts)
	{
		std::cout << "Cannot set parts\n";
	}
	catch (...)
	{
		std::cout << "unknown exception\n";
	}
	DWORD deltat = timeGetTime()-starttime;

	raskroy::t_stat common_stat;
	common_stat = x.get_common_stat();

	std::cout << "statistica:\n\tremain=" << common_stat.sum_remain/1000000.0f << "\n\tcut length=" << common_stat.sum_cut_length/1000.0f << std::endl;
	std::cout << "\ttime=" << deltat/1000.0f << "sec\n";

	return 0;
}
