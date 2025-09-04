//Eduardo Leite Braz - 2° Semestre ADS
//cv3095401

/*Construa um programa em linguagem C que declare um array de inteiros com 50
posições. A seguir deverá ser solicitado ao usuário que digite valores para preencher cada
uma das posições do array. Feito isso, o programa deverá declarar, preencher e imprimir
um array 2 com 25 posições seguindo a seguinte lógica: cada posição será preenchida com
o resultado da multiplicação de pares consecutivos de valores do array 1 a partir do índice
0. Exemplo: supondo que o array 1 fosse {1, 23, 10, 5, 7, 11}, o array 2 conteria os seguintes
valores: {23, 50, 77}.
*/

#include <stdio.h>
#define TAM 10
#define MIN 5
#define FOR 2
int main(){

    int array1[TAM], array2[MIN], i;
    
    for(i = 0; i < TAM; i++){
        printf("Digite o valor da posicao[%i]", i);
        scanf("%i", &array1[i]);
    }
    for(i =0; i<MIN;i++){
        // vai andar de par em par, pq o *2 pula as duas anteriores e o +1 pega o próximo
        array2[i] = array1[2*i] * array1[2*i+1];
    }
    for(i = 0; i<TAM; i++){
        printf("%i ", array1[i]); 
    }
    printf("\n");
    for(i = 0; i<MIN; i++){
        printf("%i ", array2[i]);
    }
    return(1);
}