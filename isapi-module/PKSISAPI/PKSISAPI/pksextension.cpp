#include "pch.h"
#include "httpext.h"
#include "stdio.h"
#include "pksextension.h"

BOOL WINAPI GetExtensionVersion(HSE_VERSION_INFO* pVer)
{
	pVer->dwExtensionVersion = HSE_VERSION;
	strncpy_s(pVer->lpszExtensionDesc, "Validate ISAPI Extension", HSE_MAX_EXT_DLL_NAME_LEN);
	return TRUE;
}

void ResponseWrite(EXTENSION_CONTROL_BLOCK* pECB, char* sz)
{
	DWORD dwSize = strlen(sz);
	pECB->WriteClient(pECB->ConnID, sz, &dwSize, 0);
}

DWORD WINAPI HttpExtensionProc(EXTENSION_CONTROL_BLOCK* pECB) 
{
	HSE_SEND_HEADER_EX_INFO header;
	header.pszStatus = "200 OK";
	header.pszHeader = "Content-type: text/html\r\n\r\n";
	header.cchStatus = strlen(header.pszStatus);
	header.cchHeader = strlen(header.pszHeader);
	header.fKeepConn = FALSE;
	pECB->ServerSupportFunction(pECB->ConnID, HSE_REQ_SEND_RESPONSE_HEADER_EX, &header, NULL, NULL);

	ResponseWrite(pECB, (char *)"<html><body>Hello, PKS!</body></html>\r\n");
	return HSE_STATUS_SUCCESS;
}