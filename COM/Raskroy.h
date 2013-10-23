#ifndef __RASKROY_H_
#define __RASKROY_H_

#include "resource.h"
#include "..\results_generator.h"

class ATL_NO_VTABLE CRaskroy : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRaskroy, &CLSID_Raskroy>,
	public IDispatchImpl<IRaskroy, &IID_IRaskroy, &LIBID_COMRASKROYLib>,
	Denisenko::Raskroy::ResultsGenerator
{
public:
	CRaskroy();

DECLARE_REGISTRY_RESOURCEID(IDR_RASKROY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRaskroy)
	COM_INTERFACE_ENTRY(IRaskroy)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

public:
	STDMETHOD(Begin)(ISheets *Parts, ISheets *Sheets);
	STDMETHOD(NextResult)(IResult **ppRes, BOOL *bRes);
	STDMETHOD(get_CutWidth)(DOUBLE* pVal);
	STDMETHOD(put_CutWidth)(DOUBLE newVal);
};

#endif //__RASKROY_H_
