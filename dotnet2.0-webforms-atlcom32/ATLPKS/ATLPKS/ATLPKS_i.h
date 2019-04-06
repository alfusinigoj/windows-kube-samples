

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Apr 06 17:38:27 2019
 */
/* Compiler settings for ATLPKS.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

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

#ifndef __ATLPKS_i_h__
#define __ATLPKS_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IThing_FWD_DEFINED__
#define __IThing_FWD_DEFINED__
typedef interface IThing IThing;
#endif 	/* __IThing_FWD_DEFINED__ */


#ifndef __Thing_FWD_DEFINED__
#define __Thing_FWD_DEFINED__

#ifdef __cplusplus
typedef class Thing Thing;
#else
typedef struct Thing Thing;
#endif /* __cplusplus */

#endif 	/* __Thing_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IThing_INTERFACE_DEFINED__
#define __IThing_INTERFACE_DEFINED__

/* interface IThing */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IThing;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C64EC0B1-56E4-43B5-AEC2-4C881CF822FE")
    IThing : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Action( 
            /* [retval][out] */ BSTR *retstr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IThingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IThing * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IThing * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IThing * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IThing * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IThing * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IThing * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IThing * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Action )( 
            IThing * This,
            /* [retval][out] */ BSTR *retstr);
        
        END_INTERFACE
    } IThingVtbl;

    interface IThing
    {
        CONST_VTBL struct IThingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IThing_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IThing_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IThing_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IThing_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IThing_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IThing_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IThing_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IThing_Action(This,retstr)	\
    ( (This)->lpVtbl -> Action(This,retstr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IThing_INTERFACE_DEFINED__ */



#ifndef __ATLPKSLib_LIBRARY_DEFINED__
#define __ATLPKSLib_LIBRARY_DEFINED__

/* library ATLPKSLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLPKSLib;

EXTERN_C const CLSID CLSID_Thing;

#ifdef __cplusplus

class DECLSPEC_UUID("E8DEA7F4-7526-4265-876A-5D2300BBAB6C")
Thing;
#endif
#endif /* __ATLPKSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


