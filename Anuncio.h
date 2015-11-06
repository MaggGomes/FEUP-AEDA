#ifndef ANUNCIO_H_
#define ANUNCIO_H_

#include <vector>
#include <iostream>
#include <ctime>

#include "Utilizador.h"
#include "Data.h"
#include "Contato.h"

using namespace std;

class Utilizador; // Diz ao compilador que a classe Utilizador se encontra definida

/**
* @brief Classe base Anuncio
*/
class Anuncio
{
public:
	Utilizador * Anunciante;
	string titulo;
	string categoria;
	string descricao;
	int id;
	vector <string> imagens;
	Data datacriacao;
	bool possivelNegociar;
	int num_clicks;
	float preco;
	static int last_id;  // falta inicializar
 
	/**
	* @brief Construtor da classe Anuncio
	*/
	Anuncio(Utilizador * ut,string tit,string cat,string des,bool pNeg,float pr);
	
	/**
	* @return Retorna o anunciante
	*/
	Utilizador * getAnunciante() const;
	
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
	* @brief Modifica o título do anuncio
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setTitulo(string tit);
	/**
	* @brief Modifica a categoria do anuncio
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setCategoria(string cat);
	/**
	* @brief Modifica a descrição do anuncio
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setDescricao(string desr);
	/**
	* @brief Modifica o id do anuncio
	*
	* @param Recebe um parâmetro do tipo int
	*/
	void setId(int tId);
	/**
	* @brief Modifica a data de criação do anuncio
	*
	* @param Recebe um parâmetro do tipo Data
	*/
	void setDataCriacao(Data dt);
	/**
	* @brief Modifica se a possibilidade de negociar o anuncio
	*
	* @param Recebe um parâmetro do tipo bool
	*/
	void setPossivelNegociar(bool neg);
	/**
	* @brief Modifica o número de clicks do anuncio
	*
	* @param Recebe um parâmetro do tipo int
	*/
	void setNum_clicks(int clicks);

	/**
	* @brief Adiciona um click ao anuncio
	*/
	void addClick();

	/**
	* @brief Modifica o preço do anuncio
	*
	* @param Recebe um parâmetro do tipo float
	*/
	void setPreco(float pr);
	/**
	* @brief Função virtual pura que será implementada nas classes derivadas e que irá permitir visualizar o anúncio
	*/
	virtual void visAnuncio() = 0;
	/**
	* @return Retorna ture/false conforme seja ou não anuncio de venda
	*/
	virtual bool isVenda() const = 0;
};

/**
* @brief Classe derivada AnuncioVenda
*/

class AnuncioVenda: public Anuncio
{
private:
	string estado;
public:

	/**
	* @brief Construtor da classe AnuncioVenda
	*/
	AnuncioVenda(Utilizador * ut, string tit, string cat, string des, bool pNeg, float pr, string est);
	/**
	* @return Retorna o estado do artigo
	*/
	string getEstado();

	void setEstado(string est);
	/**
	* @brief Permite a visualização do anunucio
	*/
	void visAnuncio();
	/**
	* @return Retorna true pois é um anuncio de venda
	*/
	bool isVenda() const;
};

/**
* @brief Classe derivada AnuncioCompra
*/

class AnuncioCompra: public Anuncio
{
private:
	vector<AnuncioVenda> troca;
public:

	/**
	* @brief Construtor da classe AnuncioCompra
	*/
	AnuncioCompra(Utilizador * ut, string tit, string cat, string des, bool pNeg, float pr, vector<AnuncioVenda> tr);
	/**
	* @return Retorna o vetor com os anuncios pelos quais o utilizador está disposta a trocar
	*/
	vector<AnuncioVenda> getTroca();
	/**
	* @brief Modifica os anuncios para troca
	*
	* @param Recebe um parâmetro do tipo vector<Anuncio>
	*/
	void setTroca(vector<AnuncioVenda> tr);
	/**
	* @brief Permite a visualização do anunucio
	*/
	void visAnuncio();
	/**
	* @return Retorna false pois não é um anuncio de venda
	*/
	bool isVenda() const;

};

#endif /*ANUNCIO_H_*/