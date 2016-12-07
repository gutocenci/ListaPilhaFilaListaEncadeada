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