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
	int id;
	Anuncio * anuncio;
	string mensagem;
	string contacto;
	string remetente;
	static int last_id;
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
	* @return Retorna o ID
	*/
	int getID() const;

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

	/**
	* @brief Modifica o ID
	*
	* @param Recebe um parâmetro do tipo int
	*/
	void setID(int nID);

	/**
	* @brief Mostra no ecra o contacto, como se o utilizador em causa foi o que recebeu o contacto
	*/
	void displayContatoRecebido();

	/**
	* @brief Mostra no ecra o contacto, como se o utilizador em causa foi o que enviou o contacto
	*/
	void displayContatoEnviado();

};

#endif /*CONTATO_H_*/
