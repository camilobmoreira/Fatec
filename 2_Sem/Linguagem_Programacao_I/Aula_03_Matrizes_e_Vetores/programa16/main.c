#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool palindromo(char frase, char fraseInvertida)
{
	if (frase == fraseInvertida) return true;
	else return false;
}

int main()
{
	char frase;
    printf("Informe uma frase (apenas letras minusculas)\n");
    scanf("%s", &frase);

    if (palindromo(frase, strrev(frase))) printf("Palindromo.");
	else printf("Não é palindromo.");
    system("pause");
    return 0;
}
