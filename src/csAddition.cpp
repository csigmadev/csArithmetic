#include "csArithmetic.h"
#include "csArithmeticUtils.h"

using namespace std;

cs2Digits** additionTable;

inline void makeAddition(char* a, char* b, char*& result, size_t opSize, size_t& resultSize)
{
    cs2Digits prevCarry = {'0', '0'};
    size_t m = opSize-1;

    char* i = a + m, *j = b + m, *_j = b, *k = result + opSize;
    for (; j >= _j; i--, j--)
    {
        cs2Digits current = additionTable[*i][*j];
        cs2Digits currentSum = additionTable[current.units][prevCarry.units];

        prevCarry = additionTable[current.tens][currentSum.tens];
        *k = currentSum.units;
        k--;
    }
    *k = prevCarry.units;

    csArithmeticUtils::deleteFrontZero(result, resultSize);
    
}

namespace csArithmetic 
{

cs2Digits** to2DigitsTable(int **table)
{
    cs2Digits** result = (cs2Digits**)malloc(58 * sizeof(cs2Digits*));
    for (int i = 0; i < 58; i++)
    {
        result[i] = (cs2Digits*)malloc(58 * sizeof(cs2Digits));
    }
    for (int i = 48; i < 58; i++)
    {
        for (int j = 48; j < 58; j++)
        {
            result[i][j].units = table[i][j] % 10 + '0'; // '0' is 48 in ASCII
            result[i][j].tens = table[i][j] / 10 + '0'; // '0' is 48 in ASCII
        }
    }
    return result;
}

namespace csAddition {

void initAdditionTable()
{
    int** table = (int**)malloc(58 * sizeof(int*));
    for (int i = 0; i < 58; i++)
    {
        table[i] = (int*)malloc(58 * sizeof(int));
    }

    for (int i = 48; i < 58; i++)
    {
        for (int j = 48; j < 58; j++)
        {
            //table[i][j] = i-48 + j-48;
            table[i][j] = i + j - 96;
        }
    }

    additionTable = to2DigitsTable(table);

    for (int i = 0; i < 58; i++) free(table[i]);
    free(table);
}
        
char* add(char* a, char* b) 
{
    size_t opSize;
    char* a1 = 0, *b1 = 0;

    csArithmeticUtils::prepareOperandsForAddition(a, b, opSize, a1, b1);
    
    size_t resultSize = opSize + 1;
    char* result = csMemoryUtils::csAllocCharInit(resultSize, '0');
    makeAddition(a1, b1, result, opSize, resultSize);
    
    free(a1);
    free(b1);
    return result;

}


}

}