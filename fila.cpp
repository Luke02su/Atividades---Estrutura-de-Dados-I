#include <stdio.h>
#include <limits.h>

struct No {
    int valor; 
    No* prox; 

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Lista {
    No* inicio;
    No* fim;    
    int n;    

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

    void imprimir() {
        
        No* aux = inicio;
        
        while (aux != NULL) {
            if (aux->valor >= 65) {
                 printf("%d ", aux->valor);
            } 
            aux = aux->prox;
        }
    }
    
    void imprimir2() {
        
        No* aux = inicio;
        
        while (aux != NULL) {
            if (aux->valor < 65) {
                printf("%d ", aux->valor);
            }
            aux = aux->prox;
        }
    }
    
    
};

int main() {
    Lista l;
    int qtd1, qtd2;
    int num;
    
    scanf("%d", &qtd1);
    for (int i = 0; i < qtd1; i++) {
        scanf("%d", &num);
        l.inserirFinal(num);
    }
    
    scanf("%d", &qtd2);
    for (int i = 0; i < qtd2; i++) {
        scanf("%d", &num);
        l.inserirFinal(num);
    }
    
    l.imprimir();
    l.imprimir2();
    
    return 0;
}