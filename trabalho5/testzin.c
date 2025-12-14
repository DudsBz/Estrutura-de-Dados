//Eduardo Leite Braz
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 20
#define MAX_CLIENTES 10000
#define MAX_EXAMES 500
#define MAX_AGENDAMENTOS 100
#define MAX_EXAMES_POR_AGENDAMENTO 10


typedef struct cliente 
{
    char nome[MAX];
    char cpf[13];
}Cliente;

typedef struct exame
{
    char codigo[5];
    char nome[50];
    float valor;
}Exame;

typedef struct agendamento
{
    char cpf[13]; //cpf do cliente
    int quant; // quantidade de agendamentos por cliente
    short int quaisExames[10];  //indice do exame com inteiro
}Agendamento;


//Área de protótipo
int existirCliente(char cpf[], Cliente clientes[], int *quantosCli);
int existirExame(char codigo[], Exame exames[], int *quantosExa);
char pegarOpcao(void);
int cadastrarCliente(Cliente clientes[], int *quantosCli);
int cadastrarExame(Exame exames[], int *quantosExa);
int agendamentoExame(Agendamento agendamentos[], int *quantosAge, Cliente clientes[], int *quantosCli, Exame exames[], int *quantosExa);
int relatorioAgendamentosExames(Agendamento agendamentos[], int *quantosAge, Cliente clientes[], int *quantosCli, Exame exames[], int *quantosExa);
void inicializarVariaveis(Agendamento agendamentos[MAX_AGENDAMENTOS]);
int seraQueJaExisteEsseExameCadastrado(Exame exames[], int *quantosExa, char codigo[], Agendamento agendamentos[]);
char decisao(void);


int main()
{
    Cliente clientes[MAX_CLIENTES];
    int quantosCli = 0;

    Exame exames[MAX_EXAMES];
    int quantosExa = 0;

    Agendamento agendamentos[MAX_AGENDAMENTOS];
    int quantosAge = 0;

    inicializarVariaveis(agendamentos);
    do
    {
        char escolha = pegarOpcao();
        switch (toupper(escolha))
        {
        case 'C':
            printf("\nCadastrando....");
            cadastrarCliente(clientes, &quantosCli);
            break;
        case 'E':
            printf("\nCadastrando novo Exame....");
            cadastrarExame(exames, &quantosExa);
            break;
        case 'A':
            printf("\nAgendamento de Exame....");
            agendamentoExame(agendamentos, &quantosAge, clientes, &quantosCli, exames, &quantosExa);
            break;
        case 'R':
            printf("\nRelatório de Agendamentos e Exames....");
            relatorioAgendamentosExames(agendamentos, &quantosAge, clientes, &quantosCli, exames, &quantosExa);
            break;
        case 'S':
            printf("\nSaindo....");
            break;
        default:
            break;
        }
    } while (toupper(pegarOpcao()) != 'S');

    return 1;
}

int cadastrarExame(Exame exames[MAX_EXAMES], int *quantosExa)
{
    int mensagem = 1;
    char codigo[5];
    if(*quantosExa == MAX_EXAMES){
        printf("Saporra ta cheia já");
    }else
    {
        do
        {
            printf("\nDigite o código do novo exame: ");
            if (scanf("%4s", codigo) != 1) codigo[0] = '\0';
            if(existirExame(codigo, exames, quantosExa))
            {
                printf("\nErro. Jah existe um exame com o mesmo código");
            }
        }
        while(existirExame(codigo, exames, quantosExa));
        strcpy(exames[*quantosExa].codigo, codigo);
    }

    printf("\nDigite o nome do novo exame: ");
    if (scanf("%49s", exames[*quantosExa].nome) != 1) exames[*quantosExa].nome[0] = '\0';
    printf("\nDigite o valor do novo exame: ");
    scanf("%f", &exames[*quantosExa].valor);

    (*quantosExa)++;

    return mensagem;
}

void inicializarVariaveis(Agendamento agendamentos[MAX_AGENDAMENTOS])
{
    int i;
    for(i = 0; i < MAX_AGENDAMENTOS; i++)
    {
        agendamentos[i].quant = 0;
        agendamentos[i].cpf[0] = '\0';
    }
}

int existirCliente(char cpf[], Cliente clientes[], int *quantosCli)
{
    int resultado = 0;
    int i;
    for(i = 0; i < *quantosCli && resultado == 0; i++)
    {
        if(strcmp(clientes[i].cpf, cpf) == 0)
        {
            resultado = 1;
        }
    }
    return resultado;
}

int existirExame(char codigo[], Exame exames[], int *quantosExa)
{
    int resultado = 0;
    int i;
    for(i = 0; i < *quantosExa && resultado == 0; i++)
    {
        if(strcmp(exames[i].codigo, codigo) == 0)
        {
            resultado = 1;
        }
    }
    return resultado;
}

int cadastrarCliente(Cliente *clientes, int *quantosCli)
{
    int mensagem = 1;
    char cpf[13];
    if(*quantosCli == MAX_CLIENTES){
        printf("\nTa cheio essa porra");
    }else
    {
        do
        {
            printf("\nDigite o cpf do novo cliente: ");
            if (scanf("%12s", cpf) != 1) cpf[0] = '\0';
            if(existirCliente(cpf, clientes, quantosCli))
            {
                printf("\nErro. Jah existe um cliente com o mesmo CPF");
            }
        }
        while(existirCliente(cpf, clientes, quantosCli));
        strcpy(clientes[*quantosCli].cpf, cpf);
    }

    printf("\nDigite o nome do novo cliente: ");
    if (scanf("%19s", clientes[*quantosCli].nome) != 1) clientes[*quantosCli].nome[0] = '\0';

    (*quantosCli)++;

    return mensagem;
}

char pegarOpcao()
{
    char opcao = '\0';
    printf("\nMenu de OPCOES\n");
    printf("\nC - Cadastrar Cliente");
    printf("\nE - Cadastrar Exame");
    printf("\nA - Agendamento de Exames");
    printf("\nD - Deletar");
    printf("\nR - Relatorio");
    printf("\nS - Sair");
    printf("\nDigite a opcao desejada: ");
    if (scanf(" %c", &opcao) != 1) opcao = '\0';
    return opcao;
}

int seraQueJaExisteEsseExameCadastrado(Exame exames[], int *quantosExa, char codigo[], Agendamento agendamentos[])
{
    int i, j;
    int resultado = 0;
    int indiceExame = -1;
    int encontrouExame = 0;

    for (i = 0; i < *quantosExa && encontrouExame == 0; i++) {
        if (strcmp(exames[i].codigo, codigo) == 0) {
            indiceExame = i;
            encontrouExame = 1;
        }
    }
    if (indiceExame == -1) resultado = 0;

    for (i = 0; i < MAX_AGENDAMENTOS && resultado == 0; i++) {
        for (j = 0; j < agendamentos[i].quant && resultado == 0; j++) {
            if (agendamentos[i].quaisExames[j] == indiceExame) {
                resultado = 1;
            }
        }
    }

    return resultado;
}

char decisao()
{
    char deci = '\0';
    printf("\nDeseja continuar?....");
    printf("\n'S' - Sim   'N' - Não");
    if (scanf(" %c", &deci) != 1) deci = 'N';
    return toupper(deci);
}

int agendamentoExame(Agendamento *agendamentos, int *quantosAge, Cliente *clientes, int *quantosCli, Exame exames[MAX_EXAMES], int *quantosExa)
{
    int resultado = 1;
    char cpf[13];
    printf("\nAgendando....");
    if(*quantosAge == MAX_AGENDAMENTOS)
    {
        printf("\n--!Máximo de Agendamentos obtido!--");
        resultado = 0;
    }
    else
    {
        printf("\nDigite o cpf do cliente: ");
        if (scanf("%12s", cpf) != 1) cpf[0] = '\0';
        if(existirCliente(cpf, clientes, quantosCli))
        {
            do
            {
                char cod[5];
                printf("Digite o código do exame: ");
                if (scanf("%4s", cod) != 1) cod[0] = '\0';
                if(!existirExame(cod, exames, quantosExa))
                {
                    printf("\nNao existe esse exame, cadastre-o!");
                }
                else
                {
                    int indiceExame = -1;
                    int encontrouExame = 0;
                    int i;
                    for (i = 0; i < *quantosExa && encontrouExame == 0; i++) {
                        if (strcmp(exames[i].codigo, cod) == 0) {
                            indiceExame = i;
                            encontrouExame = 1;
                        }
                    }
                    if (indiceExame == -1) {
                        printf("Erro: exame não encontrado\n");
                    } else {
                        int indiceAgendamento = -1;
                        int encontrouAgendamento = 0;
                        for (i = 0; i < *quantosAge && encontrouAgendamento == 0; i++) {
                            if (strcmp(agendamentos[i].cpf, cpf) == 0) {
                                indiceAgendamento = i;
                                encontrouAgendamento = 1;
                            }
                        }
                        if (indiceAgendamento == -1) {
                            if (*quantosAge >= MAX_AGENDAMENTOS) {
                                printf("Limite de agendamentos atingido\n");
                            } else {
                                indiceAgendamento = *quantosAge;
                                strcpy(agendamentos[indiceAgendamento].cpf, cpf);
                                agendamentos[indiceAgendamento].quant = 0;
                                (*quantosAge)++;
                            }
                        }
                        if (indiceAgendamento != -1) {
                            if (agendamentos[indiceAgendamento].quant >= MAX_EXAMES_POR_AGENDAMENTO) {
                                printf("Limite de exames por agendamento atingido\n");
                            } else {
                                agendamentos[indiceAgendamento].quaisExames[agendamentos[indiceAgendamento].quant] = (short)indiceExame;
                                agendamentos[indiceAgendamento].quant = agendamentos[indiceAgendamento].quant + 1;
                                printf("Exame cadastrado com sucesso!");
                            }
                        }
                    }
                }
            } while (decisao() != 'N' && agendamentos[*quantosAge - 1].quant < MAX_EXAMES_POR_AGENDAMENTO);
        }
    }
    return resultado;
}

int relatorioAgendamentosExames(Agendamento *agendamentos, int *quantosAge, Cliente *clientes, int *quantosCli, Exame exames[], int *quantosExa)
{
    int i, j;
    printf("\n--- RELATORIO DE AGENDAMENTOS ---\n");
    for(i = 0; i < *quantosAge; i++)
    {
        printf("Agendamento %d - CPF: %s\n", i+1, agendamentos[i].cpf);
        for(j = 0; j < agendamentos[i].quant; j++)
        {
            int idx = agendamentos[i].quaisExames[j];
            if(idx >= 0 && idx < *quantosExa)
            {
                printf("  Exame: %s - %s - R$ %.2f\n", exames[idx].codigo, exames[idx].nome, exames[idx].valor);
            }
        }
    }
    return 1;
}