#include <stdio.h>

void inverterVetor(int v[], int n);

int main()
{
	int v[100];
	for (int i = 0; i < 100; i++) v[i] = i+1;
	printf("Vetor original: \n\n");
	for (int i = 0; i < 100; i++) printf("%d \n", v[i]);
	inverterVetor(v, 100);
	printf("\n\n");
	printf("Vetor invertido: \n\n");
	for (int i = 0; i < 100; i++) printf("%d \n", v[i]);
	return 0;
}

void inverterVetor(int v[], int n)
{
	int aux = v[100-n];
	v[100 - n] = v[n-1];
	v[n-1] = aux;
	if (n-1 != 50) inverterVetor(v, n-1);
}
