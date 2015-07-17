#include "profiler.h"
#include "log.h"

Profiler::Profiler()
	: m_referenceCount(1)
{
}

Profiler::~Profiler()
{
}

HRESULT STDMETHODCALLTYPE Profiler::QueryInterface(REFIID riid, void **ppvObject)
{
	if (riid == IID_ICorProfilerCallback3 ||
		riid == IID_ICorProfilerCallback2 ||
		riid == IID_ICorProfilerCallback ||
		riid == IID_IUnknown)
	{
		*ppvObject = this;
		this->AddRef();

		return S_OK;
	}

	*ppvObject = NULL;
	return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE Profiler::AddRef(void)
{
	return __sync_fetch_and_add(&m_referenceCount, 1) + 1;
}

ULONG STDMETHODCALLTYPE Profiler::Release(void)
{
	LONG result = __sync_fetch_and_sub(&m_referenceCount, 1) - 1;
	if (result == 0)
	{
		delete this;
	}

	return result;
}

HRESULT STDMETHODCALLTYPE Profiler::Initialize(IUnknown *pICorProfilerInfoUnk)
{
	LogProfilerActivity("Initialize\n");

	ICorProfilerInfo3 *info;
	HRESULT hr = pICorProfilerInfoUnk->QueryInterface(IID_ICorProfilerInfo3, (void **) &info);
	if (hr == S_OK && info != NULL)
	{
		info->SetEventMask(COR_PRF_MONITOR_JIT_COMPILATION | COR_PRF_MONITOR_ASSEMBLY_LOADS | COR_PRF_MONITOR_CLASS_LOADS);

		info->Release();
		info = NULL;
	}

	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::Shutdown(void)
{
	LogProfilerActivity("Shutdown\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::AppDomainCreationStarted(AppDomainID appDomainId)
{
	LogProfilerActivity("AppDomainCreationStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::AppDomainCreationFinished(AppDomainID appDomainId, HRESULT hrStatus)
{
	LogProfilerActivity("AppDomainCreationFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::AppDomainShutdownStarted(AppDomainID appDomainId)
{
	LogProfilerActivity("AppDomainShutdownStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::AppDomainShutdownFinished(AppDomainID appDomainId, HRESULT hrStatus)
{
	LogProfilerActivity("AppDomainShutdownFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::AssemblyLoadStarted(AssemblyID assemblyId)
{
	LogProfilerActivity("AssemblyLoadStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::AssemblyLoadFinished(AssemblyID assemblyId, HRESULT hrStatus)
{
	LogProfilerActivity("AssemblyLoadFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::AssemblyUnloadStarted(AssemblyID assemblyId)
{
	LogProfilerActivity("AssemblyUnloadStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::AssemblyUnloadFinished(AssemblyID assemblyId, HRESULT hrStatus)
{
	LogProfilerActivity("AssemblyUnloadFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ModuleLoadStarted(ModuleID moduleId)
{
	LogProfilerActivity("ModuleLoadStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ModuleLoadFinished(ModuleID moduleId, HRESULT hrStatus)
{
	LogProfilerActivity("ModuleLoadFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ModuleUnloadStarted(ModuleID moduleId)
{
	LogProfilerActivity("ModuleUnloadStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ModuleUnloadFinished(ModuleID moduleId, HRESULT hrStatus)
{
	LogProfilerActivity("ModuleUnloadFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ModuleAttachedToAssembly(ModuleID moduleId, AssemblyID AssemblyId)
{
	LogProfilerActivity("ModuleAttachedToAssembly\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ClassLoadStarted(ClassID classId)
{
	LogProfilerActivity("ClassLoadStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ClassLoadFinished(ClassID classId, HRESULT hrStatus)
{
	LogProfilerActivity("ClassLoadFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ClassUnloadStarted(ClassID classId)
{
	LogProfilerActivity("ClassUnloadStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ClassUnloadFinished(ClassID classId, HRESULT hrStatus)
{
	LogProfilerActivity("ClassUnloadFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::FunctionUnloadStarted(FunctionID functionId)
{
	LogProfilerActivity("FunctionUnloadStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::JITCompilationStarted(FunctionID functionId, BOOL fIsSafeToBlock)
{
	LogProfilerActivity("JITCompilationStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::JITCompilationFinished(FunctionID functionId, HRESULT hrStatus, BOOL fIsSafeToBlock)
{
	LogProfilerActivity("JITCompilationFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::JITCachedFunctionSearchStarted(FunctionID functionId, BOOL *pbUseCachedFunction)
{
	LogProfilerActivity("JITCachedFunctionSearchStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::JITCachedFunctionSearchFinished(FunctionID functionId, COR_PRF_JIT_CACHE result)
{
	LogProfilerActivity("JITCachedFunctionSearchFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::JITFunctionPitched(FunctionID functionId)
{
	LogProfilerActivity("JITFunctionPitched\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::JITInlining(FunctionID callerId, FunctionID calleeId, BOOL *pfShouldInline)
{
	LogProfilerActivity("JITInlining\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ThreadCreated(ThreadID threadId)
{
	LogProfilerActivity("ThreadCreated\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ThreadDestroyed(ThreadID threadId)
{
	LogProfilerActivity("ThreadDestroyed\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ThreadAssignedToOSThread(ThreadID managedThreadId, DWORD osThreadId)
{
	LogProfilerActivity("ThreadAssignedToOSThread\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RemotingClientInvocationStarted(void)
{
	LogProfilerActivity("RemotingClientInvocationStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RemotingClientSendingMessage(GUID *pCookie, BOOL fIsAsync)
{
	LogProfilerActivity("RemotingClientSendingMessage\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RemotingClientReceivingReply(GUID *pCookie, BOOL fIsAsync)
{
	LogProfilerActivity("RemotingClientReceivingReply\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RemotingClientInvocationFinished(void)
{
	LogProfilerActivity("RemotingClientInvocationFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RemotingServerReceivingMessage(GUID *pCookie, BOOL fIsAsync)
{
	LogProfilerActivity("RemotingServerReceivingMessage\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RemotingServerInvocationStarted(void)
{
	LogProfilerActivity("RemotingServerInvocationStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RemotingServerInvocationReturned(void)
{
	LogProfilerActivity("RemotingServerInvocationReturned\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RemotingServerSendingReply(GUID *pCookie, BOOL fIsAsync)
{
	LogProfilerActivity("RemotingServerSendingReply\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::UnmanagedToManagedTransition(FunctionID functionId, COR_PRF_TRANSITION_REASON reason)
{
	LogProfilerActivity("UnmanagedToManagedTransition\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ManagedToUnmanagedTransition(FunctionID functionId, COR_PRF_TRANSITION_REASON reason)
{
	LogProfilerActivity("ManagedToUnmanagedTransition\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RuntimeSuspendStarted(COR_PRF_SUSPEND_REASON suspendReason)
{
	LogProfilerActivity("RuntimeSuspendStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RuntimeSuspendFinished(void)
{
	LogProfilerActivity("RuntimeSuspendFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RuntimeSuspendAborted(void)
{
	LogProfilerActivity("RuntimeSuspendAborted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RuntimeResumeStarted(void)
{
	LogProfilerActivity("RuntimeResumeStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RuntimeResumeFinished(void)
{
	LogProfilerActivity("RuntimeResumeFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RuntimeThreadSuspended(ThreadID threadId)
{
	LogProfilerActivity("RuntimeThreadSuspended\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RuntimeThreadResumed(ThreadID threadId)
{
	LogProfilerActivity("RuntimeThreadResumed\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::MovedReferences(ULONG cMovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[])
{
	LogProfilerActivity("MovedReferences\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ObjectAllocated(ObjectID objectId, ClassID classId)
{
	LogProfilerActivity("ObjectAllocated\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ObjectsAllocatedByClass(ULONG cClassCount, ClassID classIds[], ULONG cObjects[])
{
	LogProfilerActivity("ObjectsAllocatedByClass\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ObjectReferences(ObjectID objectId, ClassID classId, ULONG cObjectRefs, ObjectID objectRefIds[])
{
	LogProfilerActivity("ObjectReferences\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RootReferences(ULONG cRootRefs, ObjectID rootRefIds[])
{
	LogProfilerActivity("RootReferences\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionThrown(ObjectID thrownObjectId)
{
	LogProfilerActivity("ExceptionThrown\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionSearchFunctionEnter(FunctionID functionId)
{
	LogProfilerActivity("ExceptionSearchFunctionEnter\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionSearchFunctionLeave(void)
{
	LogProfilerActivity("ExceptionSearchFunctionLeave\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionSearchFilterEnter(FunctionID functionId)
{
	LogProfilerActivity("ExceptionSearchFilterEnter\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionSearchFilterLeave(void)
{
	LogProfilerActivity("ExceptionSearchFilterLeave\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionSearchCatcherFound(FunctionID functionId)
{
	LogProfilerActivity("ExceptionSearchCatcherFound\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionOSHandlerEnter(UINT_PTR __unused)
{
	LogProfilerActivity("ExceptionOSHandlerEnter\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionOSHandlerLeave(UINT_PTR __unused)
{
	LogProfilerActivity("ExceptionOSHandlerLeave\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionUnwindFunctionEnter(FunctionID functionId)
{
	LogProfilerActivity("ExceptionUnwindFunctionEnter\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionUnwindFunctionLeave(void)
{
	LogProfilerActivity("ExceptionUnwindFunctionLeave\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionUnwindFinallyEnter(FunctionID functionId)
{
	LogProfilerActivity("ExceptionUnwindFinallyEnter\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionUnwindFinallyLeave(void)
{
	LogProfilerActivity("ExceptionUnwindFinallyLeave\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionCatcherEnter(FunctionID functionId, ObjectID objectId)
{
	LogProfilerActivity("ExceptionCatcherEnter\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionCatcherLeave(void)
{
	LogProfilerActivity("ExceptionCatcherLeave\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::COMClassicVTableCreated(ClassID wrappedClassId, REFGUID implementedIID, void *pVTable, ULONG cSlots)
{
	LogProfilerActivity("COMClassicVTableCreated\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::COMClassicVTableDestroyed(ClassID wrappedClassId, REFGUID implementedIID, void *pVTable)
{
	LogProfilerActivity("COMClassicVTableDestroyed\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionCLRCatcherFound(void)
{
	LogProfilerActivity("ExceptionCLRCatcherFound\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ExceptionCLRCatcherExecute(void)
{
	LogProfilerActivity("ExceptionCLRCatcherExecute\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ThreadNameChanged(ThreadID threadId, ULONG cchName, _In_reads_opt_(cchName) WCHAR name[])
{
	LogProfilerActivity("ThreadNameChanged\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::GarbageCollectionStarted(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason)
{
	LogProfilerActivity("GarbageCollectionStarted\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::SurvivingReferences(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[])
{
	LogProfilerActivity("SurvivingReferences\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::GarbageCollectionFinished(void)
{
	LogProfilerActivity("GarbageCollectionFinished\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::FinalizeableObjectQueued(DWORD finalizerFlags, ObjectID objectID)
{
	LogProfilerActivity("FinalizeableObjectQueued\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::RootReferences2(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[])
{
	LogProfilerActivity("RootReferences2\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::HandleCreated(GCHandleID handleId, ObjectID initialObjectId)
{
	LogProfilerActivity("HandleCreated\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::HandleDestroyed(GCHandleID handleId)
{
	LogProfilerActivity("HandleDestroyed\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::InitializeForAttach(IUnknown *pCorProfilerInfoUnk, void *pvClientData, UINT cbClientData)
{
	LogProfilerActivity("InitializeForAttach\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ProfilerAttachComplete(void)
{
	LogProfilerActivity("ProfilerAttachComplete\n");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE Profiler::ProfilerDetachSucceeded(void)
{
	LogProfilerActivity("ProfilerDetachSucceeded\n");
	return S_OK;
}
