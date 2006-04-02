// Sheet.h : Declaration of the CSheet

#ifndef __SHEET_H_
#define __SHEET_H_

#include "resource.h"       // main symbols

using namespace ATL;

/////////////////////////////////////////////////////////////////////////////
// CSheet
class ATL_NO_VTABLE CSheet : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSheet, &CLSID_Sheet>,
	public IDispatchImpl<ISheet, &IID_ISheet, &LIBID_COMRASKROYLib>
{
	CComCurrency length, width;
	long amount;
	BOOL rotate;
public:
	CSheet()
		: amount(0), rotate(FALSE)
	{
	}

	~CSheet()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SHEET)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSheet)
	COM_INTERFACE_ENTRY(ISheet)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ISheet
public:
	STDMETHOD(get_Rotate)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_Rotate)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_Amount)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Amount)(/*[in]*/ long newVal);
	STDMETHOD(get_Width)(/*[out, retval]*/ CURRENCY *pVal);
	STDMETHOD(put_Width)(/*[in]*/ CURRENCY newVal);
	STDMETHOD(get_Length)(/*[out, retval]*/ CURRENCY *pVal);
	STDMETHOD(put_Length)(/*[in]*/ CURRENCY newVal);
};

#endif //__SHEET_H_
