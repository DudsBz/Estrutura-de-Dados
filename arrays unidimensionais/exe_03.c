/*. Construa um programa em linguagem C que declare um array de 8 posições de inteiros. A
seguir deverá ser solicitado ao usuário que digite um valor que será armazenado na posição de
índice 0 do array. Feito isso o programa deverá preencher as 7 posições restantes seguindo a
regra: a posição seguinte deverá ser preenchida pela multiplicação do valor contido na posição
atual multiplicado pelo índice da posição seguinte. Ao final o array deverá ser exibido na tela.
Exemplo: caso o usuário digitasse o valor 2, o restante do array seria preenchido assim:*/

#include <stdio.h>
#define MAX 8
int main(){

    int i, escolha, array[8];
    printf("Digite um valor para o indice 0: ");
    scanf("%i", &escolha);
    array[0] = escolha;

    for(i=1; i<=MAX-1; i++)
    {
        array[i] = array[i-1]*i;
    }
    for(i=1; i<=MAX-1; i++)
    {
        printf("%i  ", array[i]);
    }


    return(1);
}