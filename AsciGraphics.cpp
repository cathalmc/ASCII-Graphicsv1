//Real basic ASCII graphics

#include <iostream>
#include <cwchar>
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS

void printline(int length,char pix = '#') {
    for (int i = 0; i < length; i++) {
        std::cout << pix;
    }

    std::cout << std::endl;
}

int main()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 8;                   // Width of each character in the font
    cfi.dwFontSize.Y = 8;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Arial"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    int size = 20;

    while (1) {
        for (int i = 0; i < size; i++) {
            printline(size);
        }
        Sleep(200);
        std::cout << "\x1B[2J\x1B[H";
        for (int i = 0; i < size; i++) {
            printline(size, '0');
        }
        Sleep(200);
        std::cout << "\x1B[2J\x1B[H";
    }

}
