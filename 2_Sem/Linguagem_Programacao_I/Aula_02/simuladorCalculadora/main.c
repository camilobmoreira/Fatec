#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int somar(int n1, int n2)
{
    return (n1 + n2);
}

int subtrair(int n1, int n2)
{
    return (n1 - n2);
}

int multiplicar(int n1, int n2)
{
    return (n1 * n2);
}

int dividir(int n1, int n2)
{
    return (n1 / n2);
}

int main()
{
    int n1, n2, resp = 0, op;
    printf("Digite os números\n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    printf("Operação desejada? (1 +, 2 -, 3 *, 4 / )\n");
    //__fpurge(stdin);
    scanf("%d", &op);
    //op = getchar();
    switch(op)
    {
        case 1:
        {
            resp = somar(n1, n2);
            break;
        }
        case 2:
        {
            resp = subtrair(n1, n2);
            break;
        }
        case 3:
        {
            resp = multiplicar(n1, n2);
            break;
        }
        case 4:
        {
            resp = dividir(n1, n2);
            break;
        }
        default:
        {
            printf("Operação inválida\n");
            break;
        }
    }
    printf("Resposta: %d", resp);

    return 0;
}
