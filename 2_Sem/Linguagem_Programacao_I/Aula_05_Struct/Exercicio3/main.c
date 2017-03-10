#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

typedef struct Circulo
{
    int x;
    int y;
    int raio;
}Circulo;

Circulo circ;

void calcularComprimento()
{
    printf("Circunferencia: %d\n", (3.14*(2*circ.raio)));
}

void area()
{
    printf("Area circunferencia: %d\n", (3.14*(circ.raio*circ.raio)));
}

/* move cursor na tela conforme coordenada recebida, sem retorno de valor */
void gotoxy(int coluna, int linha)
{
      COORD point;
      point.X = coluna;
      point.Y = linha;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void desenhar()
{

    gotoxy(circ.x, circ.y-circ.raio);
    putch(169);
    //printf("-");
    gotoxy(circ.x-circ.raio, circ.y);
    //printf("|");
    putch(169);
    gotoxy(circ.x, circ.y);
    //printf("+");
    putch(169);
    gotoxy(circ.x+circ.raio, circ.y);
    //printf("|");
    putch(169);
    gotoxy(circ.x, circ.y+circ.raio);
    putch(169);
    //printf("-");

}



int main()
{
    int op;
    printf("Digite o raio do circulo: \n");
    scanf("%d", &circ.raio);
    printf("Digite a coordenada X (horizontal): \n");
    scanf("%d", &circ.x);
    printf("Digite a coordenada Y (vertical): \n");
    scanf("%d", &circ.y);

    while(op!=4)
    {
        gotoxy(0,0);
        printf("Escolha dentre as opcoes\n");
        printf("1-Calcular comprimento\n");
        printf("2-Calcular area\n");
        printf("3-Desenhar\n");
        printf("4-Sair\n");

        scanf("%d", &op);

        switch (op)
        {
            case 1:
            {
                calcularComprimento();
                break;
            }
            case 2:
            {
                area();
                break;
            }
            case 3:
            {
                desenhar();
                break;
            }
            case 4:
            {
                break;
            }
        }
    }

    return 0;
}
