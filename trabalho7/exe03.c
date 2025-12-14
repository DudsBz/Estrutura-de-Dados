/*

Construa uma função em linguagem C que receba dois parâmetros: um
ponteiro inicio (por valor) para uma LLSE de valores inteiros e um
ponteiro novo (por valor), que aponta para um nó que será inserido na
LLSE apontada por inicio. A função deverá inserir o novo nó exatamente
na posição equivalente à metade da quantidade de nós armazenada na
LLSE. Assumir que a LLSE não está vazia e é par a quantidade de nós que
ela armazena

*/

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

int alocaNoMeio(No *inicio, No *novo)
{
    int contador = 0, controle = 1;
    No *atual = inicio;
    if (inicio == NULL || novo == NULL)
    {
        controle = 0;
    }

    /* conta nós */
    while (atual != NULL)
    {
        contador += 1;
        atual = atual->prox;
    }

    
    int posicaoMetade = contador / 2; 
    No *noParaInserir = devolveNo(novo->valor);
    if (noParaInserir == NULL)
    {
        controle = 0;
    }
    
    if (posicaoMetade == 0)
    {
        noParaInserir->prox = inicio->prox; 
        inicio->prox = noParaInserir;
        controle = 0;
    }
    atual = inicio;
    int i = 1;
    while (i < posicaoMetade && atual->prox != NULL)
    {
        atual = atual->prox;
        i = i + 1;
    }
    noParaInserir->prox = atual->prox;
    atual->prox = noParaInserir;

    return controle;
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
    }

    novo2 = devolveNo(999); /* exemplo: valor 999 será inserido na metade */
    alocaNoMeio(inicio1, novo2);
    

    return 1;
}