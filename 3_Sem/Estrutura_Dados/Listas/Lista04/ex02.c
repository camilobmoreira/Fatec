#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int num;
	struct cel *prox;
	struct cel *ant;
} celula;

typedef struct {
	struct cel *head;
	struct cel *tail;
} headTail;


celula * transformaListaDuplamenteEncadeada(int v[], int n);
void imprimirLista(celula *s);

int main() {
	int v[4] = {10, 20, 30, 40};
	celula *cab = transformaListaDuplamenteEncadeada(v, 4);

	printf("Lista: \n");
	imprimirLista(cab->prox);
}

celula * transformaListaDuplamenteEncadeada(int v[], int n) {

	celula *cab = malloc(sizeof(celula));
	celula *aux = malloc(sizeof(celula));
	celula *temp;
	
	aux->ant = cab;
	cab->prox = aux;
		
	for (int i = 0; i < n; i++) {
		aux->num = v[i];
		if (i <= (n -1)) {
			temp = aux;
			aux->prox = malloc(sizeof(celula));
			aux = aux->prox;
			aux->ant = temp;
		}
	}
	
	free(aux);
	return cab;
}

void imprimirLista(celula *s)
{
	for(s; s->prox != NULL ; s = s->prox) { 
		printf("%d \n", s->num);
	}
}
