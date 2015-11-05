#include <string>

#include "Utilizador.h"

using namespace std;

Utilizador(const std::string &nome, const std::string &email, int telefone, Localizacao localizacao){
	this->nome = nome;
	this->email = email;
	this-> telefone = telefone;
	this->localizacao = localizacao;
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
	return localizacao;
}

vector<Anuncio *> Utilizador::getAnuncios() const{
	return anuncios;
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
	mensagensRecebidas.push_back(cont);
}

void Utilizador::addmsgEnv(Contato cont){
	mensagensEnviadas.push_back(cont);
}

void Utilizador::lerMensagens() const{	

	for (unsigned int i = 0; i < mensagensRecebidas.size(); i++){
		cout << "Nome: " << mensagensRecebidas.size()[i].getRemetente() << endl;
		cout << "Contato: " << mensagensRecebidas.size()[i].getContacto() << endl << endl;
		cout << "Mensagem: "<<mensagensRecebidas.size()[i].getMensagem() << endl << endl;
	}
}

void Utilizador::addAnuncio(Anuncio* anuncio){
	anuncios.push_back(anuncio);
}

void Utilizador::setEmail(const string& email){
	this->email = email;
}

void Utilizador::setLocalizacao(const Localizacao& localizacao){
	this->localizacao = localizacao;
}

void Utilizador::setNome(const string& nome){
	this->nome = nome;
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

ostream& operator<<(ostream& os, const Utilizador& user){
	
	if (vis_nome)
		os << "Nome: " << nome << endl;
	if (vis_email)
		os << "Email: " << email << endl;
	if (vis_telefone)
		os << "Telefone: " << telefone << endl;

	if (!vis_nome && !vis_email && !vis_telefone)
		os << "O Utilizador nao pertende mostrar as suas informações. " << endl;

	os << endl;

	return os;
}
