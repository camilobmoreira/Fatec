#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b_menor, b_maior, h, area;
    char c[1];
    printf("Informe a base menor:\n");
    scanf("%d", &b_menor);
    printf("Informe a base maior:\n");
    scanf("%d", &b_maior);
    printf("Informe a altura:\n");
    scanf("%d", &h);

    area = ((b_menor + b_maior) * h)/2;

    printf("A  área do trapezio é: %d\n", area);

    printf("Diite q e aperte ENTER para sair:\n");
    scanf("%s", &c);
    return 0;
}
