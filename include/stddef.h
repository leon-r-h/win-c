#ifndef WIN_C_STDDEF_H
#define WIN_C_STDDEF_H

#include "win-c/null.h"
#ifdef WIN_C_NULL_H
#endif

#define offsetof(TYPE, MEMBER) __builtin_offsetof(TYPE, MEMBER)

typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __WCHAR_TYPE__ wchar_t;
typedef __SIZE_TYPE__ size_t;
typedef typeof(nullptr) nullptr_t;
typedef double max_align_t;

#endif
