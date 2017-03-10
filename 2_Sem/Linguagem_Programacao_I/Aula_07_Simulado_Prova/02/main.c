#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nome
{
    char letra;
    struct nome *next;
} NOME;

NOME *addItem (NOME *head, char c)
{
    NOME *node = malloc(sizeof (struct nome));
    if (node != NULL)
    {
         node->letra = c;
         node->next = NULL;
         if (head == NULL) head = node;
         else
         {
             NOME *tail = head;
             while (tail->next != NULL) tail = tail->next;
             tail->next = node;
         }
    }
    return head;
}

void imprimir (NOME *head)
{
    NOME *node = head;
    while (node != NULL)
    {
        printf("%c \n", node->letra);
        node = node->next;
    }
}

NOME *deletarItem (NOME *head, char c)
{
    NOME *node = head, *prev = NULL;
    while (node != NULL && node->letra != c)
    {
        prev = node;
        node = node->next;
    }
    if (node == NULL) return;
    if (prev == NULL) head = node->next;
    else prev->next = node->next;
    free(node);
    return head;
}

NOME *acessa(NOME *head, int n)
{
    NOME *pos = head;
    int cont = 0;
    while (pos != NULL && cont != n)
    {
        pos = pos->next;
        cont++;
    }
    return pos;
}

int main()
{
    NOME *head = NULL;
    int op;
    while (op != 0)
    {
        printf("Escolha a opcao desejada: \n");
        printf("1 - Criar lista vazia; \n");
        printf("2 - Inserir na lista os caracteres do seu primeiro nome; \n");
        printf("3 - Imprimir a lista na tela; \n");
        printf("4 - Inserir na lista os caracteres 'B', 'D', 'R', '4'; \n");
        printf("5 - Remover da lista o caracter '4'; \n");
        printf("6 - Acessar uma posicao da lista e imprimir o valor; \n");
        printf("0 - Sair. \n");
        scanf("%d", &op);
        system("cls");
        switch(op)
        {
        case 1:
            {
                printf("Criando lista vazia...\n");
                NOME *head = NULL;
                printf("Lista vazia criada.\n");
                printf("\n");
                break;
            }
        case 2:
            {
                char c = "";
                printf("Insira um caracter de seu primeiro nome: \n");
                c = getche();
                head = addItem(head, c);
                printf("\n\n");
                break;
            }
        case 3:
            {
                imprimir(head);
                printf("\n");
                break;
            }
        case 4:
            {
                char bdr4[4] = {'B', 'D', 'R', '4'};
                int x = 0;
                for (x = 0; x < 4; x++) head = addItem(head, bdr4[x]);
                printf("\n");
                break;
            }
        case 5:
            {
                char c = '4';
                head = deletarItem(head, c);
                break;
            }
        case 6:
            {
                NOME *pos = NULL;
                int n;
                printf("Informe a posicao que deseja acessar da lista: \n");
                fflush(stdin);
                scanf("%d", &n);
                pos = acessa(head, n);
                printf("Na posicao %d contem a letra %c\n", n, pos->letra);
                break;
            }
        case 0: break;
        default:
            {
                printf("Opcao invalida. \n");
                printf("\n");
            }
        }
    }
    return 0;
}
