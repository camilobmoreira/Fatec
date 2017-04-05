#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int num;
	struct cel *prox;
} celula;

celula * juntarListasEcadeadasOrdenadas(celula *l1, celula *l2);
celula * transformaListaEncadeada(int v[], int t);;

int main()
{
	int v1[4] = {1, 3, 5, 6};	
	celula *l1 = transformaListaEncadeada(v1, 4);
	int v2[4] = {2, 4, 7, 8};
	celula *l2 = transformaListaEncadeada(v2, 4);
	
	celula *l3 = juntarListasEcadeadasOrdenadas(l1->prox, l2->prox);
	for (l3 = l3->prox; l3 != NULL; l3 = l3->prox) printf("l3 %d\n", l3->num);
	return 0;
}

celula * juntarListasEcadeadasOrdenadas(celula *l1, celula *l2)
{
	celula *l3 = malloc(sizeof(celula));
	celula *aux = malloc(sizeof(celula));
	l3->prox = aux;

	while (l1 != NULL || l2 != NULL) {
		if (l1 != NULL && l1->num <= l2->num) {
			aux->num = l1->num;
			if (l1->prox == NULL) {
				aux->prox = l2;
				break;
			}
			l1 = l1->prox;
		} else if (l2 != NULL && l2->num < l1->num) {
			aux->num = l2->num;
			if (l2->prox == NULL) {
				aux->prox = l1;
				break;
			}
			l2 = l2->prox;
		}
		aux->prox = malloc(sizeof(celula));
		aux = aux->prox;
	}
		
	return l3;
}

celula * transformaListaEncadeada(int v[], int t)
{
	celula *aux = malloc(sizeof(celula));
	celula *cab = malloc(sizeof(celula));
	cab->prox = aux;
	
	for (int i = 0; i < t; i++)
	{
		aux->num = v[i];
		if (i < t-1) {
			aux->prox = malloc(sizeof(celula));
			aux = aux->prox;	
		}
	}

	return cab;
}

