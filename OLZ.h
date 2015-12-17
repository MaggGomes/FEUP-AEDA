#ifndef OLZ_H_
#define OLZ_H_

#include <fstream>
#include <sstream>

#include "Utilizador.h"
#include "Functions.h"
#include <algorithm>

using namespace std;

/**
* @brief Classe OLZ que armazena todos utilizadores e anúncios da aplicação
*/
class OLZ
{
private:
	vector<Utilizador> utilizadores;
	vector <Anuncio *> anuncios;
	vector <Contato> contatos;
	vector <Anuncio *> realizados;
	string userOnline; // Indica qual o e-mail do utilizador que efetuou login
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
	bool existeEmail(string mail);

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
	* @brief Regista a password de utilizador
	*
	* @return Retorna a password que é um parâmetro do tipo string
	*/
	string setPass();

	/**
	* @brief Verifica se a password é válida
	*
	* @return Retorna true se for válida, false se não for.
	*/
	bool validarPassword(string pass);

	/**
	* @brief Verifica se o telefone ja existe
	*
	* @return Retorna true se ja existe, false caso contrário
	*/
	bool existeTelefone(int tele);

	/**
	* @brief regista a localizacao do utilizador
	*
	* @return a localizacao do utilizador
	*/
	Localizacao registarLoc();

	/**
	* @brief Verifica se o nome do local é válido
	*
	* @return True caso seja válido, false caso não seja
	*/
	bool validarLocal(string local);

	/**
	* @brief Regista a Freguesia do utilizador
	*
	* @return a freguesia introduzida
	*/
	string registarFreg();

	/**
	* @brief Regista o Concelho do utilizador
	*
	* @return o concelho introduzida
	*/
	string registarConc();

	/**
	* @brief Regista o Distrito do utilizador
	*
	* @return o distrito introduzida
	*/
	string registarDistr();

	/**
	* @brief Regista estado do anuncio
	*
	* @return o estado introduzido
	*/
	string registarEstado();

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
	* @brief Verifica a validação do nickname e password do Utilizador e loga o mesmo na sua conta de utilizador
	*/
	void logar();

	/**
	* @brief Cria um anúncio de Compra
	*/
	void criaAnuncioCompra();

	/**
	* @brief Cria um anúncio de Venda
	*/
	void criaAnuncioVenda();

	/**
	* @brief Cria e envia um contacto do Utilizador para o Anuncio em questão.
	*/
	void criaContacto(Anuncio * a);

	/**
	* @brief Cria e envia um contacto do Utilizador logado para o Anuncio em questão.
	*/
	void criaContactoLogado(Anuncio * a);

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
	* @brief Menu Utilizador de Criar Anuncio
	*/
	void createMenuCriaAnuncio();

	/**
	* @brief Menu Administrador
	*/
	void createMenuAdmin();
	
	/**
	* @brief Menu dos anuncios do Utilizador
	*/
	void createMenuAnuncios();

	/**
	* @brief Menu de pesquisa dos Visitantes
	*/
	void createMenuPesquisaVis();

	/**
	* @brief Menu de pesquisa do Utilizador
	*/
	void createMenuPesquisaUser();

	/**
	* @brief Menu de escolha de visualizacao dos Contactos
	*/
	void createMenuVerContactos();

	/**
	* @brief Guarda todos os dados criados em dois ficheiros .txt
	*/
	void saveData();

	/**
	* @brief Carrega todos os dados de dois ficheiros .txt para os vetores correspondentes
	*/
	void loadData();

	/**
	* @brief Procura no vetor de Utilizadores o utilizador com o email inserido
	*
	* @return o utilizador encontrado
	*/
	Utilizador * pesquisaEmail(string mail);

	/**
	* @brief Verifica se o titulo do Anuncio e valido
	*
	* @return True se for valido, false se nao for
	*/
	bool validarTitulo(string tit);

	/**
	* @brief Regista o titulo do anuncio
	*
	* @return o titulo do anuncio
	*/
	string registarTitulo();

	/**
	* @brief Regista a categoria do produto do anuncio
	*
	* @return categoria do anuncio
	*/
	string registarCategoria();

	/**
	* @brief Verifica se a Categoria do Anuncio e valida
	*
	* @return True se for valido, false se nao for
	*/
	bool validarCategoria(string cat);

	/**
	* @brief Regista a descricao do produto do anuncio
	*
	* @return descricao do anuncio
	*/
	string registarDescricao();

	/**
	* @brief Regista o conjunto de imagens do produto do anuncio
	*
	* @return vetor imagens do anuncio
	*/
	vector<string> registarImagens();

	/**
	* @brief Regista se no anuncio se permite negociar ou nao
	*
	* @return true para ser possivel, false para nao ser possivel
	*/
	bool registarPossivelNegociar();

	/**
	* @brief Regista o preco do anuncio
	*
	* @return o valor do preco
	*/
	float registarPreco();


	/**
	* @brief Regista as trocas do anuncioCompra
	*
	* @return o vetor com os anuncios para trocar
	*/
	vector<Anuncio *> registarTroca();

	/**
	* @brief Procura todos os anuncios de venda do utilizador com o mail especificado
	*
	* @return vetor com os anuncios
	*/
	vector<Anuncio *> searchAnuncioVenda(string mailutilizador);

	/**
	* @brief Procura todos os anuncios do utilizador especificado
	*
	* @return vetor com os anuncios
	*/
	vector<Anuncio *> searchAnuncio(string mail);

	/**
	* @brief Procura todos os anuncios do utilizador na qual a transação se realizou
	*
	* @return vetor com os anuncios
	*/
	vector<Anuncio *> searchAnuncioRealizado(string mail);

	/**
	* @brief Procura titulo do anuncio no vetor
	*
	* @return posicao no vetor
	*/
	int searchTituloNoVetor(string t, vector<Anuncio *> v);
	
	/**
	* @brief Procura um determinado utilizador através do seu email, baseado em sequential search
	*
	* @return Retorna a posiçao do utilizador com o email pretendido, -1 se nao for encontrado 
	*/
	int searchUtilizador(string emailUt);

	/**
	* @brief Procura um determinado anuncio através do seu id, baseado em sequential search
	*
	* @return Retorna a posiçao do anuncio com o email pretendido, -1 se nao for encontrado
	*/
	int searchAnuncio(int AnID);

	/**
	* @brief Cria menu para gerir os users
	*/
	void createMenuGerirUsers();
	/**
	* @brief Cria menu para gerir os anuncios
	*/
	void createMenuGerirAnuncios();
	/**
	* @brief Elimina um utilizador
	*/
	void apagarUser();
	/**
	* @brief Elimina anuncio e todos os contactos associados. 1º corresponde a modo Admin; 2º corresponde a modo User
	*/
	void apagarAnuncio();
	void apagarAnuncio(vector<Anuncio *> a); 

	/**
	* @brief Elimina anuncio com o ID correspondente
	*/
	void apagarAnuncioUtilizador(int id);

	/**
	* @brief Apaga o Anuncio com o id em todos os Anuncios de Compra com este anuncio como troca
	*/
	void apagarAnuncioTroca(int id, string email);

	/**
	* @brief Elimina todos os contactos relacionados com o Anuncio
	*/
	void apagarContactos(Anuncio * a);

	/**
	* @brief Elimina todos os contactos Enviados relativos a este anuncio
	*/
	void apagarContactosEnv(Anuncio * a);

	/**
	* @brief Elimina todos os contactos que o Utilizador u recebeu relativos ao anuncio a
	*/
	void apagarContactosRec(Utilizador * u, Anuncio * a);

	/**
	* @brief Elimina todos os contactos no OLZ relativos ao anuncio
	*/
	void apagarContactosOLZ(Anuncio * a);

	/**
	* @brief Mostra um resumo dos utilizadores existentes
	*/
	void adminMostraUsers();
	/**
	*@brief Mostra um resumo dos anuncios existentes
	*/
	void adminMostraAnuncios();

	/**
	* @brief Mostra os anuncios existentes
	*/
	void MostraAnunciosUser(string mail);
	
	/**
	* @brief Mostra os anuncios existentes cujas transações foram realizadas pelo User
	*/
	void MostraAnunciosRealizadosUser(string mail);

	/**
	* @return Retorna os anuncios organizados por categoria
	*/
	vector<Anuncio * > ordenaAnCat();

	/**
	* @return Retorna os anuncios organizados por nome do utlizador
	*/
	vector<Anuncio * > ordenaAnUt();

	/**
	* @return Retorna os anuncios organizados por ID
	*/
	vector<Anuncio * > ordenaAnID();

	/**
	* @return Retorna o contacto com o ID correspondente
	*/
	Contato pesquisaContactoID(int id);

	/**
	* @return Retorna os anuncios pertencentes a cada categoria
	*/
	vector<Anuncio * > pesquisaAnCat(string cat);

	/**
	* @return Retorna os anuncios que possam ter o mesmo titulo
	*/
	vector<Anuncio * > pesquisaAnTit(string tit);

	/**
	* @brief Mostra o anuncio do utilizador mais recente. Se dois anuncios possuem a mesma data, mostra o que aparece mais cedo alfabeticamente
	*/
	void AnuncUserRec();

	/**
	* @brief Mostra o anuncio do utilizador com mais clicks. Se dois anuncios possuem a mesma data, mostra o que aparece mais cedo alfabeticamente
	*/
	void AnuncUserClicks();

	/**
	* @brief Pesquisa anuncios por categoria
	*/
	void pesquisaCat(const string &cat);

	/**
	* @brief Pesquisa anuncios por preco
	*/
	void pesquisaPreco(float p);

	/**
	* @brief Pesquisa anuncios por palavra chave
	*/
	void pesquisaPalavra(string p);

	/**
	* @brief Seleciona os anuncios com preco menor ou igual a p
	* @return vetor com os anuncios
	*/
	vector<Anuncio * > pesquisaAnPreco(float p);

	/**
	* @brief Seleciona os anuncios que contenham p na descricao/titulo
	* @return vetor com os anuncios
	*/
	vector<Anuncio * > pesquisaAnPalavra(string p);

	static bool maisLikes(Anuncio * v1, Anuncio * v2);

	/**
	* @brief Imprime as mensagens recebidas pelo User Logado
	*/
	void lerMensagensRecebidas();			//Lê todas as mensagens recebidas através de cada um dos anúncios

	/**
	* @brief Imprime as mensagens enviadas pelo User Logado
	*/
	void lerMensagensEnviadas();			//Lê todas as mensagens recebidas através de cada um dos anúncios
};
#endif /*OLZ_H_*/