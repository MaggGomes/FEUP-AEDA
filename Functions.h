#include <iostream>
#include <windows.h>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <conio.h>

#include "Variables.h"

using namespace std;

void clrscr(void)
{
	COORD coordScreen = { 0, 0 }; // Canto superior esquerdo
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Preenchimento com espaços
	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	// Cursor no canto superior esquerdo
	SetConsoleCursorPosition(hCon, coordScreen);
}

void setcolor(unsigned int color, unsigned int background_color) // Altera a cor das letras da consola
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (background_color == BLACK)
		SetConsoleTextAttribute(hCon, color);
	else
		SetConsoleTextAttribute(hCon, color | BACKGROUND_BLUE | BACKGROUND_GREEN |
		BACKGROUND_RED);
}