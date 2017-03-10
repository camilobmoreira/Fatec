#include <stdio.h>
#include <stdlib.h>

//char nome[20];
int idade = -1;
float peso = -1, altura = -1;

void envelhecer(int anos)
{
	for (int x = 1; x <= anos; x++)
	{
		if (idade < 21) crescer();
		idade++;
	}	
}

void engordar(float kg)
{
	peso += kg;
}

void emagrecer(float kg)
{
	peso -= kg;
}

void crescer()
{
	altura += .05;
}

int main()
{
	int op = -1;
	printf("Informe o nome: \n");
	//getch(nome);
	while (idade < 0)
	{
		printf("Informe a idade: \n");
		scanf("%d", &idade);
	}
	while (peso < 0)
	{
		printf("Informe o peso: \n");
		scanf("%f", &peso);
	}
	while (altura < 0)
	{
		printf("Informe a altura: \n");
		scanf("%f", &altura);
	}
	
	while (op != 0)
	{
		printf("O que deseja fazer? "
				"\n1 - envelhecer;"
				"\n2 - engordar;"
				"\n3 - emagrecer;"
				"\n4 - crescer;"
				"\n5 - ver informações;"
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
				int anos = -1;
				while (anos < 0)
				{
					printf("Informe quantos anos: \n");
					scanf("%d", &anos);
				}
				envelhecer(anos);
				break;
			}
			case(2):
			{
				float kg = -1;
				while (kg < 0)
				{
					printf("Informe quantos kg: \n");
					scanf("%f", &kg);
				}
				engordar(kg);
				break;
			}
			case(3):
			{
				float kg = -1;
				while (kg < 0)
				{
					printf("Informe quantos kg: \n");
					scanf("%f", &kg);
				}
				emagrecer(kg);
				break;
			}
			case(4):
			{
				crescer();
				break;
			}
			case(5):
			{
				printf("Nome: ;" //adicionar %c para nome
						"\nIdade: %d;"
						"\nPeso: %.2f;"
						"\nAltura: %.2f;" ,idade, peso, altura); //adicionar varial nome no inicio
				break;
			}
			default:
			{
				printf("Opção invalida.\n");
			}
		}
	}
	system("pause");
    return 0;
}
