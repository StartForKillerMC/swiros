#ifndef __STRING_H__
#define __STRING_H__

#include <swiros/stddef.h>
#include <asm/string.h>
#include <asm/io.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef HAVE_ARCH_MEMCPY
void *memcpy(void *dest, const void *src, size_t count);
#endif

#ifndef HAVE_ARCH_MEMSET
void *memset(void *dest, int val, size_t count);
#endif

#ifndef HAVE_ARCH_STRLEN
size_t strlen(const char *str);
#endif

#ifndef HAVE_ARCH_STRNCPY
char* strncpy(char *dest, const char *src, size_t n);
#endif

#ifndef HAVE_ARCH_STRCPY
char* strcpy(char *dest, const char *src);
#endif

#ifndef HAVE_ARCH_STRCMP
int strcmp(const char *s1, const char *s2);
#endif

#ifndef HAVE_ARCH_STRNCMP
int strncmp(const char *s1, const char *s2, size_t n);
#endif

#ifdef __cplusplus
}
#endif

#endif
