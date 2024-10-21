#ifndef WIN_C_CRT_ENTRY_H
#define WIN_C_CRT_ENTRY_H

#define va_start(ap, arg) __builtin_va_start((ap), (arg))
#define va_arg			  __builtin_va_arg
#define va_copy			  __builtin_va_copy
#define va_end(ap)		  __builtin_va_end((ap))

#endif
