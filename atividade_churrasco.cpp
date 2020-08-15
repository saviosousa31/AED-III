#include <iostream>

using namespace std;

class celula
{
private:
	string nome, sexo, bebe;
	int idade; 
	celula * proxima;
public:
	celula()
	{
		proxima = NULL;
	}
	celula(string n)
	{
		nome = n;
	}
	celula(string n, celula *p)
	{
		nome = n;
		proxima = p;
	}
	celula(string n, int i, string s, string b, celula *p){
		nome = n;
		idade = i;
		sexo = s;
		bebe = b;
		proxima = p;
	}
	string getNome()
	{
		return nome;
	}
	void setNome(string n)
	{
		nome = n;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
	int getIdade(){
		return idade;
	}
	void setIdade(int i){
		idade = i;
	}
	void setSexo(string s)
	{
		sexo = s;
	}
	string getSexo(){
		return sexo;
	}
	void setBebe(string b)
	{
		bebe = b;
	}
	string getBebe(){
		return bebe;
	}
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	~lista(){
		esvaziar();
	}
	lista(celula *i)
	{
		inicio = i;
	}
	celula * getInicio()
	{
		return inicio;
	}

	void inserirInicio(string n, int i, string s, string b)
	{
		celula *nova = new celula;
		nova->setNome(n);
		nova->setProxima(inicio);
		nova->setIdade(i);
		nova->setSexo(s);
		nova->setBebe(b);
		inicio = nova;
	}

	void inserirFim(string n, int i, string s, string b)
	{
		if(inicio == NULL)
		{
			inserirInicio(n, i, s, b);
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			celula *nova = new celula(n, i, s, b, NULL);
			aux->setProxima(nova); 
		}
	}


	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
				cout << aux->getNome() << " - " << aux->getIdade() << " - " << aux->getSexo() << " - " << aux->getBebe() << endl;
				aux = aux->getProxima();
			}
		}
	}
	
	void esvaziar(){
		celula *aux = inicio;
		while(aux != NULL){
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\n----Memoria liberada----\n";
	}
};

int main()
{
	lista listaPessoas;
	listaPessoas.inserirInicio("Savio", 19, "M", "Sim");
	listaPessoas.inserirFim("Gabriel", 18, "M", "Nao");
	listaPessoas.inserirFim("Ana", 21, "F", "Nao");
	listaPessoas.inserirInicio("Julia", 23, "F", "Sim");
	listaPessoas.imprimir();
	return 0;
}