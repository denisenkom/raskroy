/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Nov 28 16:33:09 2003
 */
/* Compiler settings for C:\GILOTINE\MsVC\COMRaskroy\COMRaskroy.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
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

#ifndef __COMRaskroy_h__
#define __COMRaskroy_h__

#ifdef __cplusplus
extern "C"{
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


#ifndef __IParsedPart_FWD_DEFINED__
#define __IParsedPart_FWD_DEFINED__
typedef interface IParsedPart IParsedPart;
#endif 	/* __IParsedPart_FWD_DEFINED__ */


#ifndef __IParsedCut_FWD_DEFINED__
#define __IParsedCut_FWD_DEFINED__
typedef interface IParsedCut IParsedCut;
#endif 	/* __IParsedCut_FWD_DEFINED__ */


#ifndef __IParsedParts_FWD_DEFINED__
#define __IParsedParts_FWD_DEFINED__
typedef interface IParsedParts IParsedParts;
#endif 	/* __IParsedParts_FWD_DEFINED__ */


#ifndef __IParsedCuts_FWD_DEFINED__
#define __IParsedCuts_FWD_DEFINED__
typedef interface IParsedCuts IParsedCuts;
#endif 	/* __IParsedCuts_FWD_DEFINED__ */


#ifndef __IStatistic_FWD_DEFINED__
#define __IStatistic_FWD_DEFINED__
typedef interface IStatistic IStatistic;
#endif 	/* __IStatistic_FWD_DEFINED__ */


#ifndef __IResult_FWD_DEFINED__
#define __IResult_FWD_DEFINED__
typedef interface IResult IResult;
#endif 	/* __IResult_FWD_DEFINED__ */


#ifndef __IResultView_FWD_DEFINED__
#define __IResultView_FWD_DEFINED__
typedef interface IResultView IResultView;
#endif 	/* __IResultView_FWD_DEFINED__ */


#ifndef __IRaskroy_FWD_DEFINED__
#define __IRaskroy_FWD_DEFINED__
typedef interface IRaskroy IRaskroy;
#endif 	/* __IRaskroy_FWD_DEFINED__ */


#ifndef __Raskroy_FWD_DEFINED__
#define __Raskroy_FWD_DEFINED__

#ifdef __cplusplus
typedef class Raskroy Raskroy;
#else
typedef struct Raskroy Raskroy;
#endif /* __cplusplus */

#endif 	/* __Raskroy_FWD_DEFINED__ */


#ifndef __Sheets_FWD_DEFINED__
#define __Sheets_FWD_DEFINED__

#ifdef __cplusplus
typedef class Sheets Sheets;
#else
typedef struct Sheets Sheets;
#endif /* __cplusplus */

#endif 	/* __Sheets_FWD_DEFINED__ */


#ifndef __Result_FWD_DEFINED__
#define __Result_FWD_DEFINED__

#ifdef __cplusplus
typedef class Result Result;
#else
typedef struct Result Result;
#endif /* __cplusplus */

#endif 	/* __Result_FWD_DEFINED__ */


#ifndef __Sheet_FWD_DEFINED__
#define __Sheet_FWD_DEFINED__

#ifdef __cplusplus
typedef class Sheet Sheet;
#else
typedef struct Sheet Sheet;
#endif /* __cplusplus */

#endif 	/* __Sheet_FWD_DEFINED__ */


#ifndef __ResultView_FWD_DEFINED__
#define __ResultView_FWD_DEFINED__

#ifdef __cplusplus
typedef class ResultView ResultView;
#else
typedef struct ResultView ResultView;
#endif /* __cplusplus */

#endif 	/* __ResultView_FWD_DEFINED__ */


#ifndef __ParsedPart_FWD_DEFINED__
#define __ParsedPart_FWD_DEFINED__

#ifdef __cplusplus
typedef class ParsedPart ParsedPart;
#else
typedef struct ParsedPart ParsedPart;
#endif /* __cplusplus */

#endif 	/* __ParsedPart_FWD_DEFINED__ */


#ifndef __ParsedCut_FWD_DEFINED__
#define __ParsedCut_FWD_DEFINED__

#ifdef __cplusplus
typedef class ParsedCut ParsedCut;
#else
typedef struct ParsedCut ParsedCut;
#endif /* __cplusplus */

#endif 	/* __ParsedCut_FWD_DEFINED__ */


#ifndef __ParsedParts_FWD_DEFINED__
#define __ParsedParts_FWD_DEFINED__

#ifdef __cplusplus
typedef class ParsedParts ParsedParts;
#else
typedef struct ParsedParts ParsedParts;
#endif /* __cplusplus */

#endif 	/* __ParsedParts_FWD_DEFINED__ */


#ifndef __ParsedCuts_FWD_DEFINED__
#define __ParsedCuts_FWD_DEFINED__

#ifdef __cplusplus
typedef class ParsedCuts ParsedCuts;
#else
typedef struct ParsedCuts ParsedCuts;
#endif /* __cplusplus */

#endif 	/* __ParsedCuts_FWD_DEFINED__ */


#ifndef __Statistic_FWD_DEFINED__
#define __Statistic_FWD_DEFINED__

#ifdef __cplusplus
typedef class Statistic Statistic;
#else
typedef struct Statistic Statistic;
#endif /* __cplusplus */

#endif 	/* __Statistic_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ISheet_INTERFACE_DEFINED__
#define __ISheet_INTERFACE_DEFINED__

/* interface ISheet */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISheet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58EBA5A6-FC50-49F9-9D01-D9CDF15C677E")
    ISheet : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Length( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Amount( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Amount( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rotate( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rotate( 
            /* [in] */ BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISheetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISheet __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISheet __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISheet __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISheet __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISheet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISheet __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Length )( 
            ISheet __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Length )( 
            ISheet __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            ISheet __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            ISheet __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Amount )( 
            ISheet __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Amount )( 
            ISheet __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Rotate )( 
            ISheet __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Rotate )( 
            ISheet __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        END_INTERFACE
    } ISheetVtbl;

    interface ISheet
    {
        CONST_VTBL struct ISheetVtbl __RPC_FAR *lpVtbl;
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


#define ISheet_get_Length(This,pVal)	\
    (This)->lpVtbl -> get_Length(This,pVal)

#define ISheet_put_Length(This,newVal)	\
    (This)->lpVtbl -> put_Length(This,newVal)

#define ISheet_get_Width(This,pVal)	\
    (This)->lpVtbl -> get_Width(This,pVal)

#define ISheet_put_Width(This,newVal)	\
    (This)->lpVtbl -> put_Width(This,newVal)

#define ISheet_get_Amount(This,pVal)	\
    (This)->lpVtbl -> get_Amount(This,pVal)

#define ISheet_put_Amount(This,newVal)	\
    (This)->lpVtbl -> put_Amount(This,newVal)

#define ISheet_get_Rotate(This,pVal)	\
    (This)->lpVtbl -> get_Rotate(This,pVal)

#define ISheet_put_Rotate(This,newVal)	\
    (This)->lpVtbl -> put_Rotate(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISheet_get_Length_Proxy( 
    ISheet __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ISheet_get_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISheet_put_Length_Proxy( 
    ISheet __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ISheet_put_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISheet_get_Width_Proxy( 
    ISheet __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ISheet_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISheet_put_Width_Proxy( 
    ISheet __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ISheet_put_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISheet_get_Amount_Proxy( 
    ISheet __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISheet_get_Amount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISheet_put_Amount_Proxy( 
    ISheet __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISheet_put_Amount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISheet_get_Rotate_Proxy( 
    ISheet __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB ISheet_get_Rotate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISheet_put_Rotate_Proxy( 
    ISheet __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB ISheet_put_Rotate_Stub(
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
    
    MIDL_INTERFACE("00CF5F84-9E33-4798-AD68-24017A4E3F2F")
    ISheets : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ ISheet __RPC_FAR *Sheet) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ ISheet __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Item( 
            /* [in] */ long Index,
            /* [in] */ ISheet __RPC_FAR *pnewVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISheetsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISheets __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISheets __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISheets __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISheets __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISheets __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISheets __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISheets __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            ISheets __RPC_FAR * This,
            /* [in] */ ISheet __RPC_FAR *Sheet);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            ISheets __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            ISheets __RPC_FAR * This,
            /* [in] */ long Index,
            /* [retval][out] */ ISheet __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Item )( 
            ISheets __RPC_FAR * This,
            /* [in] */ long Index,
            /* [in] */ ISheet __RPC_FAR *pnewVal);
        
        END_INTERFACE
    } ISheetsVtbl;

    interface ISheets
    {
        CONST_VTBL struct ISheetsVtbl __RPC_FAR *lpVtbl;
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


#define ISheets_Add(This,Sheet)	\
    (This)->lpVtbl -> Add(This,Sheet)

#define ISheets_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define ISheets_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define ISheets_put_Item(This,Index,pnewVal)	\
    (This)->lpVtbl -> put_Item(This,Index,pnewVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISheets_Add_Proxy( 
    ISheets __RPC_FAR * This,
    /* [in] */ ISheet __RPC_FAR *Sheet);


void __RPC_STUB ISheets_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISheets_get_Count_Proxy( 
    ISheets __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISheets_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISheets_get_Item_Proxy( 
    ISheets __RPC_FAR * This,
    /* [in] */ long Index,
    /* [retval][out] */ ISheet __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ISheets_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISheets_put_Item_Proxy( 
    ISheets __RPC_FAR * This,
    /* [in] */ long Index,
    /* [in] */ ISheet __RPC_FAR *pnewVal);


void __RPC_STUB ISheets_put_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISheets_INTERFACE_DEFINED__ */


#ifndef __IParsedPart_INTERFACE_DEFINED__
#define __IParsedPart_INTERFACE_DEFINED__

/* interface IParsedPart */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IParsedPart;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6806208-1C74-4C4E-AE00-A0AB298A2DFE")
    IParsedPart : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_X( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_X( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Y( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Y( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Length( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IParsedPartVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IParsedPart __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IParsedPart __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IParsedPart __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IParsedPart __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IParsedPart __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IParsedPart __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IParsedPart __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_X )( 
            IParsedPart __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_X )( 
            IParsedPart __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Y )( 
            IParsedPart __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Y )( 
            IParsedPart __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Length )( 
            IParsedPart __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Length )( 
            IParsedPart __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Width )( 
            IParsedPart __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Width )( 
            IParsedPart __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IParsedPartVtbl;

    interface IParsedPart
    {
        CONST_VTBL struct IParsedPartVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParsedPart_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IParsedPart_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IParsedPart_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IParsedPart_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IParsedPart_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IParsedPart_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IParsedPart_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IParsedPart_get_X(This,pVal)	\
    (This)->lpVtbl -> get_X(This,pVal)

#define IParsedPart_put_X(This,newVal)	\
    (This)->lpVtbl -> put_X(This,newVal)

#define IParsedPart_get_Y(This,pVal)	\
    (This)->lpVtbl -> get_Y(This,pVal)

#define IParsedPart_put_Y(This,newVal)	\
    (This)->lpVtbl -> put_Y(This,newVal)

#define IParsedPart_get_Length(This,pVal)	\
    (This)->lpVtbl -> get_Length(This,pVal)

#define IParsedPart_put_Length(This,newVal)	\
    (This)->lpVtbl -> put_Length(This,newVal)

#define IParsedPart_get_Width(This,pVal)	\
    (This)->lpVtbl -> get_Width(This,pVal)

#define IParsedPart_put_Width(This,newVal)	\
    (This)->lpVtbl -> put_Width(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedPart_get_X_Proxy( 
    IParsedPart __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IParsedPart_get_X_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedPart_put_X_Proxy( 
    IParsedPart __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IParsedPart_put_X_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedPart_get_Y_Proxy( 
    IParsedPart __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IParsedPart_get_Y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedPart_put_Y_Proxy( 
    IParsedPart __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IParsedPart_put_Y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedPart_get_Length_Proxy( 
    IParsedPart __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IParsedPart_get_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedPart_put_Length_Proxy( 
    IParsedPart __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IParsedPart_put_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedPart_get_Width_Proxy( 
    IParsedPart __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IParsedPart_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedPart_put_Width_Proxy( 
    IParsedPart __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IParsedPart_put_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IParsedPart_INTERFACE_DEFINED__ */


#ifndef __IParsedCut_INTERFACE_DEFINED__
#define __IParsedCut_INTERFACE_DEFINED__

/* interface IParsedCut */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IParsedCut;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33D428BC-D123-4DBB-AE87-A21A2DA7EDF3")
    IParsedCut : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_X( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_X( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Y( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Y( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_S( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_S( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Length( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IParsedCutVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IParsedCut __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IParsedCut __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IParsedCut __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IParsedCut __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IParsedCut __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IParsedCut __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IParsedCut __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_X )( 
            IParsedCut __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_X )( 
            IParsedCut __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Y )( 
            IParsedCut __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Y )( 
            IParsedCut __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_S )( 
            IParsedCut __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_S )( 
            IParsedCut __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Length )( 
            IParsedCut __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Length )( 
            IParsedCut __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IParsedCutVtbl;

    interface IParsedCut
    {
        CONST_VTBL struct IParsedCutVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParsedCut_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IParsedCut_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IParsedCut_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IParsedCut_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IParsedCut_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IParsedCut_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IParsedCut_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IParsedCut_get_X(This,pVal)	\
    (This)->lpVtbl -> get_X(This,pVal)

#define IParsedCut_put_X(This,newVal)	\
    (This)->lpVtbl -> put_X(This,newVal)

#define IParsedCut_get_Y(This,pVal)	\
    (This)->lpVtbl -> get_Y(This,pVal)

#define IParsedCut_put_Y(This,newVal)	\
    (This)->lpVtbl -> put_Y(This,newVal)

#define IParsedCut_get_S(This,pVal)	\
    (This)->lpVtbl -> get_S(This,pVal)

#define IParsedCut_put_S(This,newVal)	\
    (This)->lpVtbl -> put_S(This,newVal)

#define IParsedCut_get_Length(This,pVal)	\
    (This)->lpVtbl -> get_Length(This,pVal)

#define IParsedCut_put_Length(This,newVal)	\
    (This)->lpVtbl -> put_Length(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedCut_get_X_Proxy( 
    IParsedCut __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IParsedCut_get_X_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedCut_put_X_Proxy( 
    IParsedCut __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IParsedCut_put_X_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedCut_get_Y_Proxy( 
    IParsedCut __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IParsedCut_get_Y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedCut_put_Y_Proxy( 
    IParsedCut __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IParsedCut_put_Y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedCut_get_S_Proxy( 
    IParsedCut __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IParsedCut_get_S_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedCut_put_S_Proxy( 
    IParsedCut __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IParsedCut_put_S_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedCut_get_Length_Proxy( 
    IParsedCut __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IParsedCut_get_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedCut_put_Length_Proxy( 
    IParsedCut __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IParsedCut_put_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IParsedCut_INTERFACE_DEFINED__ */


#ifndef __IParsedParts_INTERFACE_DEFINED__
#define __IParsedParts_INTERFACE_DEFINED__

/* interface IParsedParts */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IParsedParts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3ABDE08B-93E3-480E-96D3-0ACA19DA7AED")
    IParsedParts : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            long Index,
            /* [retval][out] */ IParsedPart __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Item( 
            long Index,
            /* [in] */ IParsedPart __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            IParsedPart __RPC_FAR *Part) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IParsedPartsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IParsedParts __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IParsedParts __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IParsedParts __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IParsedParts __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IParsedParts __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IParsedParts __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IParsedParts __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IParsedParts __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IParsedParts __RPC_FAR * This,
            long Index,
            /* [retval][out] */ IParsedPart __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Item )( 
            IParsedParts __RPC_FAR * This,
            long Index,
            /* [in] */ IParsedPart __RPC_FAR *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IParsedParts __RPC_FAR * This,
            IParsedPart __RPC_FAR *Part);
        
        END_INTERFACE
    } IParsedPartsVtbl;

    interface IParsedParts
    {
        CONST_VTBL struct IParsedPartsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParsedParts_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IParsedParts_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IParsedParts_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IParsedParts_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IParsedParts_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IParsedParts_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IParsedParts_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IParsedParts_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IParsedParts_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define IParsedParts_put_Item(This,Index,newVal)	\
    (This)->lpVtbl -> put_Item(This,Index,newVal)

#define IParsedParts_Add(This,Part)	\
    (This)->lpVtbl -> Add(This,Part)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedParts_get_Count_Proxy( 
    IParsedParts __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IParsedParts_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedParts_get_Item_Proxy( 
    IParsedParts __RPC_FAR * This,
    long Index,
    /* [retval][out] */ IParsedPart __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IParsedParts_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedParts_put_Item_Proxy( 
    IParsedParts __RPC_FAR * This,
    long Index,
    /* [in] */ IParsedPart __RPC_FAR *newVal);


void __RPC_STUB IParsedParts_put_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IParsedParts_Add_Proxy( 
    IParsedParts __RPC_FAR * This,
    IParsedPart __RPC_FAR *Part);


void __RPC_STUB IParsedParts_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IParsedParts_INTERFACE_DEFINED__ */


#ifndef __IParsedCuts_INTERFACE_DEFINED__
#define __IParsedCuts_INTERFACE_DEFINED__

/* interface IParsedCuts */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IParsedCuts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FCE1C030-1780-49B2-9371-CBE6B625D6F4")
    IParsedCuts : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            long Index,
            /* [retval][out] */ IParsedCut __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Item( 
            long Index,
            /* [in] */ IParsedCut __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            IParsedCut __RPC_FAR *Cut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IParsedCutsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IParsedCuts __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IParsedCuts __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IParsedCuts __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IParsedCuts __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IParsedCuts __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IParsedCuts __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IParsedCuts __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IParsedCuts __RPC_FAR * This,
            long Index,
            /* [retval][out] */ IParsedCut __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Item )( 
            IParsedCuts __RPC_FAR * This,
            long Index,
            /* [in] */ IParsedCut __RPC_FAR *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IParsedCuts __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IParsedCuts __RPC_FAR * This,
            IParsedCut __RPC_FAR *Cut);
        
        END_INTERFACE
    } IParsedCutsVtbl;

    interface IParsedCuts
    {
        CONST_VTBL struct IParsedCutsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParsedCuts_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IParsedCuts_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IParsedCuts_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IParsedCuts_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IParsedCuts_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IParsedCuts_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IParsedCuts_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IParsedCuts_get_Item(This,Index,pVal)	\
    (This)->lpVtbl -> get_Item(This,Index,pVal)

#define IParsedCuts_put_Item(This,Index,newVal)	\
    (This)->lpVtbl -> put_Item(This,Index,newVal)

#define IParsedCuts_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IParsedCuts_Add(This,Cut)	\
    (This)->lpVtbl -> Add(This,Cut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedCuts_get_Item_Proxy( 
    IParsedCuts __RPC_FAR * This,
    long Index,
    /* [retval][out] */ IParsedCut __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IParsedCuts_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IParsedCuts_put_Item_Proxy( 
    IParsedCuts __RPC_FAR * This,
    long Index,
    /* [in] */ IParsedCut __RPC_FAR *newVal);


void __RPC_STUB IParsedCuts_put_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IParsedCuts_get_Count_Proxy( 
    IParsedCuts __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IParsedCuts_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IParsedCuts_Add_Proxy( 
    IParsedCuts __RPC_FAR * This,
    IParsedCut __RPC_FAR *Cut);


void __RPC_STUB IParsedCuts_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IParsedCuts_INTERFACE_DEFINED__ */


#ifndef __IStatistic_INTERFACE_DEFINED__
#define __IStatistic_INTERFACE_DEFINED__

/* interface IStatistic */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStatistic;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5D0F5976-87CE-4434-BAC6-849F3D1A76D9")
    IStatistic : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SumCutLength( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SumCutLength( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SumRemain( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SumRemain( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStatisticVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IStatistic __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IStatistic __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IStatistic __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IStatistic __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IStatistic __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IStatistic __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IStatistic __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SumCutLength )( 
            IStatistic __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SumCutLength )( 
            IStatistic __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SumRemain )( 
            IStatistic __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SumRemain )( 
            IStatistic __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IStatisticVtbl;

    interface IStatistic
    {
        CONST_VTBL struct IStatisticVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStatistic_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStatistic_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStatistic_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStatistic_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStatistic_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStatistic_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStatistic_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStatistic_get_SumCutLength(This,pVal)	\
    (This)->lpVtbl -> get_SumCutLength(This,pVal)

#define IStatistic_put_SumCutLength(This,newVal)	\
    (This)->lpVtbl -> put_SumCutLength(This,newVal)

#define IStatistic_get_SumRemain(This,pVal)	\
    (This)->lpVtbl -> get_SumRemain(This,pVal)

#define IStatistic_put_SumRemain(This,newVal)	\
    (This)->lpVtbl -> put_SumRemain(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IStatistic_get_SumCutLength_Proxy( 
    IStatistic __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IStatistic_get_SumCutLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IStatistic_put_SumCutLength_Proxy( 
    IStatistic __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IStatistic_put_SumCutLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IStatistic_get_SumRemain_Proxy( 
    IStatistic __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IStatistic_get_SumRemain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IStatistic_put_SumRemain_Proxy( 
    IStatistic __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IStatistic_put_SumRemain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStatistic_INTERFACE_DEFINED__ */


#ifndef __IResult_INTERFACE_DEFINED__
#define __IResult_INTERFACE_DEFINED__

/* interface IResult */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BB7C7109-1239-4938-B571-8DCBC6AEF1C7")
    IResult : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sheet( 
            /* [retval][out] */ ISheet __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sheet( 
            /* [in] */ ISheet __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Amount( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Amount( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParsedParts( 
            /* [retval][out] */ IParsedParts __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParsedCuts( 
            /* [retval][out] */ IParsedCuts __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Statistic( 
            /* [retval][out] */ IStatistic __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Statistic( 
            /* [in] */ IStatistic __RPC_FAR *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IResult __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IResult __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IResult __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IResult __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IResult __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IResult __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IResult __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Sheet )( 
            IResult __RPC_FAR * This,
            /* [retval][out] */ ISheet __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Sheet )( 
            IResult __RPC_FAR * This,
            /* [in] */ ISheet __RPC_FAR *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Amount )( 
            IResult __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Amount )( 
            IResult __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ParsedParts )( 
            IResult __RPC_FAR * This,
            /* [retval][out] */ IParsedParts __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ParsedCuts )( 
            IResult __RPC_FAR * This,
            /* [retval][out] */ IParsedCuts __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Statistic )( 
            IResult __RPC_FAR * This,
            /* [retval][out] */ IStatistic __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Statistic )( 
            IResult __RPC_FAR * This,
            /* [in] */ IStatistic __RPC_FAR *newVal);
        
        END_INTERFACE
    } IResultVtbl;

    interface IResult
    {
        CONST_VTBL struct IResultVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IResult_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IResult_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IResult_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IResult_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IResult_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IResult_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IResult_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IResult_get_Sheet(This,pVal)	\
    (This)->lpVtbl -> get_Sheet(This,pVal)

#define IResult_put_Sheet(This,newVal)	\
    (This)->lpVtbl -> put_Sheet(This,newVal)

#define IResult_get_Amount(This,pVal)	\
    (This)->lpVtbl -> get_Amount(This,pVal)

#define IResult_put_Amount(This,newVal)	\
    (This)->lpVtbl -> put_Amount(This,newVal)

#define IResult_get_ParsedParts(This,pVal)	\
    (This)->lpVtbl -> get_ParsedParts(This,pVal)

#define IResult_get_ParsedCuts(This,pVal)	\
    (This)->lpVtbl -> get_ParsedCuts(This,pVal)

#define IResult_get_Statistic(This,pVal)	\
    (This)->lpVtbl -> get_Statistic(This,pVal)

#define IResult_put_Statistic(This,newVal)	\
    (This)->lpVtbl -> put_Statistic(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IResult_get_Sheet_Proxy( 
    IResult __RPC_FAR * This,
    /* [retval][out] */ ISheet __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IResult_get_Sheet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IResult_put_Sheet_Proxy( 
    IResult __RPC_FAR * This,
    /* [in] */ ISheet __RPC_FAR *newVal);


void __RPC_STUB IResult_put_Sheet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IResult_get_Amount_Proxy( 
    IResult __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IResult_get_Amount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IResult_put_Amount_Proxy( 
    IResult __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IResult_put_Amount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IResult_get_ParsedParts_Proxy( 
    IResult __RPC_FAR * This,
    /* [retval][out] */ IParsedParts __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IResult_get_ParsedParts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IResult_get_ParsedCuts_Proxy( 
    IResult __RPC_FAR * This,
    /* [retval][out] */ IParsedCuts __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IResult_get_ParsedCuts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IResult_get_Statistic_Proxy( 
    IResult __RPC_FAR * This,
    /* [retval][out] */ IStatistic __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IResult_get_Statistic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IResult_put_Statistic_Proxy( 
    IResult __RPC_FAR * This,
    /* [in] */ IStatistic __RPC_FAR *newVal);


void __RPC_STUB IResult_put_Statistic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IResult_INTERFACE_DEFINED__ */


#ifndef __IResultView_INTERFACE_DEFINED__
#define __IResultView_INTERFACE_DEFINED__

/* interface IResultView */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IResultView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("254327C9-7706-47D3-9770-117DDF4B0597")
    IResultView : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Result( 
            /* [retval][out] */ IResult __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Result( 
            /* [in] */ IResult __RPC_FAR *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IResultViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IResultView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IResultView __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IResultView __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IResultView __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IResultView __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IResultView __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IResultView __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Result )( 
            IResultView __RPC_FAR * This,
            /* [retval][out] */ IResult __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Result )( 
            IResultView __RPC_FAR * This,
            /* [in] */ IResult __RPC_FAR *newVal);
        
        END_INTERFACE
    } IResultViewVtbl;

    interface IResultView
    {
        CONST_VTBL struct IResultViewVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IResultView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IResultView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IResultView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IResultView_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IResultView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IResultView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IResultView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IResultView_get_Result(This,pVal)	\
    (This)->lpVtbl -> get_Result(This,pVal)

#define IResultView_putref_Result(This,newVal)	\
    (This)->lpVtbl -> putref_Result(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IResultView_get_Result_Proxy( 
    IResultView __RPC_FAR * This,
    /* [retval][out] */ IResult __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IResultView_get_Result_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IResultView_putref_Result_Proxy( 
    IResultView __RPC_FAR * This,
    /* [in] */ IResult __RPC_FAR *newVal);


void __RPC_STUB IResultView_putref_Result_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IResultView_INTERFACE_DEFINED__ */


#ifndef __IRaskroy_INTERFACE_DEFINED__
#define __IRaskroy_INTERFACE_DEFINED__

/* interface IRaskroy */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRaskroy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8DFC4AFF-69C1-4D5F-A0EB-832650D32326")
    IRaskroy : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecursionDepth( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RecursionDepth( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE First( 
            /* [in] */ ISheets __RPC_FAR *Parts,
            /* [in] */ ISheets __RPC_FAR *Sheets,
            /* [ref][out] */ IResult __RPC_FAR *__RPC_FAR *Result,
            /* [retval][out] */ BOOL __RPC_FAR *Res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [ref][out] */ IResult __RPC_FAR *__RPC_FAR *Result,
            /* [retval][out] */ BOOL __RPC_FAR *Res) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRaskroyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRaskroy __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRaskroy __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRaskroy __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRaskroy __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRaskroy __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRaskroy __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRaskroy __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RecursionDepth )( 
            IRaskroy __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RecursionDepth )( 
            IRaskroy __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *First )( 
            IRaskroy __RPC_FAR * This,
            /* [in] */ ISheets __RPC_FAR *Parts,
            /* [in] */ ISheets __RPC_FAR *Sheets,
            /* [ref][out] */ IResult __RPC_FAR *__RPC_FAR *Result,
            /* [retval][out] */ BOOL __RPC_FAR *Res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IRaskroy __RPC_FAR * This,
            /* [ref][out] */ IResult __RPC_FAR *__RPC_FAR *Result,
            /* [retval][out] */ BOOL __RPC_FAR *Res);
        
        END_INTERFACE
    } IRaskroyVtbl;

    interface IRaskroy
    {
        CONST_VTBL struct IRaskroyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRaskroy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRaskroy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRaskroy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRaskroy_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRaskroy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRaskroy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRaskroy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRaskroy_get_RecursionDepth(This,pVal)	\
    (This)->lpVtbl -> get_RecursionDepth(This,pVal)

#define IRaskroy_put_RecursionDepth(This,newVal)	\
    (This)->lpVtbl -> put_RecursionDepth(This,newVal)

#define IRaskroy_First(This,Parts,Sheets,Result,Res)	\
    (This)->lpVtbl -> First(This,Parts,Sheets,Result,Res)

#define IRaskroy_Next(This,Result,Res)	\
    (This)->lpVtbl -> Next(This,Result,Res)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IRaskroy_get_RecursionDepth_Proxy( 
    IRaskroy __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IRaskroy_get_RecursionDepth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IRaskroy_put_RecursionDepth_Proxy( 
    IRaskroy __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IRaskroy_put_RecursionDepth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRaskroy_First_Proxy( 
    IRaskroy __RPC_FAR * This,
    /* [in] */ ISheets __RPC_FAR *Parts,
    /* [in] */ ISheets __RPC_FAR *Sheets,
    /* [ref][out] */ IResult __RPC_FAR *__RPC_FAR *Result,
    /* [retval][out] */ BOOL __RPC_FAR *Res);


void __RPC_STUB IRaskroy_First_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRaskroy_Next_Proxy( 
    IRaskroy __RPC_FAR * This,
    /* [ref][out] */ IResult __RPC_FAR *__RPC_FAR *Result,
    /* [retval][out] */ BOOL __RPC_FAR *Res);


void __RPC_STUB IRaskroy_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRaskroy_INTERFACE_DEFINED__ */



#ifndef __COMRASKROYLib_LIBRARY_DEFINED__
#define __COMRASKROYLib_LIBRARY_DEFINED__

/* library COMRASKROYLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_COMRASKROYLib;

EXTERN_C const CLSID CLSID_Raskroy;

#ifdef __cplusplus

class DECLSPEC_UUID("1659A58C-EE79-4303-B273-23390FD76749")
Raskroy;
#endif

EXTERN_C const CLSID CLSID_Sheets;

#ifdef __cplusplus

class DECLSPEC_UUID("CCAAFCDD-889A-4B76-97A0-8DED964E2A0D")
Sheets;
#endif

EXTERN_C const CLSID CLSID_Result;

#ifdef __cplusplus

class DECLSPEC_UUID("82158893-1A25-4BF2-8964-455215D48D07")
Result;
#endif

EXTERN_C const CLSID CLSID_Sheet;

#ifdef __cplusplus

class DECLSPEC_UUID("C4A512A1-F77B-4308-8EC0-4BCDF97D4FD7")
Sheet;
#endif

EXTERN_C const CLSID CLSID_ResultView;

#ifdef __cplusplus

class DECLSPEC_UUID("7B1770F2-69EB-4420-B6D1-666619866CDA")
ResultView;
#endif

EXTERN_C const CLSID CLSID_ParsedPart;

#ifdef __cplusplus

class DECLSPEC_UUID("B2D1A997-66AD-40EB-A4D6-5A3B467272D1")
ParsedPart;
#endif

EXTERN_C const CLSID CLSID_ParsedCut;

#ifdef __cplusplus

class DECLSPEC_UUID("2F6FC5D2-5F9C-43FC-8FFB-9972D3405110")
ParsedCut;
#endif

EXTERN_C const CLSID CLSID_ParsedParts;

#ifdef __cplusplus

class DECLSPEC_UUID("47DE8B04-BD6C-470A-8677-028B5740B870")
ParsedParts;
#endif

EXTERN_C const CLSID CLSID_ParsedCuts;

#ifdef __cplusplus

class DECLSPEC_UUID("D3715FAF-D060-4B29-BF50-9C0377AF6FBA")
ParsedCuts;
#endif

EXTERN_C const CLSID CLSID_Statistic;

#ifdef __cplusplus

class DECLSPEC_UUID("F678F0B5-BFB8-47F9-86A1-DF1E809CE9DF")
Statistic;
#endif
#endif /* __COMRASKROYLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
