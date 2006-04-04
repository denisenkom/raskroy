

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ISheet,0x8A0A905F,0x99D6,0x4617,0x82,0xED,0xA6,0x9A,0xFE,0x02,0x30,0xC0);


MIDL_DEFINE_GUID(IID, IID_ISheets,0x979E8858,0x3D7B,0x4863,0x98,0x9E,0x64,0x40,0x1B,0x02,0xB1,0x00);


MIDL_DEFINE_GUID(IID, IID_ICuttingOptimizer,0xAEEBC2B7,0xE906,0x4F56,0xAB,0x9E,0x38,0x00,0xD3,0xDE,0x0C,0x29);


MIDL_DEFINE_GUID(IID, LIBID_ActiveXCutting,0xC8A15DB7,0x3875,0x4DC4,0xAA,0x51,0xE7,0xCA,0x20,0x74,0x3A,0xB8);


MIDL_DEFINE_GUID(CLSID, CLSID_Sheet,0x6260DA6D,0x9679,0x4CE4,0xB8,0xA4,0x10,0x3B,0x0C,0x45,0xDD,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_Sheets,0x4CF7DFFE,0x084B,0x4BEC,0xA8,0xE1,0xEA,0x82,0x05,0xF1,0xF8,0x44);


MIDL_DEFINE_GUID(IID, DIID__ICuttingOptimizerEvents,0xB4C90F66,0x1B62,0x4D31,0x9B,0x2C,0x3D,0x52,0x53,0xEF,0xA4,0x1A);


MIDL_DEFINE_GUID(CLSID, CLSID_CuttingOptimizer,0x2A7AE3A2,0xDB4D,0x4E01,0xA5,0xFE,0x2D,0xF8,0x75,0xF8,0xC8,0xD0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



