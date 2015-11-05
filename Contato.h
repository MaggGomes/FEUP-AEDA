#ifndef CONTATO_H_
#define CONTATO_H_

#include <string>
#include <vector>
#include <iostream>

#include "Anuncio.h"

using namespace std;

/**
* @brief Classe Utilizador
*/

class Contato
{
private:
	Anuncio * anuncio;
	std::string mensagem;
	std::string contacto;
	std::string remetente;
public:

	/**
	* @brief Construtor da classe Data
	*/
	Contato(Anuncio * anun, std::string rem,  std::string mens,std::string cont);

	/**
	* @return Retorna o remetente
	*/
	std::string getRementente() const;

	/**
	* @return Retorna a mensagem
	*/
	std::string getMensagem() const;

	/**
	* @return Retorna o contato
	*/
	std::string getContacto() const;

	/**
	* @return Retorna o anuncio
	*/
	Anuncio * getAnuncio() const;

	/**
	* @brief Modifica o remetente
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setRemetente(std::string rem);

	/**
	* @brief Modifica a mensagem
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setMensagem(std::string mens);

	/**
	* @brief Modifica o contato
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setContacto(std::string cont);

};

#endif /*CONTATO_H_*/
