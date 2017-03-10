#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, x=5;
    //*p indica que a variavel p é um ponteiro

    *p *= 2**p;
    //*p indica um ponteiro
    //*= indica multiplicação por ele proprio e o numero 2 (seria a mesma coisa que p = p * 2)
    // após o numero 2 indica multiplicação
    // *p indica um ponteiro

    printf("%d\n", x);
    //printa na tela o valor de x (que ainda é 5)

    system("pause");
    return 0;
}

