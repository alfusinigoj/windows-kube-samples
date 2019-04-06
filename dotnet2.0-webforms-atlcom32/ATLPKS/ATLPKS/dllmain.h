// dllmain.h : Declaration of module class.

class CATLPKSModule : public ATL::CAtlDllModuleT< CATLPKSModule >
{
public :
	DECLARE_LIBID(LIBID_ATLPKSLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLPKS, "{DE5F3C1D-C7E7-4268-A28A-ECA3602AE062}")
};

extern class CATLPKSModule _AtlModule;
