/*
Construa um programa em linguagem C que implemente e invoque a função
int devolveMaior(int *array, int tamanho), a qual deverá receber
como parâmetros um array de inteiros e uma variável int tamanho informando
o tamanho do array de inteiros (quantidade de inteiros armazenado no array). A
função deverá retornar o inteiro de maior tamanho armazenado no array.
*/

#include <stdio.h>
#define MAX 20

int devolveMaior(int *arrayInt, int tamanhoDoArrayInt)
{
    int intMaior = 0;

    for(int i = 0; i <= tamanhoDoArrayInt; i++)
    {
        if(arrayInt[i++] == -1)
        {
            printf("Acabou o array");
        }
        else if(arrayInt[i++] > arrayInt[i])
        {
            intMaior = arrayInt[i++];
        }
        else
        {
            intMaior = arrayInt[i];
        }
    }



    return intMaior;
}

int main()
{
    int arrayInt[MAX];
    int escolhaContinuar = 1;
    int tamanhoDoArrayInt = 0;
    for (int i = 0; i <= MAX && escolhaContinuar == 1; i++)
    {
        do
        {
            if(i == MAX)
            {
                printf("Você chegou ao limite do arrayInt");
                arrayInt[i] = -1;
            }else
            {
                printf("Digite o valor para a posicao [%i]: \n", i);
                scanf("%i", &arrayInt[i]);
                tamanhoDoArrayInt++;
            }
            fflush(stdin);
            printf("Deseja continuar? [1-Sim / 0 - Nao]");
            scanf("%i", &escolhaContinuar);

        }while(escolhaContinuar);
        
        
    }
    
    
    devolveMaior(arrayInt, tamanhoDoArrayInt);

    return 1;
}