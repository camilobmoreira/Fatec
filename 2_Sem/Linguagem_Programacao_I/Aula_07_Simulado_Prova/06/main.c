#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[10][20];
    int cont = 0;
    printf("Informe 10 nomes, um de cada vez: \n");
    char temp[20];
    for (cont = 0; cont < 10; cont++)
    {
        fflush(stdin);
        fgets(temp, 20, stdin);
        strcpy(nome[cont], temp);
    }
    printf("Imprimindo nomes: \n");
    for (cont = 0; cont < 10; cont++) printf("%s \n", nome[cont]);
    return 0;
}
