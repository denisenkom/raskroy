#include "stdafx.h"
#include "Drawer.h"

using namespace std;

namespace Denisenko {
namespace Raskroy {

Drawer::Drawer(void)
	: m_hwnd(0), m_hdc(0)
{
	CreatePensBrushes();
}

Drawer::Drawer(HWND hwnd)
	: m_hwnd(hwnd)
{
	// владеем DC
	assert(IsWindow(hwnd));
	m_hdc = GetDC(hwnd);
	assert(m_hdc);
	CreatePensBrushes();
}

Drawer::Drawer(HDC hdc)
	: m_hwnd(0), m_hdc(hdc)
{
	// не владеем DC
	assert(hdc);
	CreatePensBrushes();
}

Drawer::~Drawer(void)
{
	IfOwnDCThanRelease();
	BOOL bres;
	bres = DeleteObject(m_hwhitebrush);
	assert(bres);
	bres = DeleteObject(m_hhatchbrush);
	assert(bres);
	bres = DeleteObject(m_hredpen);
	assert(bres);
	bres = DeleteObject(m_hblackpen);
	assert(bres);
}

void Drawer::CreatePensBrushes(void)
{
	m_hblackpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	assert(m_hblackpen);
	m_hredpen = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
	assert(m_hredpen);
	LOGBRUSH logbrush;
	logbrush.lbStyle = BS_HATCHED;
	logbrush.lbColor = RGB(255, 0, 0);
	logbrush.lbHatch = HS_BDIAGONAL;
	m_hhatchbrush = CreateBrushIndirect(&logbrush);
	assert(m_hhatchbrush);
	logbrush.lbStyle = BS_SOLID;
	logbrush.lbColor = RGB(255, 255, 255);
	m_hwhitebrush = CreateBrushIndirect(&logbrush);
	assert(m_hwhitebrush);
}

void Drawer::IfOwnDCThanRelease(void)
{
	if (m_hwnd)	// это значит владение DC
	{
		assert(IsWindow(m_hwnd));
		int ires = ReleaseDC(m_hwnd, m_hdc);
		assert(ires);
	}
}

void Drawer::ResetDC(HDC hdc)
{
	IfOwnDCThanRelease();
	m_hwnd = 0;
	m_hdc = hdc;
}

void Drawer::ResetWnd(HWND hwnd)
{
	IfOwnDCThanRelease();
	m_hwnd = hwnd;
	assert(IsWindow(hwnd));
	m_hdc = GetDC(hwnd);
	assert(m_hdc);
}

void Drawer::Draw(int width, int height, const t_parsed_parts& parts, const t_parsed_cuts& cuts, const Part& sheet)
{
	double scalex = width / (double)sheet.Rect.Size[0];
    double scaley = height / (double)sheet.Rect.Size[1];
    double scale;
    if (scalex < scaley)
    	scale = scalex;
    else
      	scale = scaley;
	HGDIOBJ hres = SelectObject(m_hdc, m_hblackpen);
	assert(hres);

	// рисуем лист
	hres = SelectObject(m_hdc, m_hhatchbrush);
	assert(hres != NULL);
	BOOL bres = Rectangle(m_hdc, 0, 0, int(sheet.Rect.Size[0] * scale),
		int(sheet.Rect.Size[1] * scale));
    assert(bres != FALSE);

	// рисуем детали
	hres = SelectObject(m_hdc, m_hwhitebrush);
	assert(hres != NULL);
    {for (t_parsed_parts::const_iterator i = parts.begin(); i != parts.end(); i++)
    {
    	RECT Rect;
        Rect.left = LONG(i->pos[0] * scale);
        Rect.top = LONG(i->pos[1] * scale);
        Rect.right = LONG((i->pos[0] + i->rect.Size[0]) * scale);
        Rect.bottom = LONG((i->pos[1] + i->rect.Size[1]) * scale);
		bres = Rectangle(m_hdc, Rect.left, Rect.top, Rect.right, Rect.bottom);
    	assert(bres != FALSE);
		ostringstream ss;
		ss << i->rect.Size[0] << "x" << i->rect.Size[1];
		int ires = DrawTextA(m_hdc, ss.str().c_str(), ss.str().length(), &Rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		assert(ires != 0);
    }}

	// рисуем резы
	hres = SelectObject(m_hdc, m_hredpen);
	assert(hres != NULL);
    {for (t_parsed_cuts::const_iterator i = cuts.begin(); i != cuts.end(); i++)
    {
		bres = MoveToEx(m_hdc, int(i->pos[0] * scale), int(i->pos[1] * scale), NULL);
		assert(bres);
    	if (i->s)
		{
			bres = LineTo(m_hdc, int((i->pos[0]) * scale), int((i->pos[1] + i->length) * scale));
        	assert(bres);
		}
        else
		{
			bres = LineTo(m_hdc, int((i->pos[0] + i->length) * scale), int(i->pos[1] * scale));
        	assert(bres);
		}
    }}
}

} // namespace Denisenko
} // namespace Raskroy
