#ifndef CONTATO_H
#define CONTATO_H

// --- Constantes ---
#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_TEL 20
#define TAM_EMAIL 50

// --- Structs ---
typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TEL];
    char email[TAM_EMAIL];
} Contato;

// --- Funções Principais do Módulo Contato ---

// Adiciona um novo contato.
void adicionarContato(Contato agenda[], int *total);

// Lista todos os contatos com seus IDs.
void listarContatos(const Contato agenda[], int total);

// Interface para buscar um contato pelo nome.
void buscarContatoPorNomeInterface(const Contato agenda[], int total);

// Interface para buscar um contato pelo ID (número na lista).
void buscarContatoPorIdInterface(const Contato agenda[], int total);

// Interface para editar um contato existente.
void editarContatoInterface(Contato agenda[], int total);

// Interface para excluir um contato.
void excluirContatoInterface(Contato agenda[], int *total);

// Mostra quantos contatos estão cadastrados e o espaço livre.
void exibirStatusAgenda(int total);

#endif