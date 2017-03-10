#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int exerc_1 ()
{
    int n;
    printf("Informe um número: \n");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int exerc_2()
{
    int x = -1, z = -1;
    while (x < 0 || z < 0)
    {
        printf("Informe um núermo: ");
        scanf("%d", &x);
        if (x < 0)
        {
            printf("O numero precisa ser maior que zero");
            continue;
        }
        printf("Informe uma potencia: ");
        scanf("%d", &z);
        if (z < 0)
        {
            printf("A potencia precisa ser maior que zero");
            continue;
        }
        return pow(x, z);
    }


}

bool verificaPrimo(int n)
{
    int x;
    if (n < 2) return false;
    for (x = 2; x <= n;x++)
    {
        if (x != n && n % x == 0) return false;
    }
    return true;
}

int exerc_3()
{
    int n = -1, contPrimos = 0, somaPrimos = 0, cont = 2;

    while (n < 0)
    {
        printf("Informe quantos números primos deseja somar: \n");
        scanf("%d", &n);
        if (n < 0) printf("Informe um número maior que zero");
    }

    for (cont = 2; contPrimos < n; cont++)
    {
        if (verificaPrimo(cont))
        {
            if (contPrimos == n -1)  printf("%d = ", cont);
            else printf("%d + ", cont);
            somaPrimos += cont;
            contPrimos++;
        }
    }

    return somaPrimos;
}

bool verificaDivisao(int divisor, int dividendo)
{
    if (divisor % dividendo == 0) return true;
    else return false;
}

int exerc_4()
{
    int n = -1, contDivisores = 0, cont = 2;

    while (n < 0)
    {
        printf("Informe um numero: \n");
        scanf("%d", &n);
        if (n < 0) printf("Informe um número maior que zero");
    }

    int x;
    for(x = 1; x <= n; x++)
    {
        if (verificaDivisao(n, x)) contDivisores++;
    }
    printf("%d possui %d divisores", n, contDivisores);
}

int calculaFatorial(int n)
{
    if (n <= 1) return n;
    else return (n * calculaFatorial(n - 1));
}

int exerc_5()
{
    int n = 0;
    printf("Informe um numero: \n");
    while (n <= 0)
    {
        scanf("%d", &n);
        if (n <= 0) printf("Informe um número maior que zero: \n");
    }
    return (calculaFatorial(n));
}

int exerc_6()
{
    int n;
    printf("Informe um numero: \n");
    scanf("%d", &n);
    if (verificaPrimo(n)) printf("Primo");
    else printf("Não é primo");
}

int calculaPermutacao(int p)
{
    calculaFatorial(p);
}

int calculaCombinacao(int n, int p)
{
    return calculaFatorial(n) / (calculaFatorial(p) * calculaFatorial(n - p));
}

int calculaArranjo(int n, int p)
{
    return calculaFatorial(n) / calculaFatorial(n - p);
}

int exerc_7()
{
    int op = 0;
    while (op < 1 || op > 3)
    {
        printf("Escolha a opção que deseja calcular: \n1 - Permutação \n2 - Combinação \n3 - Arranjo \n");
        scanf("%d", &op);
    }

    int n = 0, p = 0;
    switch(op)
        {
            case 1:
            {
                printf("Informe P: \n");
                scanf("%d", &p);
                calculaPermutacao(p);
                break;
            }
            case 2:
            {
                printf("Informe N: \n");
                scanf("%d", &n);
                printf("Informe P: \n");
                scanf("%d", &p);
                calculaCombinacao(n, p);
                break;
            }
            case 3:
            {
                printf("Informe N: \n");
                scanf("%d", &n);
                printf("Informe P: \n");
                scanf("%d", &p);
                calculaArranjo(n, p);
                break;
            }
        }
}

int exerc_8()
{
    int c = 0, h = 0;

    printf("Informe a altura do retangulo: \n");
    scanf("%d", &h);

    printf("Informe o comprimento do retangulo: \n");
    scanf("%d", &c);

    printf("A área do retangulo é %d \n", h * c);
    printf("O perimetro do retangulo é %d \n", 2 * (h + c));
}

int exerc_9()
{
    int r;
    double pi = 3.14;
    printf("Informe o raio do circulo: \n");
    scanf("%d", &r);

    printf("A área do circulo é %.2f \n", (pi * (r * r)));
    printf("O perimetro do circulo é %.2f \n", (2 * pi * r));
}

int exerc_10()
{
    int a, b, c, p, area;

    printf("Jow, informe o lado A do triangulo: \n");
    scanf("%d", &a);
    printf("Brodi, informe o lado B do triangulo: \n");
    scanf("%d", &b);
    printf("Parça, informe o lado C do triangulo: \n");
    scanf("%d", &c);

    if (a + b > c && b + c > a && a + c > b)
    {
        p = (a + b + c)/2;
        area = sqrt(p * (p - a) * (p - b) * (p - c));

        printf("A área do triangulo é %d \n", area);
        printf("O perimetro do triangulo é %d \n", a + b +c);
    }
}

int main()
{
    int op = -1;

    while (op < 1 || op > 10)
    {
        printf("Escolha o número do exercício (1 - 10) \n");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                printf("%d", exerc_1());
                break;

            case 2:
                printf("%d", exerc_2());
                break;

            case 3:
                printf("%d",exerc_3());
                break;

            case 4:
                printf("%d",exerc_4());
                break;

            case 5:
                printf("%d",exerc_5());
                break;

            case 6:
                printf("%d",exerc_6());
                break;

            case 7:
                printf("%d",exerc_7());
                break;

            case 8:
                printf("%d",exerc_8());
                break;

            case 9:
                printf("%d",exerc_9());
                break;

            case 10:
                printf("%d",exerc_10());
                break;

            default:
                printf("Opção inválida! \n");

        }
    }
    return 0;
}
