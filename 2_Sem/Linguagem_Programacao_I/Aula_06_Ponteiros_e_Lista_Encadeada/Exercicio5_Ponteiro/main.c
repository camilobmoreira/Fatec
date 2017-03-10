#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct voos
{
    int numeroVoo;
    char ciaAerea[20];
    char modeloAeronave[20];
    char origem[20];
    char destino[20];
    int qtdeTotalAssentos;
    int qtdeAssentosOcupados;
    struct voos *proximo;
} cadastroVoo;

cadastroVoo *addVoo (cadastroVoo *lista)
{
    cadastroVoo *novo = malloc(sizeof (struct voos));
    char temp[20];
    if (novo != NULL)
    {
        printf("Informe o numero do voo: \n");
        fflush(stdin);
        scanf("%d", &novo->numeroVoo);

        printf("Informe a cia aerea: \n");
        fflush(stdin);
        fgets(temp, 20, stdin);
        strcpy(novo->ciaAerea, temp);

        printf("Informe o modelo da aeronave: \n");
        fflush(stdin);
        fgets(temp, 20, stdin);
        strcpy(novo->modeloAeronave, temp);

        printf("Informe a origem do voo: \n");
        fflush(stdin);
        fgets(temp, 20, stdin);
        strcpy(novo->origem, temp);

        printf("Informe o destino do voo: \n");
        fflush(stdin);
        fgets(temp, 20, stdin);
        strcpy(novo->destino, temp);

        printf("Informe o numero total de assentos: \n");
        fflush(stdin);
        scanf("%d", &novo->qtdeTotalAssentos);

        novo->qtdeAssentosOcupados = 0;

        novo->proximo = NULL;
        if(lista == NULL)
        {
            lista = novo;
        }
        else
        {
            cadastroVoo *ultimo = lista;
            while(ultimo->proximo != NULL)
            {
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = novo;
        }
    }
    return lista;
}

void listarVoos(cadastroVoo *lista)
{
    cadastroVoo *local = lista;
    printf("Imprimindo lista atualizada: \n\n\n");
    while (local != NULL)
    {
        printf("Numero voo: %d\n", local->numeroVoo);
        printf("Cia Aerea: %s\n", local->ciaAerea);
        printf("Modelo aeronave: %s\n", local->modeloAeronave);
        printf("Origem: %s\n", local->origem);
        printf("Destino: %s\n", local->destino);
        printf("Quantidade total de assentos: %d\n", local->qtdeTotalAssentos);
        printf("Quantidade de assentos ocupados: %d\n", local->qtdeAssentosOcupados);
        printf("\n");
        local = local->proximo;
    }
}

cadastroVoo *reservarAssento(cadastroVoo *lista, int numVoo, int assentos)
{
    cadastroVoo *temp = lista;
    while (temp != NULL)
    {
        if (temp->numeroVoo == numVoo)
        {
            if ((temp->qtdeAssentosOcupados + assentos) < temp->qtdeTotalAssentos)
            {
                temp->qtdeAssentosOcupados += assentos;
                printf("Assento(s) reservado(s).\n");
            }
            else printf("Nao e possivel reservar este numero de assentos");
        }
        temp = temp->proximo;
    }
    return lista;
}

void cancelarPassagem(cadastroVoo *lista, int numVoo, int assentos)
{
    cadastroVoo *temp = lista;
    while (temp != NULL)
    {
        if (temp->numeroVoo == numVoo)
        {
            if ((temp->qtdeAssentosOcupados + assentos) > 0)
            {
                temp->qtdeAssentosOcupados -= assentos;
                printf("Passagen(s) cancelada(s).\n");
            }
            else printf("Nao e possivel cancelar este numero de passagens");
        }
        temp = temp->proximo;
    }
    return lista;
}

cadastroVoo *cancelarVoo(cadastroVoo *lista, int numVoo)
{
    cadastroVoo *atual = lista, *anterior = NULL;
    while(atual != NULL && atual->numeroVoo != numVoo) {
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual == NULL) {
        return;
    }
    if(anterior == NULL) {
        lista = atual->proximo;
        printf("Voo cancelado. \n");
    }
    else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    return lista;
}

int main()
{
    cadastroVoo *lista = NULL;

    char op;
    while(op != 'f')
    {
        printf("Escolha a opcao:\n");
        printf("a - Incluir voos:\n");
        printf("b - Listar voos:\n");
        printf("c - Reservar assento em um voo:\n");
        printf("d - Cancelar voo:\n");
        printf("e - Cancelar passagem:\n");
        printf("f - Sair:\n");
        op = getche();
        printf("\n");
        switch(op)
        {
        case 'a':
            {
                printf("Incluir voo. \n");
                lista = addVoo(lista); //cadastro->proximo =
                printf("Voo incluso.\n");
                break;
            }
        case 'b':
            {
                listarVoos(lista);
                break;
            }
        case 'c':
            {
                int numVoo = 0, assentos = 0;
                printf("Reservar assento em um voo. \n");
                printf("Informe o numero do voo: \n");
                fflush(stdin);
                scanf("%d", &numVoo);
                printf("Informe a quantidade de assentos que deseja reservar: \n");
                fflush(stdin);
                scanf("%d", &assentos);
                lista = reservarAssento(lista, numVoo, assentos);
                break;
            }
        case 'd':
            {
                int numVoo = 0;
                printf("Informe o numero do voo que deseja cancelar: \n");
                fflush(stdin);
                scanf("%d", &numVoo);
                lista = cancelarVoo(lista, numVoo);
                break;
            }
        case 'e':
            {
                int numVoo = 0, passagem = 0;
                printf("Cancelar passagem. \n");
                printf("Informe o numero do voo: \n");
                scanf("%d", &numVoo);
                printf("Informe quantas passagens deseja cancelar: \n");
                scanf("%d", &passagem);
                cancelarPassagem(lista, numVoo, passagem);
                break;
            }
        case 'f': break;
        default:
            {
                printf("Opcao invalida.");
                break;
            }
        }
    }
    system("pause");
    return 0;
}
