// Raskroy.h : Declaration of the CRaskroy

#ifndef __RASKROY_H_
#define __RASKROY_H_

#include "resource.h"       // main symbols
#include "..\raskroy.h"

/////////////////////////////////////////////////////////////////////////////
// CRaskroy
class ATL_NO_VTABLE CRaskroy : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRaskroy, &CLSID_Raskroy>,
	public IDispatchImpl<IRaskroy, &IID_IRaskroy, &LIBID_COMRASKROYLib>,
	Denisenko::Raskroy::Raskroy
{
public:
	CRaskroy();

DECLARE_REGISTRY_RESOURCEID(IDR_RASKROY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRaskroy)
	COM_INTERFACE_ENTRY(IRaskroy)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IRaskroy
public:
	STDMETHOD(First)(ISheets *Parts, ISheets *Sheets, IResult **ppRes, BOOL *bRes);
	STDMETHOD(Next)(IResult **ppRes, BOOL *bRes);
	STDMETHOD(get_RecursionDepth)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_RecursionDepth)(/*[in]*/ short newVal);
private:
	//Denisenko::Raskroy::Monitor monitor;
	//raskroy::criteria criteria;
	HRESULT CRaskroy::FirstNextProc(class FirstNextClass &cls, /*[out]*/ IResult **pRes, /*[out, retval]*/ BOOL * bRes) throw ();
public:
	STDMETHOD(get_CutWidth)(DOUBLE* pVal);
	STDMETHOD(put_CutWidth)(DOUBLE newVal);
};

#endif //__RASKROY_H_
