#ifndef DrawerH
#define DrawerH

#include <windows.h>
#include "parser.h"

namespace Denisenko {
namespace Raskroy {

class Drawer {
	HDC hdc;
	HWND hwnd;
	HPEN hblackpen, hredpen;
	HBRUSH hwhitebrush, hhatchbrush;

	void create_pens_brushes(void);
	void if_own_dc_than_release(void);

public:
	Drawer(void);
	Drawer(HDC);
	Drawer(HWND);
	~Drawer(void);

	void ResetDC(HDC = 0);
	void ResetWnd(HWND);
	void Draw(int width, int height, const t_parsed_parts&, const t_parsed_cuts&, const t_part& sheet);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // DrawerH