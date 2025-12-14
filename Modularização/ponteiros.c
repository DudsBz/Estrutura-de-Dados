#include <stdio.h>

int main()
{
    int variavel = 10;

    printf("\nValor da variavel %i", variavel);
    printf("\nEndereco da variavel %p", &variavel);

    int *papelzinho = &variavel;

    printf("\nO que vale papelzinho: %p", papelzinho);
    printf("\nChegando na casa atraves do papelzinho: %i", *papelzinho);

    *papelzinho = *papelzinho + 1;
}