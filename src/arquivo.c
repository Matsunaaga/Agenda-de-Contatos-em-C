#include <stdio.h>
#include "../include/arquivo.h"

void salvarDadosBinario(const Contato agenda[], int total) {
    FILE *file = fopen(NOME_ARQUIVO_BIN, "wb"); 
    if (file == NULL) {
        printf("\nERRO CRITICO: Nao foi possivel abrir o arquivo para salvar.\n");
        return;
    }

    // 1. Salva a quantidade de contatos
    fwrite(&total, sizeof(int), 1, file);

    // 2. Salva o array de structs inteiro de uma vez
    if (total > 0) {
        fwrite(agenda, sizeof(Contato), total, file);
    }

    fclose(file);
    printf("\nDados salvos com sucesso no arquivo binario.\n");
}

void carregarDadosBinario(Contato agenda[], int *total) {
    FILE *file = fopen(NOME_ARQUIVO_BIN, "rb"); // Read Binary
    if (file == NULL) {
        // Arquivo não existe na primeira execução, não é um erro crítico.
        *total = 0;
        printf("\nArquivo de dados nao encontrado. Iniciando agenda vazia.\n");
        return;
    }

    // 1. Lê a quantidade de contatos
    if (fread(total, sizeof(int), 1, file) != 1) {
        *total = 0;
        fclose(file);
        return;
    }

    // Validação de segurança
    if (*total > MAX_CONTATOS) {
         printf("AVISO: Arquivo corrompido ou versao incompativel. Resetando agenda.\n");
         *total = 0;
         fclose(file);
         return;
    }

    // 2. Lê os contatos para o array
    if (*total > 0) {
        fread(agenda, sizeof(Contato), *total, file);
    }

    fclose(file);
    printf("\n%d contatos carregados com sucesso.\n", *total);
}