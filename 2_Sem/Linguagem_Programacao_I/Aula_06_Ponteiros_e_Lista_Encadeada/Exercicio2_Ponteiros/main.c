#include <stdio.h>
#include <stdlib.h>

char *dia_semana(int n)
{
    char *d[] = {"erro","domingo","segunda-feira","terça-feira","quarta-feira","quinta-feira","sexta-feira","sábado"};
    return d[1<=n && n<=7 ? n : 0];
}

int main()
{
    printf("dia da semana %s", dia_semana(9));
    system("pause");
    return 0;
}
/**
2)-
a) O programa mostra um dia da semana referente ao inteiro escolhido. Ex: 1 - Domingo, 2 - Segunda, 0 - Erro.
b)Sim Existe. É um ponteiro de char, que facilita no entendimento e reduz algumas linhas do código.
 */

