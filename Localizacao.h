#ifndef LOCALIZACAO_H_
#define LOCALIZACAO_H_

#include <string>

using namespace std;

/**
* @brief Classe Localizacao: classe que armazena de um utilizador ou arigo de um anúncio
*/

class Localizacao {
private:
	string freguesia;
	string concelho;
	string distrito;
public:

	/**
	* @brief Construtor Default da classe Localizacao
	*/
	Localizacao();

	/**
	* @brief Construtor da classe Localizacao
	*/
	Localizacao(string f, string c, string d);

	/**
	* @return Retorna a freguesia
	*/
	string getFreguesia() const;

	/**
	* @return Retorna o concelho
	*/
	string getConcelho() const;

	/**
	* @return Retorna o distrito
	*/
	string getDistrito() const;

	/**
	* @brief Modifica a freguesia
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setFreguesia(const string& freguesia);

	/**
	* @brief Modifica o concelho
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setConcelho(const string& concelho);

	/**
	* @brief Modifica o distrito
	*
	* @param Recebe um parâmetro do tipo string
	*/
	void setDistrito(const string& distrito);
};


#endif /*LOCALIZACAO_H_*/
