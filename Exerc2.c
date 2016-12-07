/*
Nome:Gustavo Montanini Cenci RA:0030481521018
Nome:João Pedro Dornelas     RA:0030481521021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regNo {char vRA[14], disc[6]; float nota; int faltas;};
typedef struct regNo TNo;

struct descri {int inicio;int final;};
typedef struct descri Descritor;

Descritor ImprimeLista(Descritor);
Descritor AdicionaLista(Descritor);
Descritor ApagaLista(Descritor);

TNo Lista[100];

int main(){
	Descritor DescritorLista;
	int aux=0,aux2=0,c;
	
	DescritorLista=AdicionaLista(DescritorLista);

	if(strcmp(Lista[0].vRA, "XXX") == 0){
		printf("Lista Vazia");
		return 0;
	}
	
	DescritorLista=ApagaLista(DescritorLista);
	
	DescritorLista=ImprimeLista(DescritorLista);
	
	return 0;
}


Descritor AdicionaLista(Descritor DescritorLista)
{
	int c;
	for(c=0,DescritorLista.final=0,DescritorLista.inicio=0;c<100;c++){
		printf("Informe o RA ou XXX para encerrar:\n");
		scanf("%s", Lista[c].vRA);
		
		if(strcmp(Lista[c].vRA, "XXX") == 0)
			break;
		
		printf("Informe a sigla da disciplina:\n");
		scanf("%s", Lista[c].disc);
		
		printf("Informe a nota final:\n");
		scanf("%f", &Lista[c].nota);
		
		printf("Informe o total de faltas:\n");
		scanf("%d", &Lista[c].faltas);
		DescritorLista.final=DescritorLista.final+1;
	}
	return DescritorLista;
}

Descritor ApagaLista(Descritor DescritorLista)
{
	int aux2=0,c;
	char remove[6];
	while(1){
	printf("Informe a disciplina a remover ou XXX para encerrar:\n");
	scanf("%s",remove);
	
		if(strcmp(remove, "XXX") ==0)
			return DescritorLista;
		
		for(c=0,aux2=0; c<100; c++,aux2++){
			if(strcmp(Lista[c].disc, remove) == 0){
				for(c=aux2;c<100;c++)
					Lista[c] = Lista[c+1];
				DescritorLista.final--;
				}
		}
		DescritorLista=ImprimeLista(DescritorLista);
	}
	return DescritorLista;
}

Descritor ImprimeLista(Descritor DescritorLista)
{
	int c;
	printf("Conteudo atual da lista");
	for(c=0;c<DescritorLista.final;c++){
		printf("RA:%s  \tDiciplina:%s  \tNota:%.1f  \tFalta:%d\n",Lista[c].vRA,
		Lista[c].disc, Lista[c].nota, Lista[c].faltas);
	}
	return DescritorLista;
}
