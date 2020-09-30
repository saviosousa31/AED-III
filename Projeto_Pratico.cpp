#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

struct Pessoa{
  string nome, cep, rua, cidade, nomedestinatario, cepdestinatario, ruadestinatario, cidadedestinatario;
  int numero, numerodestinatario;
  public:
  Pessoa(string nome, string cep, string rua, int numero, string cidade, string nomedestinatario, string cepdestinatario, string ruadestinatario, int numerodestinatario, string cidadedestinatario){
    this->nome = nome;
    this->cep = cep;
    this->rua = rua;
    this->numero = numero;
    this->cidade = cidade;
    this->nomedestinatario = nomedestinatario;
    this->cepdestinatario = cepdestinatario;
    this->ruadestinatario = ruadestinatario;
    this->numerodestinatario = numerodestinatario;
    this->cidadedestinatario = cidadedestinatario;
  }
   void imprimirPessoa(){
     cout << "DADOS DO REMETENTE:\n\n" << "Nome do remetente: " << nome << " - " << "CEP do remetente: " << cep << " - " << "Rua do remetente: " << rua << " - " << "Numero do remetente: " << numero << " - " << "Cidade do remetente: " << cidade << endl << "DADOS DO DESTINATARIO:\n\n" << endl << "Nome do destinatario: " << nomedestinatario << " - " << "CEP do destinatario: " << cepdestinatario << " - " << "Rua do destinatario: " << ruadestinatario << " - " << "Numero do destinatario: " << numerodestinatario << " - " << "Cidade do destinatario: " << cidadedestinatario << endl;
  }
  
};

void imprimirFila(queue<Pessoa> fila, string servico){
  cout << "\n\n*** Clientes na fila '" << servico << "': ***";
  while(fila.size() > 0){
    cout << "\nNome de remetente: " << fila.front().nome;
    fila.pop();
  }
}

queue<Pessoa> PAC;
queue<Pessoa> Sedex;

int main() {
  int r=1;
  do{
    system("cls");
    cout << "\n========== MENU ==========\n";
    cout << "Escolha uma opçao para prosseguir: \n\n";
    cout << "1) Adicionar pessoa na fila\n2) Chamar proximo da fila, informando a fila correspondente\n3) Mostrar as filas\n\n0) Sair\n\nR: ";
    cin >> r;
    while(r < 0 || r > 3){
      cout << "Por favor, selecione uma opçao valida: ";
      cin >> r;
    }
    if(r == 1){
      system("cls");
      cout << "\n========== Adicionar Pessoa na fila ==========\n";
      cout << "Qual o serviço desejado? (Insira '1' para PAC / Insira '2' para Sedex): ";
      int x;
      cin >> x;
      while(x < 1 || x > 2){
      cout << "Por favor, selecione uma opçao valida: ";
      cin >> x;
      }
      cout << "\n* DADOS DO REMETENTE: *\n\n";
      cout << "Insira o nome do remetente: ";
      string nome;
      cin >> nome;
      cout << "Insira o CEP do remetente: ";
      string cep;
      cin >> cep;
      cout << "Insira a rua do remetente: ";
      string rua;
      cin >> rua;
      cout << "Insira o numero do remetente: ";
      int numero;
      cin >> numero;
      cout << "Insira a cidade do remetente: ";
      string cidade;
      cin >> cidade;
      cout << "\n\n* DADOS DO DESTINATARIO: *\n\n";
      cout << "Insira o nome do destinatario: ";
      string nomedestinatario;
      cin >> nomedestinatario;
      cout << "Insira o CEP do destinatario: ";
      string cepdestinatario;
      cin >> cepdestinatario;
      cout << "Insira a rua do destinatario: ";
      string ruadestinatario;
      cin >> ruadestinatario;
      cout << "Insira o numero do destinatario: ";
      int numerodestinatario;
      cin >> numerodestinatario;
      cout << "Insira a cidade do destinatario: ";
      string cidadedestinatario;
      cin >> cidadedestinatario;
      Pessoa p(nome, cep, rua, numero, cidade, nomedestinatario, cepdestinatario, ruadestinatario, numerodestinatario, cidadedestinatario);
      if(x == 1){
        PAC.push(p);
        cout << "Pessoa cadastrada com sucesso!\n\n";      
      }
      if(x == 2){
        Sedex.push(p);
        cout << "Pessoa cadastrada com sucesso!\n\n";
      }
      system("pause");
    }

    if(r == 2){
      system("cls");
      cout << "\n========== Chamar proximo da fila ==========\n";
      cout << "Qual o serviço desejado? (Insira '1' para PAC / Insira '2' para Sedex): ";
      int x;
      cin >> x;
      while(x < 1 || x > 2){
      cout << "Por favor, selecione uma opçao valida: ";
      cin >> x;
      }
      if(x == 1){
        cout << "\n* Chamando proximo da fila 'PAC'... *\n\n";
        PAC.pop();
      }
      if(x == 2){
        cout << "\n* Chamando proximo da fila 'Sedex'... *\n\n";
        Sedex.pop();
      }
      system("pause");
		}
    
    if(r == 3){
      system("cls");
      cout << "\n========== Mostrar as filas ==========";
      imprimirFila(PAC, "PAC");
      imprimirFila(Sedex, "Sedex");
      cout << endl << endl;
      system("pause");
    }

    if(r == 0){
      cout << "\n\n* Saindo do programa... *\n\n";
    }
  } while(r != 0);
}
