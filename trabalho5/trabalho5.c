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

typedef struct cliente {
    char nome[MAX];
    char cpf[13];
} Cliente;

typedef struct exame {
    char codigo[5];
    char nome[50];
    float valor;
} Exame;

typedef struct agendamento {
    char cpf[13]; // cpf do cliente
    int quant; // quantidade de exames agendados nesse registro
    short int quaisExames[MAX_EXAMES_POR_AGENDAMENTO]; // indices dos exames
} Agendamento;

/* protótipos corretos */
char pegarOpcao(void);
void inicializarVariaveis(Agendamento agendamentos[], int maxAg);
int existirCliente(const char cpf[], Cliente clientes[], int quantosCli);
int existirExame(const char codigo[], Exame exames[], int quantosExa);
int cadastrarCliente(Cliente clientes[], int *quantosCli);
int cadastrarExame(Exame exames[], int *quantosExa);
int buscarIndiceExame(const char codigo[], Exame exames[], int quantosExa);
int agendamentoExame(Agendamento agendamentos[], int *quantosAge, Cliente clientes[], int quantosCli, Exame exames[], int quantosExa);
void relatorioAgendamentosExames(Agendamento agendamentos[], int quantosAge, Cliente clientes[], int quantosCli, Exame exames[], int quantosExa);
int exameJaAgendado(int idxExame, Agendamento *ag);

int main(void)
{
    Cliente clientes[MAX_CLIENTES];
    int quantosCli = 0;

    Exame exames[MAX_EXAMES];
    int quantosExa = 0;

    Agendamento agendamentos[MAX_AGENDAMENTOS];
    int quantosAge = 0;

    inicializarVariaveis(agendamentos, MAX_AGENDAMENTOS);

    while (1) {
        char escolha = pegarOpcao();
        switch (toupper(escolha)) {
            case 'C':
                cadastrarCliente(clientes, &quantosCli);
                break;
            case 'E':
                cadastrarExame(exames, &quantosExa);
                break;
            case 'A':
                agendamentoExame(agendamentos, &quantosAge, clientes, quantosCli, exames, quantosExa);
                break;
            case 'R':
                relatorioAgendamentosExames(agendamentos, quantosAge, clientes, quantosCli, exames, quantosExa);
                break;
            case 'S':
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    return 0;
}

char pegarOpcao(void)
{
    char opcao;
    printf("\nMenu de OPCOES\n");
    printf("C - Cadastrar Cliente\n");
    printf("E - Cadastrar Exame\n");
    printf("A - Agendamento de Exames\n");
    printf("R - Relatorio\n");
    printf("S - Sair\n");
    printf("Digite a opcao desejada: ");
    /* lê um caractere ignorando espaços em branco anteriores */
    if (scanf(" %c", &opcao) != 1) {
        opcao = ' ';
    }
    return opcao;
}

void inicializarVariaveis(Agendamento agendamentos[], int maxAg)
{
    int i;
    for (i = 0; i < maxAg; i++) {
        agendamentos[i].quant = 0;
        agendamentos[i].cpf[0] = '\0';
    }
}

int existirCliente(const char cpf[], Cliente clientes[], int quantosCli)
{
    int i;
    for (i = 0; i < quantosCli; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            return 1;
        }
    }
    return 0;
}

int existirExame(const char codigo[], Exame exames[], int quantosExa)
{
    int i;
    for (i = 0; i < quantosExa; i++) {
        if (strcmp(exames[i].codigo, codigo) == 0) {
            return 1;
        }
    }
    return 0;
}

int cadastrarCliente(Cliente clientes[], int *quantosCli)
{
    if (*quantosCli >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return 0;
    }
    char cpf[13];
    char nome[MAX];

    do {
        printf("Digite o cpf do novo cliente (somente numeros, sem espacos): ");
        scanf("%12s", cpf);
        if (existirCliente(cpf, clientes, *quantosCli)) {
            printf("Erro. Ja existe um cliente com o mesmo CPF.\n");
        } else {
            break;
        }
    } while (1);

    printf("Digite o nome do novo cliente (sem espacos): ");
    scanf("%19s", nome);

    strcpy(clientes[*quantosCli].cpf, cpf);
    strcpy(clientes[*quantosCli].nome, nome);
    (*quantosCli)++;
    printf("Cliente cadastrado com sucesso!\n");
    return 1;
}

int cadastrarExame(Exame exames[], int *quantosExa)
{
    if (*quantosExa >= MAX_EXAMES) {
        printf("Limite de exames atingido!\n");
        return 0;
    }
    char codigo[5];
    char nome[50];
    float valor;

    do {
        printf("Digite o codigo do novo exame (sem espacos): ");
        scanf("%4s", codigo);
        if (existirExame(codigo, exames, *quantosExa)) {
            printf("Erro. Ja existe um exame com o mesmo codigo.\n");
        } else {
            break;
        }
    } while (1);

    printf("Digite o nome do novo exame (sem espacos): ");
    scanf("%49s", nome);
    printf("Digite o valor do exame: ");
    scanf("%f", &valor);

    strcpy(exames[*quantosExa].codigo, codigo);
    strcpy(exames[*quantosExa].nome, nome);
    exames[*quantosExa].valor = valor;
    (*quantosExa)++;
    printf("Exame cadastrado com sucesso!\n");
    return 1;
}

int buscarIndiceExame(const char codigo[], Exame exames[], int quantosExa)
{
    int i;
    for (i = 0; i < quantosExa; i++) {
        if (strcmp(exames[i].codigo, codigo) == 0) return i;
    }
    return -1;
}

int exameJaAgendado(int idxExame, Agendamento *ag)
{
    int k;
    for (k = 0; k < ag->quant; k++) {
        if (ag->quaisExames[k] == idxExame) return 1;
    }
    return 0;
}

int agendamentoExame(Agendamento agendamentos[], int *quantosAge, Cliente clientes[], int quantosCli, Exame exames[], int quantosExa)
{
    if (*quantosAge >= MAX_AGENDAMENTOS) {
        printf("Limite de agendamentos atingido!\n");
        return 0;
    }

    char cpf[13];
    printf("Digite o CPF do cliente para agendar exames: ");
    scanf("%12s", cpf);

    if (!existirCliente(cpf, clientes, quantosCli)) {
        printf("Cliente nao cadastrado!\n");
        return 0;
    }

    Agendamento novo;
    novo.quant = 0;
    strcpy(novo.cpf, cpf);

    int repetir = 1;
    while (novo.quant < MAX_EXAMES_POR_AGENDAMENTO && repetir == 1) {
        char codigo[5];
        printf("Digite o codigo do exame para agendar: ");
        scanf("%4s", codigo);

        int idx = buscarIndiceExame(codigo, exames, quantosExa);
        if (idx == -1) {
            printf("Exame nao cadastrado! Cadastre antes.\n");
        } else {
            if (exameJaAgendado(idx, &novo)) {
                printf("Exame ja agendado neste agendamento!\n");
            } else {
                novo.quaisExames[novo.quant] = idx;
                novo.quant++;
                printf("Exame adicionado ao agendamento.\n");
            }
        }

        if (novo.quant < MAX_EXAMES_POR_AGENDAMENTO) {
            printf("Deseja agendar outro exame? (1-Sim, 0-Nao): ");
            scanf("%d", &repetir);
            if (repetir != 1) repetir = 0;
        }
    }

    agendamentos[*quantosAge] = novo;
    (*quantosAge)++;
    printf("Agendamento realizado com sucesso!\n");
    return 1;
}

void relatorioAgendamentosExames(Agendamento agendamentos[], int quantosAge, Cliente clientes[], int quantosCli, Exame exames[], int quantosExa)
{
    int i, j;
    printf("\n--- RELATORIO DE AGENDAMENTOS ---\n");
    for (i = 0; i < quantosAge; i++) {
        /* busca nome do cliente */
        const char *nomeCliente = "(cliente nao encontrado)";
        for (j = 0; j < quantosCli; j++) {
            if (strcmp(clientes[j].cpf, agendamentos[i].cpf) == 0) {
                nomeCliente = clientes[j].nome;
                break;
            }
        }
        printf("Cliente: %s (CPF: %s)\n", nomeCliente, agendamentos[i].cpf);
        float total = 0.0f;
        for (j = 0; j < agendamentos[i].quant; j++) {
            int idx = agendamentos[i].quaisExames[j];
            if (idx >= 0 && idx < quantosExa) {
                printf("  Exame: %s - %s - R$ %.2f\n", exames[idx].codigo, exames[idx].nome, exames[idx].valor);
                total += exames[idx].valor;
            }
        }
        printf("  Valor total: R$ %.2f\n\n", total);
    }
}