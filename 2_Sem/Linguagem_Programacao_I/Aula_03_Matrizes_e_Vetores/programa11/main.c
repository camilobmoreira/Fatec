#include <stdio.h>
#include <stdlib.h>

int somarMatriz(int num1[4][4], int num2[4][4])
{
    int x, y;
	int num[4][4];
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			num[x][y] = num1[x][y] + num2[x][y];
		}
	}
	return num[x][y];
}

int subtrairMatriz(int num1[4][4], int num2[4][4])
{
    int x, y;
	int num[4][4];
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			num[x][y] = num1[x][y] - num2[x][y];
		}
	}
	return num[x][y];
}

void imprimirMatriz (int num[4][4])
{
    int x, y;
	printf("Matriz resultante:\n");
    for (x = 0; x < 4; x++)
    {
        printf("a");
        for (y = 0; y < 4; y++)
        {
            printf("%d ", num[x][y]);
        }
        printf("\n");
    }
}

int main()
{
	int x, y;
	int num1[4][4], num2[4][4];
	printf("Matriz 1: \n");
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
        {
			printf("Informe o numero da linha %d coluna %d\n", x, y);
			scanf("%d", &num1[x][y]);
		}
	}

	printf("Matriz 2: \n");
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			printf("Informe o numero da linha %d coluna %d\n", x, y);
			scanf("%d", &num2[x][y]);
		}
	}

	printf("Matriz 1: \n");
	imprimirMatriz(num1[4][4]);
	printf("Matriz 2: \n");
	imprimirMatriz(num2[4][4]);

	int op;
	printf("Escolha a opção desejada: \n"
			"1 - Soma de matrizes;\n"
			"2 - Subtração de matrizes.\n");
	scanf("%d", &op);
	if (op == 1) imprimirMatriz(somarMatriz(num1[4][4], num2[4][4]));
	else if (op == 2) imprimirMatriz(subtrairMatriz(num1[4][4], num2[4][4]));
	else printf("Opção inválida. Saindo...");
	system("pause");
    return 0;
}
