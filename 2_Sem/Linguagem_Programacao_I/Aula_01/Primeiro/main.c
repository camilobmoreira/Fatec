#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n1, n2, media;

    printf("Digite a 1ª nota\n");
    scanf("%d", &n1);
    printf("Digite a 2ª nota\n");
    scanf("%d", &n2);
    media = (n1 + n2)/2;
    if (media >= 7)
    {
        printf("Aprovado com média %d", media);
    }
    else
    {
        printf("Reprovado com média %d", media);
    }
    return 0;
}
