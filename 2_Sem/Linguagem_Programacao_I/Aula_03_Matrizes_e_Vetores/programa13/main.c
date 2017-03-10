#include <stdio.h>
#include <stdlib.h>

int imprimirNota(int mat, char resp[3], char gab[3])
{
	int nota = 0, x;
	for (x = 0; x < 3; x++) if (resp[x] == gab[x]) nota++;
	printf("Gabarito: \n");
	for (x = 0; x < 3; x++) printf("%c ", gab[x]);
	printf("\nMatricula: %d\n", mat);
	printf("Respostas: \n");
	for (x = 0; x < 3; x++) printf("%c ", resp[x]);
	printf("\nNota: %d\n", nota);
}

void imprimirRespsotas(char resp[3])
{
	int x;
	for (x = 0; x < 3; x++) printf("%c ", &resp[x]);
}

int main()
{
    char gabarito[3], respostas	[3][3];
    int matricula[3];
    int x, y;

    printf("Informe as respostas do gabarito: \n");
    for (x = 0; x < 3; x++) scanf("%c", &gabarito[x]);

    for (x = 0; x < 3; x++)
    {
    	printf("Informe sua matricula: \n");
    	scanf("%d", &matricula[x]);
    	printf("Informe suas respostas: \n");
    	for (y = 0; y < 3; y++) scanf("%c", &respostas[x][y]);
    }

    for (x = 0; x < 10; x++) printf("\n");
    printf("Calculando notas...\n");
    for (x = 0; x < 2; x++) printf("\n");
    for (x = 0; x < 3; x++) imprimirNota(matricula[x], respostas[x], gabarito);
    system("pause");
    return 0;
}
