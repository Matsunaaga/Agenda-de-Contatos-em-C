#include <stdio.h>
#include <string.h>
#include "../include/utils.h" // Inclui a própria interface

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removerQuebraLinha(char *string) {
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}

void lerStringSegura(const char *prompt, char *destino, int tamanho) {
    do {
        printf("%s", prompt);
        fgets(destino, tamanho, stdin);
        removerQuebraLinha(destino);
        if (strlen(destino) == 0) {
            printf("Entrada invalida. O campo nao pode ser vazio.\n");
        }
    } while (strlen(destino) == 0);
}