#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool anoBissexto (int ano)
{
	if (ano % 100 != 0 && ano % 4 == 0) return true;
	else if (ano % 400 == 0) return true;
	else return false;
}


char *dia_semana(int n)
{
    char *d[] = {"sábado","domingo","segunda-feira","terça-feira","quarta-feira","quinta-feira","sexta-feira","erro"};
    return d[0<=n && n<=6 ? n : 7];
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


int main()
{
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
	if (anoBissexto && mes < 3) printf("%s", dia_semana(chave - 1));
	else printf("%s", dia_semana(chave));

	system("pause");
	return 0;
}
