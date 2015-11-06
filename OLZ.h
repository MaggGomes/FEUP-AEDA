#ifndef OLZ_H_
#define OLZ_H_

#include <fstream>

#include "Utilizador.h"
#include "Functions.h"

/**
* @brief Classe OLZ que armazena todos utilizadores e an�ncios da aplica��o
*/
class OLZ
{
private:
	vector<Utilizador> utilizadores;
	vector <Anuncio *> anuncios;
	string userOnline; // Infica qual o e-mail do utilizador que efetuou login
	bool userLogado;
public:

	/**
	* @brief Construtor default da classe OLZ
	*/
	OLZ();

	/**
	* @brief Destructor da classe OLZ que remove todos os an�ncios
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
	* @brief Regista se o nome fica vis�vel
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
	* @brief Regista se o email fica vis�vel
	*
	* @return Retorna a visibilidade do email do utilizador
	*/
	bool setVisEmail();

	/**
	* @brief Verifica se o email tem o caracter @
	* 
	* @return Se tiver o @, retorna true, sen�o retorna false
	*/
	bool validaEmail(string mail);

	/**
	* @brief Verifica se o email � igual ao email de outros utilizadores
	*
	* @return Se for igual, retorna true. Se n�o houver nenhum igual, retorna false
	*/
	bool existeEmail(string mail);

	/**
	* @brief Regista o telefone do utilizador
	*
	* @return Retorna o telefone do utilizador
	*/
	int registarTelefone();

	/**
	* @brief Regista se o telefone fica vis�vel
	*
	* @return Retorna se o telefone fica vis�vel
	*/
	bool setVisTelefone();

	/**
	* @brief Regista a password de utilizador
	*
	* @return Retorna a password que � um par�metro do tipo string
	*/
	string setPass();
	
	/**
	* @brief Verifica se o telefone ja existe
	*
	* @return Retorna true se ja existe, false caso contr�rio
	*/
	bool existeTelefone(int tele);

	/**
	* @brief regista a localizacao do utilizador
	*
	* @return a localizacao do utilizador
	*/
	Localizacao registarLoc();

	/**
	* @brief cria e regista um utilizador
	*/
	void registar();

	/**
	* @brief Especifica se o utilizador est� ou n�o logado
	*/
	void setuserLogado(bool &log);
	
	/**
	* @brief Retorna um booleano se o utilizador est� ou n�o logado
	*/
	bool getuserLogado() const;

	/**
	* @brief Verifica a valida��o do nickname e password do Utilizador e loga o mesmo na sua conta de utilizador
	*/
	void logar();

	/**
	* @brief Cria um an�ncio
	*/
	void criaAnuncio();

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
	* @brief Menu Pesquisa Visitante
	*/
	void createMenuPesquisaVis();

	/**
	* @brief Menu Pesquisa Utilizador
	*/
	void createMenuPesquisaUser();

	/**
	* @brief Menu Meus Anuncios do utilizador
	*/
	void createMenuAnuncios();

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