#ifndef OLZ_H_
#define OLZ_H_

#include "Utilizador.h"

/**
* @brief Classe OLZ que armazena todos utilizadores e anúncios da aplicação
*/
class OLZ
{
private:
	vector<Utilizador> utilizadores;
	vector <Anuncio *> anuncios;
public:

	/**
	* @brief Construtor default da classe OLZ
	*/
	OLZ();

	/**
	* @brief Destructor da classe OLZ que remove todos os anúncios
	*/
	~OLZ();

	/**
	* @brief Destructor da classe OLZ
	*
	* @return Retorna vetor com os utilizadores registados
	*/
	vector<Utilizador> getUtilizadores() const;

	/**	
	* @return Retorna vetor com os anuncios
	*/
	vector<Anuncio *> getAnuncios() const;

	/**
	* @brief Adiciona um utilizador
	*/
	void addUtilizador(Utilizador user);

	/**
	* @brief Adiciona um anuncio
	*/
	void addAnuncio(Anuncio * anunc);
};

#endif OLZ_H_