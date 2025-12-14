/*
Construa um programa em linguagem C que implemente e invoque a função
strmrg(char *s1, char *s2, char *s3), a qual tem a função de
intercalar (merge) os caracteres da string s1 com os caracteres da string s2,
armazenando o resultado na string s3. Exemplo: caso s1 contenha “ACEG” e s2
contenha “BDFH”, a string s3 deverá conter “ABCDEFGH”. Se as strings tiverem
tamanhos diferentes, os caracteres restantes da string de maior tamanho
deverão ser inseridos no final de s3.
*/


#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

void strmrg(char *s1, char *s2, char *s3)
{
    int i = 0, j = 0, k = 0;

    while (s1[i] != '\0' && s2[j] != '\0') {
        s3[k++] = s1[i++];
        s3[k++] = s2[j++];
    }
    while (s1[i] != '\0') {
        s3[k++] = s1[i++];
    }
    while (s2[j] != '\0') {
        s3[k++] = s2[j++];
    }

    s3[k] = '\0';
}

int main()
{
    char s1[MAX] = "ACEG";
    char s2[MAX] = "BDFH";
    char s3[2 * MAX];

    strmrg(s1, s2, s3);
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    printf("s3 = %s\n", s3);

    return 1;
}