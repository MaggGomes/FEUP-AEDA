#ifndef CONTATO_H_
#define CONTATO_H_

#include <string>
#include <vector>
#include <iostream>

#include "Anuncio.h"

using namespace std;

class Anuncio; // Diz ao compilador que a classe Anuncio se encontra definida

/**
* @brief Classe Contato
*/
class Contato
{
private:
	Anuncio * anuncio;
	string mensagem;
	string contacto;
	string remetente;
public:

	/**
	* @brief Construtor da classe Contato
	*/
	Contato(Anuncio * anun, string rem, string mens, string cont);

	/**
	* @return Retorna o remetente
	*/
	string getRemetente() const;

	/**
	* @return Retorna a mensagem
	*/
	string getMensagem() const;

	/**
	* @return Retorna o contato
	*/
	string getContacto() const;

	/**
	* @return Retorna o anuncio
	*/
	Anuncio* getAnuncio() const;

	/**
	* @brief Modifica o remetente
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setRemetente(string rem);

	/**
	* @brief Modifica a mensagem
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setMensagem(string mens);

	/**
	* @brief Modifica o contato
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setContacto(string cont);
};

#endif /*CONTATO_H_*/
