// ResultView.h : Declaration of the CResultView

#ifndef __RESULTVIEW_H_
#define __RESULTVIEW_H_

#include "resource.h"       // main symbols
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CResultView
class ATL_NO_VTABLE CResultView : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IResultView, &IID_IResultView, &LIBID_COMRASKROYLib>,
	public CComControl<CResultView>,
	public IPersistStreamInitImpl<CResultView>,
	public IOleControlImpl<CResultView>,
	public IOleObjectImpl<CResultView>,
	public IOleInPlaceActiveObjectImpl<CResultView>,
	public IViewObjectExImpl<CResultView>,
	public IOleInPlaceObjectWindowlessImpl<CResultView>,
	public IPersistStorageImpl<CResultView>,
	public ISpecifyPropertyPagesImpl<CResultView>,
	public IQuickActivateImpl<CResultView>,
	public IDataObjectImpl<CResultView>,
	public IProvideClassInfo2Impl<&CLSID_ResultView, NULL, &LIBID_COMRASKROYLib>,
	public CComCoClass<CResultView, &CLSID_ResultView>,
	private raskroy::drawer
{
public:
	CResultView()
		: iresult(0)
	{
		result.sheet.rect.size[0] = 2800;
		result.sheet.rect.size[1] = 1400;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RESULTVIEW)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CResultView)
	COM_INTERFACE_ENTRY(IResultView)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

BEGIN_PROP_MAP(CResultView)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CResultView)
	CHAIN_MSG_MAP(CComControl<CResultView>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IResultView
public:
	STDMETHOD(get_Result)(/*[out, retval]*/ IResult **pVal);
	STDMETHOD(putref_Result)(/*[in]*/ IResult *newVal);

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{		
		if (!iresult)
		{
			RECT& rc = *(RECT*)di.prcBounds;
			Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

			SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
			LPCTSTR pszText = _T("No data");
			TextOut(di.hdcDraw, 
				(rc.left + rc.right) / 2, 
				(rc.top + rc.bottom) / 2, 
				pszText, 
				lstrlen(pszText));
		}
		else
		{
			reset_dc(di.hdcDraw);
			draw(di.prcBounds->right, di.prcBounds->bottom, result.parts, result.cuts, result.sheet);
		}

		return S_OK;
	}
private:
	raskroy::t_parsed_result result;
	IResult *iresult;
};

#endif //__RESULTVIEW_H_
