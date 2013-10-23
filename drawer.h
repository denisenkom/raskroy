#ifndef DrawerH
#define DrawerH

#include <windows.h>
#include "Parser.h"

namespace Denisenko {
namespace Raskroy {

class Drawer {
	HDC m_hdc;
	HWND m_hwnd;
	HPEN m_hblackpen;
	HPEN m_hredpen;
	HBRUSH m_hwhitebrush;
	HBRUSH m_hhatchbrush;

	void CreatePensBrushes(void);
	void IfOwnDCThanRelease(void);

public:
	Drawer(void);
	Drawer(HDC);
	Drawer(HWND);
	~Drawer(void);

	void ResetDC(HDC = 0);
	void ResetWnd(HWND);
	void Draw(int width, int height, const ParsedParts&, const t_parsed_cuts&, const Part& sheet);
};

} // namespace Denisenko
} // namespace Raskroy

#endif // DrawerH
