/*Construa um programa em linguagem C que declare um array de 10 posições de inteiros. A
seguir deverá ser solicitado ao usuário que digite um valor positivo que será armazenado na
posição de índice 0 do array. Feito isso o programa deverá preencher as 9 posições restantes
seguindo a regra: as posições de índice impar armazenam o negativo do valor digitado e as
posições de índice par armazenam o próprio valor. Ao final o array deverá ser exibido na tela.
Exemplo: caso o usuário digitasse o valor 10, o restante do array seria preenchido assim: */

#include <stdio.h>
#define MAX 10

int main(){
    int array[MAX];
    int i, inteiro;
    printf("Digite um valor positivo para colocar no índice 0 do array: ");
    scanf("%i", &inteiro);
    array[0] = inteiro;

    
    for(i = 1; i < MAX-1; i++){
        if(i % 2 == 0){
            array[i] = inteiro;
        }else{
            array[i] = inteiro*-1;
        }
    }
    for(i = 0; i < MAX -1; i++){
        printf("%i  ", array[i]);
    }
    
    return(1);
}