// ParsedParts.h : Declaration of the CParsedParts

#ifndef __PARSEDPARTS_H_
#define __PARSEDPARTS_H_

#include "resource.h"       // main symbols
#include "..\Parser.h"

/////////////////////////////////////////////////////////////////////////////
// CParsedParts
class ATL_NO_VTABLE CParsedParts : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CParsedParts, &CLSID_ParsedParts>,
	public IDispatchImpl<IParsedParts, &IID_IParsedParts, &LIBID_COMRASKROYLib>,
	public Denisenko::Raskroy::t_parsed_parts
{
public:
	CParsedParts()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PARSEDPARTS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CParsedParts)
	COM_INTERFACE_ENTRY(IParsedParts)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IParsedParts
public:
	STDMETHOD(Add)(IParsedPart *Part);
	STDMETHOD(get_Item)(long Index, /*[out, retval]*/ IParsedPart **pVal);
	STDMETHOD(put_Item)(long Index, /*[in]*/ IParsedPart* newVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
};

#endif //__PARSEDPARTS_H_
