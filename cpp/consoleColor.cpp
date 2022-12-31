#include <windows.h>

void consoleColor(int backgroundColor, int textColor){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((backgroundColor << 4) | textColor));
}
