/*
Nome:Gustavo Montanini Cenci RA:0030481521018
Nome:João Pedro Dornelas     RA:0030481521021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regNo {struct regNo *ant;char RA[14], disc[7];float nota;int faltas;struct regNo *prox;};
typedef struct regNo TNo;
struct TNoDesc {struct regNo *inicio;struct regNo *final;int itens;};
typedef struct TNoDesc Descritor;

Descritor IniciaLista(Descritor);
Descritor ApagaLista(Descritor );
Descritor AdicionaLista(Descritor);
void ImprimeLista(Descritor, char *, char);

Descritor IniciaLista(Descritor DescritorLista)
{
	DescritorLista.inicio = NULL;
	DescritorLista.final = NULL;
	DescritorLista.itens = 0;
	return DescritorLista;
}


Descritor AdicionaLista(Descritor DescritorLista)
{
	char vRA[14];
	TNo *aux;
	while (1)
	{	
		printf("Informe o RA ou XXX para encerrar:\n");
		scanf("%s", vRA);
		
		if (strcmp(vRA, "XXX") == 0)
			return DescritorLista;
		
		aux = (TNo *) malloc(sizeof(TNo));
		if (aux == NULL)
		{	puts("Memoria insuficiente para esta operacao!");
			exit(2);
		}
		strcpy(aux->RA, vRA);
		
		printf("Informe a sigla da disciplina:\n");
		scanf("%s", aux->disc);
		
		printf("Informe a nota final:\n");
		scanf("%f", &(aux->nota));
		
		printf("Informe o total de faltas:\n");
		scanf("%d", &(aux->faltas));
		
		aux->prox = NULL;
		
		if (DescritorLista.inicio == NULL)
		{	DescritorLista.inicio = aux;
			aux->ant = NULL;
		}
		else
		{	DescritorLista.final->prox = aux;
			aux->ant = DescritorLista.final;
		}
		
		DescritorLista.final = aux;
		DescritorLista.itens=DescritorLista.itens+1;
	}
	return DescritorLista;
}
Descritor ApagaLista(Descritor DescritorLista)
{
	TNo *aux; 
	int achou;
	char vDisc[7];
	printf("Informe a disciplina ou XXX para encerrar:\n");
	achou=0;
	while(strcmp("XXX",vDisc)!=0)
	{	
		scanf("%s", vDisc);
		
		while(1)
		{
			aux = DescritorLista.inicio;
			while (aux != NULL && !(strcmp(aux->disc, vDisc) == 0))
			{
				aux = aux->prox;
			}
			if (aux == NULL)
			{
				if(achou==0)
				{
					puts("Erro:Nao achou a diciplina");
				}
				break;
			}
			else
			{
				if (aux->ant == NULL)
				{	
					DescritorLista.inicio = aux->prox;
					if(aux->prox != NULL)
						aux->prox->ant = NULL;
				}
				else
				{	
					aux->ant->prox = aux->prox;
					if (aux == DescritorLista.final)
						DescritorLista.final = aux->ant;
					else
						aux->prox->ant = aux->ant;
					}
				free(aux);
				DescritorLista.itens=DescritorLista.itens-1;
				achou=1;
			}
		}
		ImprimeLista(DescritorLista, "Novo conteudo da lista:\n", 0);
		
	}
	return DescritorLista;
}

void ImprimeLista(Descritor	DescritorLista, char *cabec, char direcao)
{	TNo *aux;

	printf("%s", cabec);
	if(DescritorLista.inicio!=NULL)
	{
		if (direcao == 0)
		{	
			aux = DescritorLista.inicio;
			while (aux != NULL)
			{
				printf("RA:%s \tDiciplina:%s \tNota:%5.2f \tFalta:%3d\n", aux->RA, aux->disc,	aux->nota, aux->faltas);						
				aux = aux->prox;
			}
		}
		else
		{	
			aux = DescritorLista.final;
		while (aux != NULL)
		{	
			printf("RA:%s \tDiciplina:%s \tNota:%5.2f \tFalta:%3d\n", aux->RA, aux->disc,	aux->nota, aux->faltas);						
				aux = aux->ant;
			}
		}
	}
	else
	{
		printf("Lista vazia\n");
	}
}