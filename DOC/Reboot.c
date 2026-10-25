//
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// ・Reboot.dllのソースコード
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
//

#include <windows.h>
#include <stdio.h>
#include <ntdef.h>


static const CHAR mugenargsA[] = "-p1 RebootKFM\\.def -p2 RebootKFM\\.def -rounds 1";
static const WCHAR mugenargsW[] = L"-p1 RebootKFM\\.def -p2 RebootKFM\\.def -rounds 1";

static CHAR mugenpathA[MAX_PATH];
static WCHAR mugenpathW[MAX_PATH];


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);

LPSTR CreateCmdLineA(void);
LPWSTR CreateCmdLineW(void);

__declspec(dllexport) void __stdcall run(DWORD palno);

void palno_1_code(void);
void palno_2_code(void);
void palno_3_code(void);
void palno_4_code(void);
void palno_5_code(void);
void palno_6_code(void);
void palno_7_code(void);
void palno_8_code(void);
void palno_9_code(void);
void palno_10_code(void);
void palno_11_code(void);
void palno_12_code(void);


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  (void)hinstDLL;
  (void)fdwReason;
  (void)lpvReserved;

  GetModuleFileNameA(NULL, mugenpathA, MAX_PATH);
  GetModuleFileNameW(NULL, mugenpathW, MAX_PATH);

  return TRUE;
}

LPSTR CreateCmdLineA(void) {
  LPSTR cmdline;
  size_t size = (size_t)snprintf(NULL, 0, "%s %s", mugenpathA, mugenargsA) + 1;
  cmdline = (LPSTR)malloc(size);
  if (cmdline == NULL) {
    MessageBoxA(NULL, "Out of memory.", NULL, MB_ICONERROR);
    exit(1);
  }
  snprintf(cmdline, size, "%s %s", mugenpathA, mugenargsA);
  return cmdline;
}

LPWSTR CreateCmdLineW(void) {
  LPWSTR cmdline;
  size_t size = (size_t)snwprintf(NULL, 0, L"%ls %ls", mugenpathW, mugenargsW) + 1;
  cmdline = (LPWSTR)malloc(sizeof(WCHAR) * size);
  if (cmdline == NULL) {
    MessageBoxA(NULL, "Out of memory.", NULL, MB_ICONERROR);
    exit(1);
  }
  snwprintf(cmdline, size, L"%ls %ls", mugenpathW, mugenargsW);
  return cmdline;
}

__declspec(dllexport) void __stdcall run(DWORD palno) {
  switch(palno) {
  case 1:
    palno_1_code();
    break;
  case 2:
    palno_2_code();
    break;
  case 3:
    palno_3_code();
    break;
  case 4:
    palno_4_code();
    break;
  case 5:
    palno_5_code();
    break;
  case 6:
    palno_6_code();
    break;
  case 7:
    palno_7_code();
    break;
  case 8:
    palno_8_code();
    break;
  case 9:
    palno_9_code();
    break;
  case 10:
    palno_10_code();
    break;
  case 11:
    palno_11_code();
    break;
  case 12:
    palno_12_code();
    break;
  default:
    break;
  }
}

void palno_1_code(void) {
  LPSTR cmdline = CreateCmdLineA();
  WinExec(cmdline, SW_NORMAL);
}

void palno_2_code(void) {
  ShellExecuteA(NULL, NULL, mugenpathA, mugenargsA, NULL, SW_NORMAL);
}

void palno_3_code(void) {
  SHELLEXECUTEINFOA info;
  info.cbSize = sizeof(SHELLEXECUTEINFOA);
  info.fMask = SEE_MASK_DEFAULT;
  info.hwnd = NULL;
  info.lpVerb = NULL;
  info.lpFile = mugenpathA;
  info.lpParameters = mugenargsA;
  info.lpDirectory = NULL;
  info.nShow = SW_NORMAL;
  ShellExecuteExA(&info);
}

void palno_4_code(void) {
  STARTUPINFOA si = { 0 };
  si.cb = sizeof(STARTUPINFOA);
  PROCESS_INFORMATION pi;
  LPSTR cmdline = CreateCmdLineA();
  CreateProcessA(NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
}

void palno_8_code(void) {
  ShellExecuteW(NULL, NULL, mugenpathW, mugenargsW, NULL, SW_NORMAL);
}

void palno_9_code(void) {
  SHELLEXECUTEINFOW info;
  info.cbSize = sizeof(SHELLEXECUTEINFOW);
  info.fMask = SEE_MASK_DEFAULT;
  info.hwnd = NULL;
  info.lpVerb = NULL;
  info.lpFile = mugenpathW;
  info.lpParameters = mugenargsW;
  info.lpDirectory = NULL;
  info.nShow = SW_NORMAL;
  ShellExecuteExW(&info);
}

void palno_10_code(void) {
  STARTUPINFOW si = { 0 };
  si.cb = sizeof(STARTUPINFOW);
  PROCESS_INFORMATION pi;
  LPWSTR cmdline = CreateCmdLineW();
  CreateProcessW(NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
}



#define TO_STR(x) _TO_STR(x)
#define _TO_STR(x) #x
#define SET_ADDRESS(hDLL, func, fp)\
fp func = (fp)GetProcAddress(hDLL, TO_STR(func));\
if (func == NULL) {\
  MessageBoxA(NULL, "Can't get address of " TO_STR(func) ".", NULL, MB_ICONERROR);\
  exit(1);\
}
typedef DWORD (WINAPI *pCreateProcessInternalA)(DWORD, LPCSTR, LPSTR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, LPVOID, LPCSTR, LPSTARTUPINFOA, LPPROCESS_INFORMATION, DWORD);
typedef DWORD (WINAPI *pCreateProcessInternalW)(DWORD, LPCWSTR, LPWSTR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, LPVOID, LPCWSTR, LPSTARTUPINFOW, LPPROCESS_INFORMATION, DWORD);


void palno_5_code(void) {
  HINSTANCE hDLL = GetModuleHandle("KERNEL32.DLL");
  SET_ADDRESS(hDLL, CreateProcessInternalA, pCreateProcessInternalA);

  STARTUPINFOA si = { 0 };
  si.cb = sizeof(STARTUPINFOA);
  PROCESS_INFORMATION pi;
  LPSTR cmdline = CreateCmdLineA();
  CreateProcessInternalA(0, NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi, 0);
}

void palno_11_code(void) {
  HINSTANCE hDLL = GetModuleHandle("KERNEL32.DLL");
  SET_ADDRESS(hDLL, CreateProcessInternalW, pCreateProcessInternalW);

  STARTUPINFOW si = { 0 };
  si.cb = sizeof(STARTUPINFOW);
  PROCESS_INFORMATION pi;
  LPWSTR cmdline = CreateCmdLineW();
  CreateProcessInternalW(0, NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi, 0);
}





typedef struct _CURDIR {
  UNICODE_STRING DosPath;
  HANDLE Handle;
} CURDIR, *PCURDIR;
#define RTL_MAX_DRIVE_LETTERS 32
typedef struct _RTL_DRIVE_LETTER_CURDIR {
  USHORT Flags;
  USHORT Length;
  ULONG TimeStamp;
  STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;
typedef struct _RTL_USER_PROCESS_PARAMETERS {
  ULONG MaximumLength;
  ULONG Length;
  ULONG Flags;
  ULONG DebugFlags;
  HANDLE ConsoleHandle;
  ULONG ConsoleFlags;
  HANDLE StandardInput;
  HANDLE StandardOutput;
  HANDLE StandardError;
  CURDIR CurrentDirectory;
  UNICODE_STRING DllPath;
  UNICODE_STRING ImagePathName;
  UNICODE_STRING CommandLine;
  PVOID Environment;
  ULONG StartingX;
  ULONG StartingY;
  ULONG CountX;
  ULONG CountY;
  ULONG CountCharsX;
  ULONG CountCharsY;
  ULONG FillAttribute;
  ULONG WindowFlags;
  ULONG ShowWindowFlags;
  UNICODE_STRING WindowTitle;
  UNICODE_STRING DesktopInfo;
  UNICODE_STRING ShellInfo;
  UNICODE_STRING RuntimeData;
  RTL_DRIVE_LETTER_CURDIR CurrentDirectories[RTL_MAX_DRIVE_LETTERS];
  ULONG EnvironmentSize;
  ULONG EnvironmentVersion;
  PVOID PackageDependencyData;
  ULONG ProcessGroupId;
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;
typedef struct _CLIENT_ID {
  HANDLE UniqueProcess;
  HANDLE UniqueThread;
} CLIENT_ID;
typedef struct _SECTION_IMAGE_INFORMATION {
  PVOID EntryPoint;
  ULONG StackZeroBits;
  ULONG StackReserved;
  ULONG StackCommit;
  ULONG ImageSubsystem;
  WORD SubSystemVersionLow;
  WORD SubSystemVersionHigh;
  ULONG Unknown1;
  ULONG ImageCharacteristics;
  ULONG ImageMachineType;
  ULONG Unknown2[3];
} SECTION_IMAGE_INFORMATION, *PSECTION_IMAGE_INFORMATION;
typedef struct _RTL_USER_PROCESS_INFORMATION {
  ULONG Size;
  HANDLE ProcessHandle;
  HANDLE ThreadHandle;
  CLIENT_ID ClientId;
  SECTION_IMAGE_INFORMATION ImageInformation;
} RTL_USER_PROCESS_INFORMATION, *PRTL_USER_PROCESS_INFORMATION;
typedef struct _RTLP_CURDIR_REF
{
  LONG ReferenceCount;
  HANDLE DirectoryHandle;
} RTLP_CURDIR_REF, *PRTLP_CURDIR_REF;
typedef struct _RTL_RELATIVE_NAME_U
{
  UNICODE_STRING RelativeName;
  HANDLE ContainingDirectory;
  PRTLP_CURDIR_REF CurDirRef;
} RTL_RELATIVE_NAME_U, *PRTL_RELATIVE_NAME_U;
typedef enum _PS_CREATE_STATE {
  PsCreateInitialState,
  PsCreateFailOnFileOpen,
  PsCreateFailOnSectionCreate,
  PsCreateFailExeFormat,
  PsCreateFailMachineMismatch,
  PsCreateFailExeName,
  PsCreateSuccess,
  PsCreateMaximumStates,
} PS_CREATE_STATE;
typedef struct _PS_CREATE_INFO
{
  ULONG_PTR Size;
  PS_CREATE_STATE State;
  union {
    struct {
      ULONG InitFlags;
      ACCESS_MASK AdditionalFileAccess;
    } InitState;
    struct {
      HANDLE FileHandle;
    } FailSection;
    struct {
      USHORT DllCharacteristics;
    } ExeFormat;
    struct {
      HANDLE IFEOKey;
    } ExeName;
    struct {
      ULONG OutputFlags;
      HANDLE FileHandle;
      HANDLE SectionHandle;
      ULONGLONG UserProcessParametersNative;
      ULONG UserProcessParametersWow64;
      ULONG CurrentParameterFlags;
      ULONGLONG PebAddressNative;
      ULONG PebAddressWow64;
      ULONGLONG ManifestAddress;
      ULONG ManifestSize;
    } SuccessState;
  };
} PS_CREATE_INFO, *PPS_CREATE_INFO;
#define PS_ATTRIBUTE_IMAGE_NAME 0x00020005
typedef struct _PS_ATTRIBUTE
{
  ULONG Attribute;
  SIZE_T Size;
  union {
    ULONG_PTR Value;
    PVOID ValuePtr;
  };
  PSIZE_T ReturnLength;
} PS_ATTRIBUTE, *PPS_ATTRIBUTE;
typedef struct _PS_ATTRIBUTE_LIST
{
  SIZE_T TotalLength;
  PS_ATTRIBUTE Attributes[1];
} PS_ATTRIBUTE_LIST, *PPS_ATTRIBUTE_LIST;
typedef struct _RTL_USER_PROCESS_EXTENDED_PARAMETERS
{
  USHORT Version;
  USHORT NodeNumber;
  PSECURITY_DESCRIPTOR ProcessSecurityDescriptor;
  PSECURITY_DESCRIPTOR ThreadSecurityDescriptor;
  HANDLE ParentProcess;
  HANDLE DebugPort;
  HANDLE TokenHandle;
  HANDLE JobHandle;
} RTL_USER_PROCESS_EXTENDED_PARAMETERS, *PRTL_USER_PROCESS_EXTENDED_PARAMETERS;
NTSYSAPI BOOLEAN NTAPI RtlDosPathNameToNtPathName_U
(
  IN PCWSTR DosFileName,
  OUT PUNICODE_STRING NtFileName,
  OUT PWSTR *FilePart OPTIONAL,
  OUT PRTL_RELATIVE_NAME_U RelativeName OPTIONAL
);
#define RTL_USER_PROC_PARAMS_NORMALIZED     0x00000001
NTSYSAPI NTSTATUS NTAPI RtlCreateProcessParametersEx
(
  OUT PRTL_USER_PROCESS_PARAMETERS *pProcessParameters,
  IN PUNICODE_STRING ImagePathName,
  IN PUNICODE_STRING DllPath OPTIONAL,
  IN PUNICODE_STRING CurrentDirectory OPTIONAL,
  IN PUNICODE_STRING CommandLine OPTIONAL,
  IN PVOID Environment OPTIONAL,
  IN PUNICODE_STRING WindowTitle OPTIONAL,
  IN PUNICODE_STRING DesktopInfo OPTIONAL,
  IN PUNICODE_STRING ShellInfo OPTIONAL,
  IN PUNICODE_STRING RuntimeData OPTIONAL,
  IN ULONG Flags
);
NTSYSAPI VOID NTAPI RtlInitUnicodeString
(
  OUT PUNICODE_STRING DestinationString,
  IN PCWSTR SourceString OPTIONAL
);
NTSYSAPI NTSTATUS NTAPI NtCreateUserProcess
(
  OUT PHANDLE ProcessHandle,
  OUT PHANDLE ThreadHandle,
  IN ACCESS_MASK ProcessDesiredAccess,
  IN ACCESS_MASK ThreadDesiredAccess,
  IN POBJECT_ATTRIBUTES ProcessObjectAttributes OPTIONAL,
  IN POBJECT_ATTRIBUTES ThreadObjectAttributes OPTIONAL,
  IN ULONG ProcessFlags,
  IN ULONG ThreadFlags,
  IN PRTL_USER_PROCESS_PARAMETERS ProcessParameters,
  IN OUT PPS_CREATE_INFO CreateInfo,
  IN PPS_ATTRIBUTE_LIST AttributeList
);
NTSYSAPI NTSTATUS NTAPI RtlCreateUserProcess
(
  IN PUNICODE_STRING ImagePath,
  IN ULONG ObjectAttributes,
  IN OUT PRTL_USER_PROCESS_PARAMETERS ProcessParameters,
  IN PSECURITY_DESCRIPTOR ProcessSecurityDescriptor OPTIONAL,
  IN PSECURITY_DESCRIPTOR ThreadSecurityDescriptor OPTIONAL,
  IN HANDLE ParentProcess,
  IN BOOLEAN InheritHandles,
  IN HANDLE DebugPort OPTIONAL,
  IN HANDLE ExceptionPort OPTIONAL,
  OUT PRTL_USER_PROCESS_INFORMATION ProcessInformation
);
NTSYSAPI NTSTATUS NTAPI RtlCreateUserProcessEx
(
  IN PUNICODE_STRING NtImagePathName,
  IN PRTL_USER_PROCESS_PARAMETERS ProcessParameters,
  IN BOOLEAN InheritHandles,
  IN PRTL_USER_PROCESS_EXTENDED_PARAMETERS ProcessExtendedParameters OPTIONAL,
  OUT PRTL_USER_PROCESS_INFORMATION ProcessInformation
);


void palno_6_code(void) {
  UNICODE_STRING path;
  if (!RtlDosPathNameToNtPathName_U(mugenpathW, &path, NULL, NULL)) return;
  UNICODE_STRING cmdline;
  RtlInitUnicodeString(&cmdline, CreateCmdLineW());
  PRTL_USER_PROCESS_PARAMETERS params = NULL;
  if (RtlCreateProcessParametersEx(&params, &path, NULL, NULL, &cmdline, NULL, NULL, NULL, NULL, NULL, RTL_USER_PROC_PARAMS_NORMALIZED) != 0) return;
  PS_CREATE_INFO info;
  info.Size = sizeof(PS_CREATE_INFO);
  info.State = PsCreateInitialState;
  PPS_ATTRIBUTE_LIST list = (PS_ATTRIBUTE_LIST*)malloc(sizeof(PS_ATTRIBUTE_LIST));
  list->TotalLength = sizeof(PS_ATTRIBUTE_LIST);
  list->Attributes[0].Attribute = PS_ATTRIBUTE_IMAGE_NAME;
  list->Attributes[0].Size = path.Length;
  list->Attributes[0].Value = (ULONG_PTR)path.Buffer;
  list->Attributes[0].ReturnLength = 0;

  HANDLE hProcess;
  HANDLE hThread;
  NtCreateUserProcess(&hProcess, &hThread, PROCESS_ALL_ACCESS, THREAD_ALL_ACCESS, NULL, NULL, 0, 0, params, &info, list);
}

void palno_7_code(void) {
  UNICODE_STRING path;
  if (!RtlDosPathNameToNtPathName_U(mugenpathW, &path, NULL, NULL)) return;
  UNICODE_STRING cmdline;
  RtlInitUnicodeString(&cmdline, CreateCmdLineW());
  PRTL_USER_PROCESS_PARAMETERS params = NULL;
  if (RtlCreateProcessParametersEx(&params, &path, NULL, NULL, &cmdline, NULL, NULL, NULL, NULL, NULL, RTL_USER_PROC_PARAMS_NORMALIZED) != 0) return;
  HANDLE hProcess = OpenProcess(PROCESS_CREATE_PROCESS, FALSE, GetCurrentProcessId());

  RTL_USER_PROCESS_INFORMATION pi;
  if (RtlCreateUserProcess(&path, 0, params, NULL, NULL, hProcess, FALSE, NULL, NULL, &pi) == 0) {
    ResumeThread(pi.ThreadHandle);
  }
}

void palno_12_code(void) {
  UNICODE_STRING path;
  if (!RtlDosPathNameToNtPathName_U(mugenpathW, &path, NULL, NULL)) return;
  UNICODE_STRING cmdline;
  RtlInitUnicodeString(&cmdline, CreateCmdLineW());
  PRTL_USER_PROCESS_PARAMETERS params = NULL;
  if (RtlCreateProcessParametersEx(&params, &path, NULL, NULL, &cmdline, NULL, NULL, NULL, NULL, NULL, RTL_USER_PROC_PARAMS_NORMALIZED) != 0) return;

  RTL_USER_PROCESS_INFORMATION pi;
  if (RtlCreateUserProcessEx(&path, params, FALSE, NULL, &pi) == 0) {
    ResumeThread(pi.ThreadHandle);
  }
}
