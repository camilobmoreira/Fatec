#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

/**
 *Define os metodos para que eles possam ser chamados no código sem dar errro.
 *Porém, são construidos apenas no final do código
 */
void LeVetor (float *v, int tam);
float  ProcuraMaior (float *v, int tam, int *vezes);

int main(void)
{
    /**
    *Define as variaveis a serem usadas no programa
    */
    float *v, maior;
    int i, tam, vezes;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &tam); /**Lê uma entrada do teclado*/
    v = (float *) malloc(tam * sizeof(float)); /**Aloca/reserva memória na RAM do tamanho de um float*/
    if (v) /**Verifica se V existe(foi alocado em memoria)*/
    {
        LeVetor(v, tam); /**Chama o método LeVetor que é definido no começo do código mas seu código é criado no final*/
        maior = ProcuraMaior (v, tam, &vezes); /**Chama o método ProcuraMaior e salva o seu retorno na variavel 'maior'*/

        /**Printa na tela o valor de 'maior' na tela e quantas vezes ele foi digitado*/
        printf("O maior elemento e %f e aparece %d vezes.\n", maior, vezes);
        free(v); /**Libera a memoria onde V estava salvo*/
    }
    else
    {
        printf("Nao consegui alocar memoria."); /**Exibe uma mensagem por não ter sido possivel alocar memoria para V*/
    }
    getch(); /**Lê algo do teclado*/
}

void LeVetor (float *v, int tam)
{
    int i;
    for (i=0; i<tam; i++) /**Executa o código dentro de chaves X(tam) vezes*/
    {
        printf("Elemento %d ?", i);
        scanf("%f", v+i); /**Salva o valor lido do teclado no espaço de memória v[i]'*/
        printf("Li valor %f \n", *(v+i));
    }
}

float ProcuraMaior (float *v, int tam, int *vezes)
{
    int i;
    float maior;
    maior = v[0]; /**Define um valor inicial para variavel maior*/
    *vezes = 1; /**Define um valor inicial para variavel vezes*/
    for (i=1; i<tam; i++) /**Executa o código dentro de chaves X(tam) vezes*/
    {
        if (v[i] > maior) /**Verifica se v[i] é maior que o numero salvo na variavel maior */
        {
            maior = v[i]; /**Salva o valor de v[i] em maior*/
            *vezes = 1;
        }
        else if (maior == v[i]) *vezes=*vezes+1;; /**Aumenta o valor na variavel vezes em 1*/
    }
    return maior; /**Retorna o valor salvo em maior onde o metodo foi chamado*/
}
