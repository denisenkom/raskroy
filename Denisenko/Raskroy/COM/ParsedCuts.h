// ParsedCuts.h : Declaration of the CParsedCuts

#ifndef __PARSEDCUTS_H_
#define __PARSEDCUTS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CParsedCuts
class ATL_NO_VTABLE CParsedCuts : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CParsedCuts, &CLSID_ParsedCuts>,
	public IDispatchImpl<IParsedCuts, &IID_IParsedCuts, &LIBID_COMRASKROYLib>,
	public Denisenko::Raskroy::t_parsed_cuts
{
public:
	CParsedCuts()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PARSEDCUTS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CParsedCuts)
	COM_INTERFACE_ENTRY(IParsedCuts)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IParsedCuts
public:
	STDMETHOD(Add)(IParsedCut *Cut);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_Item)(long, IParsedCut **);
	STDMETHOD(put_Item)(long, IParsedCut *);
};

#endif //__PARSEDCUTS_H_
