/*Construa um programa em linguagem C que declare um arrayzão de 12 posições de inteiros
e peça para o usuário preencher todos os seus valores. A seguir o programa deverá copiar os
dados deste arrayzão em dois outros arrays: “array1” e “array2” que foram declarados com 12
posições cada um. A lógica de armazenamento deverá ser: o array1 recebe os valores positivos
armazenados no arrayzão e o array2 recebe os valores negativos do arrayzão. Ao final o array1
e o array2 deverão ser impressos na tela, assim também como a quantidade de valores que cada
um está armazenando.
*/  
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int main(){
    system("cls");
    int arrayzao[MAX];
    int arrayA[MAX];
    int arrayB[MAX];
    int i;

    for(i=0; i<=MAX-1;i++){
        printf("Digite o valor do indice[%i]: ", i);
        scanf("%i", &arrayzao[i]);
        system("cls");
    }
    for(i=0; i<=MAX-1;i++){
        if(arrayzao[i] >= 0){
            arrayA[i] = arrayzao[i];
        }else{
            arrayB[i] = arrayzao[i];
        }
    }
    for(i=0; i<=MAX-1; i++){
        printf("%i  ", arrayzao[i]);
    }
    printf("\n");

    for(i=0; i<=MAX-1; i++){
        //if(arrayA[i] ){
        //    printf("False");
        //}else{
        //    printf("%i  ", arrayA[i]);
        //}
        printf("%i  ", arrayA[i]);

    }
    printf("\n");

    for(i=0; i<=MAX-1; i++){
        printf("%i  ", arrayB[i]);
    }
    





    return(1);
}