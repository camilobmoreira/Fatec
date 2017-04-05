#include <stdio.h>

void inverteNumero(int n);

int main()
{
	int n = 123;
	inverteNumero(n);
	return 0;
}

void inverteNumero(int n)
{
	if (n > 0)
	{	
		printf("%.0f", (((((double)n/10) - (n/10)) * 10)));
		
		inverteNumero(n/10);
	}
	printf("\n");
}
