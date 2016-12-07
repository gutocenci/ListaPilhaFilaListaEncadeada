/*
Nome:Gustavo Montanini Cenci RA:0030481521018
Nome:João Pedro Dornelas     RA:0030481521021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Exerc2reader.h"
TNo Lista[100];

int main(){
	Descritor DescritorLista;
	
	DescritorLista=AdicionaLista(DescritorLista);

	if(strcmp(Lista[0].vRA, "XXX") == 0){
		printf("Lista Vazia");
		return 0;
	}
	
	DescritorLista=ApagaLista(DescritorLista);
	
	DescritorLista=ImprimeLista(DescritorLista);
	
	return 0;
}
