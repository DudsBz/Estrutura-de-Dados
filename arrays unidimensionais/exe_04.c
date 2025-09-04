/*Construa um programa em linguagem C que declare um array de 8 posições de inteiros. A
seguir deverá ser solicitado ao usuário que digite dois valores que serão armazenados nas
posições de índice 0 e 1 do array. Feito isso o programa deverá preencher as 6 posições restantes
seguindo a regra: a posição seguinte deverá ser preenchida pela soma do conteúdo das duas
posições imediatamente anteriores. Ao final o array deverá ser exibido na tela. Exemplo: caso o
usuário digitasse os valores 10 e 20, o restante do array seria preenchido assim*/

#include <stdio.h>
#define MAX 8

int main(){
    int i, indice0, indice1, array[8];
    printf("Digite um valor para o indice 0: \n");
    scanf("%i", &indice0);
    array[0] = indice0;
    printf("Digite um valor para o indice 1: ");
    scanf("%i", &indice1);
    array[1] = indice1;

    for(i = 2; i <= MAX-1; i++)
    {
        array[i] = array[i-2] + array[i-1];
    }
    for(i=0; i<=MAX-1;i++){
        printf("%i  ", array[i]);
    }

    return(1);
}