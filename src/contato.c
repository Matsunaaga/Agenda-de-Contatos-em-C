#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "../include/contato.h"
#include "../include/utils.h"


// Retorna o índice do contato pelo nome, ou -1 se não achar.
int buscarIndicePorNome(const Contato agenda[], int total, const char *nomeBusca) {
    for (int i = 0; i < total; i++) {
        if (strcasecmp(agenda[i].nome, nomeBusca) == 0) {
            return i;
        }
    }
    return -1;
}

// Pede um ID ao usuário e retorna o índice válido do array (0 a total-1), ou -1 se inválido.
int solicitarIndiceValido(int total) {
    int id;
    printf("Digite o ID do contato (numero da lista): ");
    if (scanf("%d", &id) != 1) {
        limparBufferEntrada();
        return -1;
    }
    limparBufferEntrada();

    if (id > 0 && id <= total) {
        return id - 1; 
    }
    return -1;
}

// Vai exibir um único contato de forma formatada.
void exibirContato(const Contato c) {
    printf("\n--- Detalhes do Contato ---\n");
    printf("Nome:     %s\n", c.nome);
    printf("Telefone: %s\n", c.telefone);
    printf("E-mail:   %s\n", c.email);
    printf("---------------------------\n");
}

void adicionarContato(Contato agenda[], int *total) {
    if (*total >= MAX_CONTATOS) {
        printf("\nA agenda esta cheia! Impossivel adicionar.\n");
        return;
    }

    printf("\n--- Adicionar Novo Contato ---\n");
    lerStringSegura("Nome: ", agenda[*total].nome, TAM_NOME);
    lerStringSegura("Telefone: ", agenda[*total].telefone, TAM_TEL);
    lerStringSegura("E-mail: ", agenda[*total].email, TAM_EMAIL);

    (*total)++;
    printf("\n[OK] Contato adicionado com sucesso!\n");
}

void listarContatos(const Contato agenda[], int total) {
    if (total == 0) {
        printf("\nA agenda esta vazia.\n");
        return;
    }
    printf("\n--- Lista de Contatos (%d registados) ---\n", total);
    for (int i = 0; i < total; i++) {
        printf("ID %02d | %-20s | Tel: %s\n", i + 1, agenda[i].nome, agenda[i].telefone);
    }
    printf("----------------------------------------\n");
}

void buscarContatoPorNomeInterface(const Contato agenda[], int total) {
    if (total == 0) { printf("\nAgenda vazia.\n"); return; }
    
    char nomeBusca[TAM_NOME];
    printf("\n--- Buscar por Nome ---\n");
    lerStringSegura("Digite o nome (ou parte dele): ", nomeBusca, TAM_NOME);

    int index = buscarIndicePorNome(agenda, total, nomeBusca);

    if (index != -1) {
        exibirContato(agenda[index]);
    } else {
        printf("\n[!] Contato nao encontrado com esse nome exato.\n");
    }
}

void buscarContatoPorIdInterface(const Contato agenda[], int total) {
    if (total == 0) { printf("\nAgenda vazia.\n"); return; }
    
    printf("\n--- Buscar por ID ---\n");
    listarContatos(agenda, total); // Mostra a lista para ajudar
    int index = solicitarIndiceValido(total);

    if (index != -1) {
        exibirContato(agenda[index]);
    } else {
        printf("\n[!] ID invalido.\n");
    }
}

void editarContatoInterface(Contato agenda[], int total) {
    if (total == 0) { printf("\nAgenda vazia.\n"); return; }

    printf("\n--- Editar Contato ---\n");
    listarContatos(agenda, total);
    int index = solicitarIndiceValido(total);

    if (index != -1) {
        printf("\nEditando: %s\n", agenda[index].nome);
        printf("(Pressione ENTER para manter o valor atual)\n");

        char buffer[TAM_NOME];

        printf("Novo Nome [%s]: ", agenda[index].nome);
        fgets(buffer, TAM_NOME, stdin);
        removerQuebraLinha(buffer);
        if (strlen(buffer) > 0) strcpy(agenda[index].nome, buffer);

        printf("Novo Telefone [%s]: ", agenda[index].telefone);
        fgets(buffer, TAM_TEL, stdin);
        removerQuebraLinha(buffer);
        if (strlen(buffer) > 0) strcpy(agenda[index].telefone, buffer);

        printf("Novo Email [%s]: ", agenda[index].email);
        fgets(buffer, TAM_EMAIL, stdin);
        removerQuebraLinha(buffer);
        if (strlen(buffer) > 0) strcpy(agenda[index].email, buffer);

        printf("\n[OK] Contato atualizado com sucesso!\n");
    } else {
        printf("\n[!] Operacao cancelada ou ID invalido.\n");
    }
}

void excluirContatoInterface(Contato agenda[], int *total) {
    if (*total == 0) { printf("\nAgenda vazia.\n"); return; }

    printf("\n--- Excluir Contato ---\n");
    listarContatos(agenda, *total);
    int index = solicitarIndiceValido(*total);

    if (index != -1) {
        printf("\nATENCAO: Tem certeza que deseja excluir '%s'?\n", agenda[index].nome);
        printf("Digite 1 para CONFIRMAR ou 0 para CANCELAR: ");
        int confirma;
        scanf("%d", &confirma);
        limparBufferEntrada();

        if (confirma == 1) {
            // Algoritmo de exclusão: move todos os itens da frente uma posição para trás
            for (int i = index; i < *total - 1; i++) {
                agenda[i] = agenda[i + 1];
            }
            (*total)--; // Decrementa o contador total
            printf("\n[OK] Contato excluido permanentemente.\n");
        } else {
            printf("\nExclusao cancelada.\n");
        }
    } else {
         printf("\n[!] Operacao cancelada ou ID invalido.\n");
    }
}

void exibirStatusAgenda(int total) {
    printf("\n--- Status da Agenda ---\n");
    printf("Contatos cadastrados: %d\n", total);
    printf("Capacidade total:     %d\n", MAX_CONTATOS);
    printf("Espaco livre:         %d\n", MAX_CONTATOS - total);
    printf("------------------------\n");
}