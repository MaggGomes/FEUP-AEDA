#include "Utilizador.h"

Utilizador::Utilizador(){};

Utilizador::Utilizador(const string &nome, const string &email, int telefone, Localizacao local, const string &password){
	this->nome = nome;
	this->email = email;
	this->telefone = telefone;
	this->local = local;
	this->password = password;
	this->negocios = 0;
}

bool Utilizador::operator<(const Utilizador &uti) const
{
	if (negocios < uti.getNegocios())
		return true;
	else if (negocios == uti.getNegocios())
	{
		if (ultimonegocio < uti.getUltimoNegocio())
			return true;
		else if (ultimonegocio == uti.getUltimoNegocio())
		{
			if (nome < uti.getNome())
				return true;
			else
				return false; //Mesmo se for igual, o que é improvavel, retorna falso
		}
	}

	return false;
}

bool Utilizador::operator==(const Utilizador &uti) const{
	return email == uti.getEmail();
}

void Utilizador::incNegocios(){
	negocios = negocios + 1;
}

int Utilizador::getNegocios() const{
	return negocios;
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

void Utilizador::setNegocios(int num){
	negocios = num;
}

void Utilizador::setDataNegocios(Data data){
	ultimonegocio = data;
}

string Utilizador::getPass() const{
	return password;
}

Data Utilizador::getUltimoNegocio() const
{
	return ultimonegocio;
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

void Utilizador::setUltimoNegocio(Data dt)
{
	ultimonegocio = dt;
}

ostream& operator<<(ostream& os, const Utilizador& user){

	setcolor(3, 0);
	os << " >NOME: ";
	setcolor(7, 0);
	os << setw(10) << user.nome;
	setcolor(3, 0);
	os << "   >EMAIL: ";
	setcolor(7, 0);
	os << setw(20) << user.email;
	setcolor(3, 0);
	os << "   >NEGOCIOS EFETUADOS: ";
	setcolor(7, 0);
	os << user.negocios;
	
	os << endl;

	return os;
}
