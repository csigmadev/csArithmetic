#ifndef CS_MEMORYUTILS_H
#define CS_MEMORYUTILS_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

namespace csMemoryUtils {
    
    inline char* csAllocChar(size_t size) 
    {
        char* str = (char*)malloc((size + 1) * sizeof(char));
        str[size] = '\0';

        return str;
    }

    inline char* csReallocChar(char* str, size_t size) 
    {
        str = (char*)realloc(str, (size + 1) * sizeof(char));
        str[size] = '\0';

        return str;
    }

    inline char* csAllocCharInit(size_t size, char value)
    {
        char* ptr = csAllocChar(size);
        char* ptrBegin = ptr, *ptrEnd = ptr + size;
        for (; ptrBegin < ptrEnd; ptrBegin++)
        {
            *ptrBegin = value;
        }
        return ptr;
    }
}

#endif