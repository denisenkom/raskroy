
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the OLDRASKROY_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// OLDRASKROY_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef OLDRASKROY_EXPORTS
#define OLDRASKROY_API __declspec(dllexport)
#else
#define OLDRASKROY_API __declspec(dllimport)
#endif

#ifndef OLDRASKROY_H_INCLUDED
#define OLDRASKROY_H_INCLUDED

#include <objbase.h>
#include ".\common.h"

namespace raskroy_api {

	struct t_result {
		HLOCAL parts;	// 4B
		HLOCAL cuts;	// 4B
		unsigned amount;		// 4B
		unsigned force_8b_alignment;	// 4B

		raskroy::t_part sheet;	// 24B
		raskroy::t_stat stat;	// 24B

		t_result()
			: parts(0), cuts(0)
		{
		}

		/*t_result(raskroy::t_parsed_part* parts, unsigned parts_num,
			raskroy::t_parsed_cut* cuts, unsigned cuts_num,
			const raskroy::t_part& sheet, const raskroy::t_stat& stat,
			unsigned amount)
			: parts(parts), parts_num(parts_num), cuts(cuts), cuts_num(cuts_num),
				sheet(sheet), stat(stat), amount(amount)
		{
		}*/
	};	// 8+8+32+24+4+4=70B*/

	#define E_CANNOTSETPARTS	MAKE_HRESULT(SEVERITY_ERROR, 0, 10)

	class IResult1 : public IUnknown
	{
	public:
		STDMETHOD(get_DetailsCount)(long *pRet) = 0;
		STDMETHOD(get_DetailsItem)(long Index, raskroy::t_parsed_part *pRet) = 0;
		STDMETHOD(get_CutsCount)(long *pRet) = 0;
		STDMETHOD(get_CutsItem)(long Index, raskroy::t_parsed_cut *pRet) = 0;
		STDMETHOD(get_Sheet)(raskroy::t_part *pRet) = 0;
		STDMETHOD(get_RepetitionFactor)(long *pRet) = 0;
		STDMETHOD(get_Statistic)(raskroy::t_stat *pRet) = 0;
	};

	class IDrawer1 : public IUnknown
	{
	public:
		STDMETHOD(Draw)(HDC hDC, long Width, long Height, IResult1 *Result) = 0;
	};

	class IRaskroy1 : public IUnknown {
	public:
		STDMETHOD(SetRecursionDepth)(long) = 0;
		//STDMETHOD(GetRecursionDepth)(unsigned char*) = 0;
		STDMETHOD(SetFactory)(const raskroy::t_factory* pfactory) = 0;
		STDMETHOD(SetCriteria)(const raskroy::criteria* pcriteria) = 0;
		STDMETHOD(SetMonitor)(raskroy::monitor* pmonitor) = 0;
		STDMETHOD(First)(const raskroy::t_part* parts, WORD parts_num,
			const raskroy::t_part* sheets, WORD sheets_num, IResult1** ppResult, bool* pReturn) = 0;
		STDMETHOD(Next)(IResult1** ppResult, bool* pReturn) = 0;
		//STDMETHOD(GetErrorStr)(TCHAR* buf, ULONG bufsize) = 0;
	};

	OLDRASKROY_API HRESULT __stdcall RaskroyCreate(IRaskroy1**);
	typedef HRESULT (__stdcall *pRaskroyCreate)(IRaskroy1**);
	OLDRASKROY_API HRESULT __stdcall DrawerCreate(IDrawer1**);
	typedef HRESULT (__stdcall *pDrawerCreate)(IDrawer1**);
}

#endif	// OLDRASKROY_H_INCLUDED
