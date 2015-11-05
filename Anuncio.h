#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include <string>
#include <vector>
#include <iostream>

#include "Data.h"
#include "Contato.h"
#include "Utilizador.h"

using namespace std;

class Anuncio
{
private:
	Utilizador Anunciante;
	std::string titulo;
	std::string categoria;
	std::string descricao;
	vector<std::string> imagens;
	int id;
	Data datacriacao;
	bool possivelNegociar;
	int num_clicks;
	vector<Contato> mensagens;
	float preco;
	static int last_id;  // falta inicializar
public:
	Anuncio(Utilizador ut);
};



class AnuncioVenda: public Anuncio
{

};

class AnuncioCompra: public Anuncio
{

};

#endif /*ANUNCIO_H_*/