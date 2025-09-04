//Eduardo Leite Braz -> CV3095401
/*
Dizemos que uma matriz inteira Anxn é uma matriz de permutação se em cada linha e em
cada coluna houver n-1 elementos nulos e um único elemento igual a 1. Construa um programa em
linguagem C que, dada uma matriz inteira Anxn, verifique se é de permutação.
*/

#include <stdio.h>
#define TAM 4
int main()
{
    int matriz[TAM][TAM];
    int l, c;
    int permutacao = 1;

    for(l = 0; l < TAM; l++){
        for(c = 0; c < TAM; c++){
            printf("Digite o valor da celula [%i][%i]: ", l, c);
            scanf("%i", &matriz[l][c]);
        }
    }
    for(l = 0; l < TAM; l++)
    {
        int somaL = 0;
        for (c = 0; c < TAM; c++)
        {
            if(matriz[l][c] != 0 && matriz[l][c] != 1 ){
                permutacao = 0;
            }
            somaL += matriz[l][c];
        }
        if(somaL != 1)
        {
            permutacao = 0;
        }
    }
    for(c = 0; c < TAM; c++)
    {
        int somaC = 0;
        for (l = 0; l < TAM; l++)
        {
            if(matriz[l][c] != 0 && matriz[l][c] != 1 ){
                permutacao = 0;
            }
            somaC += matriz[l][c];
        }
        if(somaC != 1)
        {
            permutacao = 0;
        }
    }
    if(permutacao){
        printf("E permutaçao");
    }else{
        printf("Nao e permutaçao");
    }
    return(1);
}

    

