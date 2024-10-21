#ifndef WIN_C_WINDOWS_USER32_H
#define WIN_C_WINDOWS_USER32_H

extern int MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption,
					   unsigned int uType);
extern int MessageBoxW(void* hWnd, const unsigned short* lpText,
					   const unsigned short* lpCaption, unsigned int uType);

#endif
