//Eduardo Leite Braz - CV3095401

#include <stdio.h>
#define L 4
#define C 4

int main()
{
    int matriz[L][C];
    int l, c;
    int linhas_nulas = 0, colunas_nulas = 0;
    int nula = 1;

    
    for(l = 0; l < L; l++){
        for(c = 0; c < C; c++){
            printf("Digite o valor da celula [%i][%i]: ", l, c);
            scanf("%i", &matriz[l][c]);
        }
    }

    
    for(l = 0; l < L; l++){
        for(c = 0; c < C && nula == 1; c++){
            if(matriz[l][c] != 0){
                nula = 0;
            }
        }
        if(nula){
            linhas_nulas++;
        }
    }

    
    for(c = 0; c < C; c++){
        for(l = 0; l < L && nula == 1; l++){
            if(matriz[l][c] != 0){
                nula = 0;
            }
        }
        if(nula){
            colunas_nulas++;
        }
    }

    printf("Numero de linhas nulas: %i\n", linhas_nulas);
    printf("Numero de colunas nulas: %i\n", colunas_nulas);
    return(1);
}