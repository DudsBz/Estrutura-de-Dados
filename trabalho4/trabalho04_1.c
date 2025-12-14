///Eduardo Leite Braz - CV3095401 - 2° Semestre de ADS


/*. Implemente uma função que receba como parâmetros um valor inteiro e um valor float
e retorne o resultado da divisão do primeiro valor pelo segundo, caso possível. Do
contrário ela deverá retornar o valor -1. Esta função deverá estar contida em um programa
que faça a sua invocação e demonstre seu funcionamento.*/
#include <stdio.h>
float divisao(int valor1, float valor2){
    float resultado = -1;

    if(valor2 != 0)
    {
        resultado = (float) valor1 / valor2;
    }

    return resultado;
}
int main(){
    int valorP;
    float valorS;
    printf("Digite um valor inteiro: ");
    scanf("%i", &valorP);
    printf("Digite um valor quebrado: ");
    scanf("%f", &valorS);
    float resul = divisao(valorP, valorS);
    printf("O valor da divisão é: %.2f", resul); 
    return 1;
}