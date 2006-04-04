// Sheets.h : Declaration of the Sheets

#pragma once
#include "resource.h"       // main symbols
#include "Sheet.h"


using namespace ATL;


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// ISheets
[
	object,
	uuid("979E8858-3D7B-4863-989E-64401B02B100"),
	dual,	helpstring("ISheets Interface"),
	pointer_default(unique)
]
__interface ISheets : IDispatch
{
	[id(DISPID_NEWENUM), propget]
	HRESULT _NewEnum([out, retval] IUnknown** ppUnk);

	[id(DISPID_VALUE), propget]
	HRESULT Item([in] long Index, [out, retval] IDispatch** pVal);

	[id(0x00000001), propget]
	HRESULT Count([out, retval] long* pVal);

	//[id(0x00000002), method]
	HRESULT Add([in] IDispatch* sheet);
};

// Store the data in a vector of ...
typedef std::vector< ATL::CComPtr<ISheet> >         ContainerType;

// The collection interface exposes the data as IDispatch
typedef IDispatch*                         CollectionExposedType;
typedef ISheets                            CollectionInterface;

// Use IEnumVARIANT as the enumerator for VB compatibility
typedef VARIANT                            EnumeratorExposedType;
typedef IEnumVARIANT                       EnumeratorInterface;

class EnumeratorCopyType
{
public :
    static void init(VARIANT* p)
    {
        VariantInit(p);
    }
    static void destroy(VARIANT* p)
    {
		VariantClear(p);
    }
    static HRESULT copy(VARIANT* pTo, const CComPtr<ISheet>* pFrom)
    {
		init(pTo);
		pTo->vt = VT_DISPATCH;
		pTo->pdispVal = *pFrom;
		pTo->pdispVal->AddRef();
		return S_OK;
    }

}; // class GenericCopy

class CollectionCopyType
{
public :
    static void init(IDispatch** p)
    {
        _CopyInterface<IDispatch>::init(p);
    }
    static void destroy(IDispatch** p)
    {
        _CopyInterface<IDispatch>::destroy(p);
    }
    static HRESULT copy(IDispatch** pTo, const CComPtr<ISheet>* pFrom)
    {
		IDispatch* sheet = *pFrom;
		return _CopyInterface<IDispatch>::copy(pTo, &sheet);
    }

}; // class GenericCopy

// Typedef the copy classes using existing typedefs
//typedef _CopyInterface<ISheet> CollectionCopyType;
//typedef _Copy<CComVariant> EnumeratorCopyType;
//typedef GenericCopy<EnumeratorExposedType, ContainerType::value_type>    EnumeratorCopyType;
//typedef GenericCopyInterface<ISheet, ISheet>    CollectionCopyType;

typedef CComEnumOnSTL< EnumeratorInterface, &__uuidof(EnumeratorInterface), EnumeratorExposedType, EnumeratorCopyType, ContainerType >    EnumeratorType;
typedef ICollectionOnSTLImpl< CollectionInterface, ContainerType, CollectionExposedType, CollectionCopyType, EnumeratorType >    CollectionType;

extern GUID LibID;

// Sheets
[
	coclass,
	default(ISheets),
	threading(apartment),
	vi_progid("ActiveXCutting.Sheets"),
	progid("ActiveXCutting.Sheets.1"),
	version(1.0),
	uuid("4CF7DFFE-084B-4BEC-A8E1-EA8205F1F844"),
	helpstring("Sheets Class")
]
class ATL_NO_VTABLE Sheets :
	public IDispatchImpl<CollectionType, &__uuidof(ISheets), &LibID>
{
public:
	Sheets()
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

	STDMETHOD(Add)(IDispatch* sheet)
	{
		CComPtr<ISheet> sheetPtr;
		HRESULT hres = sheet->QueryInterface<ISheet>(&sheetPtr);
		if(FAILED(hres))
		{
			return hres;
		}
		this->m_coll.push_back(sheetPtr);
		return S_OK;
	}

public:

};

static CComObject<Sheets> optimizer;
