/* Construa um programa em linguagem C que declare um arrayzão de 12 posições de inteiros
e peça para o usuário preencher todos os seus valores. A seguir o programa deverá copiar os
dados deste arrayzão em três outros arrays: arrayA, array2 e array3 que foram declarados com 4
posições cada um. A lógica de armazenamento deverá ser: o arrayA recebe os valores de índice
0, 3, 6 e 9 do arrayzão, o array2 recebe os valores de índice 1, 4, 7 e 10 do arrayzão e o array3
recebe os valores de índice 2, 5, 8 e 11 do arrayzão. Ao final os arrays arrayA, array2 e array3
deverão ser impressos na tela.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 12
#define TAM 4

int main(){

    int arrayzao[MAX];
    int arrayA[TAM];
    int arrayB[TAM];
    int arrayC[TAM];

    int indice;
    int x = 0, y =0, z=0;

    for(indice = 0; indice <= MAX-1; indice++){
        printf("Digite o valor para o indice[%indice]: ", indice);
        scanf("%indice", &arrayzao[indice]);
        system("cls");
    }

   
    for(indice = 0; indice <= MAX-1; indice++){
        if(indice == 0 || indice == 3 ||indice == 6 ||indice == 9 ){
            arrayA[x] = arrayzao[indice];
            x++;
        }else if(indice == 1 || indice == 4 ||indice == 7 ||indice == 10){
            arrayB[y] = arrayzao[indice];
            y++;
        }else{
            arrayC[z] = arrayzao[indice];
            z++;
        }
    }
    for(indice = 0; indice<=TAM-1; indice++){
        printf("%i  ", arrayA[indice]);
    }
    printf("\n");
    for(indice = 0; indice<=TAM-1; indice++){
        printf("%i  ", arrayB[indice]);
    }
    printf("\n");
    for(indice = 0; indice<=TAM-1; indice++){
        printf("%i  ", arrayC[indice]);
    }



    return(1);
}