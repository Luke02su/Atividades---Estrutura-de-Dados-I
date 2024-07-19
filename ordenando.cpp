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
        No* atual = inicio;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
};

// Função para combinar duas listas ordenadas em uma terceira lista ordenada
Lista combinarListasOrdenadas(Lista &lista1, Lista &lista2) {
    Lista listaCombinada;
    No* atual1 = lista1.inicio;
    No* atual2 = lista2.inicio;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->valor <= atual2->valor) {
            listaCombinada.inserirFinal(atual1->valor);
            atual1 = atual1->prox;
        } else {
            listaCombinada.inserirFinal(atual2->valor);
            atual2 = atual2->prox;
        }
    }

    while (atual1 != NULL) {
        listaCombinada.inserirFinal(atual1->valor);
        atual1 = atual1->prox;
    }

    while (atual2 != NULL) {
        listaCombinada.inserirFinal(atual2->valor);
        atual2 = atual2->prox;
    }

    return listaCombinada;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    Lista lista1;
    Lista lista2;
    
    int valor;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &valor);
        lista1.inserirFinal(valor);
    }
    
    for (int i = 0; i < M; ++i) {
        scanf("%d", &valor);
        lista2.inserirFinal(valor);
    }
    
    Lista listaCombinada = combinarListasOrdenadas(lista1, lista2);
    
    listaCombinada.imprimir();
    
    return 0;
}
