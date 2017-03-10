#include <stdio.h>
#include <stdlib.h>

char nomeNoiva[10][20], nomePaiNoiva[10][20], nomeMaeNoiva[10][20];
char nomeNoivo[10][20], nomePaiNoivo[10][20], nomeMaeNoivo[10][20];
int diaCasamento[10], mesCasamento[10], anoCasamento[10], horaCasamento[10], minutosHoraCasamento[10];
int i = 0;

int cadastrarCasamento()
{
    if (i >= 10)
    {
        printf("Agenda cheia. Nao é possivel registrar mais casamentos.");
        return 0;
    }
    printf("Informe o nome da NOIVA: \n");
    fflush(stdin);
    gets(nomeNoiva[i]);
    printf("Informe o nome do NOIVO: \n");
    gets(nomeNoivo[i]);
    printf("Informe o nome do PAI da NOIVA: \n");
    gets(nomePaiNoiva[i]);
    printf("Informe o nome da MAE da NOIVA: \n");
    gets(nomeMaeNoiva[i]);
    printf("Informe o nome do PAI do NOIVO: \n");
    gets(nomePaiNoivo[i]);
    printf("Informe o nome da MAE do NOIVO: \n");
    gets(nomeMaeNoiva[i]);
    diaCasamento[i] = -1;
    while (diaCasamento[i] < 1 || diaCasamento[i] > 31) //Verifica se o dia digitado é valido
    {
        printf("Informe o DIA do casamento: \n");
        scanf("%d", &diaCasamento[i]);
        if (diaCasamento[i] < 1 || diaCasamento[i] > 31) printf("Dia invalido. Informe dia maior que 0 e menor que 32.\n");
    }
    mesCasamento[i] = -1;
    while (mesCasamento[i] < 1 || mesCasamento[i] > 12) //Verifica se o mes digitado é valido
    {
        printf("Informe o MES do casamento: \n");
        scanf("%d", &mesCasamento[i]);
        if (mesCasamento[i] < 1 || mesCasamento[i] > 12) printf("Mes invalido. Informe mes maior que 0 e menor que 13.\n");
    }
    anoCasamento[i] = -1;
    while (anoCasamento[i] < 2016 || anoCasamento[i] > 2100) //Verifica se o ano digitado é valido
    {
        printf("Informe o ANO do casamento (formato aaaa): \n");
        scanf("%d", &anoCasamento[i]);
        if (anoCasamento[i] < 2016 || anoCasamento[i] > 2100) printf("Ano invalido. Informe ano maior que 2015 e menor que 2100.\n");
    }
    horaCasamento[i] = -1;
    minutosHoraCasamento[i] = -1;
    while (horaCasamento[i] < 0 || horaCasamento[i] > 24 || minutosHoraCasamento[i] < 0 || minutosHoraCasamento[i] > 59) //Verifica se a hora digitada é valida
    {
        printf("Informe a HORA do casamento (formato hh (APENAS NUMEROS): \n");
        scanf("%d", &horaCasamento[i]);
        printf("Informe os MINUTOS da hora do casamento (formato mm (APENAS NUMEROS): \n");
        scanf("%d", &minutosHoraCasamento[i]);
        if (horaCasamento[i] < 0 || horaCasamento[i] > 24 || minutosHoraCasamento[i] < 0 || minutosHoraCasamento[i] > 59) printf("Hora invalida. Informe hora maior que 00 e menor 24. \nE minutos maior que 0 e menor que 60\n");
    }
    printf("Casamento registrado com sucesso!\n");
    if (i < 10) i++;
    return 0;
}

int listarCerimonias(int dia, int mes, int ano)
{
    int x;
    for (x = 0;x < 10;x++)
    {
        if (diaCasamento[x] == NULL)
        {
            printf("Final da lista de casamentos cadastrados. \n.");
            return 0;
        }
        if (diaCasamento[x] == dia && mesCasamento[x] == mes && anoCasamento[x] == ano)
        {
            printf("Nome da NOIVA: %s\n", nomeNoiva[x]);
            printf("Nome do NOIVO: %s\n", nomeNoivo[x]);
            printf("Nome do PAI da NOIVA: %s\n", nomePaiNoiva[x]);
            printf("Nome da MAE da NOIVA: %s\n", nomeMaeNoiva[x]);
            printf("Nome do PAI do NOIVO: %s\n", nomePaiNoivo[x]);
            printf("Nome da MAE do NOIVO: %s\n", nomeMaeNoivo[x]);
            printf("Hora da cerimonia: %d:%d\n", horaCasamento[x], minutosHoraCasamento[x]);
        }
    }
    if (x == 10) printf("Final da lista de casamentos cadastrados. \n."); //Se mostrar essa mensagem sem mostrar nenhum registro, é porque não existe registro válido
    return 0;
}

int verificaHoraCerimonia(char noivo[], char noiva[])
{
    int y;
    for (y = 0;y < 10;y++)
    {
        if (diaCasamento[y] == NULL)
        {
            printf("Final da lista de casamentos cadastrados. \n."); //Se mostrar essa mensagem sem mostrar nenhum registro, é porque não existe registro válido
            return 0;
        }
        if (strcmp(tolower(noiva), tolower(nomeNoiva[y])) == 0 && strcmp(tolower(noivo), tolower(nomeNoivo[y])) == 0)
        {
            printf("Data da cerimonia: %d/%d/%d\n", diaCasamento[y], mesCasamento[y], anoCasamento[y]);
            printf("Hora da cerimonia: %d:%d\n", horaCasamento[y], minutosHoraCasamento[y]);
        }
    }
    if (y == 10) printf("Final da lista de casamentos cadastrados. \n."); //Se mostrar essa mensagem sem mostrar nenhum registro, é porque não existe registro válido
    return 0;
}

int main()
{
    int op = -1, dia, mes, ano;
    char noivo[20], noiva[20];
    while (op != 0)
    {
        printf("Informe a opcao desejada: \n1 - Cadastrar casamento; \n2 - Listar cerimonias por data; \n3 - Verificar hora da cerimonia por nome nos noivos; \n0 - Sair.\n");
        fflush(stdin);
        scanf("%d", &op);
        if (op == 0) break;
        switch (op)
        {
            case 1:
                {
                    cadastrarCasamento();
                    break;
                }
            case 2:
                {
                    printf("Informe os dados da data que deseja pesquisar:\n");
                    dia = -1;
                    while (dia < 0 || dia > 31)
                    {
                        printf("DIA: ");
                        scanf("%d", &dia);
                        if (dia < 0 || dia > 31) printf("Dia invalido. Informe dia maior que 0 e menor que 32.\n ");
                    }
                    mes = -1;
                    while (mes < 0 || mes > 12)
                    {
                        printf("MES: ");
                        scanf("%d", &mes);
                        if (mes < 0 || mes > 12) printf("Mes invalido. Informe mes maior que 0 e menor que 13.\n ");
                    }
                    ano = -1;
                    while (ano < 2016 || ano > 2100)
                    {
                        printf("ANO: ");
                        scanf("%d", &ano);
                        if (ano < 2016 || ano > 2100) printf("Ano invalido. Informe ano maior que 2016 e menor que 2100.\n ");
                    }
                    listarCerimonias(dia, mes, ano);
                    break;
                }
            case 3:
                {
                    printf("Informe o nome do noivo: \n");
                    fflush(stdin);
                    gets(noivo);
                    printf("Informe o nome da noiva: \n");
                    gets(noiva);
                    verificaHoraCerimonia(noivo, noiva);
                    break;
                }
            default:
                {
                    printf("Opcao invalida.\n");
                }
        }
    }
    return 0;
}
