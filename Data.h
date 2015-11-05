#ifndef DATA_H_
#define DATA_H_

#include <iostream>

using namespace std;

/**
* @brief Classe Data: classe que armazena a data criada aquando do registo de anúncios ou da venda/compra de produtos registados nos anúncios
*/

class Data
{
private:
	int dia;
	int mes;
	int ano;
public:

	/**
	* @brief Construtor da classe Data
	*/
	Data(int dia, int mes, int ano);

	/**
	* @return Retorna o dia da Data
	*/
	int getDia() const;

	/**
	* @return Retorna o mes da Data
	*/
	int getMes() const;

	/**
	* @return Retorna o ano da Data
	*/
	int getAno() const;

	/**
	* @brief Modifica o dia
	*
	* @param Recebe um parâmetro do tipo inteiro
	*/
	void setDia(int dia);

	/**
	* @brief Modifica o mes
	*
	* @param Recebe um parâmetro do tipo inteiro
	*/
	void setMes(int mes);

	/**
	* @brief Modifica o ano
	*
	* @param Recebe um parâmetro do tipo inteiro
	*/
	void setAno(int ano);

	/**
	* @brief Overload do operator << para imprimir a data
	*
	* @param Recebe um parâmetro do tipo Data e do tipo ostream para permitir imprimir a Data
	*/
	friend ostream& operator<<(ostream& os, const Data& d); // Overloading do operador "<<"

	/**
	* @brief Destrutor da classe Data
	*/
	~Data();
};

#endif /*DATA_H_*/