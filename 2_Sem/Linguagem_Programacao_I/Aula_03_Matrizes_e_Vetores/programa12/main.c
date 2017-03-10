#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

void converteMaiuscula(char nomes[5][10])
{
	printf("Nomes em letra maiuscula: \n");
	int i;
	for(i=0;i<5;i++) printf("%s\n", strupr(nomes[i]));
}

void ordemAlfabetica(char nomes[5][10])
{
	char nomesTemp[5][10];
	int i, x;
	for(i=0;i<5;i++) strcpy(nomesTemp[i], nomes[i]);
	//for(i=0;i<5;i++) strcpy(nomesTemp[i], nomes[i]);

    int menor;
	for(i=0;i<5;i++)
    {
        menor = 0;
		for(x=0;x<5;x++)
		{
            if(strcmp(nomesTemp[menor], nomesTemp[x]) > 0) menor = x;
			//if(nomes[menor][0] > nomes[x][0]) menor = x;
		}
		strcpy(nomes[i], nomes[menor]);
        strcpy(nomesTemp[menor], "z");
	}
	printf("Nomes em ordem alfabetica: \n");
	for(i=0;i<5;i++) printf("%s\n", nomes[i]);
}

void informarUmNomes(char nomes[5][10])
{
    char n[10];
    int z = 0;
	printf("Informe o novo nome: \n");
    fflush(stdin);
    gets(n);
    printf("Informe o indice que deseja alterar o nome: \n");
    scanf("%d", &z);
    strcpy(nomes[z], n);
}

int main()
{
	char nomes[5][10];
	int i;
	printf("\Digite nomes:\n");
	for(i=0;i<5;i++) gets(nomes[i]);
	converteMaiuscula(nomes);
	ordemAlfabetica(nomes);
	informarUmNomes(nomes);
	for(i=0;i<5;i++) printf("%s\n", nomes[i]);
	system("pause");
    return 0;
}
