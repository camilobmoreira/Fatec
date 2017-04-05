#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int num;
	struct cel *prox;
} celula;

void concatenarListasEcadeadas(celula **l1, celula *l2);
celula * transformaListaEncadeada(int v[], int t);;

int main()
{
	int v1[4] = {10, 20, 30, 40};	
	celula *l1 = transformaListaEncadeada(v1, 4);
	int v2[4] = {50, 60, 70, 80};
	celula *l2 = transformaListaEncadeada(v2, 4);
	concatenarListasEcadeadas(&l1, l2);
	celula *l3 = l1->prox;
	for (*l3; l3->prox != NULL; l3 = l3->prox) printf("l3 %d\n", l3->num);
	return 0;
}

void concatenarListasEcadeadas(celula **l1, celula *l2)
{
	celula *l3 = *l1;
	for (*l3; l3 != NULL; l3 = l3->prox) 
	{
		if (l3->prox->prox == NULL) 
		{
			l3->prox = l2->prox;
			break;
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

