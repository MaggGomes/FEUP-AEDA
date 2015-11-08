#include "OLZ.h"
#include "Anuncio.h"

using namespace std;

int main(){

	OLZ OLZ;
	//OLZ.loadData();
	OLZ.createMenuGerirUsers();
	OLZ.createMenuInicial();

	// CODIGO PARA TESTAR
	
	Localizacao local("porto", "porto", "porto");
	Utilizador ut("Jose", "jose@gmail.com", 966870031, local, "password");
	Utilizador ut2("Pedro", "aaasd@gmail.com", 966822231, local, "pasasdfasdf");
	//OLZ.createMenuInicial();

	ut.setVisNome(true);
	ut.setVisEmail(false);
	ut.setVisTelefone(true);
	OLZ.addUtilizador(ut);
	//cout << local.getFreguesia() << " " << local.getConcelho() << " " << local.getDistrito() << endl;

	//if (ut.getVisEmail())
		//cout << ut.getEmail() << endl;
	//if (ut.getVisTelefone())
		//cout << ut.getTelefone() << endl;
	//if (ut.getVisNome())
		//cout << ut.getNome() << endl;

	Anuncio * anun = new AnuncioVenda (&ut, "CARRO", "automoveis","asdfsafasdfasdf" , true, 5000,"pecas");
	anun->addImagem("8495");
	anun->addImagem("f5sfsd4566");
	anun->addImagem("tgfg");

	anun->visAnuncio();
	//anun->visAnuncio();
	//anun->visAnuncio();
	//anun->visAnuncio();
	//anun->visAnuncio();
	vector<Anuncio *> temp;
	Anuncio * anun2 = new AnuncioCompra(&ut, "CASA", "Imoveis", "asdfsafasdfasdasdf", false, 9000, temp);

	anun2->visAnuncio();

	OLZ.addUtilizador(ut2);
	OLZ.addAnuncio(anun);
	OLZ.addAnuncio(anun2);
	OLZ.saveData();

	cout << "savedata" << endl;

	return 0;
}