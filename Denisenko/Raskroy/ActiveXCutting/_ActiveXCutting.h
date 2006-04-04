

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Apr 03 22:29:52 2006
 */
/* Compiler settings for _ActiveXCutting.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef ___ActiveXCutting_h__
#define ___ActiveXCutting_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISheet_FWD_DEFINED__
#define __ISheet_FWD_DEFINED__
typedef interface ISheet ISheet;
#endif 	/* __ISheet_FWD_DEFINED__ */


#ifndef __ISheets_FWD_DEFINED__
#define __ISheets_FWD_DEFINED__
typedef interface ISheets ISheets;
#endif 	/* __ISheets_FWD_DEFINED__ */


#ifndef __ICuttingOptimizer_FWD_DEFINED__
#define __ICuttingOptimizer_FWD_DEFINED__
typedef interface ICuttingOptimizer ICuttingOptimizer;
#endif 	/* __ICuttingOptimizer_FWD_DEFINED__ */


#ifndef __Sheet_FWD_DEFINED__
#define __Sheet_FWD_DEFINED__

#ifdef __cplusplus
typedef class Sheet Sheet;
#else
typedef struct Sheet Sheet;
#endif /* __cplusplus */

#endif 	/* __Sheet_FWD_DEFINED__ */


#ifndef __Sheets_FWD_DEFINED__
#define __Sheets_FWD_DEFINED__

#ifdef __cplusplus
typedef class Sheets Sheets;
#else
typedef struct Sheets Sheets;
#endif /* __cplusplus */

#endif 	/* __Sheets_FWD_DEFINED__ */


#ifndef ___ICuttingOptimizerEvents_FWD_DEFINED__
#define ___ICuttingOptimizerEvents_FWD_DEFINED__
typedef interface _ICuttingOptimizerEvents _ICuttingOptimizerEvents;
#endif 	/* ___ICuttingOptimizerEvents_FWD_DEFINED__ */


#ifndef __CuttingOptimizer_FWD_DEFINED__
#define __CuttingOptimizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CuttingOptimizer CuttingOptimizer;
#else
typedef struct CuttingOptimizer CuttingOptimizer;
#endif /* __cplusplus */

#endif 	/* __CuttingOptimizer_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"
#include "objsafe.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __ISheet_INTERFACE_DEFINED__
#define __ISheet_INTERFACE_DEFINED__

/* interface ISheet */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISheet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8A0A905F-99D6-4617-82ED-A69AFE0230C0")
    ISheet : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeA( 
            /* [retval][out] */ CY *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeA( 
            /* [in] */ CY newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeB( 
            /* [retval][out] */ CY *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeB( 
            /* [in] */ CY newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISheetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISheet * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISheet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISheet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISheet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISheet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISheet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISheet * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeA )( 
            ISheet * This,
            /* [retval][out] */ CY *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeA )( 
            ISheet * This,
            /* [in] */ CY newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeB )( 
            ISheet * This,
            /* [retval][out] */ CY *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeB )( 
            ISheet * This,
            /* [in] */ CY newVal);
        
        END_INTERFACE
    } ISheetVtbl;

    interface ISheet
    {
        CONST_VTBL struct ISheetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISheet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISheet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISheet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISheet_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISheet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISheet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISheet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISheet_get_SizeA(This,pVal)	\
    (This)->lpVtbl -> get_SizeA(This,pVal)

#define ISheet_put_SizeA(This,newVal)	\
    (This)->lpVtbl -> put_SizeA(This,newVal)

#define ISheet_get_SizeB(This,pVal)	\
    (This)->lpVtbl -> get_SizeB(This,pVal)

#define ISheet_put_SizeB(This,newVal)	\
    (This)->lpVtbl -> put_SizeB(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISheet_get_SizeA_Proxy( 
    ISheet * This,
    /* [retval][out] */ CY *pVal);


void __RPC_STUB ISheet_get_SizeA_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISheet_put_SizeA_Proxy( 
    ISheet * This,
    /* [in] */ CY newVal);


void __RPC_STUB ISheet_put_SizeA_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISheet_get_SizeB_Proxy( 
    ISheet * This,
    /* [retval][out] */ CY *pVal);


void __RPC_STUB ISheet_get_SizeB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISheet_put_SizeB_Proxy( 
    ISheet * This,
    /* [in] */ CY newVal);


void __RPC_STUB ISheet_put_SizeB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISheet_INTERFACE_DEFINED__ */


#ifndef __ISheets_INTERFACE_DEFINED__
#define __ISheets_INTERFACE_DEFINED__

/* interface ISheets */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISheets;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("979E8858-3D7B-4863-989E-64401B02B100")
    ISheets : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IDispatch *sheet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISheetsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISheets * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISheets * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISheets * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISheets * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISheets * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISheets * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISheets * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ISheets * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ISheets * This,
            /* [in] */ long Index,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ISheets * This,
            /* [retval][out] */ long *pVal);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            ISheets * This,
            /* [in] */ IDispatch *sheet);
        
        END_INTERFACE
    } ISheetsVtbl;

    interface ISheets
    {
        CONST_VTBL struct ISheetsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISheets_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISheets_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISheets_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISheets_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISheets_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISheets_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISheets_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISheets_get__NewEnum(This,ppUnk)	\
    (This)->lpVtbl -> get__NewEnum(This,ppUnk)

#define ISheets_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define ISheets_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define ISheets_Add(This,sheet)	\
    (This)->lpVtbl -> Add(This,sheet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE ISheets_get__NewEnum_Proxy( 
    ISheets * This,
    /* [retval][out] */ IUnknown **ppUnk);


void __RPC_STUB ISheets_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ISheets_get_Item_Proxy( 
    ISheets * This,
    /* [in] */ long Index,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB ISheets_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ISheets_get_Count_Proxy( 
    ISheets * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB ISheets_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISheets_Add_Proxy( 
    ISheets * This,
    /* [in] */ IDispatch *sheet);


void __RPC_STUB ISheets_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISheets_INTERFACE_DEFINED__ */


#ifndef __ICuttingOptimizer_INTERFACE_DEFINED__
#define __ICuttingOptimizer_INTERFACE_DEFINED__

/* interface ICuttingOptimizer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICuttingOptimizer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AEEBC2B7-E906-4F56-AB9E-3800D3DE0C29")
    ICuttingOptimizer : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin( 
            /* [in] */ IDispatch *sheets) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICuttingOptimizerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICuttingOptimizer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICuttingOptimizer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICuttingOptimizer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICuttingOptimizer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICuttingOptimizer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICuttingOptimizer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICuttingOptimizer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *Begin )( 
            ICuttingOptimizer * This,
            /* [in] */ IDispatch *sheets);
        
        END_INTERFACE
    } ICuttingOptimizerVtbl;

    interface ICuttingOptimizer
    {
        CONST_VTBL struct ICuttingOptimizerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICuttingOptimizer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICuttingOptimizer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICuttingOptimizer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICuttingOptimizer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICuttingOptimizer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICuttingOptimizer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICuttingOptimizer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICuttingOptimizer_Begin(This,sheets)	\
    (This)->lpVtbl -> Begin(This,sheets)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICuttingOptimizer_Begin_Proxy( 
    ICuttingOptimizer * This,
    /* [in] */ IDispatch *sheets);


void __RPC_STUB ICuttingOptimizer_Begin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICuttingOptimizer_INTERFACE_DEFINED__ */



#ifndef __ActiveXCutting_LIBRARY_DEFINED__
#define __ActiveXCutting_LIBRARY_DEFINED__

/* library ActiveXCutting */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_ActiveXCutting;

EXTERN_C const CLSID CLSID_Sheet;

#ifdef __cplusplus

class DECLSPEC_UUID("6260DA6D-9679-4CE4-B8A4-103B0C45DD36")
Sheet;
#endif

EXTERN_C const CLSID CLSID_Sheets;

#ifdef __cplusplus

class DECLSPEC_UUID("4CF7DFFE-084B-4BEC-A8E1-EA8205F1F844")
Sheets;
#endif

#ifndef ___ICuttingOptimizerEvents_DISPINTERFACE_DEFINED__
#define ___ICuttingOptimizerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ICuttingOptimizerEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ICuttingOptimizerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B4C90F66-1B62-4D31-9B2C-3D5253EFA41A")
    _ICuttingOptimizerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICuttingOptimizerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ICuttingOptimizerEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ICuttingOptimizerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ICuttingOptimizerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ICuttingOptimizerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ICuttingOptimizerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ICuttingOptimizerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ICuttingOptimizerEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ICuttingOptimizerEventsVtbl;

    interface _ICuttingOptimizerEvents
    {
        CONST_VTBL struct _ICuttingOptimizerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICuttingOptimizerEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ICuttingOptimizerEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ICuttingOptimizerEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ICuttingOptimizerEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ICuttingOptimizerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ICuttingOptimizerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ICuttingOptimizerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICuttingOptimizerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CuttingOptimizer;

#ifdef __cplusplus

class DECLSPEC_UUID("2A7AE3A2-DB4D-4E01-A5FE-2DF875F8C8D0")
CuttingOptimizer;
#endif
#endif /* __ActiveXCutting_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


