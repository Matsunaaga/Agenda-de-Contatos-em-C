#include <stdio.h>
#include <stdlib.h>
#include "../include/contato.h"
#include "../include/arquivo.h"
#include "../include/utils.h"

int main() {
    Contato agenda[MAX_CONTATOS];
    int totalContatos = 0;
    int opcao;

    carregarDadosBinario(agenda, &totalContatos);

    do {
        // Menu
        printf("\n====================================\n");
        printf("       AGENDA DE CONTATOS\n");
        printf("====================================\n");
        printf(" 1. Adicionar Novo Contato\n");
        printf(" 2. Listar Todos os Contatos\n");
        printf(" 3. Buscar por Nome\n");
        printf(" 4. Buscar por ID\n");
        printf(" 5. Editar Contato\n");
        printf(" 6. Excluir Contato\n");
        printf(" 7. Ver Status da Agenda\n");
        printf("------------------------------------\n");
        printf(" 0. Sair e Salvar Alteracoes\n");
        printf("====================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                adicionarContato(agenda, &totalContatos);
                break;
            case 2:
                listarContatos(agenda, totalContatos);
                break;
            case 3:
                buscarContatoPorNomeInterface(agenda, totalContatos);
                break;
            case 4:
                buscarContatoPorIdInterface(agenda, totalContatos);
                break;
            case 5:
                editarContatoInterface(agenda, totalContatos);
                break;
            case 6:
                excluirContatoInterface(agenda, &totalContatos);
                break;
            case 7:
                exibirStatusAgenda(totalContatos);
                break;
            case 0:
                salvarDadosBinario(agenda, totalContatos);
                printf("\nObrigado por usar a agenda. Ate logo!\n");
                break;
            default:
                printf("\n[!] Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return EXIT_SUCCESS;
}