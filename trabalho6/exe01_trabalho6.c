#include <stdio.h>
#include <string.h>
#define MAX 10

void stup(char *string)
{
    char *p;
    p = string;
    while(*p != '\0')
    {
        p++;
    }
    p--;
    while(p+1 != string)
    {
        printf("%c", *p);
        p--;
    }
}

int main()
{
    char string[MAX];
    gets(string);
    stup(string);

    return 1;
}