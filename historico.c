#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "historico.h"

// Inicializa o histórico vazio
void inicializarHistorico(Historico* historico) {
    historico->inicio = NULL;
    historico->fim = NULL;
    historico->proximaSequencia = 1;
}

// Verifica se o histórico está vazio
int historicoVazio(const Historico* historico) {
    return historico->inicio == NULL;
}


// Registra um novo evento no histórico
int registrarEvento(Historico* historico, const char* tipo, int codigoAtividade, int matricula) {

    // Aloca memória para um novo evento
    NoHistorico* novo = malloc(sizeof(NoHistorico));

    // Verifica se a memória foi alocada corretamente
    if (novo == NULL) {
        return 0;
    }

    // Copia o tipo do evento
    strcpy(novo->tipo, tipo);

    // Armazena o código da atividade
    novo->codigoAtividade = codigoAtividade;

    // Armazena a matrícula do estudante
    novo->matricula = matricula;

    // Define o número de sequência do evento
    novo->sequencia = historico->proximaSequencia;

    // Como será o último evento, seu próximo será NULL
    novo->prox = NULL;

    // Verifica se o histórico está vazio
    if (historicoVazio(historico)) {

        // O novo evento será o primeiro e também o último
        historico->inicio = novo;
        historico->fim = novo;
    }
    else {

        // Liga o último evento ao novo evento
        historico->fim->prox = novo;

        // Atualiza o ponteiro fim
        historico->fim = novo;
    }

    // Incrementa a sequência para o próximo evento
    historico->proximaSequencia++;

    return 1;
}


void imprimirHistorico(const Historico* historico) {
    // Ponteiro para percorrer o historico
    NoHistorico* atual = historico->inicio;

    // Para contar a quantidade de eventos que tem
    int quantidade = 0;

    while (atual->prox != NULL) {
        quantidade++;
        atual = atual->prox;
    }

    // Imprime a quantidade de eventos
    printf("HISTORICO %d\n", quantidade);

    // Volta para o início do histórico
    atual = historico->inicio;

    // Percorre o histórico imprimindo cada evento
    while (atual != NULL) {
        printf("EVENTO %d %s %d %d\n",
            atual->sequencia,
            atual->tipo,
            atual->codigoAtividade,
            atual->matricula);

        atual = atual->prox;
    }
}

void liberarHistorico(Historico* historico) {
    // Ponteiro para percorrer o histórico
    NoHistorico* atual = historico->inicio;

    // Ponteiro para guardar o próximo evento
    NoHistorico* proximo;

    while (atual != NULL) {
        // Guarda o próximo evento antes de liberar o atual
        proximo = atual->prox;

        // Libera a memória do evento
        free(atual);

        // Avança para o próximo evento
        atual = proximo;
    }

    historico->inicio = NULL;
    historico->fim = NULL;

    // Reinicia a sequência
    historico->proximaSequencia = 1;

}