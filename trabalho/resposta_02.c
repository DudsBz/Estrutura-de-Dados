//Eduardo Leite Braz - 2° Semestre de ADS
//cv3095401

/* Construa um programa em linguagem C que declare um array de inteiros com 20
posições. A seguir o programa deverá solicitar que o usuário forneça valores inteiros que
serão armazenados no array. Feito isso o programa deverá informar se os dados
armazenados estão dispostos em ordem crescente ou decrescente no array*/

#include <stdio.h>
#define MAX 20
int main(){
    int array[MAX], i;
    int decrescente = 1, crescente = 1, igual = 1;
    for(i = 0; i<MAX; i++){
        printf("Digite o valor da posicao[%i]", i);
        scanf("%i", &array[i]); 
    }
    


    for(i = 0; i<MAX-1; i++){
        if(array[i]<array[i+1]){
            decrescente = 0;
        }
        if(array[i] > array[i+1]){
            crescente = 0;
        }
        if(array[i] == array[i+1]){
            igual = 0;
        }
        
    }
    if(crescente == 0){
        printf("E decrescente");
    }
    else if(decrescente == 0){
        printf("E crescente");
    }
    else if(igual == 0){
        printf("Os valores sao iguais");
    }else{
        printf("Nao e crescente, nem decrescente e os valores tambem nao sao iguais");
    }
    

    return(1);
}