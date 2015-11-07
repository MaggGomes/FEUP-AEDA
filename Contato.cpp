#include "Contato.h"

int Contato::last_id = 1;

Contato::Contato(Anuncio * anun, string rem, string mens, string cont)
{
	id = last_id;
	last_id++;
	anuncio = anun;
	mensagem = rem;
	contacto = mens;
	remetente = cont;
}


std::string Contato::getRemetente() const {
	return remetente;
}


std::string Contato::getMensagem() const {
	return mensagem;
}

std::string Contato::getContacto() const {
	return contacto;
}

Anuncio * Contato::getAnuncio() const{
	return anuncio;
}

int Contato::getID() const
{
	return id;
}

void Contato::setRemetente(std::string rem){
	remetente = rem;
}

void Contato::setMensagem(std::string mens){
	mensagem = mens;
}

void Contato::setContacto(std::string cont){
	contacto = cont;
}

void Contato::setID(int tid)
{
	id = tid;
}