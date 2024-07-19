#include <stdio.h>
#include <limits.h>

// Estrutura para representar um nó na lista
struct No {
    int valor; // Valor armazenado no nó
    No* prox;  // Ponteiro para o próximo nó na lista

    // Construtor padrão que inicializa prox como NULL
    No() {
        prox = NULL;
    }

    // Construtor que inicializa o valor e prox como NULL
    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

// Estrutura para representar a lista encadeada
struct Lista {
    No* inicio; // Ponteiro para o primeiro nó da lista
    No* fim;    // Ponteiro para o último nó da lista
    int n;      // Número de nós na lista

    // Construtor padrão que inicializa a lista vazia
    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    // Método para inserir um novo nó no início da lista
    void inserirInicio(int valor) {
        No* novo = new No(valor); // Cria um novo nó com o valor dado
        if (inicio == NULL) {     // Se a lista está vazia
            inicio = novo;        // O novo nó é o início
            fim = novo;           // E também o fim
        } else {
            novo->prox = inicio;  // O próximo do novo nó é o antigo início
            inicio = novo;        // O novo nó se torna o início
        }
        n++;                      // Incrementa o contador de nós
    }

    // Método para inserir um novo nó no final da lista
    void inserirFinal(int valor) {
        No* novo = new No(valor); // Cria um novo nó com o valor dado
        if (inicio == NULL) {     // Se a lista está vazia
            inicio = novo;        // O novo nó é o início
            fim = novo;           // E também o fim
        } else {
            fim->prox = novo;     // O próximo do fim é o novo nó
            fim = novo;           // O novo nó se torna o fim
        }
        n++;
    }

    // Método para imprimir a lista
    void imprimir() {
        double soma = 0;
        No* aux = inicio;
        while (aux != NULL) {
            soma += aux->valor;
            if (soma <= 0.01) {
                printf("invalido\n");
                return;
            }
            aux = aux->prox;
        }
        if (soma >= 0.00) {
            printf("%2.f\n", soma);
        }
    }
};

int main() {
    Lista l;
    int qtd;
    double num;
    
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++) {
        scanf("%lf", &num);
        l.inserirFinal(num);
    }
    
    l.imprimir();
    
    return 0;
}
