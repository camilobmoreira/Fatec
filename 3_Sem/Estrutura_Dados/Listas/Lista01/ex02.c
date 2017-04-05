#include <stdio.h>

void imprimirRecursivo(int n);

int main()
{
	imprimirRecursivo(5);
	return 0;
}

void imprimirRecursivo(int n)
{
	printf("%d \n", n);
	if (n != 0)
	{
		imprimirRecursivo(n-1);
		printf("%d \n", n);
	}
}
