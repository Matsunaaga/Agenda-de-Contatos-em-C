#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "contato.h" // Precisa conhecer a struct Contato

#define NOME_ARQUIVO_BIN "../bin/agenda_dados.bin"

// Salva o array de contatos em um arquivo binário.
// agenda: O array de structs Contato.
// total: O número atual de contatos no array.
void salvarDadosBinario(const Contato agenda[], int total);

// Carrega os contatos do arquivo binário para o array.
// agenda: O array onde os dados serão carregados.
// total: Ponteiro para a variável que guarda o total de contatos (será atualizada).
void carregarDadosBinario(Contato agenda[], int *total);

#endif