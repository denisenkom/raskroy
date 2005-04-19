// ParsedCut.h : Declaration of the CParsedCut

#ifndef __PARSEDCUT_H_
#define __PARSEDCUT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CParsedCut
class ATL_NO_VTABLE CParsedCut : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CParsedCut, &CLSID_ParsedCut>,
	public IDispatchImpl<IParsedCut, &IID_IParsedCut, &LIBID_COMRASKROYLib>,
	private raskroy::t_parsed_cut
{
public:
	CParsedCut()
	{
	}

	CParsedCut(const raskroy::t_parsed_cut &cut)
		: raskroy::t_parsed_cut(cut)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PARSEDCUT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CParsedCut)
	COM_INTERFACE_ENTRY(IParsedCut)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IParsedCut
public:
	STDMETHOD(get_Length)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_Length)(/*[in]*/ double newVal);
	STDMETHOD(get_S)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_S)(/*[in]*/ long newVal);
	STDMETHOD(get_Y)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_Y)(/*[in]*/ double newVal);
	STDMETHOD(get_X)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_X)(/*[in]*/ double newVal);
};

#endif //__PARSEDCUT_H_
