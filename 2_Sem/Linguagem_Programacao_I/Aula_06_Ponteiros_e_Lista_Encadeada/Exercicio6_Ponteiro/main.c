#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct rotlista {
        char item;
        struct rotlista *prox;
        }* lista;

void inserir(lista *p, char x)
{
  lista n=malloc(sizeof(struct rotlista));
  if(n!=NULL)
  {
      n->item=x;
      n->prox=*p;
      *p=n;
  }
}

 void remover(lista *p)
{
 lista n=*p;
 if(n==NULL)return;
 *p=n->prox;
  free(n);

}

void imprime(lista p)
{
     while(p!=NULL)
     {
     printf("\t dado: %c\t endereco: %x\n", p->item, p->prox);
     p=p->prox;
     }
}


void inverte(lista p)
{
    lista listaOrd = NULL;
    while (p != NULL)
    {
        inserir(&listaOrd, p->item);
        p = p->prox;
    }
    imprime(listaOrd);
}


int contaEspacos(lista p)
{
    int cont = 0;
     while(p != NULL)
     {
        p=p->prox;
        cont++;
     }
     return cont;
}

lista acessa(lista p, int i)
{
      while( i>0 && p!=NULL)
      {
              p=p->prox;
              i--;
      }
    return p;
}

int main()
{
 lista lex=NULL;
 lista aux=NULL;
 char letra;
 int op,pos;
 do {


         printf("\n1-inserir\n2-remover\n3-listar\n4-sair\n5-inserir depois da posicao i\n6-limpar tela\n7-inverte lista\n8-conta espacos\n");
         scanf("%d",&op);
         switch(op)
         {
              case 1: printf("\nDigite letra\n");
                      letra=getche();
                      inserir(&lex,letra);
                     break;
              case 2:remover(&lex);
                     break;
              case 3: imprime(lex);
                     break;
              case 4: printf("\nSaindo...");
                    break;
              case 5:printf("\nInsira posicao desejada\n");
                     scanf("%d",&pos);
                     aux=acessa(lex,pos);
                     printf("\nDigite letra\n");
                     letra=getche();
                     inserir(&aux->prox,letra);
                     break;
              case 6:system("cls");
                    break;
              case 7:inverte(lex);
                    break;
              case 8:printf("Espacos: %d", contaEspacos(lex));
                    break;
              default: printf("\nerro\n");
         }
     } while (op!=4);
 system("pause");
 return 0;
}



