@echo off
setlocal

where g++ >nul 2>&1
if errorlevel 1 (
    echo Erreur: g++ introuvable. Installez MinGW-w64 ou equivalent et ajoutez-le au PATH.
    exit /b 1
)

if not exist bin mkdir bin

echo Compilation du projet csArithmetic...
g++ -std=c++17 -Wall -Iinclude test.cpp src\*.cpp -o bin\csArithmetic.exe
if errorlevel 1 (
    echo Echec de la compilation.
    pause
    rem exit /b 1
)


echo Compilation reussie.
echo.
bin\csArithmetic.exe

endlocal
