#include "Utilizador.h"

Utilizador::Utilizador(){};

Utilizador::Utilizador(const string &nome, const string &email, int telefone, Localizacao local){
	this->nome = nome;
	this->email = email;
	this-> telefone = telefone;
	this->local = local;
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

vector<Contato> Utilizador::getMensRec() const{
	return mensagensRecebidas;
}

vector<Contato> Utilizador::getMensEnv() const {
	return mensagensEnviadas;
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
		cout << "Nome: " << mensagensRecebidas[i].getRemetente() << endl;
		cout << "Contato: " << mensagensRecebidas[i].getContacto() << endl << endl;
		cout << "Mensagem: "<<mensagensRecebidas[i].getMensagem() << endl << endl;
	}
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
