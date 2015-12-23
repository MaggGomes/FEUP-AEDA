#include "OLZ.h"
#include "Anuncio.h"

using namespace std;

int main(){

	OLZ OLZ;
	OLZ.loadData();	
	OLZ.createMenuInicial();
	OLZ.saveData();

	return 0;
}