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