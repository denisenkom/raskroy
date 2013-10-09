// test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//raskroy_api::CRaskroyLibrary raskroy_api::Lonely::library;
raskroy_api::CRaskroyLibrary raskroy_api::library;

class my_monitor : public raskroy::monitor
{
	HWND hwnd;
	raskroy_api::Drawer1 Drawer;
public:
	my_monitor(raskroy_api::Drawer1 &Drawer)
		: Drawer(Drawer), hwnd(0)
	{
		WNDCLASS cls = {0};
		cls.hInstance = GetModuleHandle(NULL);
		cls.lpfnWndProc = DefWindowProc;
		cls.lpszClassName = "mycls";
		cls.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
		ATOM ares = RegisterClass(&cls);
		if (!ares)
			throw raskroy_api::windows_error("RegisterClass");
		hwnd = CreateWindow("mycls", NULL, WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, GetModuleHandle(NULL), NULL);
		if (!hwnd)
			throw raskroy_api::windows_error("CreateWindow");
		assert(IsWindow(hwnd));
	}

	~my_monitor(void)
	{
		assert(IsWindow(hwnd));
		BOOL bres = DestroyWindow(hwnd);
		assert(bres);
		bres = UnregisterClass("mycls", GetModuleHandle(NULL));
		assert(bres);
	}

	virtual void sheet_ready(raskroy_api::Result1 &Result)
	{
		assert(IsWindow(hwnd));
		HDC hdc = GetDC(hwnd);
		if (!hdc)
			throw raskroy_api::windows_error("GetDC");
		RECT rect;
		BOOL bres = GetClientRect(hwnd, &rect);
		assert(bres);

		try
		{
			Drawer.Draw(hdc, rect.right, rect.bottom, Result);
		}
		catch (...)
		{
			int ires = ReleaseDC(hwnd, hdc);
			assert(ires);
			throw;
		}
		int ires = ReleaseDC(hwnd, hdc);
		assert(ires);
		Sleep(1000);
	}

	virtual void __stdcall progress_update(BYTE new_progress)
	{
		std::cout << new_progress << '%';
	}
};

typedef std::vector<raskroy::t_part> t_parts;

void test1(t_parts& parts, t_parts& sheets)
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

void test2(t_parts& parts, t_parts& sheets)
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

void test3(t_parts& parts, t_parts& sheets)
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

void test4(t_parts &parts, t_parts &sheets)
{
	parts.resize(2);
	parts[0].rect.size[0] = 400;
	parts[0].rect.size[1] = 300;
	parts[0].amount = 30;
	parts[0].rotate = true;

	parts[1].rect.size[0] = 400;
	parts[1].rect.size[1] = 300;
	parts[1].amount = 30;
	parts[1].rotate = true;

	sheets.resize(1);
	sheets[0].rect.size[0] = 2800;
	sheets[0].rect.size[1] = 1200;
	sheets[0].amount = 200;
	sheets[0].rotate = true;
}

int main(int argc, char* argv[])
{
	raskroy_api::library.lpLibFileName = "c:\\gilotine\\msvc\\oldraskroy\\release\\oldraskroy.dll";
	try
	{
		raskroy_api::Raskroy1 Raskroy;
		raskroy_api::Drawer1 Drawer;

		t_parts parts, sheets;
		test1(parts, sheets);

		my_monitor monitor(Drawer);

		raskroy::t_stat common_stat;
		raskroy_api::Result1 Result;
		bool ret = Raskroy.First(parts, sheets, Result);
		while (ret)
		{
			monitor.sheet_ready(Result);
			ret = Raskroy.Next(Result);
		}
	}
	catch (raskroy_api::error& err)
	{
		MessageBox(NULL, err.what().c_str(), 0, MB_ICONSTOP);
	}
	return 0;
}
