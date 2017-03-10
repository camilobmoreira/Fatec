#include <stdio.h>
#include <stdlib.h>

char tipoCombustivel;
float valorLitro = -1, quantidadeCombustivel = -1;

void abastecerPorValor (float valor)
{
	printf("Abastecido %.f litros\n", valor/valorLitro);
	quantidadeCombustivel -= valor/valorLitro;
}

void abastecerPorLitro (float litros)
{
	printf("Valor a ser pago $\n", litros * valorLitro);
	quantidadeCombustivel -= litros;
}

void alterarValor(float valor)
{
	valorLitro = valor;
}

void alterarCombustivel(char c)
{
	tipoCombustivel = c;
}

void alterarQuantidadeCombustivel()
{
	float litros = -1;
	while (litros < 0)
	{
		printf("Informe nova quantidade de litros na bomba:\n");
		scanf("%f", &litros);
	}
	quantidadeCombustivel = litros;
}

int main()
{
	printf("Informe tipo de combustivel\n");
	//getch(tipoCombustivel);
	scanf(" %c", &tipoCombustivel);
	while (valorLitro < 0)
	{
		printf("Informe valor do litro\n");
		scanf(" %f", &valorLitro);
	}
	while (quantidadeCombustivel < 0)
	{
		printf("Informe quantidade de combustivel na bomba\n");
		scanf("%f", &quantidadeCombustivel);
	}

	int op = -1;
	while (op != 0)
	{
		printf("O que deseja fazer?"
				"\n1 - Abastecer por valor;"
				"\n2 - Abastecer por litros;"
				"\n3 - Alterar valor do litro;"
				"\n4 - Alterar tipo de combustivel;"
				"\n5 - Alterar quantidade de combustivel na bomba;"
				"\n0 - sair.\n");
		scanf("%d", &op);
		switch(op)
		{
			case(0):
			{
				break;
			}
			case(1):
			{
				float valor = -1;
				while (valor < 0)
				{
					printf("Informe valor a abastecer:\n");
					scanf("%f", &valor);
				}
				abastecerPorValor(valor);
				break;
			}
			case(2):
			{
				float litros = -1;
				while (litros < 0)
				{
					printf("Informe quantidade de litros a abastecer:\n");
					scanf("%f", &litros);
				}
				abastecerPorLitro(litros);
				break;
			}
			case(3):
			{
				float valor = -1;
				while (valor < 0)
				{
					printf("Informe novo valor:\n");
					scanf("%f", &valor);
				}
				alterarValor(valor);
				break;
			}
			case(4):
			{
				char c;
				//getch(c);
				printf("Informe novo tipo de combustivel:\n");
				scanf(" %c", &c);
				alterarCombustivel(c);
				op = 3;
				continue;
			}

		}
	}
	system("pause");
    return 0;
}
