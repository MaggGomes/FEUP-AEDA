#include "OLZ.h"
#include "Anuncio.h"

using namespace std;

int main(){

	OLZ OLZ;
	OLZ.loadData();

	/*Localizacao local1("Ramalde", "Porto", "Porto");
	Utilizador ut3("Max", "j@gmail.com", 999999999, local1, "password");
	OLZ.addUtilizador(ut3);
		
	Localizacao local("porto", "porto", "porto");
	Utilizador ut("Jose", "jose@gmail.com", 966870031, local, "password");
	Utilizador ut2("Pedro", "aaasd@gmail.com", 966822231, local, "pasasdfasdf");

	
	ut.setVisNome(true);
	ut.setVisEmail(false);
	ut.setVisTelefone(true);
	OLZ.addUtilizador(ut);
	

	Anuncio * anun = new AnuncioVenda (&ut, "CARRO", "automoveis","asdfsafasdfasdf" , true, 5000,"pecas");
	anun->addImagem("8495");
	anun->addImagem("f5sfsd4566");
	anun->addImagem("tgfg");

	vector<Anuncio *> temp;
	Anuncio * anun2 = new AnuncioCompra(&ut, "CASA", "Imoveis", "asdfsafasdfasdasdf", false, 9000, temp);


	OLZ.addUtilizador(ut2);

	OLZ.addAnuncio(anun2);
	OLZ.addAnuncio(anun);*/
	OLZ.createMenuInicial();

	OLZ.saveData();

	return 0;
}