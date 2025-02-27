#pragma once
#include "fumo_data_header.h"

// Windows 10 2004/20H1 (19041) or higher
#define MIN_OS_MAJOR_VERSION 10
#define MIN_OS_BUILD_NUMBER 19041

#define FUMO_DRIVER_VERSION 0x00000003
#define FUMO_HOOKED_DRIVER_NAME L"\\Driver\\Null"
#define FUMO_HOOKED_DRIVER_NAME_USER L"\\\\.\\NUL"
#define FUMO_SECOND_STAGE_PROCESS_NAME L"explorer.exe"
#define FUMO_FILE_FORMAT_VERSION 0x00000001

#define IO_VERSION_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8000, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IO_UNLOAD_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8001, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IO_ALLOC_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8011, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IO_MAP_MEMORY_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8012, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IO_EXECUTE_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8013, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IO_FIND_MODULE_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x8014, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef struct _IO_VERSION_RESPONSE_DATA {
    ULONG Version;
} IO_VERSION_RESPONSE_DATA, *PIO_VERSION_RESPONSE_DATA;

typedef struct _IO_ALLOC_REQUEST_DATA {
    ULONG Size;
} IO_ALLOC_REQUEST_DATA, *PIO_ALLOC_REQUEST_DATA;

typedef struct _IO_ALLOC_RESPONSE_DATA {
    PVOID Address;
} IO_ALLOC_RESPONSE_DATA, *PIO_ALLOC_RESPONSE_DATA;

typedef struct _IO_MAP_MEMORY_REQUEST_DATA {
    ULONG Pid;
    PVOID Address;
    ULONG Size;
} IO_MAP_MEMORY_REQUEST_DATA, *PIO_MAP_MEMORY_REQUEST_DATA;

typedef struct _IO_EXECUTE_REQUEST_DATA {
    ULONG Pid;
    PVOID Address;
    PVOID Argument;
} IO_EXECUTE_REQUEST_DATA, *PIO_EXECUTE_REQUEST_DATA;

typedef struct _IO_FIND_MODULE_REQUEST_DATA {
    ULONG Pid;
    WCHAR ModuleName[256];
} IO_FIND_MODULE_REQUEST_DATA, *PIO_FIND_MODULE_REQUEST_DATA;

typedef struct _IO_FIND_MODULE_RESPONSE_DATA {
    PVOID Address;
} IO_FIND_MODULE_RESPONSE_DATA, *PIO_FIND_MODULE_RESPONSE_DATA;

typedef struct _FUMO_EMBEDDED_DATA {
    PVOID Data;
    DWORD Size;
} FUMO_EMBEDDED_DATA, *PFUMO_EMBEDDED_DATA;