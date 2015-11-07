#include "Contato.h"

Contato::Contato(Anuncio * anun, string rem, string mens, string cont)
{
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
void Contato::setRemetente(std::string rem){
	remetente = rem;
}

void Contato::setMensagem(std::string mens){
	mensagem = mens;
}

void Contato::setContacto(std::string cont){
	contacto = cont;
}