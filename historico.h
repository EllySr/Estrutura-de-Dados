
#ifndef HISTORICO_H
#define HISTORICO_H

typedef struct NoHistorico {
    int sequencia;
    char tipo[30];
    int codigoAtividade;
    int matricula;
    struct NoHistorico* prox;
} NoHistorico;

typedef struct {
    NoHistorico* inicio;
    NoHistorico* fim;
    int proximaSequencia;
} Historico;

// Funções do historico
void inicializarHistorico(Historico* historico);

int historicoVazio(const Historico* historico);

int registrarEvento(Historico* historico, const char* tipo,
    int codigoAtividade, int matricula);

void imprimirHistorico(const Historico* historico);

void liberarHistorico(Historico* historico);

#endif
