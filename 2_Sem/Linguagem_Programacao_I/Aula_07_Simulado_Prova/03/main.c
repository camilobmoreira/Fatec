#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *next;
} LISTA;

LISTA *addItem(LISTA *head, int n)
{
    LISTA *node = malloc(sizeof(struct lista));
    if (node != NULL)
    {
        node->num = n;
        node->next = NULL;
        if (head == NULL) head = node;
        else
        {
            LISTA *tail = head;
            while (tail->next != NULL) tail = tail->next;
            tail->next = node;
        }
    }
    return head;
}

void imprimirLista(LISTA *head)
{
    LISTA *node = head;
    printf("Imprimindo lista atualizada... \n");
    while (node != NULL)
    {
        printf("%d ", node->num);
        node = node->next;
    }
}

int main()
{
    int n = 0;
    LISTA *head = NULL;
    printf("Informe um numero: \n");
    while (n != 999)
    {
        fflush(stdin);
        scanf("%d", &n);
        if (n == 999) break;
        head = addItem(head, n);
    }
    system("cls");
    imprimirLista(head);
    return 0;
}
