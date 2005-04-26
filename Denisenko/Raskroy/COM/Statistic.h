// Statistic.h : Declaration of the CStatistic

#ifndef __STATISTIC_H_
#define __STATISTIC_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStatistic
class ATL_NO_VTABLE CStatistic : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CStatistic, &CLSID_Statistic>,
	public IDispatchImpl<IStatistic, &IID_IStatistic, &LIBID_COMRASKROYLib>,
	public raskroy::t_stat
{
public:
	CStatistic()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STATISTIC)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CStatistic)
	COM_INTERFACE_ENTRY(IStatistic)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IStatistic
public:
	STDMETHOD(get_SumRemain)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_SumRemain)(/*[in]*/ double newVal);
	STDMETHOD(get_SumCutLength)(double*);
	STDMETHOD(put_SumCutLength)(double);
};

#endif //__STATISTIC_H_
