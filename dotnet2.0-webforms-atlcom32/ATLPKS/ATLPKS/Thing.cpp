// Thing.cpp : Implementation of CThing

#include "stdafx.h"
#include "Thing.h"


// CThing



STDMETHODIMP CThing::Action(BSTR* retstr)
{
	char str[20] ;
    sprintf(str,"PKS"); 
    CComBSTR temp(str);               
    *retstr = temp.Detach();

	return S_OK;
}
