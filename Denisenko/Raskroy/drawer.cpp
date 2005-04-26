#include "stdafx.h"
#include "Drawer.h"

namespace Denisenko {
namespace Raskroy {

Drawer::Drawer(void)
	: hwnd(0), hdc(0)
{
	create_pens_brushes();
}

Drawer::Drawer(HWND hwnd)
	: hwnd(hwnd)
{
	// владеем DC
	assert(IsWindow(hwnd));
	hdc = GetDC(hwnd);
	assert(hdc);
	create_pens_brushes();
}

Drawer::Drawer(HDC hdc)
	: hwnd(0), hdc(hdc)
{
	// не владеем DC
	assert(hdc);
	create_pens_brushes();
}

Drawer::~Drawer(void)
{
	if_own_dc_than_release();
	BOOL bres;
	bres = DeleteObject(hwhitebrush); assert(bres);
	bres = DeleteObject(hhatchbrush); assert(bres);
	bres = DeleteObject(hredpen); assert(bres);
	bres = DeleteObject(hblackpen); assert(bres);
}

void Drawer::create_pens_brushes(void)
{
	hblackpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	assert(hblackpen);
	hredpen = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
	assert(hredpen);
	LOGBRUSH logbrush;
	logbrush.lbStyle = BS_HATCHED;
	logbrush.lbColor = RGB(255, 0, 0);
	logbrush.lbHatch = HS_BDIAGONAL;
	hhatchbrush = CreateBrushIndirect(&logbrush);
	assert(hhatchbrush);
	logbrush.lbStyle = BS_SOLID;
	logbrush.lbColor = RGB(255, 255, 255);
	hwhitebrush = CreateBrushIndirect(&logbrush);
	assert(hwhitebrush);
}

void Drawer::if_own_dc_than_release(void)
{
	if (hwnd)	// это значит владение DC
	{
		assert(IsWindow(hwnd));
		int ires = ReleaseDC(hwnd, hdc); assert(ires);
	}
}

void Drawer::reset_dc(HDC hdc)
{
	if_own_dc_than_release();
	hwnd = 0;
	this->hdc = hdc;
}

void Drawer::reset_wnd(HWND hwnd)
{
	if_own_dc_than_release();
	this->hwnd = hwnd;
	assert(IsWindow(hwnd));
	hdc = GetDC(hwnd);
	assert(hdc);
}

void Drawer::draw(int width, int height, const t_parsed_parts& parts, const t_parsed_cuts& cuts, const t_part& sheet)
{
    double scalex = width/sheet.rect.size[0];
    double scaley = height/sheet.rect.size[1];
    double scale;
    if (scalex < scaley)
    	scale = scalex;
    else
      	scale = scaley;
	HGDIOBJ hres = SelectObject(hdc, hblackpen);
	assert(hres);

	// рисуем лист
	hres = SelectObject(hdc, hhatchbrush);
	assert(hres != NULL);
	BOOL bres = Rectangle(hdc, 0, 0, int(sheet.rect.size[0]*scale), int(sheet.rect.size[1]*scale));
    assert(bres != FALSE);

	// рисуем детали
	hres = SelectObject(hdc, hwhitebrush);
	assert(hres != NULL);
    {for (t_parsed_parts::const_iterator i = parts.begin(); i != parts.end(); i++)
    {
    	RECT Rect;
        Rect.left = LONG(i->pos[0]*scale);
        Rect.top = LONG(i->pos[1]*scale);
        Rect.right = LONG((i->pos[0]+i->rect.size[0])*scale);
        Rect.bottom = LONG((i->pos[1]+i->rect.size[1])*scale);
		bres = Rectangle(hdc, Rect.left, Rect.top, Rect.right, Rect.bottom);
    	assert(bres != FALSE);
		int par2 = 0, par3 = 0;
		std::string str(fcvt(i->rect.size[0], 0, &par2, &par3));
		str += "x";
		str += fcvt(i->rect.size[1], 0, &par2, &par3);
		int ires = DrawText(hdc, str.c_str(), int(str.length()), &Rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		assert(ires != 0);
    }}

	// рисуем резы
	hres = SelectObject(hdc, hredpen);
	assert(hres != NULL);
    {for (t_parsed_cuts::const_iterator i = cuts.begin(); i != cuts.end(); i++)
    {
		bres = MoveToEx(hdc, int(i->pos[0]*scale), int(i->pos[1]*scale), NULL);
		assert(bres);
    	if (i->s)
		{
			bres = LineTo(hdc, int((i->pos[0])*scale), int((i->pos[1]+i->length)*scale));
        	assert(bres);
		}
        else
		{
			bres = LineTo(hdc, int((i->pos[0]+i->length)*scale), int(i->pos[1]*scale));
        	assert(bres);
		}
    }}
}

} // namespace Denisenko
} // namespace Raskroy