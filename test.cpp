#include <iostream>
#include <string.h>
#include "csArithmetic.h"

using namespace std;

int main() {
    
    csArithmetic::csAddition::initAdditionTable();
    cout << "Addition table initialized" << endl;

    string a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    char* result = csArithmetic::csAddition::add((char*)a.c_str(), (char*)b.c_str());
    cout << "Result: " << result << endl;
    system("pause");
    return 0;
}