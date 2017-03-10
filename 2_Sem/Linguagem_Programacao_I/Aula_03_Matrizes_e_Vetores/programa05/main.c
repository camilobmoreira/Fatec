#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool anoBissexto (int ano)
{
	if ((ano % 400 == 0) || (ano % 100 != 0 && ano % 4 == 0)) return true;
	else return false;
}

int pegaChaveMes (int mes)
{
	switch(mes)
	{
	case 1: return 1;
	case 2: return 4;
	case 3: return 4;
	case 4: return 0;
	case 5: return 2;
	case 6: return 5;
	case 7: return 0;
	case 8: return 3;
	case 9: return 6;
	case 10: return 1;
	case 11: return 4;
	case 12: return 6;
	}
}

int pegaChaveAno (int ano)
{
	int chaveAno = 0, finalAno = 0;
	finalAno = ano % 1000;
	if (finalAno > 100) finalAno = ano % 100;
	chaveAno += finalAno / 4;
	chaveAno += finalAno % 7;
	chaveAno = chaveAno % 7;
	return chaveAno;
}

void diaSemana (int chave)
{
	switch(chave)
	{
		case 0:
		{
			printf("Sábado");
			break;
		}
		case 1:
		{
			printf("Domingo");
			break;
		}
		case 2:
		{
			printf("Segunda-feira");
			break;
		}
		case 3:
		{
			printf("Terça-feira");
			break;
		}
		case 4:
		{
			printf("Quarta-feira");
			break;
		}
		case 5:
		{
			printf("Quinta-feira");
			break;
		}
		case 6:
		{
			printf("Sexta-feira");
			break;
		}
		default:
		{
			printf("Dia inválido");
			break;
		}
	}
}

int main()
{
	//char data[11], dia[2], mes[2], ano[4];
	//char data[11], ano[4];
	int dia = -1, mes = -1, ano = -1, chave;
	while (true)
	{
		printf("Informe uma data.\n");
		while (dia < 1 || dia > 31)
		{
			printf("Dia: ");
			scanf("%d", &dia);
			if (dia < 1 || dia > 31) printf("Dia inválido!");
		}
		while (mes < 1 || mes > 12)
		{
			printf("Mês: ");
			scanf("%d", &mes);
			if (mes < 1 || mes > 12) printf("Mês inválido!");
		}
		while (ano < 1900 || ano > 2099)
		{
			printf("Ano: ");
			scanf("%d", &ano);
			if (ano < 1900 || ano > 2099) printf("Ano inválido!");
		}
		if (!anoBissexto && mes == 2 && dia > 28)
		{
			printf("Data inválida!");
			continue;
		}
		else if (anoBissexto && mes == 2 && dia > 29)
		{
			printf("Data inválida!");
			continue;
		}
		else
		{
			break;
		}
	}

	chave = dia + pegaChaveMes(mes) + pegaChaveAno(ano);
	chave = chave % 7;
	if (anoBissexto && mes < 3) diaSemana(chave - 1);
	else diaSemana(chave);

	//dia[2] = data[0] + data[1];
	//mes[2] = data [3] + data[4];
	//ano[4] = data[6] + data[7] + data[8] + data[9];
    //ano[4] = data[0] + data[1] + data[2] + data[3];
	system("pause");
	return 0;
}
