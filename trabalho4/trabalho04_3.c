//Eduardo Leite Braz - CV3095401 - 2° Semestre ADS

/*. Implemente uma função que receba como parâmetros duas variáveis do tipo struct
pessoa e retorne verdadeiro caso elas sejam idênticas ou falso, caso contrário. A struct será
composta pelos campos nome (string) e sexo (char). Esta função deverá estar contida em
um programa que faça a sua invocação e demonstre seu funcionamento.*/

#include <stdio.h>
#include<string.h>
#include <stdbool.h>
typedef struct{
    char nome[50];
    char sexo;
} Pessoa;

bool verificacao(Pessoa p1, Pessoa p2)
{
    bool verifica = false;
    if(strcmp(p1.nome, p2.nome) == 0 && p1.sexo == p2.sexo){
        verifica = true;
    }
    return verifica;
}

int main()
{
    Pessoa p;
    printf("Digite o nome da Pessoa1: ");
    gets(p.nome);   
    printf("Digite o sexo (M/F): ");
    scanf("%c", &p.sexo);
    fflush(stdin);
    Pessoa pp;
    printf("Digite o nome da Pessoa2: ");
    gets(pp.nome);
    printf("Digite o sexo (M/F): ");
    scanf("%c", &pp.sexo);

    if(verificacao(p, pp))
    {
        printf("\n\tAs pessoas sao identicas\n\n");
    }else
    {
        printf("\n\tNao sao iguais\n\n");
    }

    return 1;
}