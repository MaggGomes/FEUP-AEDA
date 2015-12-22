#include "OLZ.h"
#include "Anuncio.h"

using namespace std;

int main(){

	OLZ OLZ;
	//OLZ.loadData();

	Localizacao local1("Ramalde", "Porto", "Porto");
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
	anun->addImagem("img1");
	anun->addImagem("img2");
	anun->addImagem("img3");
	Anuncio * anun2 = new AnuncioVenda(&ut, "CARRO", "automoveis", "asdfsafasdfasdf", true, 5000, "pecas");
	anun2->addImagem("img4");
	anun2->addImagem("img5");

	anun2->setPrioridade(500);
	vector<Anuncio *> temp;
	Anuncio * anun3 = new AnuncioCompra(&ut, "CASA", "Imoveis", "casa de ferias", false, 9000, temp);
	Anuncio * anun4 = new AnuncioCompra(&ut, "QUINTA", "Imoveis", "quinta antiga", false, 9000, temp);
	anun4->setPrioridade(1000);
	anun->setPrioridade(10000);

	OLZ.addUtilizador(ut2);
	OLZ.addAnuncio(anun4);
	OLZ.addAnuncio(anun);
	OLZ.addAnuncio(anun2);
	OLZ.addAnuncio(anun3);
	priority_queue<PtrToAnuncio> t = OLZ.getAnuncios();
	
	
	
	while (!t.empty())
	{
		cout << t.top().getPtr()->getID() << " - " << t.top().getPtr()->getPrioridade() << endl;
		t.pop();
	}

	OLZ.createMenuInicial();
	OLZ.saveData();

	return 0;
}