# Agenda de Contatos em C

Este projeto é uma agenda de contatos desenvolvida em C.

O objetivo é demonstrar conhecimentos em estruturação de código, modularização, uso de `structs`, manipulação de arquivos e boas práticas de programação.

## Funcionalidades

* **Adicionar Contato:** Cadastra nome, telefone e e-mail.
* **Listar Contatos:** Exibe todos os contatos cadastrados.
* **Buscar Contato:** Permite buscar por nome ou por ID (índice).
* **Editar Contato:** Atualiza os dados de um contato existente.
* **Excluir Contato:** Remove um contato da agenda.
* **Persistência de Dados:** Os contatos são salvos automaticamente em um arquivo binário e carregados na próxima execução.
* **Interface Modular:** Código organizado em múltiplos arquivos para facilitar a manutenção.

## Estrutura do Projeto

O projeto segue uma estrutura de diretórios organizada:

* `src/`: Contém os arquivos de código fonte (`.c`).
* `include/`: Contém os arquivos de cabeçalho (`.h`) com as definições de structs e protótipos de funções.
* `bin/`: Diretório onde o arquivo executável e o arquivo de dados são armazenados (ignorado pelo Git).
* `docs/`: Documentação do projeto (roteiros, planejamento).

## Como Compilar e Executar

Para compilar o projeto, é necessário ter um compilador C (GCC) instalado.

1.  Abra um terminal na pasta raiz do projeto.
2.  Navegue até a pasta `src`:
    ```bash
    cd src
    ```
3.  Execute o comando de compilação:
    ```bash
    gcc main.c contato.c arquivo.c utils.c -I ../include -o ../bin/agenda_app
    ```
4.  Para executar o programa:
    * **Windows:**
        ```bash
        ../bin/agenda_app.exe
        ```
    * **Linux/macOS:**
        ```bash
        ../bin/agenda_app
        ```

## Autores

LUCAS KENJI MATSUNAGA CAETANO & JOÃO VITOR BATISTA DE SOUZA

---
*Projeto desenvolvido para a disciplina de ALGORITMOS E PROGRAMAÇÃO ESTRUTURADA, sob orientação da Professora JESSICA SOUSA OLIVEIRA.*