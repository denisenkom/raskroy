// Sheets.h : Declaration of the CSheets

#ifndef __SHEETS_H_
#define __SHEETS_H_

#include <deque>
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSheets
class ATL_NO_VTABLE CSheets : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSheets, &CLSID_Sheets>,
	public IDispatchImpl<ISheets, &IID_ISheets, &LIBID_COMRASKROYLib>
{
public:
	CSheets()
	{
	}

	~CSheets();

DECLARE_REGISTRY_RESOURCEID(IDR_SHEETS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSheets)
	COM_INTERFACE_ENTRY(ISheets)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ISheets
public:
	STDMETHOD(get_Item)(/*[in]*/ long Index, /*[out, retval]*/ ISheet **pVal);
	STDMETHOD(put_Item)(/*[in]*/ long Index, /*[in]*/ ISheet *pnewVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
	STDMETHOD(Add)(/*[in]*/ ISheet* pSheet);
private:
	typedef std::deque<ISheet*>t_sheets;
	t_sheets sheets;
};

#endif //__SHEETS_H_
