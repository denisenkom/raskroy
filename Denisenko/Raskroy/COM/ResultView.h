// ResultView.h : Declaration of the CResultView

#ifndef __RESULTVIEW_H_
#define __RESULTVIEW_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "..\Drawer.h"


/////////////////////////////////////////////////////////////////////////////
// CResultView
class ATL_NO_VTABLE CResultView : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComControl<CResultView>,
	public CComCoClass<CResultView, &CLSID_ResultView>,

	public IDispatchImpl<IResultView, &IID_IResultView, &LIBID_COMRASKROYLib>,
	public IPersistStreamInitImpl<CResultView>,
	public IOleObjectImpl<CResultView>,
	public IOleControlImpl<CResultView>,
	public IOleInPlaceObjectWindowlessImpl<CResultView>,
	private Denisenko::Raskroy::Drawer
{
public:
	CResultView()
		: /*iresult(0),*/ m_Value(0)
	{
		result.sheet.rect.Length = 2800;
		result.sheet.rect.Width = 1400;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RESULTVIEW)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CResultView)
	COM_INTERFACE_ENTRY(IResultView)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
END_COM_MAP()

BEGIN_PROP_MAP(CResultView)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
	PROP_DATA_ENTRY("Value", m_Value, VT_BSTR)
END_PROP_MAP()

BEGIN_MSG_MAP(CResultView)
	CHAIN_MSG_MAP(CComControl<CResultView>)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown);
	MESSAGE_HANDLER(WM_PRINT, OnPrint);
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		MessageBox("Click");
		return 0;
	}

	LRESULT OnPrint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		return 0;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IResultView
public:
	//STDMETHOD(get_Result)(/*[out, retval]*/ IResult **pVal);
	//STDMETHOD(putref_Result)(/*[in]*/ IResult *newVal);
	HRESULT OnDraw(ATL_DRAWINFO& di);

private:
	Denisenko::Raskroy::t_parsed_result result;
	//IResult *iresult;
	BSTR m_Value;
public:
	STDMETHOD(get_Value)(BSTR* pVal);
	STDMETHOD(put_Value)(BSTR newVal);
};

#endif //__RESULTVIEW_H_
