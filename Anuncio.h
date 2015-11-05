#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include <vector>
#include <iostream>

#include "Utilizador.h"
#include "Data.h"
#include "Contato.h"

using namespace std;

class Utilizador; // Diz ao compilador que a classe Utilizador se encontra definida


/**
* @brief Classe Anuncio
*/
class Anuncio
{
private:
	Utilizador* Anunciante;
	string titulo;
	string categoria;
	string descricao;
	int id;
	Data datacriacao;
	bool possivelNegociar;
	int num_clicks;
	vector<Contato> mensagens;
	float preco;
	static int last_id;  // falta inicializar
public: 
	/**
	* @brief Construtor da classe Contato
	*/
	Anuncio(Utilizador ut,string tit,string cat,string des,bool pNeg,float pr);
	/**
	* @return Retorna o titulo
	*/
	string getTitulo() const; 
	/**
	* @return Retorna a categoria
	*/
	string getCategoria() const;
	/**
	* @return Retorna a descrição
	*/
	string getDescricao() const;
	/**
	* @return Retorna o vetor que contem as imagens
	*/
	vector<string> getImagens() const;
	/**
	* @return Retorna o id do anuncio
	*/
	int getID() const;
	/**
	* @return Retorna a data de criaçao do anuncio
	*/
	Data getDataCriacao()  const;
	/**
	* @return Retorna se o preço é negociavel
	*/
	bool getNegociar() const;
	/**
	* @return Retorna o numero de vezes que o anuncio foi "clickado"
	*/
	int getClicks() const;
	/**
	* @return Retorna o preço de venda/compra
	*/
	float getPreco() const;
	/**
	* @return Retorna se o anuncio é de venda ou não
	*/
	virtual bool isVenda() const;


	void enviaMensagem(Anuncio an, Contato ct);
	virtual void visAnuncio();
};



class AnuncioVenda: public Anuncio
{
private:
	string estado;
public:
	string getEstado();
	void setEstado();
	bool isVenda();
	void visAnuncio();
};

class AnuncioCompra: public Anuncio
{
private:
	vector<Anuncio> troca;
public:
	string getTroca();
	void setTroca();
	bool isVenda();
	void visAnuncio();
};

#endif /*ANUNCIO_H_*/