#include "Unknown.h"

namespace raskroy_api
{
	class CRaskroy1 : public IRaskroy1,
		public CUnknown,
		raskroy::gilotine
	{
		raskroy::monitor default_monitor;
		raskroy::criteria default_criteria;
		raskroy::t_factory factory;
	
		CRaskroy1(void);
		~CRaskroy1(void) {}
	public:
		STDMETHOD_(ULONG, AddRef)(void) {return CUnknown::AddRef();};
		STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppiface) {return CUnknown::QueryInterface(iid, ppiface);}
		STDMETHOD_(ULONG, Release)(void) {return CUnknown::Release();}

		//STDMETHOD(GetRecursionDepth(long*);
		STDMETHOD(SetRecursionDepth)(long);
		STDMETHOD(SetFactory)(const raskroy::t_factory* pfactory);
		STDMETHOD(SetCriteria)(const raskroy::criteria* pcriteria);
		STDMETHOD(SetMonitor)(raskroy::monitor* pmonitor);
		STDMETHOD(First)(const raskroy::t_part* parts, WORD parts_num,
			const raskroy::t_part* sheets, WORD sheets_num,
			IResult1**, bool*);
		STDMETHOD(Next)(IResult1**, bool*);

		static CRaskroy1* Create(void);
	};
}
