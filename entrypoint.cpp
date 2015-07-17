#include "classfactory.h"

extern "C" {
	HRESULT STDMETHODCALLTYPE DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
	{
		if (ppv == NULL)
			return E_FAIL;

		*ppv = new ClassFactory();

		return S_OK;
	}
}
