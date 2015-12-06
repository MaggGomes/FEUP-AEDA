#include "Anuncio.h"

int Anuncio::last_id = 1;

Anuncio::Anuncio(Utilizador * ut, string tit, string cat, string des, bool pNeg, float pr)
{
	Anunciante = ut;
	titulo = tit;
	categoria = cat;
	descricao = des;
	id = last_id;
	last_id++;

	time_t t = time(NULL);
	struct tm* timePtr = localtime(&t);
	
	int dia = timePtr->tm_mday;
	int mes = timePtr->tm_mon + 1;
	int ano = timePtr->tm_year + 1900 ;
	

	Data temp(dia,mes,ano);
	
	imagens = {};
	datacriacao = temp;
	possivelNegociar = pNeg;
	num_clicks = 0;
	preco = pr;
}

Utilizador * Anuncio::getAnunciante() const
{
	return Anunciante;
}

string Anuncio::getTitulo() const{
	return titulo;
}

string Anuncio::getCategoria() const{
	return categoria;
}

string Anuncio::getDescricao() const{
	return descricao;
}

vector<string> Anuncio::getImagens() const{
	return imagens;
}

int Anuncio::getID() const{
	return id;
}

Data Anuncio::getDataCriacao()  const{
	return datacriacao;
}

bool Anuncio::getNegociar() const{
	return possivelNegociar;
}

int Anuncio::getClicks() const{
	return num_clicks;
}

float Anuncio::getPreco() const{
	return preco;
}

void Anuncio::setTitulo(string tit){
	titulo = tit;
}

void Anuncio::setCategoria(string cat){
	categoria = cat;
}

void Anuncio::setDescricao(string desr){
	descricao = desr;
}

void Anuncio::setId(int tId){
	id = tId;
}

void Anuncio::setDataCriacao(Data dt){
	datacriacao = dt;
}

void Anuncio::addImagem(string im)
{
	imagens.push_back(im);
}

void Anuncio::setPossivelNegociar(bool neg){
	possivelNegociar = neg;
}

void Anuncio::setNum_clicks(int clicks){
	num_clicks = clicks;
}

void Anuncio::addClick(){
	num_clicks++;
}

void Anuncio::setPreco(float pr){
	preco = pr;
}



//------------------------------

AnuncioVenda::AnuncioVenda(Utilizador *ut, string tit, string cat, string des, bool pNeg, float pr, string est) :Anuncio( ut, tit, cat, des, pNeg, pr)
{
	estado = est;
}

string AnuncioVenda::getEstado() const
{
	return estado;
}

void AnuncioVenda::setEstado(string est)
{
	estado = est;
}

vector<Anuncio *> AnuncioVenda::getTroca() const
{
	return {};
}

void AnuncioVenda::visAnuncio()
{
	setcolor(9, 0);	
	cout << "ID: " << id << endl;
	cout << "Anuncio de Venda" << endl;	
	cout << "Titulo: " << titulo << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Localidade: " << Anunciante->getLocalizacao().getFreguesia() << ", " << Anunciante->getLocalizacao().getConcelho() << ", "
		<< Anunciante->getLocalizacao().getDistrito() << endl;
	cout << "Descricao: " << descricao << endl;	

	for (unsigned int i = 0; i < imagens.size(); i++){
		cout << "Imagem: " << imagens[i] << endl;
	}

	cout << "Estado: " << estado << endl;

	cout << "Preco: " << preco << endl;
	num_clicks++;
	cout << "Visualizacoes: " << num_clicks<<endl;

	if (possivelNegociar)
		cout << "Negociavel."<<endl;

	setcolor(7, 0);	
	cout << endl;
}

bool AnuncioVenda::isVenda() const
{
	return true;
}

AnuncioCompra::AnuncioCompra(Utilizador * ut, string tit, string cat, string des, bool pNeg, float pr, vector<Anuncio *> tr) : Anuncio(ut, tit, cat, des, pNeg, pr)
{
	for (int i = 0; i < tr.size(); i++)
	{
		if (!(tr[i]->isVenda()))
			throw tr;
	}
	troca = tr;
}

vector<Anuncio *> AnuncioCompra::getTroca() const
{
	return troca;
}

void AnuncioCompra::setTroca(vector<Anuncio *> tr)
{
	troca = tr;
}

void AnuncioCompra::visAnuncio()
{
	setcolor(10, 0);
	cout << "ID: " << id << endl;
	cout << "Anuncio de Compra" << endl;
	cout << "Titulo: " << titulo << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Localidade: " << Anunciante->getLocalizacao().getFreguesia() << ", " << Anunciante->getLocalizacao().getConcelho() << ", " 
		<< Anunciante->getLocalizacao().getDistrito() << endl; 
	cout << "Descricao: " << descricao << endl;

	for (unsigned int i = 0; i < imagens.size(); i++){
		cout << "Imagem: " << imagens[i] << endl;
	}

	cout << "Preco: " << preco << endl;
	num_clicks++;
	cout << "Visualizacoes: " << num_clicks;

	if (possivelNegociar)
		cout << "Negociavel.";
	
	if (troca.size()>0)
	{
		cout << "Possíveis trocas:" << endl;
		for (unsigned int i = 0; i < troca.size(); i++)
		{
			cout << "- " << troca[i]->getTitulo() << " (ID: " << troca[i]->getID() << ")" << endl;
		}
	}
	
	setcolor(7, 0);
	cout << endl;
}

bool AnuncioCompra::isVenda() const
{
	return false;
}

bool Anuncio::searchPalavra(string p)
{

	if (searchWordInString(p, titulo) || searchWordInString(p, descricao))
		return true;
	else
		return false;
}

string AnuncioCompra::getEstado() const
{
	string temp = {};
	return temp;
}

void Anuncio::setImagens(vector<string> tIma)
{
	imagens = tIma;
}