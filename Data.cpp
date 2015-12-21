#include "Data.h"

Data::Data()
{
	time_t t = time(NULL);
	struct tm* timePtr = localtime(&t);

	int dia = timePtr->tm_mday;
	int mes = timePtr->tm_mon + 1;
	int ano = timePtr->tm_year + 1900 ;
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

bool Data::operator <(Data &d) const{
	if (ano < d.getAno())
		return true;
	if (ano == d.getAno()){
		if (mes < d.getMes())
			return true;
		if (mes == d.getMes()){
			if (dia < d.getDia() || dia == d.getDia())
				return true;
		}
	}

	return false;
}

bool Data::operator==(Data &d) const
{
	if (dia == d.getDia() && mes == d.getMes() && ano == d.getAno())
		return true;
	else
		return false;
}

bool Data::operator<(const Data & d) const
{
	if (ano > d.ano)
		return true;
	else if (ano == d.ano)
	{
		if (mes > d.mes)
			return true;
		else if (mes == d.mes)
		{
			if (dia > d.dia)
				return true;
		}
	}
	
	return false;
}


bool Data::operator>(const Data & d) const
{
	if (ano < d.ano)
		return true;
	else if (ano == d.ano)
	{
		if (mes < d.mes)
			return true;
		else if (mes == d.mes)
		{
			if (dia < d.dia)
				return true;
		}
	}

	return false;
}


ostream& operator<<(ostream& os, const Data& d){
	os << d.dia << "/" << d.mes << "/" << d.ano;

	return os;
}
