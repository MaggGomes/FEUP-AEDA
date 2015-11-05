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
	vector<Anuncio *> anuncios;
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
	Utilizador(const string &nome, const string &email, int telefone, Localizacao loc);

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
	* @return Retorna os an�ncios do utilizador
	*/
	vector<Anuncio *> getAnuncios() const;

	/**
	* @return Retorna se o utilizador quer o nome vis�vel
	*/
	bool getVisNome() const;

	/**
	* @return Retorna se o utilizador quer o email vis�vel
	*/
	bool getVisEmail() const;

	/**
	* @return Retorna se o utilizador quer o telefone vis�vel
	*/
	bool getVisTelefone() const;

	/**
	* @brief Adiciona um contato ao vetor de contatos recebidos
	*
	* @param Recebe um par�metro do tipo Contato
	*/
	void addmsgRec(Contato cont);

	/**
	* @brief Adiciona um contato ao vetor do tipo contatos enviados
	*
	* @param Recebe um par�metro do tipo Contato
	*/
	void addmsgEnv(Contato cont);
	
	/**
	* @brief Imprime as mensagens recebidas
	*/
	void lerMensagens() const;			//L� todas as mensagens recebidas atrav�s de cada um dos an�ncios

	/**
	* @brief Adiciona um anuncio ao vetor de anuncios
	*
	* @param Recebe um par�metro do tipo Anuncio
	*/
	void addAnuncio(Anuncio* anuncio);

	/**
	* @brief Modifica o email
	*
	* @param Recebe um par�metro do tipo string
	*/
	void setEmail(const string& email);

	/**
	* @brief Modifica a localizacao
	*
	* @param Recebe um par�metro do tipo Localizacao
	*/
	void setLocalizacao(const Localizacao& localizacao);

	/**
	* @brief Modifica a visibilidade o nome
	*
	* @param Recebe um par�metro do tipo string
	*/
	void setNome(const string& nome);

	/**
	* @brief Modifica o telefone
	*
	* @param Recebe um par�metro do tipo inteiro
	*/
	void setTelefone(int telefone);

	/**
	* @brief Modifica a visibilidade do email
	*
	* @param Recebe um par�metro do tipo booleano
	*/
	void setVisEmail(bool visEmail);

	/**
	* @brief Modifica a visibilidade do nome
	*
	* @param Recebe um par�metro do tipo booleano
	*/
	void setVisNome(bool visNome);

	/**
	* @brief Modifica a visibilidade do telefone
	*
	* @param Recebe um par�metro do tipo booleano
	*/
	void setVisTelefone(bool visTelefone);

	/**
	* @brief Overload do operator << para os dados vis�veis do utilizador
	*
	* @param Recebe um par�metro do tipo Utilizador e do tipo ostream para permitir imprimir os dados do utilizador
	*/
	friend ostream& operator<<(ostream& os, const Utilizador& user);
};

#endif /*UTILIZADOR_H_*/
