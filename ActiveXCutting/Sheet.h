// Sheet.h : Declaration of the Sheet

#pragma once
#include "resource.h"       // main symbols
#include "../types.h"


using namespace ATL;



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// ISheet
[
	object,
	uuid("8A0A905F-99D6-4617-82ED-A69AFE0230C0"),
	dual,	helpstring("ISheet Interface"),
	pointer_default(unique)
]
__interface ISheet : IDispatch
{
	[propget, id(1), helpstring("property SizeA")] HRESULT SizeA([out, retval] CY* pVal);
	[propput, id(1), helpstring("property SizeA")] HRESULT SizeA([in] CY newVal);
	[propget, id(2), helpstring("property SizeB")] HRESULT SizeB([out, retval] CY* pVal);
	[propput, id(2), helpstring("property SizeB")] HRESULT SizeB([in] CY newVal);
};



// Sheet

[
	coclass,
	default(ISheet),
	threading(apartment),
	vi_progid("ActiveXCutting.Sheet"),
	progid("ActiveXCutting.Sheet.1"),
	version(1.0),
	uuid("6260DA6D-9679-4CE4-B8A4-103B0C45DD36"),
	helpstring("Sheet Class")
]
class ATL_NO_VTABLE Sheet :
	public ISheet
{
public:
	Sheet()
	{
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

public:
	STDMETHOD(get_SizeA)(CY* pVal)
	{
		pVal->int64 = m_part.Rect.Size[0];
		return S_OK;
	}
public:
	STDMETHOD(put_SizeA)(CY newVal)
	{
		m_part.Rect.Size[0] = newVal.int64;
		return S_OK;
	}
public:
	STDMETHOD(get_SizeB)(CY* pVal)
	{
		pVal->int64 = m_part.Rect.Size[1];
		return S_OK;
	}
public:
	STDMETHOD(put_SizeB)(CY newVal)
	{
		m_part.Rect.Size[1] = newVal.int64;
		return S_OK;
	}

private:
	Denisenko::Raskroy::Part m_part;
};
