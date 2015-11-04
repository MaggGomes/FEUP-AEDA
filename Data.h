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
	int getDia() const;
	int getMes() const;
	int getAno() const;
	void setDia(int dia);
	void setMes(int mes);
	void setAno(int ano);
	friend ostream& operator<<(ostream& os, const Data& d); // Overloading do operador "<<"
	~Data();
};

#endif /*DATA_H_*/