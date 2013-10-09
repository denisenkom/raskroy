// ParsedPart.h : Declaration of the CParsedPart

#ifndef __PARSEDPART_H_
#define __PARSEDPART_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CParsedPart
class ATL_NO_VTABLE CParsedPart : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CParsedPart, &CLSID_ParsedPart>,
	public IDispatchImpl<IParsedPart, &IID_IParsedPart, &LIBID_COMRASKROYLib>,
	public raskroy::t_parsed_part
{
public:
	CParsedPart()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PARSEDPART)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CParsedPart)
	COM_INTERFACE_ENTRY(IParsedPart)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IParsedPart
public:
	STDMETHOD(get_Width)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_Width)(/*[in]*/ double newVal);
	STDMETHOD(get_Length)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_Length)(/*[in]*/ double newVal);
	STDMETHOD(get_Y)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_Y)(/*[in]*/ double newVal);
	STDMETHOD(get_X)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_X)(/*[in]*/ double newVal);
};

#endif //__PARSEDPART_H_
