/*
Nome:Gustavo Montanini Cenci RA:0030481521018
Nome:João Pedro Dornelas     RA:0030481521021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Exerc1reader.h"

int main()
{
	TNo *aux;
	Descritor DescritorLista;
	DescritorLista=IniciaLista(DescritorLista);
	
	DescritorLista=AdicionaLista(DescritorLista);
	
	ImprimeLista(DescritorLista, "Conteudo da lista:\n", 0);

	DescritorLista=ApagaLista(DescritorLista);
	
	ImprimeLista(DescritorLista, "Conteudo da lista:\n", 0);
	
	return 0;
}