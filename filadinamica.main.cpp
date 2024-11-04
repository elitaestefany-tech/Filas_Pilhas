#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Verifica se a fila está vazia
int estaVazia(Fila *fila) {
    return (fila->inicio == NULL);
}

// Enfileirar
void enfileirar(Fila *fila, int valor) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro de memoria!\n");
        return;
    }

    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novoNo;
    } else {
        fila->fim->proximo = novoNo;
    }

    fila->fim = novoNo;
    printf("Enfileirado: %d\n", valor);
}

// Desenfileirar
int desenfileirar(Fila *fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }

    int valor = fila->inicio->valor;
    No *temp = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    return valor;
}

// Consultar o inicio da fila
int consultarInicio(Fila *fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }

    return fila->inicio->valor;
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    printf("Inicio da fila: %d\n", consultarInicio(&fila));

    desenfileirar(&fila);
    printf("Inicio apos desenfileirar: %d\n", consultarInicio(&fila));

    return 0;
}
