#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char temp[100];

void leFrase()
{
    printf("Informe uma frase: \n");
    fflush(stdin);
    fgets(temp, 100, stdin);
}

void imprimirUmCharPorVes()
{
    int x = 0;
    for (x = 0; temp[x] != '\0';x++) printf("\'%c\' ", temp[x]);
    printf("\n");
}

void imprimirInverso()
{
    int x = 0;
    for (x = 0; temp[x] != '\0';x++){}
    for (x; x >= 0; x--) printf("%c", temp[x]);
    printf("\n");
}

void contarEspacosEmBranco()
{
    int x = 0, cont = 0;
    for (x = 0; temp[x] != '\0';x++) if (temp[x] == ' ') cont++;
    printf("%d espacos em branco na frase. \n", cont);
}


int main()
{
    int op = 1;
    while (op != 0)
    {
        printf("Escolha uma opcao: \n");
        printf("1 - Ler uma frase; \n");
        printf("2 - Imprimir char por char; \n");
        printf("3 - Imprimir ao contrario; \n");
        printf("4 - Contar o numero de espacos em branco; \n");
        printf("0 - Sair.\n");
        scanf("%d", &op);
        system("cls");
        switch(op)
        {
        case 1:
            {
                leFrase();
                break;
            }
        case 2:
            {
                imprimirUmCharPorVes();
                break;
            }
        case 3:
            {
                imprimirInverso();
                break;
            }
        case 4:
            {
                contarEspacosEmBranco();
                break;
            }
        case 0: break;
        default: printf("Opcao invalida. \n");
        }
    }
    return 0;
}
