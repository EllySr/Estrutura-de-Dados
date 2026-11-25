#ifndef LISTA_H
#define LISTA_H

typedef struct NoLista {
    int matricula;
    char* nome;
    struct NoLista* prox;
} NoLista;

typedef struct {
    NoLista* inicio;
    NoLista* fim;
} Lista;

void inicializarLista(Lista* lista);

int listaVazia(const Lista* lista);

NoLista* buscarMatricula(Lista* lista, int matricula);

int inserirFim(Lista* lista, int matricula, const char* nome);

int removerMatricula(Lista* lista, int matricula);

void liberarLista(Lista* lista);

#endif
