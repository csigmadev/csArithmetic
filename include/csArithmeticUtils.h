#ifndef CS_ARITHMETICUTILS_H
#define CS_ARITHMETICUTILS_H

#include "csMemoryUtils.h"
using namespace std;

namespace csArithmeticUtils {
    inline void deleteLeftZero(char*& chrString, size_t& chrSize, size_t delLen)
    {
        size_t diff = chrSize - delLen;
        char* result = csMemoryUtils::csAllocChar(diff);
        for (size_t i = delLen, j=0; i < chrSize; i++, j++)
        {
            result[j] = chrString[i];
        }
        free(chrString);
        chrString = result;
        chrSize = diff;
    }
    inline bool deleteFrontZero(char*& result, size_t& resultSize)
    {
        for (size_t i = 0; i < resultSize; i++)
        {
            if (result[i] != '0')
            {
                if(i > 0)
                {
                    deleteLeftZero(result, resultSize, i);
                    return true;
                }
                return false;
            }
        }
        
        return false;
    }
    inline void prepareOperandsForAddition(char* a, char* b, size_t& opSize, char*& a1, char*& b1)
    {
        size_t aSize = strlen(a);
        size_t bSize = strlen(b);

        
        a1 = csMemoryUtils::csAllocChar(aSize);
        b1 = csMemoryUtils::csAllocChar(bSize);

        opSize = std::max(aSize, bSize);

        if (aSize == bSize)
        {
            char* aptr = a, *bptr = b, *aptrEnd = a + aSize, *bptrEnd = b + bSize, *aptr1 = a1, *bptr1 = b1;
            for (;aptr < aptrEnd; aptr++, aptr1++)
            {
                *aptr1 = *aptr;
            }
            for (;bptr < bptrEnd; bptr++, bptr1++)
            {
                *bptr1 = *bptr;
            }
        }
        else if (opSize > bSize)
        {
            size_t delta = opSize - bSize;
            b1 = csMemoryUtils::csReallocChar(b1, opSize);

            char* aptr = a, *bptr = b, *bptrEnd = b + bSize, *aptr1 = a1, *bptr1 = b1, *_bptr1 = b1 + delta, *_aptr1 = a1 + aSize;
            for (; bptr < bptrEnd; bptr++, _bptr1++)
            {
                *_bptr1 = *bptr;
            }

            _bptr1 = b1 + delta;

            for (; bptr1 < _bptr1; bptr1++)
            {
                *bptr1 = '0';
            }

            for (;aptr1 < _aptr1; aptr++, aptr1++)
            {
                *aptr1 = *aptr;
            }
        }
        else if (opSize > aSize)
        {
            size_t delta = opSize - aSize;
            a1 = csMemoryUtils::csReallocChar(a1, opSize);

            char* aptr = a, *bptr = b, *aptrEnd = a + aSize, *aptr1 = a1, *bptr1 = b1, *_bptr1 = b1 + bSize, *_aptr1 = a1 + delta;
            for (; aptr < aptrEnd; aptr++, _aptr1++)
            {
                *_aptr1 = *aptr;
            }
            _aptr1 = a1 + delta;
            for (; aptr1 < _aptr1; aptr1++)
            {
                *aptr1 = '0';
            }

            for (;bptr1 < _bptr1; bptr++, bptr1++)
            {
                *bptr1 = *bptr;
            }
        }
    }
}
#endif