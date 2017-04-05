#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int num;
	struct cel *prox;
} celula;

celula * transformaListaEncadeada(int v[], int t);

int main()
{
	int v[4] = {10, 20, 30, 40};
	printf("Vetor: \n");
	for (int i = 0; i < 4; i++) printf("%i \n", v[i]);
	printf("\n\n");
	
	celula *lista = transformaListaEncadeada(v, 4);
	printf("Lista Encadeada: \n");
	for (celula *l = lista->prox; l->prox != NULL; l = l->prox) printf("%i \n", l->num);
	
	
	
	return 0;
}

celula * transformaListaEncadeada(int v[], int t)
{
	celula *aux = malloc(sizeof(celula));
	celula *cab = malloc(sizeof(celula));
	cab->prox = aux;
	
	for (int i = 0; i < t; i++)
	{
		aux->num = v[i];
		aux->prox = malloc(sizeof(celula));
		aux = aux->prox;
	}
	return cab;
}
