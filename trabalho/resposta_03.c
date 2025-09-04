//Eduardo Leite Braz - 2° Semestre ADS
//cv3095401

/*
Construa um programa em linguagem C que declare um array de inteiros com 50
posições. A seguir o programa deverá solicitar ao usuário que forneça um número inteiro
e um índice do array para, caso seja possível, inserir este inteiro no respectivo índice do
array. Motivos para impossibilitar a inserção são: o valor do índice é inválido, a posição
indicada pelo índice já está ocupada ou não há mais espaço disponível no array. Repetir o
processo até que o usuário desista. Ao final o array deverá ser impresso na tela. Assuma
que somente números inteiros e positivos poderão ser armazendados.
*/
#include <stdio.h>
#define MAX 10
int main(){

    int arrayPrincipal[MAX];
    int contagem = 0, continuar = 1, indice, valor;

    int verificacao[MAX];
    int i;
    for(i = 0; i < MAX; i++){
        verificacao[i] = 0;
    }
    while(continuar == 1){
        printf("Digite um indice para adicionar um valor (0 ate %i): ", MAX-1);
        scanf("%i", &indice);
        if(indice < 0 || indice > MAX){
            printf("indice invalido\n");
        }
        else if(verificacao[indice] == 1){
            printf("Indice ja ocupado, tente novamente\n");
        }else{
            printf("Digite um valor positivo: ");
            scanf("%i", &valor);
            if(valor > -1){
                arrayPrincipal[indice] = valor;
                verificacao[indice] = 1;
                contagem++;
            }else{
                printf("Valor invalido\n");
            }
        }
        printf("Deseja continuar?\n 1 para sim e 0 para nao\n");
        scanf("%i", &continuar);
        
    }

    for(i = 0; i < MAX; i++){
        if(verificacao[i] == 1){
            printf("Indice %d: %d\n", i, arrayPrincipal[i]);
        }
}
    return (1);
}