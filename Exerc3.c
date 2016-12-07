/*
Nome:Gustavo Montanini Cenci RA:0030481521018
Nome:João Pedro Dornelas     RA:0030481521021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regNo {	float valor;
				struct regNo *prox;
			 };
typedef struct regNo TNo;

typedef struct {TNo *inicio; int qtde;} TLista;

void InicializaLista(TLista *);
void ImprimeLista(TLista *, char *);
void insereNoh(TLista *, float);
void SomaLista(TLista *,TLista *);

int main()
{
	float valor;
	TLista dLista1,dLista2,dListatotal;
	
	InicializaLista(&dLista1);
	InicializaLista(&dLista2);
	InicializaLista(&dListatotal);
	
	while (1)
	{	printf("Informe valor a ser inserido na lista:\n");
		scanf("%f", &valor);
		
		if (valor<0)
		{
			break;
		}
		insereNoh(&dLista1, valor);
	}
	
	while (1)
	{	printf("Informe valor a ser inserido na lista:\n");
		scanf("%f", &valor);
		
		if (valor<0)
		{
			break;
		}
		insereNoh(&dLista2, valor);
	}

	ImprimeLista(&dLista1, "Conteudo da lista1:\n");
	ImprimeLista(&dLista2, "Conteudo da lista2:\n");
	SomaLista(&dLista1,&dLista2);
	return 0;
}

void SomaLista(TLista *lista1,TLista *lista2)
{	TNo *aux1,*aux2;
	aux1 = lista1->inicio;
	aux2 = lista2->inicio;
	printf("Lista com a soma das anteriores\n");
		while (aux1 != NULL || aux2 != NULL)
		{	if(aux1 == NULL)
				printf("%.2f\n", aux2->valor);
			else if(aux2 == NULL)
				printf("%.2f\n", aux1->valor);	
			else
				printf("%.2f\n", aux1->valor+aux2->valor);
			
			if(aux1 != NULL)						
				aux1 = aux1->prox;
			if(aux2 != NULL)
				aux2 = aux2->prox;
			
		}
}

void ImprimeLista(TLista *lista, char *cabec)
{	TNo *aux;

	printf("%s", cabec);
	
	if (lista->inicio == NULL)
		puts("Lista estah vazia");
	else
	{	aux = lista->inicio;
		while (aux != NULL)
		{	printf("%f.2\n", aux->valor);
									
			aux = aux->prox;
		}
	}
}

void InicializaLista(TLista *d)
{	/* Inicializando o descritor da lista encadeada */
	d->inicio = NULL;
	d->qtde = 0;
}

void insereNoh(TLista *d,float valor)
{	TNo *aux, *ant;

	aux = (TNo *) malloc(sizeof(TNo));
	if (aux == NULL)
	{	puts("Memoria insuficiente para esta operacao!");
		exit(2);
	}
	aux->valor = valor;
	aux->prox = NULL;
		
	if (d->inicio == NULL)
		d->inicio = aux;
	else
	{	ant = d->inicio;
		while (ant->prox != NULL)
			ant = ant->prox;
		
		ant->prox = aux;
	}
	
	d->qtde = d->qtde + 1;
}