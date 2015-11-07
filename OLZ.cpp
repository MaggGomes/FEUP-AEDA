#include "OLZ.h"

OLZ::OLZ(){
	vector <Utilizador> usertemp;
	utilizadores = usertemp;
	vector <Anuncio * >  anunctemp;
	anuncios = anunctemp;
	userLogado = false;
}

OLZ::~OLZ(){
	
	for (unsigned int i = 0; i < anuncios.size(); i++){
		delete anuncios[i];
	}
}

vector<Utilizador> OLZ::getUtilizadores() const{
	return utilizadores;
}

vector<Anuncio *> OLZ::getAnuncios() const{
	return anuncios;
}

void OLZ::addUtilizador(Utilizador user){
	utilizadores.push_back(user);
}

void OLZ::addAnuncio(Anuncio * anunc){
	anuncios.push_back(anunc);
}

string OLZ::registarNome() {

	string nomeTemp;
	clrscr();
	impressaoTitulo();

	cout << ">> NICKNAME DE UTILIZADOR (entre 3 e 12 caracteres): ";
	getline(cin, nomeTemp);

	try{
		if (cin.fail() || nomeTemp.length() < 3 || nomeTemp.length() > 12)
			throw nomeTemp;
	}
	catch (...){
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Nickname invalido! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);	
		registarNome();
	}
		
	return nomeTemp;
}

bool OLZ::setVisNome() {

	string vis;

	clrscr();
	impressaoTitulo();

	cout << ">> DESEJA QUE O SEU NOME FIQUE VISIVEL? (<S>im / <N>ao): ";
	getline(cin, vis);

	try{
		if (cin.fail() || vis.length() != 1 )
			throw vis;
		if (vis == "s" || vis == "S")
			return true;
		if (vis == "n" || vis == "N")
			return false;

		throw vis;
	}
	catch (...){
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Opcao invalida! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		setVisNome();
	}	
}

string OLZ::registarEmail(){

	string emailTemp;

	clrscr();
	impressaoTitulo();

	cout << ">> E-MAIL: ";
	getline(cin, emailTemp);

	try{
		if (cin.fail() || !validaEmail(emailTemp) || existeEmail(emailTemp))			//Caso o cin falhe, ou o mail nao seja válido ou já exista
			throw emailTemp;
	}
	catch (...){
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: E-mail invalido! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		registarEmail();
	}

	return emailTemp;
}

bool OLZ::setVisEmail() {
	return true;
}

bool OLZ::validaEmail(string mail)
{
	bool oneat = false;

	for (unsigned int i = 0; i < mail.size(); i++)
	{
		if (oneat == true && mail[i] == '@')				//Se ler mais que um @
			return false;
		else if (oneat == false && mail[i] == '@')			//Ao ler um @, faz set ao oneat
			oneat = true;
	}

	return oneat;
}

bool OLZ::existeEmail(string mail)
{
	for (unsigned int i = 0; i < utilizadores.size(); i++)
	{
		if (mail == utilizadores[i].getEmail())
			return true;
	}

	return false;
}

int OLZ::registarTelefone(){

	int tlfTemp;

	clrscr();
	impressaoTitulo();

	cout << ">> TELEFONE (9 digitos): ";
	cin >> tlfTemp;
	cin.ignore(100, '\n');

	try{
		if (cin.fail() || tlfTemp < 900000000 || tlfTemp > 999999999 || existeTelefone(tlfTemp))
			throw tlfTemp;
	}
	catch (...){
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Telefone invalido! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(800);
		registarTelefone();
	}
	
	return tlfTemp;
}

bool OLZ::setVisTelefone(){

	string vis;

	clrscr();
	impressaoTitulo();

	cout << ">> DESEJA QUE O SEU TELEFONE FIQUE VISIVEL? (<S>im / <N>ao): ";
	getline(cin, vis);
	

	try{
		if (cin.fail() || vis.length() != 1)
			throw vis;
		if (vis == "s" || vis == "S")
			return true;
		if (vis == "n" || vis == "N")
			return false;

		throw vis;
	}
	catch (...){
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Opcao invalida! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		setVisTelefone();
	}
}

bool OLZ::existeTelefone(int tele)
{
	for (unsigned int i = 0; i < utilizadores.size(); i++)
	{
		if (tele == utilizadores[i].getTelefone())
			return true;
	}

	return false;
}

Localizacao OLZ::registarLoc(){

	string fregTemp = registarFreg();
	string concTemp = registarConc();
	string distTemp = registarDistr();

	Localizacao temp(fregTemp, concTemp, distTemp);
	return temp;
}

bool OLZ::validarLocal(string local)
{
	for (unsigned int i = 0; i < local.size(); i++)
	{
		if (local[i] < 'A' || local[i] > 'z' || (local[i] < 'a' && local[i] > 'Z'))
			return false;
	}

	return true;
}


string OLZ::registarFreg()
{
	string fregTemp;

	clrscr();
	impressaoTitulo();

	cout << ">> FREGUESIA ONDE MORA :";
	getline(cin, fregTemp);

	try
	{
		if (cin.fail() || !validarLocal(fregTemp))
			throw fregTemp;
	}
	catch(...)
	{
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Freguesia invalida! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		registarFreg();
	}

	return fregTemp;
}

string OLZ::registarConc()
{
	string concTemp;

	clrscr();
	impressaoTitulo();

	cout << ">> CONCELHO ONDE MORA :";
	getline(cin, concTemp);

	try
	{
		if (cin.fail() || !validarLocal(concTemp))
			throw concTemp;
	}
	catch (...)
	{
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Concelho invalido! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		registarFreg();
	}

	return concTemp;
}

string OLZ::registarDistr()
{
	string distrTemp;

	clrscr();
	impressaoTitulo();

	cout << ">>  DISTRITO ONDE MORA :";
	getline(cin, distrTemp);

	try
	{
		if (cin.fail() || !validarLocal(distrTemp))
			throw distrTemp;
	}
	catch (...)
	{
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Distrito invalido! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(800);
		registarFreg();
	}

	return distrTemp;
}

string OLZ::setPass(){

	// PASSWORD DEVE TER ENTRE 6 E 12 CARACTERES

	string passTemp;

	clrscr();
	impressaoTitulo();

	cout << " >> PASSWORD : ";
	getline(cin, passTemp);

	try
	{
		if (cin.fail() || passTemp.size() < 6 || passTemp.size() > 12 || !validarPassword(passTemp))
			throw passTemp;
	}
	catch (...)
	{
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Password invalida! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		setPass();
	}

	return passTemp;
}

bool OLZ::validarPassword(string pass)
{
	for (unsigned int i = 0; i < pass.size(); i++)
	{
		if (pass[i] == ' ')
			return false;
	}

	return true;
}

void OLZ::registar() {		
	//string emailTemp;
	//Localizacao locTemp;	
	//bool vis_emailTemp = true;



	string nomeTemp = registarNome();
	bool vis_nomeTemp = setVisNome();

	string emailTemp = registarEmail();
	bool vis_emailTemp = setVisEmail();

	string passTemp = setPass();

	int tlfTemp = registarTelefone();
	bool vis_telefoneTemp = setVisTelefone();

	Localizacao locTemp = registarLoc();
	
		
	

	Utilizador userTemp(nomeTemp, emailTemp, tlfTemp, locTemp, passTemp);
	userTemp.setVisNome(vis_nomeTemp);
	userTemp.setVisEmail(vis_emailTemp);	
	userTemp.setVisTelefone(vis_telefoneTemp);
	utilizadores.push_back(userTemp);

	userLogado = true;
	userOnline = emailTemp;
	createMenuLogado();
}

void OLZ::logar(){
	
	string emailTemp, nomeTemp;
	string passTemp = "";
	int i = 0;
	bool validaEmail = false;
	bool validaPass = false;

	clrscr();
	impressaoTitulo();

	cout << ">> E-MAIL DE UTILIZADOR: ";
	getline(cin, emailTemp);
	
	// Verifica a existência do email

	try{
		if (cin.fail())
			throw emailTemp;

		for (unsigned int i = 0; i < utilizadores.size(); i++){
			if (utilizadores[i].getEmail() == emailTemp){
				validaEmail = true;
				nomeTemp = utilizadores[i].getNome();
				break;
			}
		}

		if (!validaEmail)
			throw emailTemp;
	}
	catch (...){
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: E-mail de registo nao encontrado! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		logar();
	}

	while (i < 3 && !validaPass){ // Verifica se a password está correta; O utilizador tem 3 tentativas para efetuar o login
		passTemp = "";
		int tentativas = 3 - i;
		clrscr();
		impressaoTitulo();

		if (i == 0){
			setcolor(10, 0);
			cout << ":: AVISO: Tem " << tentativas << " tentativas restante(s)." << endl << endl;
			setcolor(7, 0);
		}

		if (i == 1){
			setcolor(14, 0);
			cout << ":: AVISO: Tem " << tentativas << " tentativas restante(s)." << endl << endl;
			setcolor(7, 0);
		}
		if (i == 2){
			setcolor(4, 0);
			cout << ":: AVISO: Tem " << tentativas << " tentativas restante(s)." << endl << endl;
			setcolor(7, 0);
		}

		cout << ">> PASSWORD DE UTILIZADOR: ";
		char ch;
		
		while ((ch = _getch()) != 13){

			if (ch == 8){
				if (passTemp.length() != 0){
					cout << "\b \b";
					passTemp.resize(passTemp.length() - 1);
				}
				
			}
			else if (ch == 0 || ch == 224) 
			{

				_getch(); 
				continue;
			}
			else{
				passTemp += ch;
				cout << '*';
			}
		}

		cout << endl;

		try{
			if (passTemp.length() < 6 || passTemp.length() > 12)
				throw passTemp;

			for (unsigned int i = 0; i < utilizadores.size(); i++){
				if (utilizadores[i].getEmail() == emailTemp){
					if (utilizadores[i].getPass() == passTemp)
						validaPass = true;
					break;
				}
			}

			if (!validaPass)
				throw passTemp;
		}
		catch (...){
			clean_buffer();
			setcolor(4, 0);
			cout << ":: ERRO: Password invalida! Tente novamente." << endl << endl;
			setcolor(7, 0);
			Sleep(1000);
		}

		i++;
	}

	if (!validaPass){
		setcolor(4, 0);
		cout << ":: ERRO: Falhou login! Voltando ao Menu Iniciar..." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		createMenuInicial();
	}
	
	clrscr();
	impressaoTitulo();
	setcolor(10, 0);
	cout << endl << endl << setw(40) <<":: BENVINDO "<< nomeTemp<<" !!!" << endl << endl;
	setcolor(7, 0);
	Sleep(2000);

	userLogado = true;
	userOnline = emailTemp;
	createMenuLogado();
}

// FALTA IMPLEMENTAR

void OLZ::criaAnuncio(){

	Utilizador * userTemp;
	string titTemp;
	try
	{
		userTemp = pesquisaEmail(userOnline);
	}
	catch (EmailNaoEncontrado)					//Caso haja um problema na base de dados
	{
		clrscr();
		impressaoTitulo();
		cout << "Houve um problema com a base de dados. O seu email não está registado. Registe-se novamente por favor" << endl;
		userLogado = false;
		userOnline = "";
		createMenuInicial();
	}

	return;

}

void OLZ::setuserLogado(bool &log){
	userLogado = log;
}

bool OLZ::getuserLogado() const{
	return userLogado;
}

void OLZ::createMenuInicial(){
	string Menu[4] = { "<<   VISITANTE        >>", "<<   UTILIZADOR       >>", "<<   ADMINISTRADOR    >>", "<<   SAIR             >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(51) << "<<<<< MENU INICIAL >>>>>" << endl << endl;

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
					pointer = 3;
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
					createMenuVisitante();
					break;
				case 1:
					validade = false;
					createMenuUser();
					break;
				case 2:
					validade = false;
					createMenuAdmin();
					break;
				case 3:
					exiting();
				}
			}
		}
	}
}

void OLZ::createMenuVisitante(){
	string Menu[4] = { "<<   MENU INICIAL     >>", "<<   REGISTAR         >>", "<<   PESQUISAR        >>", "<<   SAIR             >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(51) << "<<<<<  VISITANTE   >>>>>" << endl << endl;

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
					pointer = 3;
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
					validade = false;
					registar();
					break;
				case 2:
					validade = false;
					createMenuPesquisaVis();
					break;
				case 3:
					exiting();
				}
			}
		}
	}
}

void OLZ::createMenuUser(){
	string Menu[3] = { "<<   MENU INICIAL     >>", "<<   LOGIN            >>", "<<   SAIR             >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(51) << "<<<<<    LOGIN     >>>>>" << endl << endl;

		for (int i = 0; i < 3; ++i)
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
					createMenuInicial();
					break;
				case 1:
					validade = false;
					logar();
					break;
				case 2:
					exiting();
				}
			}
		}
	}
}

// FALTA TERMINAR

void OLZ::createMenuLogado(){
	string Menu[6] = { "<<   MENU INICIAR     >>", "<<   CRIAR ANUNCIO    >>", "<<   MEUS ANUNCIOS    >>", "<<   PESQUISA ANUNCIO >>", "<<   VER CONTATOS     >>", "<<   SAIR             >>" };
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
					pointer = 5;
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
					userLogado = false;
					createMenuInicial();
					break;
				case 1:
					validade = false;
					// FALTA IMPLEMENTAR
					break;
				case 2:
					createMenuAnuncios();
				case 3:
					createMenuPesquisaUser();
				case 4:
					exiting();// FALTA IMPLEMENTAR
				case 5:
					exiting();
				}
			}
		}
	}
}

void OLZ::createMenuAnuncios(){
	string Menu[6] = { "<<   MENU USER        >>", "<<   VER TODOS        >>", "<<   MAIS RECENTE     >>", "<<   MAIS CLICKS      >>", "<<   COM INTERESSADOS >>", "<<   SAIR             >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(51) << "<<<<<   ANUNCIOS   >>>>>" << endl << endl;

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
					pointer = 5;
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
					createMenuLogado();
					break;
				case 1:
					validade = false;
					exiting(); // FALTA IMPLEMENTAR
					break;
				case 2:
					exiting(); // FALTA IMPLEMENTAR
				case 3:
					exiting(); //FALTA IMPLEMENTAR
				case 4:
					exiting();// FALTA IMPLEMENTAR
				case 5:
					exiting();
				}
			}
		}
	}
}


// FALTA TERMINAR

void OLZ::createMenuAdmin(){
	string Menu[4] = { "<<   MENU INICIAL     >>", "<<   GERIR USERS      >>", "<<   GERIR ANUNCIOS   >>", "<<   SAIR             >>" };
	bool validade = true;
	int pointer = 0;

	while (validade)
	{
		clrscr();
		impressaoTitulo();
		setcolor(11, 0);
		cout << setw(51) << "<<<<<    ADMIN     >>>>>" << endl << endl;

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
					pointer = 3;
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
					validade = false;
					// FALTA OPÇAO PARA GERIR USERS
					break;
				case 2:
					validade = false;
					// FALTA OPÇÃO PARA GERIR ANUNCIOS
					break;
				case 3:
					exiting();
				}
			}
		}
	}
}

// FALTA TERMINAR

void OLZ::createMenuPesquisaVis(){
	string Menu[6] = { "<<   MENU INICIAR     >>", "<<   CATEGORIA        >>", "<<   LOCALIZACAO      >>", "<<   PALAVRA-CHAVE    >>", "<<   PRECO            >>", "<<   SAIR             >>" };
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
					pointer = 5;
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
					userLogado = false;
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
					exiting(); // FALTA IMPLEMENTAR
				case 3:
					exiting();  // FALTA IMPLEMENTAR
				case 4:
					exiting();// FALTA IMPLEMENTAR
				case 5:
					exiting();
				}
			}
		}
	}
}

// FALTA TERMINAR

void OLZ::createMenuPesquisaUser(){
	string Menu[6] = { "<<   MENU USER        >>", "<<   CATEGORIA        >>", "<<   LOCALIZACAO      >>", "<<   PALAVRA-CHAVE    >>", "<<   PRECO            >>", "<<   SAIR             >>" };
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
					pointer = 5;
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
					createMenuLogado();
					break;
				case 1:
					exiting(); // FALTA IMPLEMENTAR
				case 2:
					exiting(); // FALTA IMPLEMENTAR
				case 3:
					exiting();  // FALTA IMPLEMENTAR
				case 4:
					exiting();// FALTA IMPLEMENTAR
				case 5:					
					exiting();
				}
			}
		}
	}
}

void OLZ::saveData()
{
	ofstream utFile; // variavel que vai conter o vector de Utilizadores
	ofstream anFile; // variavel que vai conter o vector de Anuncios
	
	remove("utilizadores.csv");	
	utFile.open("utilizadores.csv");
	
	for (unsigned int i = 0; i < utilizadores.size(); i++)
	{
		Utilizador temp = utilizadores[i];
		utFile << temp.getNome() << ";" << temp.getEmail() << ";" << temp.getTelefone() << ";" << temp.getLocalizacao().getFreguesia() << ";" << temp.getLocalizacao().getConcelho() << ";" << temp.getLocalizacao().getDistrito() << ";";

		for (unsigned int j = 0; j < temp.getMensRec().size(); j++)
		{
			utFile << temp.getMensRec()[j].getAnuncio()->getID() << ";" << temp.getMensRec()[j].getContacto() << ";" << temp.getMensRec()[j].getMensagem() << ";" << temp.getMensRec()[j].getRemetente() << ";";
		}

		for (unsigned int j = 0; j < temp.getMensEnv().size(); j++)
		{
			utFile << temp.getMensEnv()[j].getAnuncio()->getID() << ";" << temp.getMensEnv()[j].getContacto() << ";" << temp.getMensEnv()[j].getMensagem() << ";" << temp.getMensEnv()[j].getRemetente() << ";";
		}
		utFile << temp.getVisNome() << ";" << temp.getVisEmail() << ";" << temp.getVisTelefone() << "\n";
	}

	utFile.close();

	remove("anuncios.csv");
	anFile.open("anuncios.csv");

	for (unsigned int i = 0; i < anuncios.size(); i++)
	{
		Anuncio * temp = anuncios[i];
		anFile << temp->getAnunciante()->getEmail() << ";" << temp->getTitulo() << ";" << temp->getCategoria() << ";" << temp->getDescricao() << ";" << temp->getID() << ";";
		for (unsigned int j = 0; j < temp->getImagens().size(); j++)
		{
			anFile << temp->getImagens()[j] << ";";
		}

		anFile << temp->getDataCriacao().getDia() << ";" << temp->getDataCriacao().getMes() << ";" << temp->getDataCriacao().getAno() << ";" << temp->getNegociar() << ";" << temp->getClicks() << ";" << temp->getPreco() << ";";
		
		if (temp->isVenda())
		{ 
			anFile << temp->getEstado() << "\n";
		}
		else
		{
			for (size_t i = 0; i < temp->getTroca().size(); i++)
			{
				if (i >= temp->getTroca().size() - 1)
					anFile << temp->getTroca()[i].getID() << "\n";
				else
					anFile << temp->getTroca()[i].getID() << ";";
			}
		}
	}

	anFile.close();
}

void OLZ::loadData()
{

}

Utilizador * OLZ::pesquisaEmail(string mail)
{
	for (unsigned int i = 0; i < utilizadores.size(); i++)
	{
		if (utilizadores[i].getEmail() == mail)
			return &utilizadores[i];
	}

	EmailNaoEncontrado m(mail);
	throw(m);
}

bool OLZ::validarTitulo(string tit)
{
	if (tit.size() < 1 || tit.size() > 30)
		return false;
	else
		return true;
}

/*string OLZ::registarTitulo()
{
	string titTemp;

	clrscr();
	impressaoTitulo();

	cout << ">> TITULO DO ANUNCIO (menos de 30 caracteres) :";
	getline(cin, titTemp);

	try
	{
		if (cin.fail() || !validarTitulo(titTemp))
			throw titTemp;
	}
	catch (...)
	{
		clean_buffer();
		setcolor(4, 0);
		cout << ":: ERRO: Titulo invalido! Tente novamente." << endl << endl;
		setcolor(7, 0);
		Sleep(1000);
		registarTitulo();
	}

	return titTemp;
}*/