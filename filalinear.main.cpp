#include <stdio.h>
#define TAMANHO 5

typedef struct {
    int itens[TAMANHO];
    int inicio, fim;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *fila) {
    fila->inicio = -1;
    fila->fim = -1;
}

int estaVazia(Fila *fila) {
    return (fila->inicio == -1);
}

// Verifica se a fila está cheia
int estaCheia(Fila *fila) {
    return (fila->fim == TAMANHO - 1);
}

// Enfileirar
void enfileirar(Fila *fila, int valor) {
    if (estaCheia(fila)) {
        printf("Fila cheia!\n");
    } else {
        if (fila->inicio == -1) {
            fila->inicio = 0;
        }
        fila->fim++;
        fila->itens[fila->fim] = valor;
        printf("Enfileirado: %d\n", valor);
    }
}

// Desenfileirar
int desenfileirar(Fila *fila) {
    int valor;
    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        valor = fila->itens[fila->inicio];
        fila->inicio++;
        if (fila->inicio > fila->fim) {
            fila->inicio = fila->fim = -1; // Resetar a fila
        }
        return valor;
    }
}

// Consultar o início da fila
int consultarInicio(Fila *fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        return fila->itens[fila->inicio];
    }
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

