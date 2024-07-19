#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na lista
struct No {
    int valor; // Valor armazenado no nó
    No* prox;  // Ponteiro para o próximo nó na lista

    No(int _valor) : valor(_valor), prox(NULL) {}
};

// Estrutura para representar a lista encadeada
struct Lista {
    No* inicio; // Ponteiro para o primeiro nó da lista
    No* fim;    // Ponteiro para o último nó da lista

    Lista() : inicio(NULL), fim(NULL) {}

    // Método para inserir um novo nó no final da lista
    void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    // Método para imprimir a lista
    void imprimir() {
        No* atual = inicio;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
};

// Função para somar duas listas e retornar a lista resultante
Lista somarListas(Lista& lista1, Lista& lista2) {
    Lista resultado;
    No* no1 = lista1.inicio;
    No* no2 = lista2.inicio;
    int carry = 0;

    while (no1 != NULL || no2 != NULL || carry) {
        int soma = carry;
        if (no1 != NULL) {
            soma += no1->valor;
            no1 = no1->prox;
        }
        if (no2 != NULL) {
            soma += no2->valor;
            no2 = no2->prox;
        }
        carry = soma / 10;
        resultado.inserirFinal(soma % 10);
    }

    return resultado; // Não inverta a lista resultante
}

int main() {
    int N;
    scanf("%d", &N);
    
    Lista lista1, lista2;
    for (int i = 0; i < N; i++) {
        int valor;
        scanf("%d", &valor);
        lista1.inserirFinal(valor);
    }
    
    for (int i = 0; i < N; i++) {
        int valor;
        scanf("%d", &valor);
        lista2.inserirFinal(valor);
    }
    
    Lista resultado = somarListas(lista1, lista2);
    resultado.imprimir();
    
    return 0;
}
