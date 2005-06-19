#ifndef __SHEETS_H_
#define __SHEETS_H_

#include "resource.h"
#include "..\common.h"

// Store the data in a vector of std::strings
typedef std::vector<CComVariant>         ContainerType;

// Use IEnumVARIANT as the enumerator for VB compatibility
typedef VARIANT                            EnumeratorExposedType;
typedef IEnumVARIANT                       EnumeratorInterface;
typedef _Copy<VARIANT> EnumeratorCopyType;
typedef CComEnumOnSTL< EnumeratorInterface, &__uuidof(EnumeratorInterface), EnumeratorExposedType, EnumeratorCopyType, ContainerType >    EnumeratorType;

// The collection interface exposes the data as BSTRs
typedef VARIANT                            CollectionExposedType;
typedef ISheets                            CollectionInterface;
typedef _Copy<VARIANT> CollectionCopyType;
typedef ICollectionOnSTLImpl< CollectionInterface, ContainerType, CollectionExposedType, CollectionCopyType, EnumeratorType >    CollectionType;

//typedef CComEnumOnSTL< IEnumVARIANT, &__uuidof(IEnumVARIANT), IDispatch*, _CopyInterface<IDispatch>, std::vector<IDispatch*> > EnumeratorType;
//typedef ICollectionOnSTLImpl< ISheets, std::vector<IDispatch*>, IDispatch*, _CopyInterface<IDispatch>, EnumeratorType > CollectionType;


class ATL_NO_VTABLE CSheets : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSheets, &CLSID_Sheets>,
	public IDispatchImpl<CollectionType, &IID_ISheets, &LIBID_COMRASKROYLib>
{
public:
	CSheets() {};

	~CSheets() {};

DECLARE_REGISTRY_RESOURCEID(IDR_SHEETS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSheets)
	COM_INTERFACE_ENTRY(ISheets)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	STDMETHODIMP put_Item(long index, VARIANT item) {
		if(index < 0)
			return E_INVALIDARG;
		if(size_t(index) >= m_coll.size())
			m_coll.resize(index + 1);
		m_coll.insert(m_coll.begin() + index, item);
		return S_OK;
	}

	STDMETHODIMP Add(VARIANT sheet) {
		m_coll.push_back(sheet);
		return S_OK;
	}

	STDMETHODIMP Add2(DOUBLE length, DOUBLE width, long amount, BOOL rotate) {
		return S_OK;
	}
};

#endif //__SHEETS_H_
