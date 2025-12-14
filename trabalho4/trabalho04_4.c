//Eduardo Leite Braz - CV3095401 - 2° Semestre

/*Implemente uma função que receba como parâmetro uma string e retorne a quantidade
de caracteres maiúsculos, a quantidade de caracteres minúsculos, assim como a
quantidade de dígitos (0 a 9) que ela contém. Esta função deverá estar contida em um
programa que faça a sua invocação e demonstre seu funcionamento.*/

#include <stdio.h>
#include <ctype.h>

void contaCaracteres(char str[], int resultado[3]) {
    resultado[0] = 0; // maiúsculas
    resultado[1] = 0; // minúsculas
    resultado[2] = 0; // dígitos

    for(int i = 0; str[i] != '\0'; i++) {
        if(isupper(str[i])) resultado[0]++;
        else if(islower(str[i])) resultado[1]++;
        else if(isdigit(str[i])) resultado[2]++;
    }
}

int main() {
    char texto[100];
    int resultado[3];

    printf("Digite uma frase: ");
    gets(texto);

    contaCaracteres(texto, resultado);

    printf("Maiusculas: %d\n", resultado[0]);
    printf("Minusculas: %d\n", resultado[1]);
    printf("Digitos: %d\n", resultado[2]);

    return 1;
}