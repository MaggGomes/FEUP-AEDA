#include <string>

#include "Menus.h"

using namespace std;

// FALTA TERMINAR - MENU INICIAL

void createMenuInicial(){
	string Menu[4] = { "<<       LOGIN        >>", "<<     CRIAR USER     >>","<<  PESQUISA ANUNCIO  >>", "<<        SAIR        >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout<<setw(51)<< "<<<<< MENU INICIAL >>>>>" << endl << endl;

		for (int i = 0; i < 4; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setcolor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setcolor(3, 0);
				cout  <<setw(51)<< Menu[i] << endl << endl;
			}
		}
		setcolor(7, 0);

		while (validade)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 4)
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
				setcolor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validade = false;
					break;
				case 1:
				{
					clrscr();
					//showScore(); - SUBSTITUIR - implementar funcionalidade
					setcolor(7, 0);
					cout << endl << ">> PRESSIONE CIMA/BAIXO PARA VOLTAR AO MENU";
					setcolor(7, 0);
				} break;
				case 2:
					createMenuPesquisa();
				case 3:
					exit(0);
				}
			}
		}
	}
}

// FALTA TERMINAR

void createMenuUser(){
	string Menu[6] = { "<<    MENU INICIAR    >>", "<<    CRIAR ANUNCIO   >>", "<<    MEUS ANUNCIOS   >>", "<<  PESQUISA ANUNCIO  >>", "<<    VER CONTATOS    >>", "<<        SAIR        >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(51) << "<<<<<  UTILIZADOR  >>>>>" << endl << endl;

		for (int i = 0; i < 6; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setcolor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setcolor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setcolor(7, 0);

		while (validade)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 6)
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
				setcolor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validade = false;
					createMenuInicial();
					break;
				case 1:
				{// FALTA IMPLMENTAR
					clrscr();
					//showScore(); - SUBSTITUIR - implementar funcionalidade
					setcolor(7, 0);
					cout << endl << ">> PRESSIONE CIMA/BAIXO PARA VOLTAR AO MENU";
					setcolor(7, 0);
				} break;
				case 2:
					exit(0); // FALTA IMPLEMENTAR
				case 3:
					exit(0);  // FALTA IMPLEMENTAR
				case 4:
					exit(0);// FALTA IMPLEMENTAR
				case 5:
					exit(0);
				}
			}
		}
	}
}

// FALTA TERMINAR MENU PESQUISA
void createMenuPesquisa(){
	string Menu[6] = { "<<    MENU INICIAR    >>", "<<      CATEGORIA     >>", "<<     LOCALIZACAO    >>", "<<    PALAVRA-CHAVE   >>", "<<        PRECO       >>","<<        SAIR        >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(51) << "<<<<<   PESQUISA   >>>>>" << endl << endl;

		for (int i = 0; i < 6; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setcolor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setcolor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setcolor(7, 0);

		while (validade)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 6)
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
				setcolor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validade = false;
					createMenuInicial();
					break;
				case 1:
				{// FALTA IMPLMENTAR
					clrscr();
					//showScore(); - SUBSTITUIR - implementar funcionalidade
					setcolor(7, 0);
					cout << endl << ">> PRESSIONE CIMA/BAIXO PARA VOLTAR AO MENU";
					setcolor(7, 0);
				} break;
				case 2:
					exit(0); // FALTA IMPLEMENTAR
				case 3:
					exit(0);  // FALTA IMPLEMENTAR
				case 4:
					exit(0);// FALTA IMPLEMENTAR
				case 5:
					exit(0);
				}
			}
		}
	}
}