#include "Utilizador.h"

Utilizador::Utilizador(){};

Utilizador::Utilizador(const string &nome, const string &email, int telefone, Localizacao local, const string &password){
	this->nome = nome;
	this->email = email;
	this-> telefone = telefone;
	this->local = local;
	this->password = password;
}

bool Utilizador::operator <(const Utilizador &uti) const{
	return nome < uti.getNome();
}

bool Utilizador::operator==(const Utilizador &uti) const{
	return email == uti.getEmail();
}

string Utilizador::getNome() const{
	return nome;
}

string Utilizador::getEmail() const{
	return email;
}

int Utilizador::getTelefone() const{
	return telefone;
}

Localizacao Utilizador::getLocalizacao() const{
	return local;
}

vector<int> Utilizador::getMensRec() const{
	return mensagensRecebidas;
}

vector<int> Utilizador::getMensEnv() const {
	return mensagensEnviadas;
}

string Utilizador::getPass() const{
	return password;
}

bool Utilizador::getVisNome() const{
	return vis_nome;
}

bool Utilizador::getVisEmail() const{
	return vis_email;
}

bool Utilizador::getVisTelefone() const{
	return vis_telefone;
}

void Utilizador::addmsgRec(Contato cont){
	mensagensRecebidas.push_back(cont.getID());
}

void Utilizador::addmsgEnv(Contato cont){
	mensagensEnviadas.push_back(cont.getID());
}

void Utilizador::deletemsgRec(int id)
{
	for (int i = 0; i < mensagensRecebidas.size(); i++)
	{
		if (mensagensRecebidas[i] == id)
		{
			mensagensRecebidas.erase(mensagensRecebidas.begin() + i);
			return;
		}
	}

	return;
}

void Utilizador::deletemsgEnv(int id)
{
	for (int i = 0; i < mensagensEnviadas.size(); i++)
	{
		if (mensagensEnviadas[i] == id)
		{
			mensagensEnviadas.erase(mensagensEnviadas.begin() + i);
			return;
		}
	}

	return;
}

void Utilizador::setEmail(const string& email){
	this->email = email;
}

void Utilizador::setLocalizacao(const Localizacao& local){
	this->local = local;
}

void Utilizador::setNome(const string& nome){
	this->nome = nome;
}

void Utilizador::setPass(const string &pass){
	password = pass;
}

void Utilizador::setTelefone(int telefone){
	this->telefone = telefone;
}

void Utilizador::setVisEmail(bool visEmail){
	vis_email = visEmail;
}

void Utilizador::setVisNome(bool visNome){
	vis_nome = visNome;
}

void Utilizador::setVisTelefone(bool visTelefone){
	vis_telefone = visTelefone;
}

void Utilizador::setME(vector<int> vME)
{
	mensagensEnviadas = vME;
}

void Utilizador::setMR(vector<int> vMR)
{
	mensagensRecebidas = vMR;
}
ostream& operator<<(ostream& os, const Utilizador& user){
	
	if (user.vis_nome)
		os << "Nome: " << user.nome << endl;
	if (user.vis_email)
		os << "Email: " << user.email << endl;
	if (user.vis_telefone)
		os << "Telefone: " << user.telefone << endl;

	if (!user.vis_nome && !user.vis_email && !user.vis_telefone)
		os << "O Utilizador nao pertende mostrar as suas informações. " << endl;

	os << endl;

	return os;
}
