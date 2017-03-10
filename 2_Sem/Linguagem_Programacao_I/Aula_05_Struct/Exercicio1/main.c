#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoas
{
    char nome[31];
    int idade;
}Pessoas;

Pessoas cadastro[10];

int main()
{
    char n[30];
    int i;
    for (i=0; i<2; i++)
    {
        printf("Informe nome: ");
        fflush(stdin);
        gets(n);
        strcpy(cadastro[i].nome, n);
        printf("Informe Idade: ");
        scanf("%d", &cadastro[i].idade);
    }
    for (i=0; i<2; i++)
    {
        printf("%s\n", cadastro[i].nome);
        printf("%d\n", cadastro[i].idade);
    }
}
