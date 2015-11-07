#include <string>

#include "Menus.h"
#include "Functions.h"

using namespace std;

// FALTA TERMINAR - MENU INICIAL

void createMenuInicial()
{
	string Menu[3] = { "<<    CRIAR UTILIZADOR   >>", "<<     PESQUISAR ANUNCIO   >>", "<<    SAIR DE OLZ   >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscreen();
		// FALTA TERMINAR - IMPRIMIR TITULO QUE SE PRETENDE COLOCAR
		set_color(11, 0);
		cout << setw(51) << "<<<<<< MENU INICIAL >>>>>>" << endl << endl;

		for (int i = 0; i < 3; ++i)
		{
			if (i == pointer)
			{
				cout << "                            ";
				set_color(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				set_color(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		set_color(7, 0);

		while (validade)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 3)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}

			if (ch == '\r')
			{
				set_color(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validade = false;
					break;
				case 1:
				{
					clrscreen();
					//FALTA ACABAR - Colocar aqui o que é suposto fazer ao selecionar esta opção
					set_color(7, 0);
					cout << endl << ">> PRESSIONE CIMA/BAIXO PARA VOLTAR AO MENU";
					set_color(7, 0);
				} break;
				case 2:
					exit(0);
				}
			}
		}
	}
}

// FALTA TERMINAR

void createMenuPesquisa()
{
	string Menu[3] = { "<<    CRIAR UTILIZADOR   >>", "<<     PESQUISAR ANUNCIO   >>", "<<    SAIR DE OLZ   >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscreen();
		// FALTA TERMINAR - IMPRIMIR TITULO QUE SE PRETENDE COLOCAR
		set_color(11, 0);
		cout << setw(51) << "<<<<<< MENU INICIAL >>>>>>" << endl << endl;

		for (int i = 0; i < 3; ++i)
		{
			if (i == pointer)
			{
				cout << "                            ";
				set_color(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				set_color(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		set_color(7, 0);

		while (validade)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 3)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}

			if (ch == '\r')
			{
				set_color(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validade = false;
					break;
				case 1:
				{
					clrscreen();
					//FALTA ACABAR - Colocar aqui o que é suposto fazer ao selecionar esta opção
					set_color(7, 0);
					cout << endl << ">> PRESSIONE CIMA/BAIXO PARA VOLTAR AO MENU";
					set_color(7, 0);
				} break;
				case 2:
					exit(0);
				}
			}
		}
	}
}