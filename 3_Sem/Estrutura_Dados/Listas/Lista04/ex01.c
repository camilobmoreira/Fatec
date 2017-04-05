#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int num;
	struct cel *prox;
} celula;

celula * transformaListaEncadeada(int v[], int t);
celula * intercalarListasEncadeadas(celula *l1, celula *l2);
void imprimirLista(celula *l);

int main()
{
	int v1[4] = {10, 20, 30, 40};	
	celula *l1 = transformaListaEncadeada(v1, 4);
	printf("Lista 1: \n");
	imprimirLista(l1->prox);
	printf("\n\n");

	int v2[4] = {50, 60, 70, 80};
	celula *l2 = transformaListaEncadeada(v2, 4);
	celula *p = l2->prox;
	printf("Lista 2: \n");
	imprimirLista(l2->prox);
	printf("\n\n");
		
	celula *l3 = intercalarListasEncadeadas(l1->prox, l2->prox);
	printf("Lista Intercalada: \n");
	imprimirLista(l3->prox);
	
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

celula * intercalarListasEncadeadas(celula *l1, celula *l2)
{
	celula *l3 = malloc(sizeof(celula));
	celula *aux = malloc(sizeof(celula));
	l3->prox = aux;
	
	
	for (l1 && l2; (l1->prox != NULL) && (l2->prox != NULL); (l1 = l1->prox) && (l2 = l2->prox))
	{
		aux->num = l1->num;
		aux->prox = malloc(sizeof(celula));
		aux = aux->prox;
		aux->num = l2->num;
		aux->prox = malloc(sizeof(celula));
		aux = aux->prox;
	}
	
	free(aux);
	return l3;
}

void imprimirLista(celula *l)
{
	for(l; l->prox != NULL; l = l->prox) printf("%d \n", l->num);
}
