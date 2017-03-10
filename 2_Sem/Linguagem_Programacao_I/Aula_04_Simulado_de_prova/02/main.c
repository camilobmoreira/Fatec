#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int x, y, menor;
	char letras[5], ordenadas[5];
    for (x = 0;x < 5;x++)
    {
    	printf("Informe a %d letra.\n", x+1);
    	letras[x] = getche();
    	printf("\n");
    }
    for (x = 0;x < 5;x++)
    {
    	menor = 0;
    	for (y = 0;y < 5;y++)
    	{
    		if(letras[menor] > letras[y]) menor = y;
    	}
    	ordenadas[x] = letras[menor];
    	letras[menor] = 'Z';
    }
    printf("Letras ordenadas: \n");
    for (x = 0;x < 5;x++) printf("%c ", ordenadas[x]);
    return 0;
}
