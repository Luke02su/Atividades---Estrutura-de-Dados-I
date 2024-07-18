#include<stdio.h>
// Estrutura para representar um nó na lista
struct No {
    
    int valor; // Valor armazenado no nó
    No* prox; // Ponteiro para o próximo nó na lista
    
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

    // Método para remover o primeiro nó da lista
    void removerInicio() {
        if (n == 0) return;     // Se a lista está vazia, não faz nada
        if (n == 1) {           // Se a lista tem apenas um nó
            delete(inicio);     // Deleta o único nó
            inicio = NULL;      // Define inicio como NULL
            fim = NULL;         // Define fim como NULL
            n--;                // Decrementa o contador de nós
            return;
        }
        No* aux = inicio;       // Guarda o nó a ser removido
        inicio = inicio->prox;  // O novo início é o próximo nó
        delete(aux);            // Deleta o nó antigo
        n--;                    // Decrementa o contador de nós
    }
    
    // Método para remover o último nó da lista
    void removerFinal() {
        if (n == 0) return;     // Se a lista está vazia, não faz nada
        if (n == 1) {           // Se a lista tem apenas um nó
            delete(fim);        // Deleta o único nó
            inicio = NULL;      // Define inicio como NULL
            fim = NULL;         // Define fim como NULL
            n--;                // Decrementa o contador de nós
            return;
        }
        No* aux = inicio;            // Inicia a partir do início
        while (aux->prox != fim) {   // Encontra o penúltimo nó
            aux = aux->prox;
        }
        delete(fim);                // Deleta o último nó
        fim = aux;                  // O penúltimo nó se torna o fim
        aux->prox = NULL;           // O próximo do novo fim é NULL
        n--;                        // Decrementa o contador de nós
    }
    
    void imprimir() {
        No* aux = inicio;       // Inicia a partir do início
        while (aux != NULL) {   // Percorre até o fim da lista
            printf("%d\n", aux->valor);  // Imprime o valor do nó
            aux = aux->prox;    // Vai para o próximo nó
        }
    }
    
    // Criar um método que recebe um número X e remove os X últimos elementos da lista. Caso o tamanho da lista seja menor que X, esvaziar a lista.
    void removerNElementos(int x) {
        for (int i = 0; i < x && n > 0; i++) { 
            removerFinal();
        }
    }
    
    // 2. Crie um método que remove o segundo elemento da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.
    void removerSegundo() {
        if (n <= 1) return;             // Se a lista tem 0 ou 1 elemento, não faz nada
        if (n == 2) {                   // Se a lista tem 2 elementos
            removerFinal();             // Remove o segundo elemento (fim)
            return;
        }
        
        No* segundo = inicio->prox;      // Ponteiro para o segundo nó
        inicio->prox = segundo->prox;    // O próximo do primeiro nó é o terceiro nó
        delete(segundo);                 // Deleta o segundo nó
        n--;                             // Decrementa o contador de nós
    }
    
    //3. Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista.
    void inserirFinalTamanho() {
        inserirFinal(n);
    }
    
    //4. Crie um método que receba um número X e insira no final da lista todos os números de 1 até X.
    void inserirNumerosX(int x) {
        for (int i = 1; i <= x; i++) {
            inserirFinal(i);
        }
    }
    
    //5. Crie um método que insere um elemento sempre na penúltima posição da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.
    void inserirPenultima(int x) {
        if (n <= 1) return;         // Se a lista tem 0 ou 1 elemento, não faz nada
        
        No* aux = inicio;           // Inicia a partir do início
        while (aux->prox != fim) {  // Encontra o penúltimo nó
            aux = aux->prox;
        }
        
        No *novo = new No(x);      // Cria o novo nó com o valor dado
        aux->prox = novo;          // O próximo do penúltimo nó é o novo nó
        novo->prox = fim;          // O próximo do novo nó é o fim
        n++;
    }
};
    
int main() {
    
    Lista l;
    
    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(1);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);
    l.inserirFinal(4);
    l.removerInicio();
    l.removerInicio();
    l.removerFinal();
    l.removerFinal();
    l.removerNElementos(0);
    l.removerSegundo();
    l.inserirNumerosX(3);
    l.inserirPenultima(100);
    l.inserirFinalTamanho();
    l.imprimir();
    
    return 0;
}
