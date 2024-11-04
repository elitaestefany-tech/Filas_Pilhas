#include <stdio.h>
#define TAMANHO 5

typedef struct {
    int itens[TAMANHO];
    int topo;
} PilhaCircular;

// Inicializa a pilha
void inicializarPilha(PilhaCircular *pilha) {
    pilha->topo = -1;
}

// Verifica se a pilha está cheia
int estaCheia(PilhaCircular *pilha) {
    return ((pilha->topo + 1) % TAMANHO == 0 && pilha->topo != -1);
}

// Verifica se a pilha está vazia
int estaVazia(PilhaCircular *pilha) {
    return (pilha->topo == -1);
}

// Empilhar na pilha circular
void empilhar(PilhaCircular *pilha, int valor) {
    if (estaCheia(pilha)) {
        printf("Pilha cheia!\n");
    } else {
        pilha->topo = (pilha->topo + 1) % TAMANHO;
        pilha->itens[pilha->topo] = valor;
        printf("Empilhado: %d\n", valor);
    }
}

// Desempilhar na pilha circular
int desempilhar(PilhaCircular *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        int valor = pilha->itens[pilha->topo];
        // Para indicar posição vazia
        pilha->itens[pilha->topo] = -1;
        pilha->topo = (pilha->topo - 1 + TAMANHO) % TAMANHO;
        return valor;
    }
}

// Consultar o topo da pilha
int consultarTopo(PilhaCircular *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha->itens[pilha->topo];
    }
}

int main() {
    PilhaCircular pilha;
    inicializarPilha(&pilha);

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    empilhar(&pilha, 40);

    printf("Topo da pilha: %d\n", consultarTopo(&pilha));

    desempilhar(&pilha);
    printf("Topo após desempilhar: %d\n", consultarTopo(&pilha));

    return 0;
}


