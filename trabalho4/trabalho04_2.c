//Eduardo Leite Braz - CV3095401 - 2° Semestre de ADS

/* Implemente uma função que não receba parâmetros e retorne uma struct pessoa lida do
teclado. A struct será composta pelos campos nome (string) e sexo (char). Esta função
deverá estar contida em um programa que faça a sua invocação e demonstre seu
funcionamento*/

#include <stdio.h>

typedef struct{
    char nome[50];
    char sexo;
} Pessoa;

Pessoa sPessoa()
{
    Pessoa p;
    printf("Digite o nome: ");
    gets(p.nome);
    printf("Digite o sexo (M/F): ");
    scanf("%c", &p.sexo);
    return p;
}

int main()
{
    Pessoa pessoa1 = sPessoa();
    printf("\nDados: \nNome: %s\nSexo: %c\n", pessoa1.nome, pessoa1.sexo);
    return 1;
}