#include <iostream>

using namespace std;

class celula
{
private:
    string nome;
    celula *proxima;
public:
    celula(){
        proxima = NULL;
    }
    //Metodo construtor
    celula(string n,celula* prox){
    	setnome(n);
    	setproxima(prox);
	}
    
    void setnome(string n){
        nome = n;
    }
    
    string getnome(){
        return nome;
    }
    
    void setproxima(celula *c){
        proxima = c;
    }
    
    celula *getproxima(){
        return proxima;
    }
};

 

class lista
{
private:
    celula * inicio;
public:
    lista(){
        inicio = NULL;
    }
    
	
    celula * getinicio(){
        return inicio;
    }
    
    void inserirInicio(string nome){
        celula * nova = new celula(nome,inicio);
        //nova->setNome(nome);
        //nova->setProxima(inicio);
        inicio = nova;
    }
    
    void show(){
        if(inicio == NULL){
            cout << "Lista Vazia" << endl;
        }
        else{
            celula *aux = inicio;
            while(aux != NULL){
                cout << aux->getnome() << endl;
                aux = aux->getproxima();
            }
        }
    }
    
};

 

int main()
{
    lista alunos;
    alunos.inserirInicio("Sousa");
    alunos.inserirInicio("Soares");
    alunos.inserirInicio("Savio");
    alunos.show();
    return 0;
}