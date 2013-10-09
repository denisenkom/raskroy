#include "oldraskroy.h"
#include "Unknown.h"

namespace raskroy_api {

class CResult1 : public IResult1, public CUnknown
{
	typedef std::vector<raskroy::t_parsed_part> t_parts_vector;
	typedef std::vector<raskroy::t_parsed_cut> t_cuts_vector;

	t_parts_vector parts;
	t_cuts_vector cuts;
	raskroy::t_part sheet;
	unsigned amount;
	raskroy::t_stat stat;

	CResult1(t_parts_vector&, t_cuts_vector&, raskroy::t_part&, unsigned amount, raskroy::t_stat&);
	~CResult1(void) {}
public:
	STDMETHOD_(ULONG, AddRef)(void) {return CUnknown::AddRef();};
	STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppiface) {return CUnknown::QueryInterface(iid, ppiface);}
	STDMETHOD_(ULONG, Release)(void) {return CUnknown::Release();}

	STDMETHOD(get_DetailsCount)(long *pRet);
	STDMETHOD(get_DetailsItem)(long Index, raskroy::t_parsed_part *pRet);
	STDMETHOD(get_CutsCount)(long *pRet);
	STDMETHOD(get_CutsItem)(long Index, raskroy::t_parsed_cut *pRet);
	STDMETHOD(get_Sheet)(raskroy::t_part *pRet);
	STDMETHOD(get_RepetitionFactor)(long *pRet);
	STDMETHOD(get_Statistic)(raskroy::t_stat *pRet);

	static CResult1* Create(t_parts_vector &parts, t_cuts_vector &cuts,
		raskroy::t_part &sheet, unsigned amount, raskroy::t_stat &stat);
};

}