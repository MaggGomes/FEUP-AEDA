#ifndef OLZ_H_
#define OLZ_H_

#include <fstream>

#include "Utilizador.h"
#include "Functions.h"

/**
* @brief Classe OLZ que armazena todos utilizadores e anúncios da aplicação
*/
class OLZ
{
private:
	vector<Utilizador> utilizadores;
	vector <Anuncio *> anuncios;
	bool userLogado;
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
	
	/**
	* @ Brief Regista o nome
	*
	* @return Retorna o nome do utilizador
	*/
	string registarNome();

	/**
	* @brief Regista se o nome fica visível
	*
	* @return Retorna a visibilidade do nome do utilizador
	*/
	bool setVisNome();

	/**
	* @brief Regista o email
	*
	* @return Retorna o email do utilizador
	*/
	string registarEmail();

	/**
	* @brief Regista se o email fica visível
	*
	* @return Retorna a visibilidade do email do utilizador
	*/
	bool setVisEmail();

	/**
	* @brief Verifica se o email tem o caracter @
	* 
	* @return Se tiver o @, retorna true, senão retorna false
	*/
	bool validaEmail(string mail);

	/**
	* @brief Verifica se o email é igual ao email de outros utilizadores
	*
	* @return Se for igual, retorna true. Se não houver nenhum igual, retorna false
	*/
	bool comparaEmail(string mail);

	/**
	* @brief Regista o telefone do utilizador
	*
	* @return Retorna o telefone do utilizador
	*/
	int registarTelefone();

	/**
	* @brief Regista se o telefone fica visível
	*
	* @return Retorna se o telefone fica visível
	*/
	bool setVisTelefone();

	/**
	* @Brief regista a localizacao do utilizador
	*
	* @return a localizacao do utilizador
	*/
	Localizacao registarLoc();

	/**
	* @brief cria e regista um utilizador
	*/
	void registar();

	/**
	* @brief Especifica se o utilizador está ou não logado
	*/
	void setuserLogado(bool &log);
	
	/**
	* @brief Retorna um booleano se o utilizador está ou não logado
	*/
	bool getuserLogado() const;

	/**
	* @brief Menu Inicial
	*/
	void createMenuInicial();

	/**
	* @brief Menu Visitante
	*/
	void createMenuVisitante();

	/**
	* @brief Menu Utilizador
	*/
	void createMenuUser();

	/**
	* @brief Menu Utilizador Logado
	*/
	void createMenuLogado();

	/**
	* @brief Menu Administrador
	*/
	void createMenuAdmin();
		
	/**
	* @brief Menu Pesquisa
	*/
	void createMenuPesquisa();

	/**
	* @brief Guarda todos os dados criados em dois ficheiros .txt
	*/
	void saveData();


	/**
	* @brief Carrega todos os dados de dois ficheiros .txt para os vetores correspondentes
	*/
	void loadData();
};

#endif /*OLZ_H_*/