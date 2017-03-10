#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Cadastrar
{
    char nome [30];
    int rg;
    int dNasc;
} Cadastrar;

Cadastrar cadastro [10];

int x;
void cadastrarPessoas()
{
    char n[30];
    if (x<10)
    {
        printf("Informe Nome: \n");
        fflush(stdin);
        gets(n);
        strcpy(cadastro[x].nome, n);
        printf("Informe o numero do RG: \n");
        scanf("%d", &cadastro[x].rg);
        printf("Informe o ano de Nascimento: \n");
        scanf("%d", &cadastro[x].dNasc);
        x++;
    }
}

int ANO;//ano atual
void anoAtual()
{
     char dateStr [9];//data no formato dd/mm/aa\0
     int i;
     _strdate(dateStr);//chamada de uma fun��o da biblioteca time.h
     ANO=2000+((dateStr[6]-48)*10)+((dateStr[7]-48));//ajuste do ano atual

}

void idadePessoa()
{
    int i;
    int op;

    printf("Escolha o indice da pessoa desejada:\n");
    for(i=0; i<x; i++)
    {
        printf("%d - %s ;\n", i, cadastro[i].nome);
    }
    anoAtual();
    scanf("%d", &op);
    printf("Idade: %d\n\n", (ANO- cadastro[op].dNasc));
}

void depoisAno()
{
    int i;
    int ano;
    printf("Migo escolha o ano: \n");
    scanf("%d", &ano);
    for (i=0; i<x; i++)
    {
        if (cadastro[i].dNasc> ano)
        {
            printf("%s\n\n", cadastro[i].nome);
        }
    }
}

void antesAno()
{
    int i;
    int ano;
    printf("Migo escolha o ano: ");
    scanf("%d", &ano);
    for (i=0; i<x; i++)
    {
        if (cadastro[i].dNasc< ano)
        {
            printf("%s\n\n", cadastro[i].nome);
        }
    }
}

void encontrarRG()
{
    int i;
    int RG;
    printf("Parcinha digite o RG: ");
    scanf("%d", &RG);
    for (i=0; i<x; i++)
    {
        if (RG == cadastro[i].rg)
        {
            printf("%s\n\n", cadastro[i].nome);
        }
    }
}

int main()
{
    int op;
    while (op!=6)
    {
        printf("1- Cadastrar uma pessoa\n");
        printf("2- Calcular a idade de uma pessoa\n");
        printf("3- Listar pessoas que nasceram depois de um determinado ano\n");
        printf("4- Listar pessoas que nasceram antes de um determinado ano\n");
        printf("5-Encontrar o nome de uma pessoa com o RG\n");
        printf("6- Sair\n");

        scanf("%d", &op);

        switch (op)
        {
            case 1:
            {
                cadastrarPessoas();
                break;
            }
            case 2:
            {
                idadePessoa();
                break;
            }
            case 3:
            {
                depoisAno();
                break;
            }
            case 4:
            {
                antesAno();
                break;
            }
            case 5:
            {
                encontrarRG();
                break;
            }
            case 6:
            {
                break;
            }
        }

    }
    return 0;
}
