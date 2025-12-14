//Eduardo Leite Braz - CV 3095401

#include <stdio.h>
#include <string.h>
#define TAM 120 

int main()
{
    char nomesMisturados[TAM][50]; 
    char paises[TAM][20];          
    char nomesOrganizados[TAM][50]; 
    char paisesOrganizados[TAM][20]; 
    int i, j, k = 0;

    // cadastro dos competidores e seus países
    for(i = 0; i < TAM; i++) {
        printf("Digite o nome do competidor %d: ", i+1);
        gets(nomesMisturados[i]); 
        nomesMisturados[i][strcspn(nomesMisturados[i], "\n")] = 0; // Remove o \n
        printf("Digite o país do competidor %d (Brasil, Cuba, India, Mali ou Togo): ", i+1);
        gets(paises[i]); 
        paises[i][strcspn(paises[i], "\n")] = 0; 
    }

    // agrupando os nomes por país na ordem pedida para fazer o strcmp e controlar os nomes em nomesOrganizados e paisesOrganizados com paises por ordem
    char ordemPaises[5] = {"Brasil", "Cuba", "India", "Mali", "Togo"};
    for(j = 0; j < 5; j++) { 
        for(i = 0; i < TAM; i++) { // para cada competidor
            if(strcmp(paises[i], ordemPaises[j]) == 0) { // se o país bate
                strcpy(nomesOrganizados[k], nomesMisturados[i]); 
                strcpy(paisesOrganizados[k], paises[i]);         
                k++;
            }
        }
    }

    printf("\nLista de competidores organizados por país:\n");
    for(i = 0; i < TAM; i++) {
        printf("%s - %s\n", nomesOrganizados[i], paisesOrganizados[i]);
    }

    return 0;
}