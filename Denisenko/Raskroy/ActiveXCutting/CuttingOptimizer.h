// CuttingOptimizer.h : Declaration of the CuttingOptimizer

#pragma once
#include "resource.h"       // main symbols
#include "../raskroy.h"
#include "Sheets.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// ICuttingOptimizer
[
	object,
	uuid("AEEBC2B7-E906-4F56-AB9E-3800D3DE0C29"),
	dual,	helpstring("ICuttingOptimizer Interface"),
	pointer_default(unique)
]
__interface ICuttingOptimizer : IDispatch
{
	HRESULT Begin(IDispatch* sheets);
};


// _ICuttingOptimizerEvents
[
	dispinterface,
	uuid("B4C90F66-1B62-4D31-9B2C-3D5253EFA41A"),
	helpstring("_ICuttingOptimizerEvents Interface")
]
__interface _ICuttingOptimizerEvents
{
};


// CuttingOptimizer

[
	coclass,
	default(ICuttingOptimizer, _ICuttingOptimizerEvents),
	threading(apartment),
	support_error_info("ICuttingOptimizer"),
	event_source(com),
	vi_progid("ActiveXCutting.CuttingOptimizer"),
	progid("ActiveXCutting.CuttingOptimizer.1"),
	version(1.0),
	uuid("2A7AE3A2-DB4D-4E01-A5FE-2DF875F8C8D0"),
	helpstring("CuttingOptimizer Class")
]
class ATL_NO_VTABLE CuttingOptimizer :
	public ICuttingOptimizer
{
public:
	CuttingOptimizer()
	{
	}

	__event __interface _ICuttingOptimizerEvents;


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	STDMETHOD(Begin)(IDispatch* sheets)
	{
		return sheets->QueryInterface<ISheets>(&m_sheets);
	}

private:
	Denisenko::Raskroy::Raskroy m_optimizer;
	CComPtr<ISheets> m_sheets;
};
