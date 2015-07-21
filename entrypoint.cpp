#include "classfactory.h"

const CLSID CLSID_DemoProfiler = {0x912E73AF,0xF51D,0x4E80,0x89,0x4D,0xF4,0xE9,0xE6,0xDD,0x7C,0x2E};

extern "C" {
	HRESULT STDMETHODCALLTYPE DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
	{
		if (ppv == NULL || rclsid != CLSID_DemoProfiler)
			return E_FAIL;

		*ppv = new ClassFactory();

		return S_OK;
	}
}
