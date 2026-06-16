#ifndef CS_ARITHMETIC_H
#define CS_ARITHMETIC_H

#include <iostream>
#include <string.h>


typedef struct
{
    char units, tens;
} cs2Digits;

namespace csArithmetic 
{
    cs2Digits** to2DigitsTable(int **table);
    namespace csAddition 
    {
        void initAdditionTable();
        char* add(char* a, char* b);
    }
}


#endif