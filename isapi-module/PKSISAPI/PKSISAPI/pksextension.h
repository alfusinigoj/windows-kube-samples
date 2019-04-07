#pragma once

BOOL WINAPI GetExtensionVersion(HSE_VERSION_INFO* pVer);
DWORD WINAPI HttpExtensionProc(EXTENSION_CONTROL_BLOCK* pECB);