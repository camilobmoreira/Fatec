#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta_caracter(char s[],char c)
{
  int i, qtde=0;
  for(i=0;s[i]!='\0';i++)
  {
      if(tolower(s[i])==tolower(c)) qtde++;
  }
  return qtde;
}

void substitui_caracter(char s[],char c1, char c2)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(tolower(s[i])==tolower(c1))
		{
			s[i]=c2;
			break;
		}
	}
	printf("\nApós substituição ficou: %s.\n", s);
}

int main()
{
	int op = -1;
	char s1[20], s2[20];
	while (op != 0)
	{
		printf("Escolha a opção desejada:"
				"\n1 - Ler uma string;"
				"\n2 - Imprimir o tamanho da string;"
				"\n3 - Comparar com uma nova string;"
				"\n4 - Concatenar com uma nova string;"
				"\n5 - Imprimir a string ao contrário"
				"\n6 - Contar caracter na string;"
				"\n7 - Substituir um carater por outro na frase;"
				"\n0 - Sair.\n");
		scanf("%d", &op);
		switch(op)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			printf("Informe uma frase (s1): \n");
			gets(s1);
			break;
		}
		case 2:
		{
			printf("Tamanho da string (s1): %d.\n", strlen(s1));
			break;
		}
		case 3:
		{
			printf("Informe uma nova frase (s2): \n");
			gets(s2);
			printf("Resultado da comparação (-1 = menor / 0 = mesmo tamanho / 1 = maior): %d.\n", strcmp(s1, s2));
			break;
		}
		case 4:
		{
			printf("Informe uma nova frase (s2): \n");
			gets(s2);
			printf("Resultado da concatenação: %s.\n", strcat(s1, s2));
			break;
		}
		case 5:
		{
			//printf("Inverso da string (s1): %s.\n", strrev(s1));
			break;
		}
		case 6:
		{
			char c;
			printf("Informe caracter que deseja contar na string (s1: \n");
			scanf("%c", &c);
			printf("%d ocorrencias.\n", conta_caracter(s1, c));
			break;
		}
		case 7:
		{
			char c1, c2;
			printf("Informe o caracter a ser substituido: \n");
			scanf("%c", &c1);
			printf("Informe o caracter por qual será substituido: \n");
			scanf("%c", &c2);
			substitui_caracter(s1, c1, c2);
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
