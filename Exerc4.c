/*
Nome:Gustavo Montanini Cenci RA:0030481521018
Nome:João Pedro Dornelas     RA:0030481521021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str_letra{char letra; struct str_letra *prox;};

typedef struct str_letra t_letra;
typedef struct{t_letra *topo;}p_top;

void push(p_top *t, char letra){	
	t_letra *aux;
	aux = (t_letra *)malloc(sizeof(t_letra));
	aux->letra = letra;
	aux->prox = t->topo;
	t->topo = aux;	
}

void pop(p_top *t){
	t_letra *aux;
	aux = t->topo;
	t->topo = aux->prox;
	free(aux);	
}

int main(){	
	
	p_top t;
	char palavra[21];
	int m, c, metade, tamanho;

	printf("Digite uma palavra ou FIM para encerrar\n");
	scanf("%s", palavra);
	while(strcmp(palavra,"FIM")){
		
		tamanho = strlen(palavra);
		metade = tamanho / 2;
		
		if(tamanho % 2 == 0)
			m=0;
		else
			m=1;
		
		for(c=0; c<strlen(palavra); c++){
			palavra[c]=tolower(palavra[c]);
		}
		
		t.topo = NULL;
		
		for(c=0; c<metade; c++){
			push(&t, palavra[c]);
		}
		
		for(c=metade+m; t.topo != NULL; c++){
			if(palavra[c] == t.topo->letra)
				pop(&t);
			else
				break;
		}
		
		if(t.topo == NULL)
			printf("Palindromo.\n");
		else
			printf("Nao eh palindromo.\n");
		
		printf("informe outra palavra ou FIM para encerrar\n");
		scanf("%s", palavra);
	}
	
	return 0;
}



