@echo off
if "%2" == "-f" del run.cpp

echo Processing
ruby run.rb %1 run.cpp
echo Compiling
g++ -std=c++11 run.cpp -o a.exe -Wall -Werror -Wextra -pedantic -Wconversion -Wno-pedantic-ms-format || (echo Failed & exit /b 1)
echo Running
a.exe
