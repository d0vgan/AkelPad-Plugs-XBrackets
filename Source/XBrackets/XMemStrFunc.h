#ifndef _mem_str_func_h_
#define _mem_str_func_h_
//---------------------------------------------------------------------------
#include <windows.h>

#define SysMemAlloc(sizeInBytes) (void *) GlobalAlloc( GMEM_FIXED, (sizeInBytes) )
#define SysMemFree(ptr)          GlobalFree( (HGLOBAL) (ptr) )

// memcmp
int x_mem_cmp(const void *pSrc1, const void *pSrc2, UINT_PTR nBytes);

// memcpy
void x_mem_cpy(void *pDest, const void *pSrc, UINT_PTR nBytes);

// memset
void x_mem_set(void *pDest, unsigned int c, UINT_PTR nBytes);

// ZeroMemory
void x_zero_mem(void* pDest, UINT_PTR nBytes);

// allocates a memory block; to be freed with x_mem_free
void* x_mem_alloc(UINT_PTR nSizeInBytes);

// deallocates a memory block allocated with x_mem_alloc
void  x_mem_free(void* ptr);

// Note: str and substr must not be NULL!
BOOL x_wstr_startswith(const WCHAR* str, const WCHAR* substr);
int  x_wstr_cmp(const WCHAR* str1, const WCHAR* str2);

//---------------------------------------------------------------------------
#endif
