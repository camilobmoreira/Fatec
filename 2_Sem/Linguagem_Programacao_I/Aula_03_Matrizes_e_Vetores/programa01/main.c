#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*Dadas três medidas de comprimento, determinar:
a) se satisfazem a condição de existência de um triangulo (maior lado < soma dos outros dois)
b) se item A for satisfatório, calcular:
    b1) perímetro do triangulo
    b2) área do triangulo
    b3) tipo do triangulo 'a' > actângulo (a² < b² + c²), 'o' > obtusangulo (a² > b² + c²) e 'r' > retangulo (a² = b² + c²)*/

int t[3];

int verificaMaior()
{
    if (t[0] > t[1] && t[0] > t[2])
    {
        return 0;
    }
    if (t[1] > t[2] && t[1] > t[0])
    {
        int temp = t[0];
        t[0] = t[1];
        t[1] = temp;
        return 0;
    }
    if (t[2] > t[0] && t[2] > t[1])
    {
        int temp = t[0];
        t[0] = t[2];
        t[2] = temp;
        return 0;
    }
}

bool triangulo()
{
    if (t[0] < t[1] + t[2]) return true;
    else return false;
}

int perimetroTriangulo ()
{
    return t[0] + t[1] + t[2];
}

int areaTriangulo ()
{
    int p = perimetroTriangulo(t[3]);
    return (sqrt(p * (p - t[0]) * (p - t[1]) * (p - t[2])));
}

char tipoTriangulo ()
{
    int tQuad[3];
    tQuad[0] = pow(t[0], 2);
    tQuad[1] = pow(t[1], 2);
    tQuad[2] = pow(t[2], 2);

    if (tQuad[0] < tQuad[1] + tQuad[2]) return 'a';
    else if (tQuad[0] > tQuad[1] + tQuad[2]) return 'o';
    else if (tQuad[0] == tQuad[1] + tQuad[2]) return 'r';
}

int main()
{

    printf("Informe os lados do triangulo: \n");
    scanf("%d %d %d", &t[0], &t[1], &t[2]);

    verificaMaior();

    if (triangulo())
    {
        int p = perimetroTriangulo();
        printf("O perímetro do triangulo é: %d\n", p);
        int area = areaTriangulo();
        printf("A áera do triangulo é: %d\n", area);
        char tipoTri = tipoTriangulo();
        if (tipoTri == 'a') printf("O triangulo é um actângulo.\n");
        else if (tipoTri == 'o') printf("O triangulo é um obtusangulo.\n");
        else if (tipoTri == 'r') printf("O triangulo é um retangulo.\n");
    }
    else printf("Nao é um triangulo.\n");
    system("pause");
    return 0;
}
