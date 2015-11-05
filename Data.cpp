#include "Data.h"

Data::Data()
{
}

Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano){}

int Data::getDia() const{
	return dia;
}

int Data::getMes() const{
	return mes;
}

int Data::getAno() const{
	return ano;
}

void Data::setDia(int dia){
	this->dia = dia;
}

void Data::setMes(int mes){
	this->mes = mes;
}

void Data::setAno(int ano){
	this->ano = ano;
}

ostream& operator<<(ostream& os, const Data& d){
	os << d.dia << "/" << d.mes << "/" << d.ano;

	return os;
}
