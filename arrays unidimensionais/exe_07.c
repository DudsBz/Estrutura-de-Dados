/*Construa um programa em linguagem C que declare um arrayzão de 12 posições de inteiros
e peça para o usuário preencher todos os seus valores. A seguir o programa deverá copiar os
dados deste arrayzão em três outros arrays: array1, array2 e array3 que foram declarados com 4
posições cada um. A lógica de armazenamento deverá ser: o array1 recebe os valores de índice 0
a 3 do arrayzão, o array2 recebe os valores de índice 4 a 7 do arrayzão e o array3 recebe os
valores de índice 8 a 11 do arrayzão. Ao final os arrays array1, array2 e array3 deverão ser
impressos na tela.
*/

#include<stdio.h>
#define TAM 4 
#define MAX 12
int main(){

    int arrayzao[MAX];
    int arrayA[TAM], arrayB[TAM], arrayC[TAM];
    int indice;

    for(indice = 0; indice<=MAX-1; indice++){
        printf("Digite o valor do indice[%i]: ", indice);
        scanf("%i", &arrayzao[indice]);
    }
    printf("\n");

    for(indice = 0; indice<=MAX-1; indice++){
       if(indice <= 3){
            arrayA[indice] = arrayzao[indice];
       }else if(indice > 3 && indice < 8){
            arrayB[indice] = arrayzao[indice];
       }else{
            arrayC[indice] = arrayzao[indice];
       }
    }

    for(indice = 0; indice <= MAX-1; indice++){
        printf("%i  ", arrayzao[indice]);
    }
    printf("\n");

    for(indice = 0; indice <= MAX-1; indice++){
        printf("%i  ", arrayA[indice]);
    }
    printf("\n");
    for(indice = 0; indice <= MAX-1; indice++){
        printf("%i  ", arrayB[indice]);
    }
    printf("\n");
    for(indice = 0; indice <= MAX-1; indice++){
        printf("%i  ", arrayC[indice]);
    }


    return(1);
}