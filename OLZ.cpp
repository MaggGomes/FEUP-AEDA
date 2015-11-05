#include "OLZ.h"

OLZ::OLZ(){
	vector <Utilizador> usertemp;
	utilizadores = usertemp;
	vector <Anuncio * >  anunctemp;
	anuncios = anunctemp;
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
