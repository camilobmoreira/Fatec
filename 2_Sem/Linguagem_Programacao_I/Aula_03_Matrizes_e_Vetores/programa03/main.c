#include <stdio.h>
#include <stdlib.h>

float calcularImposto (float salario)
{
    if (salario < 500.0) return salario * .05;
    else if (salario >= 500.0 && salario < 850.0) return salario * .1;
    else if (salario >= 850.0) return salario * .15;
}

float calcularNovoSalario (float salario)
{
    if (salario < 450.0) return salario += 100.0;
    else if (salario >= 450.0 && salario < 750.0) return salario += 75.0;
    else if (salario >= 750.0 && salario < 1500.0) return salario += 50.0;
    else if (salario >= 1500.0) return salario += 25.0;
}

void classificarSalario (float salario)
{
    if (salario < 700) printf("Mal remunerado.");
    else if (salario >= 700) printf("Bem remunerado.");
}

int main()
{
    float salario = -1;
    printf("Informe o salário\n");
    while (salario < 0)
    {
        scanf("%f", &salario);
        if (salario < 0) printf("Informe salario maior que zero.");
    }

    int op;
    printf("Informe a opção: \n1 - Imposto; \n2 - Novo Salário; \n3 - Classificação.\n");
    scanf("%d", &op);
    switch(op)
    {
        case(1):
        {
            printf("Imposto: %.2f", calcularImposto(salario));
            break;
        }
        case(2):
        {
            printf("Novo Salário: %.2f", calcularNovoSalario(salario));
            break;
        }
        case(3):
        {
            classificarSalario(salario);
            break;
        }
        default:
        {
            printf("Opção inválida.");
            break;
        }
    }
    system("pause");
    return 0;
}
