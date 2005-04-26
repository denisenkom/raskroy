// Result.h: Definition of the Result class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESULT_H__285418CC_C3BB_4B8D_A5FD_5F7A3606103E__INCLUDED_)
#define AFX_RESULT_H__285418CC_C3BB_4B8D_A5FD_5F7A3606103E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols
#include "raskroy.h"

/////////////////////////////////////////////////////////////////////////////
// Result

class CResult : 
	public IDispatchImpl<IResult, &IID_IResult, &LIBID_COMRASKROYLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CResult,&CLSID_Result>
{
public:
	CResult() : iparts(0), icuts(0), isheet(0), amount(0), str(SysAllocString(L"hello")) {}
BEGIN_COM_MAP(CResult)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IResult)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(Result) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_Result)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IResult
public:
	STDMETHOD(get_ParsedCuts)(/*[out, retval]*/ IParsedCuts * *pVal);
	STDMETHOD(put_ParsedCuts)(/*[in]*/ IParsedCuts * newVal);
	STDMETHOD(get_ParsedParts)(/*[out, retval]*/ IParsedParts * *pVal);
	STDMETHOD(put_ParsedParts)(/*[in]*/ IParsedParts * newVal);
	STDMETHOD(get_Amount)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Amount)(/*[in]*/ long newVal);
	STDMETHOD(get_Sheet)(/*[out, retval]*/ ISheet **pVal);
	STDMETHOD(put_Sheet)(/*[in]*/ ISheet *newVal);
private:
	IParsedCuts* icuts;
	IParsedParts* iparts;
	long amount;
	ISheet* isheet;
	BSTR str;
	raskroy::t_stat stat;
public:
	STDMETHOD(get_String)(BSTR* pVal);
	STDMETHOD(put_String)(BSTR newVal);
	STDMETHOD(get_UsefulScrap)(DOUBLE* pVal);
	STDMETHOD(put_UsefulScrap)(DOUBLE newVal);
	STDMETHOD(get_UnUsefulScrap)(DOUBLE* pVal);
	STDMETHOD(put_UnUsefulScrap)(DOUBLE newVal);
	STDMETHOD(get_UsefulNum)(long* pVal);
	STDMETHOD(put_UsefulNum)(long newVal);
	STDMETHOD(get_Opilki)(DOUBLE* pVal);
	STDMETHOD(put_Opilki)(DOUBLE newVal);
};

#endif // !defined(AFX_RESULT_H__285418CC_C3BB_4B8D_A5FD_5F7A3606103E__INCLUDED_)
