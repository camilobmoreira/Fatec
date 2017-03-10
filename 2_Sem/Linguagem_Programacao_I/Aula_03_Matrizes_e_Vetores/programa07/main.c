#include <stdio.h>
#include <stdlib.h>

const float consumo = 12.3;
float nivelCombustivel = 0;

void andar()
{
	float distancia = 99999;
	while (distancia > (nivelCombustivel * consumo))
	{
		printf("Quantos km?\n");
		scanf("%f", &distancia);
		if (distancia > (nivelCombustivel * consumo)) printf("Você só tem combustivel para dirigir por %.2f km\n", (consumo * nivelCombustivel));
	}
	nivelCombustivel -= distancia / consumo;
}

float obterGasolina()
{
	return nivelCombustivel;
}

void adicionarGasolina(float litros)
{
	while (nivelCombustivel + litros > 45)
		{
			if (nivelCombustivel + litros > 45)
				{
					printf("A quantidade digitada excede o limite do tanque. "
						"\nAbasteça no máximo %.2f litros. "
						"\nQuantos litros deseja abastecer?\n", (45 - nivelCombustivel));
					scanf("%f", &litros);
				}
		}

	nivelCombustivel += litros;
}

int main()
{
	int op = -1;
	while (op < 0 || op > 4)
	{
		printf("O que deseja fazer? "
				"\n1 - Dirigir; "
				"\n2 - Ver nível de combustivel; "
				"\n3 - Abastecer o veículo; "
				"\n4 - Sair.\n");
		scanf("%d", &op);
		switch(op)
		{
			case(1):
			{
				andar();
				op = -1;
				break;
			}
			case(2):
			{
				printf("%.2f litros no tanque.\n", obterGasolina());
				op = -1;
				break;
			}
			case(3):
			{
				float litros;
				printf("Quantos litros deseja abastecer?\n");
				scanf("%f", &litros);
				adicionarGasolina(litros);
				op = -1;
				break;
			}
			case(4):
			{
				break;
			}
			default:
			{
				printf("Opção inválida.\n");
				break;
			}
		}

	}
	system("pause");
    return 0;
}
