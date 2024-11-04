#include <stdio.h>
#define TAMANHO 5

typedef struct {
    int itens[TAMANHO];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

// Verifica se a pilha está cheia
int estaCheia(Pilha *pilha) {
    return (pilha->topo == TAMANHO - 1);
}

// Empilhar (push)
void empilhar(Pilha *pilha, int valor) {
    if (estaCheia(pilha)) {
        printf("Pilha cheia!\n");
    } else {
        pilha->topo++;
        pilha->itens[pilha->topo] = valor;
        printf("Empilhado: %d\n", valor);
    }
}

// Desempilhar (pop)
int desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        int valor = pilha->itens[pilha->topo];
        pilha->topo--;
        return valor;
    }
}

// Consultar o topo (peek)
int consultarTopo(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha->itens[pilha->topo];
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);

    printf("Topo da pilha: %d\n", consultarTopo(&pilha));
    desempilhar(&pilha);
    printf("Topo apos desempilhar: %d\n", consultarTopo(&pilha));

    return 0;
}
