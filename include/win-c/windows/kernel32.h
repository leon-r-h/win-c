#ifndef WIN_C_WINDOWS_KERNEL32_H
#define WIN_C_WINDOWS_KERNEL32_H

// TODO: Add hard defined stdint.h and uchar.h types, make API more C-like

/* Enum for Codepage IDs, used by the Windows API */
enum win_c_kernel32_codepage : unsigned int {
	WIN_C_KERNEL32_CODEPAGE_ACP = 0,	  // Windows standard-codepage (ANSI)
	WIN_C_KERNEL32_CODEPAGE_OEMCP = 1,	  // OEM codepage
	WIN_C_KERNEL32_CODEPAGE_MACCP = 2,	  // Macintosh codepage
	WIN_C_KERNEL32_CODEPAGE_THR_ACP = 3,  // Codepage for current thread setting
	WIN_C_KERNEL32_CODEPAGE_SYMBOL = 42,  // Symbol

	WIN_C_KERNEL32_CODEPAGE_UTF7 = 65000,  // UTF-7 codepage
	WIN_C_KERNEL32_CODEPAGE_UTF8 = 65001   // UTF-8 codepage
};

extern unsigned short* GetCommandLineW(void);
extern char* GetCommandLineA(void);
extern void LocalFree(void* hMem);
extern int WideCharToMultiByte(enum win_c_kernel32_codepage CodePage, unsigned long dwFlags,
							   unsigned short* lpWideCharStr, int cchWideChar, char* lpMultiByteStr, int cbMultiByte,
							   const char* lpDefaultChar, bool* lpUsedDefaultChar);
extern void* LocalAlloc(unsigned int uFlags, unsigned long uBytes);
extern void ExitProcess(unsigned int uExitCode);
extern int lstrlenW(const unsigned short* lpString);

#endif
