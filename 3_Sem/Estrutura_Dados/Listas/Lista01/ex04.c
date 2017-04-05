#include <stdio.h>

int multiplicacao(int a, int b);

int main()
{
	printf("Mult = %d \n", multiplicacao(20, 7));
	return 0;
}

int multiplicacao(int a, int b)
{
	if (a == 0 || b == 0) return 0;
	else if (a == 1) return b;
	else if (b == 1) return a;
	else return a + multiplicacao(a, b - 1);
}
