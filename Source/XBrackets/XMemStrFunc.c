#include "XMemStrFunc.h"

// Special form of memcmp implementation to avoid
// compiler from replace this code with memcmp call.
int x_mem_cmp(const void *pSrc1, const void *pSrc2, UINT_PTR nBytes)
{
    if ( pSrc1 != pSrc2 )
    {
        const unsigned int* pSrcUint1 = (const unsigned int *) pSrc1;
        const unsigned int* pSrcUint2 = (const unsigned int *) pSrc2;

        if ( nBytes >= sizeof(unsigned int) )
        {
            BOOL bContinue = TRUE;

            for ( ; bContinue; )
            {
                if ( *pSrcUint1 != *pSrcUint2 )
                    return ( *pSrcUint1 < *pSrcUint2 ? (-1) : 1 );

                nBytes -= sizeof(unsigned int);
                if ( nBytes < sizeof(unsigned int) )
                {
                    bContinue = FALSE;
                }
                ++pSrcUint1;
                ++pSrcUint2;
            }
        }

        if ( nBytes != 0 )
        {
            const unsigned char* pSrcByte1 = (const unsigned char *) pSrcUint1;
            const unsigned char* pSrcByte2 = (const unsigned char *) pSrcUint2;

            for ( ; ; )
            {
                if ( *pSrcByte1 != *pSrcByte2 )
                    return ( *pSrcByte1 < *pSrcByte2 ? (-1) : 1 );
                if ( --nBytes == 0 )
                    break;
                ++pSrcByte1;
                ++pSrcByte2;
            }
        }
    }

    return 0; // equal
}

// Special form of memcpy implementation to avoid
// compiler from replace this code with memcpy call.
void x_mem_cpy(void *pDest, const void *pSrc, UINT_PTR nBytes)
{
    if ( pDest != pSrc )
    {
        unsigned int* pDestUint = (unsigned int *) pDest;
        const unsigned int* pSrcUint = (const unsigned int *) pSrc;

        if ( nBytes >= sizeof(unsigned int) )
        {
            BOOL bContinue = TRUE;

            for ( ; bContinue; )
            {
                *pDestUint = *pSrcUint;
                nBytes -= sizeof(unsigned int);
                if ( nBytes < sizeof(unsigned int) )
                {
                    bContinue = FALSE;
                }
                ++pDestUint;
                ++pSrcUint;
            }
        }

        if ( nBytes != 0 )
        {
            unsigned char* pDestByte = (unsigned char *) pDestUint;
            const unsigned char* pSrcByte = (const unsigned char *) pSrcUint;

            for ( ; ; )
            {
                *pDestByte = *pSrcByte;
                if ( --nBytes == 0 )
                    break;
                ++pDestByte;
                ++pSrcByte;
            }
        }
    }
}

// Special form of memset implementation to avoid
// compiler from replace this code with memset call.
void x_mem_set(void *pDest, unsigned int c, UINT_PTR nBytes)
{
    c &= 0xFF;

    if ( c != 0 )
    {
        unsigned int* pDestUint = (unsigned int *) pDest;

        if ( nBytes >= sizeof(unsigned int) )
        {
            unsigned int nValue = c + (c << 8) + (c << 16) + (c << 24);
            BOOL bContinue = TRUE;

            for ( ; bContinue; )
            {
                *pDestUint = nValue;
                nBytes -= sizeof(unsigned int);
                if ( nBytes < sizeof(unsigned int) )
                {
                    bContinue = FALSE;
                }
                ++pDestUint;
            }
        }

        if ( nBytes != 0 )
        {
            unsigned char *pDestByte = (unsigned char *) pDestUint;

            for ( ; ; )
            {
                *pDestByte = (unsigned char) c;
                if ( --nBytes == 0 )
                    break;
                ++pDestByte;
            }
        }
    }
    else
    {
        x_zero_mem(pDest, nBytes);
    }
}

// Special form of ZeroMemory implementation to avoid
// compiler from replace this code with memset call
void x_zero_mem(void* pDest, UINT_PTR nBytes)
{
    unsigned int* pDestUint = (unsigned int *) pDest;

    if ( nBytes >= sizeof(unsigned int) )
    {
        BOOL bContinue = TRUE;

        for ( ; bContinue; )
        {
            *pDestUint = 0;
            nBytes -= sizeof(unsigned int);
            if ( nBytes < sizeof(unsigned int) )
            {
                bContinue = FALSE;
            }
            ++pDestUint;
        }
    }

    if ( nBytes != 0 )
    {
        unsigned char *pDestByte = (unsigned char *) pDestUint;

        for ( ; ; )
        {
            *pDestByte = 0;
            if ( --nBytes == 0 )
                break;
            ++pDestByte;
        }
    }
}

void* x_mem_alloc(SIZE_T nSizeInBytes)
{
    return SysMemAlloc(nSizeInBytes);
}

void  x_mem_free(void* ptr)
{
    SysMemFree(ptr);
}

