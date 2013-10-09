#include "Unknown.h"

namespace raskroy_api
{
	class CDrawer1 : public IDrawer1, public CUnknown {
		CDrawer1(void) {};
		~CDrawer1(void) {};
		raskroy::drawer drawer;
	public:
		STDMETHOD_(ULONG, AddRef)(void) {return CUnknown::AddRef();};
		STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppiface) {return CUnknown::QueryInterface(iid, ppiface);}
		STDMETHOD_(ULONG, Release)(void) {return CUnknown::Release();}

		STDMETHOD(Draw)(HDC hDC, long Width, long Height, IResult1*);

		static CDrawer1* Create(void);
	};
}
