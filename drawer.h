#ifndef RASKROY_DRAWER_H_INCLUDER
#define RASKROY_DRAWER_H_INCLUDER

#include "guillotine.h"
#include <windows.h>

namespace raskroy {
	class drawer {
		HDC hdc;
		HWND hwnd;
		HPEN hblackpen, hredpen;
		HBRUSH hwhitebrush, hhatchbrush;

		void create_pens_brushes(void);
		void if_own_dc_than_release(void);

	public:
		drawer(void);
		drawer(HDC);
		drawer(HWND);
		~drawer(void);

		void reset_dc(HDC = 0);
		void reset_wnd(HWND);
		void draw(int width, int height, const t_parsed_parts&, const t_parsed_cuts&, const t_part& sheet);
	};
}

#endif	// RASKROY_DRAWER_H_INCLUDER