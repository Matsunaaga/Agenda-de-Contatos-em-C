#ifndef UTILS_H
#define UTILS_H


// Limpa o buffer de entrada (stdin) para evitar problemas com scanf/fgets.
void limparBufferEntrada();

// Remove o caractere ('\n') do final de uma string lida por fgets.
void removerQuebraLinha(char *string);

// Lê uma string do usuário de forma segura, garantindo que não seja vazia.
// prompt: Mensagem a ser exibida antes de ler.
// destino: Buffer onde a string será salva.
// tamanho: Tamanho máximo do buffer.
void lerStringSegura(const char *prompt, char *destino, int tamanho);

#endif