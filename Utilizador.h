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
	vector<int> mensagensRecebidas;
	vector<int> mensagensEnviadas;
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
	* @brief Overloading do operador < para que se possa ordenar os utilizaodr na árvore binária de pesquisa
	*/
	bool operator <(const Utilizador &uti) const;

	/**
	* @brief Overloading do operador == para verificar se 2 utilizadores são diferentes
	*/
	bool operator==(const Utilizador &uti) const;

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
	vector<int> getMensRec() const;

	/**
	* @return Retorna as mensagens enviadas
	*/
	vector<int> getMensEnv() const;

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
	* @brief Retira a mensagem com o ID/Anuncio do vetor de Recebidas
	*/
	void deletemsgRec(int id);

	/**
	* @brief Retira a mensagem com o ID/Anuncio do vetor de Enviadas
	*/
	void deletemsgEnv(int id);

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
	* @brief Modifica o vetor de mensagens enviadas
	*
	* @param Recebe um parâmetro do tipo vector<int>
	*/
	void setME(vector<int> vME);

	/**
	* @brief Modifica o vetor de mensagens recebidas
	*
	* @param Recebe um parâmetro do tipo vector<int>
	*/
	void setMR(vector<int> vMR);

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
	string Email() { return email; };
};
#endif /*UTILIZADOR_H_*/
