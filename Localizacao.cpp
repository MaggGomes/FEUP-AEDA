#include "Localizacao.h"

Localizacao::Localizacao(){}

Localizacao::Localizacao(string f, string c, string d) : freguesia(f), concelho(c), distrito(d){}

string Localizacao::getFreguesia() const{
	return freguesia;
}

string Localizacao::getConcelho() const{
	return concelho;
}

string Localizacao::getDistrito() const{
	return distrito;
}

void Localizacao::setFreguesia(const string& freguesia){
	this->freguesia = freguesia;
}

void Localizacao::setConcelho(const string& concelho){
	this->concelho = concelho;
}

void Localizacao::setDistrito(const string& distrito){
	this->distrito = distrito;
}

bool Localizacao::operator==(const Localizacao l1) const
{
	if (l1.freguesia == freguesia)
	{
		if (l1.concelho == concelho)
		{
			if (l1.distrito == distrito)
			{
				return true;
			}
		}
	}
	return false;
}
