#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no
{
    int valor;
    struct no *prox;
};
typedef struct no No;

No *devolveNo(int valor)
{
    No *novo = (No *) malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}

void insereNoInicio(No **inicio, No *novo)
{
    novo->prox = *inicio;
    *inicio = novo;
}

void insereNoFim(No **inicio, No *novo)
{
    if (*inicio == NULL)
    {
        *inicio = novo;
    }
    else
    {
        No *atual = *inicio;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void imprimirLista(No *inicio)
{
    No *atual = inicio;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void intercalarListas(No **inicio3, No **inicio1, No **inicio2)
{
    No *ultimo3 = NULL;
    if (*inicio3 != NULL)
    {
        ultimo3 = *inicio3;
        while (ultimo3->prox != NULL)
        {
            ultimo3 = ultimo3->prox;
        }
    }
    while (*inicio1 != NULL && *inicio2 != NULL)
    {
        No *removido = *inicio1;
        *inicio1 = (*inicio1)->prox;
        removido->prox = NULL;
        if (*inicio3 == NULL)
        {
            *inicio3 = removido;
            ultimo3 = removido;
        }
        else
        {
            ultimo3->prox = removido;
            ultimo3 = ultimo3->prox;
        }
        removido = *inicio2;
        *inicio2 = (*inicio2)->prox;
        removido->prox = NULL;
        if (*inicio3 == NULL)
        {
            *inicio3 = removido;
            ultimo3 = removido;
        }
        else
        {
            ultimo3->prox = removido;
            ultimo3 = ultimo3->prox;
        }
    }
    *inicio1 = NULL;
    *inicio2 = NULL;
}

int main(void)
{
    No *inicio1 = NULL;
    No *inicio2 = NULL;
    No *inicio3 = NULL;
    srand((unsigned) time(NULL));
    int i;
    for (i = 0; i < 6; i = i + 1)
    {
        No *n = devolveNo(rand() % 100);
        insereNoFim(&inicio1, n);
    }
    for (i = 0; i < 6; i = i + 1)
    {
        No *n = devolveNo(100 + rand() % 100);
        insereNoFim(&inicio2, n);
    }
    printf("Lista 1 antes: ");
    imprimirLista(inicio1);
    printf("Lista 2 antes: ");
    imprimirLista(inicio2);
    printf("Lista 3 antes: ");
    imprimirLista(inicio3);
    intercalarListas(&inicio3, &inicio1, &inicio2);
    printf("Lista 1 depois: ");
    imprimirLista(inicio1);
    printf("Lista 2 depois: ");
    imprimirLista(inicio2);
    printf("Lista 3 depois: ");
    imprimirLista(inicio3);
    return 0;
}