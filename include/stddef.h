#ifndef WIN_C_STDDEF_H
#define WIN_C_STDDEF_H

#define offsetof(TYPE, MEMBER) __builtin_offsetof(TYPE, MEMBER)

#define NULL ((void*) 0)

typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __WCHAR_TYPE__ wchar_t;
typedef __SIZE_TYPE__ size_t;
typedef double max_align_t;

#endif
