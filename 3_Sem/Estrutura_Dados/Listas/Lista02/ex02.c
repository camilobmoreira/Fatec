#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int num;
	struct cel *prox;
} celula;

void removerElementosRepetidos(celula *aux);
celula * transformaListaEncadeada(int v[], int t);
celula * intercalarListasEncadeadas(celula *l1, celula *l2);

int main()
{
	int v[10] = {1, 1, 2, 2, 2, 3, 4, 5, 6, 6};
	printf("Vetor: \n");
	for (int i = 0; i < 10; i++) printf("%i \n", v[i]);
	printf("\n\n");
	
	celula *lista = transformaListaEncadeada(v, 10);
	printf("Lista Encadeada: \n");
	for (celula *l = lista->prox; l->prox != NULL; l = l->prox) printf("%i \n", l->num);
	printf("\n\n");

	printf("Lista Encadeada sem elementos repetidos: \n");
	removerElementosRepetidos(lista);
	for (celula *l = lista->prox; l->prox != NULL; l = l->prox) printf("%i \n", l->num);
	
	
	return 0;
}


void removerElementosRepetidos(celula *aux)
{
	for (aux = aux->prox; aux->prox != NULL;aux) 
	{
		if (aux->num == aux->prox->num) 
		{
			aux->prox = aux->prox->prox;
		}
		else
		{
			aux = aux->prox;
		}
	}	
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
