#include "Functions.h"

void clrscr(void)
{
	COORD coordScreen = { 0, 0 }; // Canto superior esquerdo
	DWORD cCharsWritten;
	DWORD dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Preenchimento com espa�os
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

void impressaoTitulo()
{
	setcolor(3, 0);

	string titulo = "###############################################################################\n##                            ____  _      ______                            ##\n##                           / __ \\| |    |___  /                            ##\n##                          | |  | | |       / /                             ##\n##                          | |  | | |      / /                              ##\n##                          | |__| | |____ / /__                             ##\n##                           \\____/|______/_____|                            ##\n##                                                                           ##\n###############################################################################";
	

	cout << titulo << endl << endl;

	setcolor(7, 0);
}

void exiting(){
	clrscr();
	impressaoTitulo();
	setcolor(11, 0);
	cout << endl<<endl<<setw(51) << "<<<<<<<<<<<<+>>>>>>>>>>>>" << endl;
	cout << setw(51) << "<<<<<               >>>>>" << endl;
	cout << setw(51) << "<<<<< A SAIR DE OLZ >>>>>" << endl;
	cout << setw(51) << "<<<<<               >>>>>" << endl;
	cout << setw(51) << "<<<<<<<<<<<<+>>>>>>>>>>>>" << endl << endl << endl;
	setcolor(7, 0);
	exit(0);
}

void clean_buffer()
{
	if (cin.fail())
	{
		cin.ignore(1000, '\n');
		cin.clear();
	}

	cin.clear();
	fflush(stdin);

}

string hidePass(){
	string pass = "";
	char ch;
	ch = _getch();
	while (ch != 13){//character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}

	return pass;
}

bool searchWordInString(string w, string s)
{
	unsigned int count = 0;
	if (w.size() > s.size())				//Se a palavra a procurar foi maior que a string
		return false;							
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (tolower(s[i]) == tolower(w[count]))
				count++;
			else
				count = 0;

			if (count == w.size())			//Se tiver verificado que a sequencia existe
				return true;
		}

		return false;
	}
}

void PressKeyToContinue()
{
	setcolor(11, 0);
	cout << " >Pressione qualquer tecla para voltar ao MENU anterior. " << flush;
	setcolor(7, 0);
	_getch();
}
