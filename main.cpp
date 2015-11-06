#include "OLZ.H"
#include "Anuncio.h"

using namespace std;

int main(){

	OLZ OLZ;	
	//OLZ.saveData();
	OLZ.createMenuInicial();
	
	// CODIGO PARA TESTAR

	/*Localizacao local("porto","porto","porto");
	Utilizador ut("Jose", "jose.oliveira@gmail.com", 966870031, local);
	
	ut.setVisNome(true);
	ut.setVisEmail(false);
	ut.setVisTelefone(true);
	cout << local.getFreguesia() << " " << local.getConcelho() << " " << local.getDistrito() << endl;

	if (ut.getVisEmail())
		cout << ut.getEmail() << endl;
	if (ut.getVisTelefone())
		cout << ut.getTelefone() << endl;
	if (ut.getVisNome())
		cout << ut.getNome() << endl;

	AnuncioVenda anun(&ut, "CARRO", "automoveis","asdfsafasdfasdf" , true, 5000,"pecas");

	anun.visAnuncio();
	anun.visAnuncio();
	anun.visAnuncio();
	anun.visAnuncio();
	anun.visAnuncio();

	AnuncioVenda anun2(&ut, "CASA", "Imoveis", "asdfsafasdfasdasdf", false, 9000, "novo");

	anun2.visAnuncio();*/

	/*OLZ.addUtilizador(ut);
	OLZ.addAnuncio(anun);
	OLZ.addAnuncio(anun2);

	cout << OLZ.getAnuncios()[0]->getCategoria();*/

	OLZ.saveData();
	return 0;
}