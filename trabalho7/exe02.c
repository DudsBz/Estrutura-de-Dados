/*

Construa uma função em linguagem C que receba três parâmetros: um
ponteiro inicio1 (por referência) para uma LLSE de valores inteiros, um
ponteiro inicio2 (por referência) para uma LLSE de valores inteiros e um
ponteiro inicio3 (por referência) que aponta para uma LLSE vazia. A
função deverá mover todos os nós das LLSE apontadas por inicio1 e
inicio2 (nessa ordem) para a LLSE apontada por inicio3. Ao término da
execução da função, tanto inicio1 quanto inicio2 deverão apontar para
NULL.

*/
#include <stdio.h>
#include <string.h>

struct no
{
    int valor;
    struct no *prox;
};
typedef struct no No;

void insereNoInicio(No **inicio, No *novo)
{
    novo->prox = *inicio;
    *inicio = novo;
}

No *devolveNo(int valor)
{
    No *novo;
    novo = (No *) malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = valor;
        novo->prox = NULL;
    }
    else
    {
        puts("\nErro");
    }
    return novo;
}

void LLSEtres(No **inicio3, No **inicio1, No **inicio2)
{
    No *controle = NULL;

    while (*inicio1 != NULL)
    {
        controle = *inicio1;
        *inicio1 = (*inicio1)->prox;
        insereNoInicio(inicio3, controle);
    }
    while (*inicio2 != NULL)
    {
        controle = *inicio2;
        *inicio2 = (*inicio2)->prox;
        insereNoInicio(inicio3, controle);
    }
}

int main()
{
    int i;
    No *novo1, *novo2;
    No *inicio1 = NULL;
    No *inicio2 = NULL;
    No *inicio3 = NULL;
    int valores[10];

    srand((unsigned) time(NULL));

    
    for (i = 0; i < 10; i++)
    {
        valores[i] = rand() % 100;
    }
    for (i = 0; i < 10; i++)
    {
        novo1 = devolveNo(valores[i]);
        insereNoInicio(&inicio1, novo1);
        novo2 = devolveNo(valores[i]);
        insereNoInicio(&inicio2, novo2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    }

    LLSEtres(&inicio3, &inicio1, &inicio2);



    return 1;
}