#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

typedef struct pessoas
{
    char nome [30];
    int rg, anoNasc;
    struct pessoas *prox;
}*PESSOA;


void addItem(PESSOA *local)
{
    PESSOA  novo;
    novo=(PESSOA)malloc(sizeof(struct pessoas));
    if(novo!=NULL)
    {

        printf("\nDigite o nome: ");
        fflush(stdin);
        gets(novo->nome);
        printf("\nDigite o RG:");
        scanf("%d", &novo->rg);
        printf("\nAno Nascimento:");
        scanf("%d", &novo->anoNasc);
        novo->prox=*local;
        *local=novo;
    }
}

void imprime(PESSOA local)
{
    int i = 0;
    printf("\n**** Imprimindo lista atualizada***\n");
    printf("\n");
    while (local!=NULL)
    {
        printf("Nome: %s\n", local->nome);
        printf("RG: %d\n", local->rg);
        printf("Ano: %d\n", local->anoNasc);
        local=local->prox;
        printf("\n");
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

void idadePessoa(PESSOA local)
{
    int i;
    char nome [30];

    imprime(local);
    printf("Digite o nome da pessoa desejada:\n");
    fflush(stdin);
    gets(nome);
    anoAtual();
    while (local!=NULL)
    {
        if (strcmp(nome, local->nome) == 0)
        {
            printf("Nome: %s\n", local->nome);
            printf("Idade: %d\n\n", (ANO - local->anoNasc));
            printf("\n");
            break;
        }
        local=local->prox;
        printf("\n");
    }

}

void depoisAno(PESSOA local)
{
    int i;
    int ano;
    printf("Migo escolha o ano: \n");
    scanf("%d", &ano);
    while (local!=NULL)
    {
        if (ano > local->anoNasc)
        {
            printf("Nome: %s\n", local->nome);
            printf("\n");
        }
        local=local->prox;
        printf("\n");
    }
}

void antesAno(PESSOA local)
{
    int i;
    int ano;
    printf("Migo escolha o ano: ");
    scanf("%d", &ano);
    while (local!=NULL)
    {
        if (ano < local->anoNasc)
        {
            printf("Nome: %s\n", local->nome);
            printf("\n");
        }
        local=local->prox;
        printf("\n");
    }
}

void encontrarRG(PESSOA local)
{
    int i;
    int RG;
    printf("Parcinha digite o RG: ");
    scanf("%d", &RG);
    while (local!=NULL)
    {
        if (RG == local->rg)
        {
            printf("Nome: %s\n", local->nome);
            printf("\n");
            break;
        }
        local=local->prox;
        printf("\n");
    }
}

int main()
{
    PESSOA acervo=NULL;
    int op;
    while (op!=6)
    {
        printf("1 - Cadastrar uma pessoa\n");
        printf("2 - Calcular a idade de uma pessoa\n");
        printf("3 - Listar pessoas que nasceram depois de um determinado ano\n");
        printf("4 - Listar pessoas que nasceram antes de um determinado ano\n");
        printf("5 - Encontrar o nome de uma pessoa com o RG\n");
        printf("6 - Sair\n");

        scanf("%d", &op);

        switch (op)
        {
            case 1:
            {
                addItem(&acervo);
                break;
            }
            case 2:
            {
                idadePessoa(acervo);
                break;
            }
            case 3:
            {
                depoisAno(acervo);
                break;
            }
            case 4:
            {
                antesAno(acervo);
                break;
            }
            case 5:
            {
                encontrarRG(acervo);
                break;
            }
            case 6: break;
        }
    }
    system("pause");
    return 0;

}
