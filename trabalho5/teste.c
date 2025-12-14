#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CLIENTES 10000
#define MAX_EXAMES 500
#define MAX_AGENDAMENTOS 100
#define MAX_EXAMES_POR_AGENDAMENTO 10
#define TAM_STR 50

typedef struct {
    char nome[TAM_STR];
    char cpf[13];
} Cliente;

typedef struct {
    char codigo[5];
    char nome[TAM_STR];
    float valor;
} Exame;

typedef struct {
    char cpf[13];
    int quant;
    int quaisExames[MAX_EXAMES_POR_AGENDAMENTO];
} Agendamento;

char apresentarOpcoes() {
    char opcao;
    printf("\nMenu de OPCOES\n");
    printf("C - Cadastrar Cliente\n");
    printf("E - Cadastrar Exame\n");
    printf("A - Agendamento de Exames\n");
    printf("R - Relatorio\n");
    printf("S - Sair\n");
    printf("Digite a opcao desejada: ");
    fflush(stdin);
    scanf(" %c", &opcao);
    return toupper(opcao);
}

int existirCliente(char cpf[], Cliente clientes[], int quantosCli) {
    int resultado = 0;
    int i = 0;
    while(i < quantosCli && resultado == 0) {
        if(strcmp(clientes[i].cpf, cpf) == 0) {
            resultado = 1;
        }
        i++;
    }
    return resultado;
}

int cadastrarCliente(Cliente clientes[], int *quantosCli) {
    if(*quantosCli >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return 0;
    }
    char cpf[13];
    int existe = 1;
    while(existe) {
        printf("Digite o CPF do novo cliente (apenas números): ");
        scanf("%12s", cpf);
        existe = existirCliente(cpf, clientes, *quantosCli);
        if(existe) {
            printf("Erro. Já existe um cliente com o mesmo CPF!\n");
        }
    }
    strcpy(clientes[*quantosCli].cpf, cpf);

    printf("Digite o nome do novo cliente (sem espaços): ");
    scanf("%49s", clientes[*quantosCli].nome);

    (*quantosCli)++;
    printf("Cliente cadastrado com sucesso!\n");
    return 1;
}

int existirExame(char codigo[], Exame exames[], int quantosExa) {
    int resultado = 0;
    int i = 0;
    while(i < quantosExa && resultado == 0) {
        if(strcmp(exames[i].codigo, codigo) == 0) {
            resultado = 1;
        }
        i++;
    }
    return resultado;
}

int cadastrarExame(Exame exames[], int *quantosExa) {
    if(*quantosExa >= MAX_EXAMES) {
        printf("Limite de exames atingido!\n");
        return 0;
    }
    char codigo[5];
    int existe = 1;
    while(existe) {
        printf("Digite o código do novo exame (sem espaços): ");
        scanf("%4s", codigo);
        existe = existirExame(codigo, exames, *quantosExa);
        if(existe) {
            printf("Erro. Já existe um exame com o mesmo código!\n");
        }
    }
    strcpy(exames[*quantosExa].codigo, codigo);

    printf("Digite o nome do novo exame (sem espaços): ");
    scanf("%49s", exames[*quantosExa].nome);

    printf("Digite o valor do exame: ");
    scanf("%f", &exames[*quantosExa].valor);

    (*quantosExa)++;
    printf("Exame cadastrado com sucesso!\n");
    return 1;
}

int buscarIndiceExame(char codigo[], Exame exames[], int quantosExa) {
    int i = 0;
    int resultado = -1;
    while(i < quantosExa && resultado == -1) {
        if(strcmp(exames[i].codigo, codigo) == 0) {
            resultado = i;
        }
        i++;
    }
    return resultado;
}

int exameJaAgendado(int idxExame, int quaisExames[], int quant) {
    int i = 0;
    int resultado = 0;
    while(i < quant && resultado == 0) {
        if(quaisExames[i] == idxExame) {
            resultado = 1;
        }
        i++;
    }
    return resultado;
}

int agendamentoExame(Agendamento agendamentos[], int *quantosAgendamentos, Cliente clientes[], int quantosCli, Exame exames[], int quantosExa) {
    if(*quantosAgendamentos >= MAX_AGENDAMENTOS) {
        printf("Limite de agendamentos atingido!\n");
        return 0;
    }
    char cpf[13];
    printf("Digite o CPF do cliente para agendar exames: ");
    scanf("%12s", cpf);

    if(!existirCliente(cpf, clientes, quantosCli)) {
        printf("Cliente não cadastrado!\n");
        return 0;
    }

    Agendamento ag;
    strcpy(ag.cpf, cpf);
    ag.quant = 0;

    int repetir = 1;
    while(ag.quant < MAX_EXAMES_POR_AGENDAMENTO && repetir == 1) {
        char codigo[5];
        printf("Digite o código do exame para agendar (sem espaços): ");
        scanf("%4s", codigo);

        int idxExame = buscarIndiceExame(codigo, exames, quantosExa);
        if(idxExame == -1) {
            printf("Exame não cadastrado!\n");
        } else {
            int repetido = exameJaAgendado(idxExame, ag.quaisExames, ag.quant);
            if(repetido == 1) {
                printf("Exame já agendado neste agendamento!\n");
            } else {
                ag.quaisExames[ag.quant] = idxExame;
                ag.quant++;
            }
        }
        if(ag.quant < MAX_EXAMES_POR_AGENDAMENTO) {
            printf("Deseja agendar outro exame? (1-Sim, 0-Nao): ");
            scanf("%d", &repetir);
        }
    }

    agendamentos[*quantosAgendamentos] = ag;
    (*quantosAgendamentos)++;
    printf("Agendamento realizado!\n");
    return 1;
}

void relatorio(Agendamento agendamentos[], int quantosAgendamentos, Cliente clientes[], int quantosCli, Exame exames[], int quantosExa) {
    printf("\n--- RELATORIO DE AGENDAMENTOS ---\n");
    int i = 0;
    while(i < quantosAgendamentos) {
        int idxCliente = -1;
        int j = 0;
        while(j < quantosCli && idxCliente == -1) {
            if(strcmp(clientes[j].cpf, agendamentos[i].cpf) == 0) {
                idxCliente = j;
            }
            j++;
        }
        if(idxCliente != -1) {
            printf("Cliente: %s (CPF: %s)\n", clientes[idxCliente].nome, clientes[idxCliente].cpf);
            float total = 0;
            int k = 0;
            while(k < agendamentos[i].quant) {
                int idxExame = agendamentos[i].quaisExames[k];
                printf("  Exame: %s - %s - R$ %.2f\n", exames[idxExame].codigo, exames[idxExame].nome, exames[idxExame].valor);
                total = total + exames[idxExame].valor;
                k++;
            }
            printf("  Valor total: R$ %.2f\n\n", total);
        }
        i++;
    }
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    int quantosCli = 0;

    Exame exames[MAX_EXAMES];
    int quantosExa = 0;

    Agendamento agendamentos[MAX_AGENDAMENTOS];
    int quantosAgendamentos = 0;

    char escolhaDeOpcao;
    int sair = 0;
    while(sair == 0) {
        escolhaDeOpcao = apresentarOpcoes();
        switch (escolhaDeOpcao) {
            case 'C':
                cadastrarCliente(clientes, &quantosCli);
                break;
            case 'E':
                cadastrarExame(exames, &quantosExa);
                break;
            case 'A':
                agendamentoExame(agendamentos, &quantosAgendamentos, clientes, quantosCli, exames, quantosExa);
                break;
            case 'R':
                relatorio(agendamentos, quantosAgendamentos, clientes, quantosCli, exames, quantosExa);
                break;
            case 'S':
                printf("Saindo...\n");
                sair = 1;
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}