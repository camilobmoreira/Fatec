#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[15];
    int x, maior = 0, indiceMaior = 0, menor = 99999999, indiceMenor = 0;
    for (x = 0;x < (sizeof(n)/sizeof(int)); x++)
    {
        printf("Informe o numero de indice %d:\n", x);
        scanf("%d", &n[x]);
        if (n[x] > maior)
        {
            maior = n[x];
            indiceMaior = x;
        }
        if (n[x] < menor)
        {
            menor = n[x];
            indiceMenor = x;
        }
    }
    printf("Incide maior: %d \nIndice menor: %d", indiceMaior, indiceMenor);
    system("pause");
    return 0;
}
