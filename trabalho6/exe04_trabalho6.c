//Eduardo Leite Braz - CV3095401

/*
Construa um programa em linguagem C que implemente e invoque a função
float devolveMedia(float *array, int tamanho), a qual deverá
receber como parâmetros um array de float e uma variável int tamanho
informando o tamanho do array de float. A função deverá retornar a média
aritmética de todos os valores armazenados no array.
*/

#include <stdio.h>

#define MAX 30


float devolveMedia(float *arrayFloat, int *ponteiro)
{
    if (ponteiro <= 0) {
        return 0.0f; // evita divisão por zero
    }
    float somaDosIndicesDoArray = 0.0f;
    for(int indice = 0; indice < ponteiro; indice++)
    {
        somaDosIndicesDoArray += arrayFloat[indice];
    }
    float mediaAritmetica = somaDosIndicesDoArray / *ponteiro;
    return mediaAritmetica;
}

int main()
{
    float arrayFloat[MAX];
    int escolhaContinuar = 1;
    int tamanhoDoArrayFloat = 0;
   
    do
    {
        if(tamanhoDoArrayFloat == MAX)
        {
            printf("Você chegou ao limite do arrayInt");
            arrayFloat[tamanhoDoArrayFloat] = -1;
        }else
        {
            printf("Digite o valor para a posicao [%i]: \n", tamanhoDoArrayFloat);
            scanf("%f", &arrayFloat[tamanhoDoArrayFloat]);
            tamanhoDoArrayFloat++;
        }
        fflush(stdin);
        printf("Deseja continuar? [1-Sim / 0 - Nao]");
        scanf("%i", &escolhaContinuar);
    }while(escolhaContinuar);
        
        
   
    int *ponteiro;
    ponteiro = &tamanhoDoArrayFloat;
    
    float resultado = devolveMedia(arrayFloat, ponteiro);
    printf("%.2f", &resultado);
    return 1;
}