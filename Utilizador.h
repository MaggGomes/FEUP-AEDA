#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <vector>
#include <iostream>

#include "Localizacao.h"
#include "Anuncio.h"
#include "Contato.h"


using namespace std;

class Contato; // Diz ao compilador que a classe Contato se encontra definida
class Anuncio; // // Diz ao compilador que a classe Anuncio se encontra definida

/**
* @brief Classe Utilizador
*/
class Utilizador {
	string nome;
	string email;
	int telefone;
	Localizacao local;
	string password;
	vector<Contato> mensagensRecebidas;
	vector<Contato> mensagensEnviadas;
	bool vis_nome;
	bool vis_email;
	bool vis_telefone;

public:

	/**
	* @brief Construtor Default da classe Utilizador
	*/
	Utilizador();

	/**
	* @brief Construtor da classe Utilizador
	*/
	Utilizador(const string &nome, const string &email, int telefone, Localizacao loc, const string &password);

	/**
	* @return Retorna o nome
	*/
	string getNome() const;

	/**
	* @return Retorna o email
	*/
	string getEmail() const;

	/**
	* @return Retorna o telefone
	*/
	int getTelefone() const;

	/**
	* @return Retorna a localizacao
	*/
	Localizacao getLocalizacao() const;

	/**	
	* @return Recebe um parâmetro do tipo string que corresponde à password
	*/
	string getPass() const;

	/**
	* @return Retorna as mensagens recebidas
	*/
	vector<Contato> getMensRec() const;

	/**
	* @return Retorna as mensagens enviadas
	*/
	vector<Contato> getMensEnv() const;

	/**
	* @return Retorna se o utilizador quer o nome visível
	*/
	bool getVisNome() const;

	/**
	* @return Retorna se o utilizador quer o email visível
	*/
	bool getVisEmail() const;

	/**
	* @return Retorna se o utilizador quer o telefone visível
	*/
	bool getVisTelefone() const;

	/**
	* @brief Adiciona um contato ao vetor de contatos recebidos
	*
	* @param Recebe um parâmetro do tipo Contato
	*/
	void addmsgRec(Contato cont);

	/**
	* @brief Adiciona um contato ao vetor do tipo contatos enviados
	*
	* @param Recebe um parâmetro do tipo Contato
	*/
	void addmsgEnv(Contato cont);
	
	/**
	* @brief Imprime as mensagens recebidas
	*/
	void lerMensagens() const;			//Lê todas as mensagens recebidas através de cada um dos anúncios

	/**
	* @brief Modifica o email
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setEmail(const string& email);

	/**
	* @brief Modifica a localizacao
	*
	* @param Recebe um parâmetro do tipo Localizacao
	*/
	void setLocalizacao(const Localizacao& localizacao);

	/**
	* @brief Modifica a visibilidade o nome
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setNome(const string& nome);

	/**
	* @brief Modifica o telefone
	*
	* @param Recebe um parâmetro do tipo inteiro
	*/
	void setTelefone(int telefone);

	/**
	* @brief Modifica password
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setPass(const string &pass);

	/**
	* @brief Modifica a visibilidade do email
	*
	* @param Recebe um parâmetro do tipo booleano
	*/
	void setVisEmail(bool visEmail);

	/**
	* @brief Modifica a visibilidade do nome
	*
	* @param Recebe um parâmetro do tipo booleano
	*/
	void setVisNome(bool visNome);

	/**
	* @brief Modifica a visibilidade do telefone
	*
	* @param Recebe um parâmetro do tipo booleano
	*/
	void setVisTelefone(bool visTelefone);

	/**
	* @brief Overload do operator << para os dados visíveis do utilizador
	*
	* @param Recebe um parâmetro do tipo Utilizador e do tipo ostream para permitir imprimir os dados do utilizador
	*/

	friend ostream& operator<<(ostream& os, const Utilizador& user);
};

class EmailNaoEncontrado
{
private:
	string email;

public:
	EmailNaoEncontrado(string mail) { email = mail; };
	string getEmail() { return email; };
};
#endif /*UTILIZADOR_H_*/
