//Eduardo Leite Braz - CV3095401

/*
Construa uma função em linguagem C que receba dois parâmetros: um
ponteiro inicio1 (por valor) para uma LLSE de valores inteiros e um
ponteiro inicio2 (por valor) para uma LLSE de valores inteiros. A função
deverá retornar 1 (verdadeiro) caso ambas as LLSE sejam exatamente iguais
ou 0 (falso), caso contrário. Por exatamente iguais entenda-se que as duas
LLSE armazenam a mesma quantidade de nós e todos os nós armazenados
em posições equivalentes de ambas as listas têm o mesmo conteúdo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no
{
    int valor;
    struct no *prox;
};
typedef struct no No;


int verificaSeSaoIguais(No *inicio1, No *inicio2)
{
    int iguais = 1; 
    while (inicio1 != NULL && inicio2 != NULL && iguais == 1)
    {
        if (inicio1->valor != inicio2->valor)
        {
            iguais = 0;
        }
        inicio1 = inicio1->prox;
        inicio2 = inicio2->prox;
    }
    if (inicio1 != NULL || inicio2 != NULL) iguais = 0;
    return iguais;
}

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

int main()
{
    int i;
    No *novo1, *novo2;
    No *inicio1 = NULL;
    No *inicio2 = NULL;
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

   
    if (verificaSeSaoIguais(inicio1, inicio2) == 1)
        printf("As listas sao exatamente iguais.\n");
    else
        printf("As listas sao diferentes.\n");

    return 0;
}