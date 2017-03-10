#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void separaParteIntDec(float n)
{
    int parteInt;
    float parteInteira, parteDecimal;
    parteInteira = floor(n);
    parteDecimal = n - parteInteira;
    parteInt = (int)(parteInteira);
    printf("Parte inteira: %d \nParte decimal: %.2f", parteInt, parteDecimal);
}

int main()
{
    float parteInteira, parteDecimal, n;

    printf("Informe um número com casa decimal: \n");
    scanf("%f", &n);
    separaParteIntDec(n);
    system("pause");
    return 0;
}
