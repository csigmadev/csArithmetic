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