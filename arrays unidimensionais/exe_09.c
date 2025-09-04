/*Construa um programa em linguagem C que execute as seguintes tarefas:
a) declare três arrays com 5 posições cada um. Os arrays deverão ser denominados “filhos” (do
tipo int), “salarioBruto” (tipo float) e “salarioLiquido” (também do tipo float).
b) cada posição do array “filhos” deverá ser preenchida com dados lidos do teclado;
c) cada posição do array “salarioBruto” deverá ser preenchida com dados lidos do teclado;
d) o programa deverá preencher cada posição do array “salarioLiquido” assim: caso a
quantidade correspondente de filhos seja 0, o salarioLiquido é igual ao valor da posição
correspondente do array salarioBruto. Se for maior que 0, o salarioLiquido é igual ao valor
da posição correspondente do array salarioBruto acrescido de 20%.
e) ao final os três arrays deverão ser impressos na tela.
*/

#define TAM 2
#include <stdio.h>
int main(){

    int filhos[TAM];
    float salarioBruto[TAM], salarioLiquido[TAM];
    int indice;
    for(indice = 0; indice<=TAM-1; indice++){
        printf("Digite a quantidade de filhos da pessoa[%i]", indice);
        scanf("%i", &filhos[indice]);
        printf("\n");
        printf("Digite o salario bruto da pessoa[%i]", indice);
        scanf("%f", &salarioBruto[indice]);
    }

        
    
    for(indice = 0; indice<=TAM-1; indice++){
        //imc = peso / (altura * altura)
            salarioLiquido[indice] = salarioBruto[indice] + /*20% para cada filho*/ (filhos[indice] * (salarioBruto[indice]*0.2));
    }
    for(indice = 0; indice<=TAM-1; indice++){
        printf("\nIndice %i:\Salário Bruto: %.2f \t Filhos: %i "
            " \t Salário Liquido: %.2f "
            , indice, salarioBruto[indice], filhos[indice], salarioLiquido[indice]);
    }

    
    return(1);
}