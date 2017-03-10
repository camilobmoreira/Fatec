#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void substitui_caracter(char s[])
{
    int i;
    for(i = 0;s[i] != '\0';i++)
    {
        if(tolower(s[i])=='a') s[i]='*';
    }
    printf("\Frase nova:%s\n", strrev(s));
}


int main()
{
    char s[50];
    printf("Informe uma frase: \n");
    gets (s);
    substitui_caracter(s);
    system("pause");
    return 0;
}
