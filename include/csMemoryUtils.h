/*
 * csArithmetic - arithmetic on large numbers
 * Copyright (C) 2026 csigmadev
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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