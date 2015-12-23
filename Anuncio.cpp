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
	datarealizacao = Data(0, 0, 0);
	possivelNegociar = pNeg;
	num_clicks = 0;
	preco = pr;
	prioridade = 0;
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

Data Anuncio::getDataRealizacao() const
{
	return datarealizacao;
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

float Anuncio::getPrioridade() const{
	return prioridade;
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

void Anuncio::setDataRealizacao(Data dt)
{
	datarealizacao = dt;
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

void Anuncio::setPrioridade(float pr){
	prioridade = pr;
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
	setcolor(3, 0);
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << " --- PREMIUM --------------------" << endl;
		cout << "#";
		setcolor(3, 0);
	}
	cout << "ID: " << id << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}
	cout << "Anuncio de Venda" << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}
	cout << "Titulo: " << titulo << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}
	cout << "Categoria: " << categoria << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}
	cout << "Localidade: " << Anunciante->getLocalizacao().getFreguesia() << ", " << Anunciante->getLocalizacao().getConcelho() << ", "
		<< Anunciante->getLocalizacao().getDistrito() << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}
	cout << "Data de Criacao: " << datacriacao << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}
	cout << "Descricao: " << descricao << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}

	for (unsigned int i = 0; i < imagens.size(); i++){
		cout << "Imagem: " << imagens[i] << endl;
		if (prioridade != 0)
		{
			setcolor(14, 6);
			cout << "#";
			setcolor(3, 0);
		}
	}

	cout << "Estado: " << estado << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}

	cout << "Preco: " << preco << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}
	num_clicks++;
	cout << "Visualizacoes: " << num_clicks << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(3, 0);
	}

	if (possivelNegociar)
	{
		cout << "Negociavel." << endl;
		if (prioridade != 0)
		{
			setcolor(14, 6);
			cout << "#";
			setcolor(3, 0);
		}
	}
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << " --------------------------------";
		setcolor(3, 0);
	}
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
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << " --- PREMIUM --------------------" << endl;
		cout << "#";
		setcolor(10, 0);
	}
	cout << "ID: " << id << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}
	cout << "Anuncio de Compra" << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}
	cout << "Titulo: " << titulo << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}
	cout << "Categoria: " << categoria << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}
	cout << "Localidade: " << Anunciante->getLocalizacao().getFreguesia() << ", " << Anunciante->getLocalizacao().getConcelho() << ", "
		<< Anunciante->getLocalizacao().getDistrito() << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}
	cout << "Data de Criacao: " << datacriacao << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}
	cout << "Descricao: " << descricao << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}

	for (unsigned int i = 0; i < imagens.size(); i++){
		cout << "Imagem: " << imagens[i] << endl;
		if (prioridade != 0)
		{
			setcolor(14, 6);
			cout << "#";
			setcolor(10, 0);
		}
	}

	cout << "Preco: " << preco << endl;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}
	num_clicks++;
	cout << "Visualizacoes: " << num_clicks;
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << "#";
		setcolor(10, 0);
	}

	if (possivelNegociar)
	{
		cout << "Negociavel.";
		if (prioridade != 0)
		{
			setcolor(14, 6);
			cout << "#";
			setcolor(10, 0);
		}
	}

	if (troca.size()>0)
	{
		cout << "Possiveis trocas:" << endl;
		if (prioridade != 0)
		{
			setcolor(14, 6);
			cout << "#";
			setcolor(10, 0);
		}
		for (unsigned int i = 0; i < troca.size(); i++)
		{
			cout << "- " << troca[i]->getTitulo() << " (ID: " << troca[i]->getID() << ")" << endl;
			if (prioridade != 0)
			{
				setcolor(14, 6);
				cout << "#";
				setcolor(10, 0);
			}
		}
	}
	if (prioridade != 0)
	{
		setcolor(14, 6);
		cout << " --------------------------------";
		setcolor(10, 0);
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

void AnuncioCompra::apagarTroca(int id)
{
	for (int i = 0; i < troca.size(); i++)
	{
		if (troca[i]->getID() == id)
		{
			troca.erase(troca.begin() + i);
		}
	}

	return;
}

void AnuncioVenda::apagarTroca(int id)
{
	return;
}

void Anuncio::apagarTroca(int id)
{
	return;
}

PtrToAnuncio::PtrToAnuncio(Anuncio* ptr)
{
	a_ptr = ptr;
}

Anuncio* PtrToAnuncio::getPtr() const
{
	return a_ptr;
}


bool operator<(const PtrToAnuncio &l, const PtrToAnuncio &r)
{
	if (l.getPtr()->getPrioridade() < r.getPtr()->getPrioridade())
		return true;
	else if (l.getPtr()->getPrioridade() == r.getPtr()->getPrioridade())
		return (l.getPtr()->getDataCriacao() > r.getPtr()->getDataCriacao());

	return false;
}