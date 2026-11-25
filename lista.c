#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Inicializa a lista vazia
void inicializarLista(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

// Verifica se a lista está vazia
int listaVazia(const Lista* lista) {
    return lista->inicio == NULL;
}

// Busca um estudante pela matrícula
NoLista* buscarMatricula(Lista* lista, int matricula) {
    NoLista* atual = lista->inicio;

    while (atual != NULL) {
        if (atual->matricula == matricula) {
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

// Inserir estudante no final
int inserirFim(Lista* lista, int matricula, const char* nome) {
    NoLista* novo = malloc(sizeof(NoLista));

    if (novo == NULL) {
        return 0;
    }

    // Aloca memória suficiente para armazenar o nome
    // O +1 reserva espaço para o caractere '\0'
    novo->nome = malloc(strlen(nome) + 1);

    if (novo->nome == NULL) {
        free(novo);
        return 0;
    }

    // Copia o nome recebido para o espaço de memória reservado
    strcpy(novo->nome, nome);

    // Armazena a matrícula do estudante
    novo->matricula = matricula;

    // Como será o último nó, seu próximo será NULL
    novo->prox = NULL;

    // Verifica se a lista está vazia
    if (listaVazia(lista)) {
        // O novo nó será o primeiro e também o último
        lista->inicio = novo;
        lista->fim = novo;
    }
    else {
        // Liga o antigo último nó ao novo nó
        lista->fim->prox = novo;
        // Atualiza o ponteiro fim para o novo último nó
        lista->fim = novo;
    }

    return 1;

}

int removerMatricula(Lista* lista, int matricula) {
    // Ponteiros que guardam o estudante procurado e a anterior a ele 
    NoLista* atual = lista->inicio;
    NoLista* anterior = NULL;

    // Procura o estudante pela matrícula
    while (atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    // Verifica se o estudante não foi encontrado
    if (atual == NULL) {
        return 0;
    }

    // Verifica se o estudante está no começo da lista
    if (anterior == NULL) {
        lista->inicio = atual->prox;
    }
    else {
        // Liga o nó anterior ao próximo nó do estudante removido
        anterior->prox = atual->prox;
    }

    // Verifica se o estudante removido era o último da lista
    if (atual == lista->fim) {
        lista->fim = anterior;
    }

    // Libera a memória utilizada pelo nome e pelo nó
    free(atual->nome);
    free(atual);

    // Garante que o fim também seja NULL se a lista ficou vazia
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }

    // Retorna 1 indicando que a remoção foi realizada
    return 1;

}


// Liberar toda a memória utilizada pela lista
void liberarLista(Lista* lista) {
    NoLista* atual = lista->inicio;
    NoLista* proximo;

    // Percorre todos os nós da lista
    while (atual != NULL) {

        // Guarda o próximo nó
        proximo = atual->prox;

        // Libera a memória do nome do estudante
        free(atual->nome);

        // Libera a memória do nó
        free(atual);

        // Avança para o próximo nó
        atual = proximo;
    }

    // Deixa a lista vazia após liberar toda a memória
    lista->inicio = NULL;
    lista->fim = NULL;
}
