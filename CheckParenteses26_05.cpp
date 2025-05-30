#include <iostream>
#include <stdlib.h>

using namespace std;

struct Item{
	char Valor;
	struct Item* Prox;
};

struct Pilha{
	Item* Topo;
	int Tamanho;
};

struct Fila{ //Cabeçalho
	Item *Inicio;
	Item *Fim;
	int Tamanho;	
};

void Ini_Pilha(Pilha* P){
	P->Topo = NULL;
	P->Tamanho = 0;
}

void Ini_Fila(Fila *F){ //Cria uma lista vazia
	F->Inicio = NULL;	
	F->Fim = NULL;	
	F->Tamanho = 0;
}

void Empilha(Pilha* P, char Valor){
	Item* ItemP;

	ItemP = (Item *) malloc(sizeof(Item));
	ItemP->Valor = Valor;
	ItemP->Prox = P->Topo;

	P->Topo = ItemP;
	P->Tamanho++;
}

Item* Desempilha(Pilha* P){
	Item* ItemP;

	if (P->Topo != NULL){ // Pilha não está vazia!
		ItemP = P->Topo;
		P->Topo = P->Topo->Prox;
		P->Tamanho--;
	}
	else{
		ItemP = NULL;
	}

	return ItemP;
}

int Fila_Vazia(Fila *T){ //Verifica se a Fila est? vazia (1 - Vazia, 0 - Tem mais de 1 elemento)
	int Ret;

	if (T->Tamanho == 0){
		Ret = 1;
	}
	else{
		Ret = 0;
	}

	return Ret;
}

void Enfileira(Fila *F, char Valor){	
	Item *ItemF;

	ItemF = (Item *) malloc(sizeof(Item));
	if (ItemF != NULL){ //Há espaço na memória		 		
		ItemF->Valor = Valor;
		ItemF->Prox= NULL;
		if (Fila_Vazia(F) == 1){
			F->Inicio = ItemF;			
		}
		else{
			F->Fim->Prox = ItemF; //Incluo no final			
		}
		
		F->Fim = ItemF;			
		F->Tamanho++;
	}
	else{
		cout << "Não há mais espaço na memória!!" << endl;
	}
}

Item* Desenfileira(Fila *F){		
	Item *Ret;

	Ret = NULL;
	if (Fila_Vazia(F) == 0){ //Há alunos na Turma			
		Ret = F->Inicio; ////Como vai retornar o elemento retirado, não limpa mais aqui. Deixa a limpeza pra quem chamou a função!!
		//Atualiza início com o seu próximo
		F->Inicio = F->Inicio->Prox;		

		if (F->Tamanho == 1){ //Se tinha apenas 1 elemento, tb deve atualizar o fim
			F->Fim = NULL;
		}
						
		F->Tamanho--;
	}
	else{
		cout << "Fila vazia!!" << endl;
	}
	
	return Ret;
}

Item* Cria_Elemento(char Valor){
	Item *Elemento;

	Elemento = (Item *) malloc(sizeof(Item));
	Elemento->Valor = Valor;

	return Elemento;	
}

void Imprime_Pilha(Pilha *P){
	Item* ItemP;
	cout<<"***** PILHA ***** " << "\n";
	for(ItemP=P->Topo;ItemP!= NULL;ItemP = ItemP->Prox){
		cout << ItemP->Valor;
	}	
}

void Imprime_Fila(Fila *F, Item *ProxItem){

	if (ProxItem != NULL){
		if (ProxItem == F->Inicio){ //Se for o topo, imprime o cabe?alho
			system("cls");
			cout<<"***** FILA ***** " << "\n";				
		}
	
		cout << ProxItem->Valor << " ";
	
		Imprime_Fila(F, ProxItem->Prox);	
	}
}

int ProcessaParenteses(Fila *F){
	Pilha P;
	Item *ItemF;
	int Ret = 1;
	
	Ini_Pilha(&P);
	while(Fila_Vazia(F) == 0 && Ret == 1){ //retira da pilha e verifica se deve incluir na pilha ou comparar com o topo
		ItemF = Desenfileira(F);
		if (ItemF->Valor == '('){
			Empilha(&P, ItemF->Valor);
		}
		else{ //')'
			if (P.Tamanho > 0 && P.Topo->Valor == '('){
				Desempilha(&P);	
			}
			else{ //Se não for fechamento dos parênteses ou a pilha está vazia, ? erro!!
			    //cout << endl << "Gerou erro. Tamanho = " << P.Tamanho << ", valor na pilha = " << P.Topo->Valor << " e valor da fila = " << Item->Valor;
				Ret = -1;
			}
		}
	}
	
	if(P.Tamanho > 0 && Ret == 1){ //Se sobrou elementos na pilha, ? erro
		//cout << endl << "Erro fora do loop!!";
		Ret = -1;
	}
	
	return Ret;
}

Pilha P;
Fila F;
Item *Elemento;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	int Elemento;
	Ini_Fila(&F);
	Ini_Pilha(&P);
	

	Enfileira(&F, '(');
	Enfileira(&F, '(');
	Enfileira(&F, ')');
	Enfileira(&F, ')');
	Enfileira(&F, '(');
	Enfileira(&F, ')');
    Imprime_Fila(&F, F.Inicio);
    if(ProcessaParenteses(&F) == 1){
    	cout << "\n" << "Parênteses OK!!!";
	}
	else{
		cout << "\n" << "<!ERRO!> Parênteses!";
	}
	/*Desenfileira(&F);
	Elemento = Desenfileira(&F);
	cout << "\n" << "Item desenfileirado: " << Elemento;
	
	Empilha(&P, ')');
	Empilha(&P, ')');
	Empilha(&P, '(');
	Empilha(&P, '(');
    Imprime_Pilha(&P);
	Desempilha(&P);
	Elemento = Desempilha(&P);
	cout << "\n" << "Item desempilhado: " << Elemento.Valor;
	Imprime_Pilha(&P);
	*/
	
	return 0;
}
