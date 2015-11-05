#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include <vector>
#include <iostream>

#include "Utilizador.h"
#include "Data.h"
#include "Contato.h"

using namespace std;

class Utilizador; // Diz ao compilador que a classe Utilizador se encontra definida

class Anuncio
{
private:
	Utilizador* Anunciante;
	string titulo;
	string categoria;
	string descricao;
	vector<string> imagens;
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