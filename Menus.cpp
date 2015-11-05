#include "Menus.h"

// FALTA TERMINAR - MENU INICIAL

void createMenu()
{
	string Menu[3] = { "<<    CRIAR UTILIZADOR   >>", "<<     PESQUISAR ANUNCIO   >>", "<<    SAIR DE OLZ   >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		// FALTA TERMINAR - IMPRIMIR TITULO QUE SE PRETENDE COLOCAR
		setcolor(11, 0);
		cout << setw(51) << "<<<<<< MENU INICIAL >>>>>>" << endl << endl;

		for (int i = 0; i < 3; ++i)
		{
			if (i == pointer)
			{
				cout << "                            ";
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
					//FALTA ACABAR - Colocar aqui o que é suposto fazer ao selecionar esta opção
					setcolor(7, 0);
					cout << endl << ">> PRESSIONE CIMA/BAIXO PARA VOLTAR AO MENU";
					setcolor(7, 0);
				} break;
				case 2:
					exit(0);
				}
			}
		}
	}
}