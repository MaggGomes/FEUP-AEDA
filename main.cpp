#include "OLZ.h"
#include "Anuncio.h"

using namespace std;

int main(){

	OLZ OLZ;
	//OLZ.saveData();
	//OLZ.createMenuInicial();

	// CODIGO PARA TESTAR
	// "jose.oliveira@gmail.com"

	Localizacao local("porto", "porto", "porto");
	Utilizador ut("Jose", "jose", 966870031, local, "password");
	OLZ.addUtilizador(ut);
	OLZ.createMenuInicial();

	/*ut.setVisNome(true);
	ut.setVisEmail(false);
	ut.setVisTelefone(true);
	cout << local.getFreguesia() << " " << local.getConcelho() << " " << local.getDistrito() << endl;

	if (ut.getVisEmail())
	cout << ut.getEmail() << endl;
	if (ut.getVisTelefone())
	cout << ut.getTelefone() << endl;
	if (ut.getVisNome())
	cout << ut.getNome() << endl;

	Anuncio * anun = new AnuncioVenda (&ut, "CARRO", "automoveis","asdfsafasdfasdf" , true, 5000,"pecas");

	anun->visAnuncio();
	anun->visAnuncio();
	anun->visAnuncio();
	anun->visAnuncio();
	anun->visAnuncio();

	Anuncio * anun2 = new AnuncioVenda(&ut, "CASA", "Imoveis", "asdfsafasdfasdasdf", false, 9000, "novo");

	anun2->visAnuncio();

	OLZ.addUtilizador(ut);
	OLZ.addAnuncio(anun);
	OLZ.addAnuncio(anun2);

	cout << OLZ.getAnuncios()[0]->getCategoria();*/

	OLZ.saveData();

	return 0;
}