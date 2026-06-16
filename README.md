# csArithmetic

A C++ library for arithmetic on large numbers, built step by step as part of **educational videos** on programming and how arithmetic operations work at the processor level.

The goal is to understand and implement fundamental operations (**addition**, **subtraction**, **multiplication**, **division**) by treating numbers as character strings, without relying on the language's native numeric types.

## Project status

| Operation      | Status           |
|----------------|------------------|
| Addition       | ✅ Implemented   |
| Subtraction    | 🔜 Coming soon   |
| Multiplication | 🔜 Coming soon   |
| Division       | 🔜 Coming soon   |

## Approach

Numbers are represented as character strings (`char*`). Each digit is processed individually, allowing values beyond native integer limits.

Addition uses a precomputed **lookup table** (`initAdditionTable`) that maps each pair of digits to a two-digit result (`cs2Digits`: units and tens). Adding two large numbers is then done digit by digit, right to left, with carries handled through this table.

## Project structure

```
csArithmetic/
├── include/
│   ├── csArithmetic.h        # Public API
│   ├── csArithmeticUtils.h   # Utilities (alignment, leading zero removal...)
│   └── csMemoryUtils.h       # Memory allocation
├── src/
│   ├── csAddition.cpp        # Addition (implemented)
│   ├── csSubstraction.cpp    # Subtraction (coming soon)
│   ├── csMultiplication.cpp  # Multiplication (coming soon)
│   └── csDivision.cpp        # Division (coming soon)
├── test.cpp                  # Interactive test program
└── compileRun.cmd            # Build and run (Windows)
```

## Requirements

- **g++** (C++17 or later) — [MSYS2 UCRT64](https://www.msys2.org/) recommended on Windows
- `g++` available in your `PATH`

## Build and run

```cmd
compileRun.cmd
```

Or manually:

```cmd
g++ -std=c++17 -Wall -Iinclude test.cpp src\*.cpp -o bin\csArithmetic.exe
bin\csArithmetic.exe
```

The program prompts for two numbers and prints their sum.

## API usage

```cpp
#include "csArithmetic.h"

// Initialize the addition table (once at startup)
csArithmetic::csAddition::initAdditionTable();

// Add two numbers represented as strings
char* result = csArithmetic::csAddition::add("123", "456");
// result -> "579"
```

## Videos

This repository accompanies an educational video series. Links for each operation will be added here as episodes are published.

<!-- Example:
- [Episode 1 — Introduction and addition](https://...)
-->

## License

This project is licensed under the [GNU General Public License v3.0](LICENSE) (GPL-3.0).

Copyright (C) 2026 csigmadev

---

Maintained by [csigmadev](https://github.com/csigmadev).
