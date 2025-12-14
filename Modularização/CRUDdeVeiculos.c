#include <stdio.h>
#include <string.h>
#define MAX 20
///tipo está global
struct carro
{
    char chassis[18];
    char marca[50];
    char modelo[40];
    int ano;
};
typedef struct carro Carro;

Carro digitarCarro()
{
    Carro umCarro;

    fflush(stdin);
    printf("\nDigite o chassi: ");
    gets(umCarro.chassis);
    fflush(stdin);
    printf("\nDigite a marca: ");
    gets(umCarro.marca);
    fflush(stdin);
    printf("\nDigite o modelo: ");
    gets(umCarro.modelo);
    fflush(stdin);
    printf("\nDigite o ano: ");
    scanf("%i", &umCarro.ano);

    return umCarro;
}
void imprimirCarro(Carro umCarro)
{
    printf("\nChassi: %20s", umCarro.chassis);
    printf("\nMarca.: %20s", umCarro.marca);
    printf("\nModelo: %20s", umCarro.modelo);
    printf("\nAno...: %4i\n",  umCarro.ano);
}

void consultarVeiculo(Carro frota[], int *quantos)
{
    int indice, achou;
    printf("\nConsultando...");

    Carro umCarro = digitarCarro();

    for(indice = 0; indice <*quantos; indice++){
        if (compararCarro(frota[indice], umCarro))
        {
            achou = 1;
        }
        
    }
    printf("\nVeiculo %s encontrado", achou?"":"NAO");
}

int compararCarro(Carro carrin, Carro umCarro)
{
    int saoIguais = 1;

    if(strcmp(carrin.chassis, umCarro.chassis) != 0)
    {
        saoIguais = 0;
    }
    if(strcmp(carrin.marca, umCarro.marca) != 0)
    {
        saoIguais = 0;
    }
    if(strcmp(carrin.modelo, umCarro.modelo) != 0)
    {
        saoIguais = 0;
    }
    if(carrin.ano == umCarro.ano)
    {
        saoIguais = 0;
    }

    return saoIguais;
}
int deletarCarro(Carro frota[], int *quantos, Carro carroDel)
{
    int deuCerto = 0; ///falso que deu certo
    int indice, i;

    for(indice = 0; indice < *quantos && !deuCerto; indice++)
    {
        if(compararCarro(frota[indice], carroDel))
        {
            deuCerto++;
            
            for (i = indice; i < *quantos; i++)
            {
                frota[i] = frota[i+1];
            }
            (*quantos)--;
            
        }
    }
    

    return deuCerto;
}
int incluirVeiculo(struct carro frota[], int *quantos)
{
    int deuCerto = 1; ///verdadeiro que deu certo

    if(*quantos == MAX) ///erro
    {
        printf("\nE R R O. Nao tem mais espaco.");
        deuCerto = 0; ///falso que deu certo
    }
    else
    {
        fflush(stdin);
        printf("\nDigite o chassi: ");
        gets(frota[*quantos].chassis);
        fflush(stdin);
        printf("\nDigite a marca: ");
        gets(frota[*quantos].marca);
        fflush(stdin);
        printf("\nDigite o modelo: ");
        gets(frota[*quantos].modelo);
        fflush(stdin);
        printf("\nDigite o ano: ");
        scanf("%i", &frota[*quantos].ano);

        (*quantos)++;
///        *quantos = *quantos + 1;
    }
    return deuCerto;
}


int main()
{
    Carro frota[MAX]; /// array de struct
    int quantos = 0;

    char opcao;
    do
    {
        /// apresentar as opcoes
        printf("\nMenu de OPCOES\n");
        printf("\nI - Incluir");
        printf("\nP - imPrimir");
        printf("\nA - Alterar");
        printf("\nD - Deletar");
        printf("\nC - Consultar");
        printf("\nS - Sair");

        /// pegar opcao desejada
        printf("\nDigite a opcao desejada: ");
        fflush(stdin);
        scanf("%c", &opcao);

        ///selecionar a a��o correspondente
        switch(toupper(opcao))
        {
        case 'A':
        {
            
            break;
        }
        case 'I': /// incluir
        {
            printf("\nIncluindo\n");
            int deuCerto = incluirVeiculo(frota, &quantos);
            if(deuCerto){
                printf("Deu certo");
            }
            else{
                printf("Nao deu certo");
            }


            break;
        }
        case 'P': /// imprimir
        {
            printf("\nImprimindo");
            int indice;
            for(indice = 0; indice < quantos; indice++)
            {
                imprimirVeiculo(frota[indice]);
            }
            break;
        }
        case 'C': /// consultar
        {
            consultarVeiculo(frota, quantos);

            break;
        }
        case 'D': ///deletar
        {
            printf("\nDeletando...");
            if(quantos == 0)
            {
                printf("\nImpossivel deletar. Nao existe carro no cadastro");
            }
            else
            {
                
                if(deletarCarro(frota, &quantos, digitarCarro())){
                    printf("\nCarro deletado.");
                }
                else{
                    printf("\nCarro nao deletado, tente novamente...");
                }
            }
            break;
        }
        case 'S': /// sair
        {
            printf("\nSaindo...");
            break;
        }
        default: ///DEFO
        {
            printf("\n\n*** Opcao invalida *** ");
        }
        }
    }
    while(toupper(opcao) != 'S');

}