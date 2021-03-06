/*++

Microsoft Windows - File History
Copyright (c) Microsoft Corporation. All Rights Reserved.

Module Name:

    FhSvcCtl.h

Abstract:

    This module contains the definitions of the API provided
    by the File History Service Control Library.

Environment:
    
    User mode.

--*/

#ifndef _FHSVCCTL_
#define _FHSVCCTL_

#if _MSC_VER > 1000
#pragma once
#endif

#include <winapifamily.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#if NTDDI_VERSION >= NTDDI_WIN8 


DECLARE_HANDLE (FH_SERVICE_PIPE_HANDLE);

HRESULT
WINAPI
FhServiceOpenPipe(
    _In_ BOOL StartServiceIfStopped,
    _Out_ FH_SERVICE_PIPE_HANDLE *Pipe
    );

HRESULT
WINAPI
FhServiceClosePipe(
    _In_ FH_SERVICE_PIPE_HANDLE Pipe
    );

HRESULT
WINAPI
FhServiceStartBackup(
    _In_ FH_SERVICE_PIPE_HANDLE Pipe,
    _In_ BOOL LowPriorityIo
    );

HRESULT
WINAPI
FhServiceStopBackup(
    _In_ FH_SERVICE_PIPE_HANDLE Pipe,
    _In_ BOOL StopTracking
    );

HRESULT
WINAPI
FhServiceReloadConfiguration(
    _In_ FH_SERVICE_PIPE_HANDLE Pipe
    );

HRESULT
WINAPI
FhServiceBlockBackup(
    _In_ FH_SERVICE_PIPE_HANDLE Pipe
    );

HRESULT
WINAPI
FhServiceUnblockBackup(
    _In_ FH_SERVICE_PIPE_HANDLE Pipe
    );


#endif // NTDDI_VERSION >= NTDDI_WIN8 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#ifdef __cplusplus
}
#endif

#endif // _FHSVCCTL_

