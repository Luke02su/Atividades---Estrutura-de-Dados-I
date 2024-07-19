#include <stdio.h>
#include <limits.h>

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
    
    void imprimir() {
        No* aux = inicio;       // Inicia a partir do início
        while (aux != NULL) {   // Percorre até o fim da lista
            printf("%d\n", aux->valor);  // Imprime o valor do nó
            aux = aux->prox;    // Vai para o próximo nó
        }
    }
    
    // Método para ordenar a lista usando Bubble Sort em ordem crescente
    void ordenar() {
        if (n <= 1) return; // Se a lista está vazia ou tem um único elemento, já está ordenada
        
        bool trocado;
        do {
            trocado = false;
            No* atual = inicio;
            No* proximo = inicio->prox;
            
            while (proximo != NULL) {
                if (atual->valor > proximo->valor) {
                    // Trocar valores
                    int temp = atual->valor;
                    atual->valor = proximo->valor;
                    proximo->valor = temp;
                    trocado = true;
                }
                atual = proximo;
                proximo = proximo->prox;
            }
        } while (trocado);
    }
    
    // Método para ordenar a lista usando Bubble Sort em ordem decrescente
    void ordenarDecrescente() {
        if (n <= 1) return; // Se a lista está vazia ou tem um único elemento, já está ordenada
        
        bool trocado;
        do {
            trocado = false;
            No* atual = inicio;
            No* proximo = inicio->prox;
            
            while (proximo != NULL) {
                if (atual->valor < proximo->valor) {
                    // Trocar valores
                    int temp = atual->valor;
                    atual->valor = proximo->valor;
                    proximo->valor = temp;
                    trocado = true;
                }
                atual = proximo;
                proximo = proximo->prox;
            }
        } while (trocado);
    }
    
    // Método para juntar duas listas
    Lista juntar(Lista& outra) {
        Lista novaLista;       // Cria uma nova lista vazia
        No* aux = inicio;      // Começa a partir do início da lista original
        
        while (aux != NULL) {  // Percorre toda a lista original
            novaLista.inserirFinal(aux->valor); // Insere cada valor na nova lista
            aux = aux->prox;   // Vai para o próximo nó na lista original
        }
        
        aux = outra.inicio;    // Começa a partir do início da outra lista
        while (aux != NULL) {  // Percorre toda a outra lista
            novaLista.inserirFinal(aux->valor); // Insere cada valor na nova lista
            aux = aux->prox;   // Vai para o próximo nó na outra lista
        }
        
        return novaLista;      // Retorna a nova lista unida
    }
};

int main() {
    Lista l1, l2;
    int valor;
    int qtd1, qtd2;
    
    printf("Digite a quantidade de elementos para a primeira lista: ");
    scanf("%d", &qtd1);
    for (int i = 0; i < qtd1; i++) {
        printf("Digite o valor do elemento %d da primeira lista: ", i+1);
        scanf("%d", &valor);
        l1.inserirFinal(valor);
    }
    
    printf("Digite a quantidade de elementos para a segunda lista: ");
    scanf("%d", &qtd2);
    for (int i = 0; i < qtd2; i++) {
        printf("Digite o valor do elemento %d da segunda lista: ", i+1);
        scanf("%d", &valor);
        l2.inserirFinal(valor);
    }
    
    
    printf("\nPrimeira lista antes da ordenação:\n");
    l1.imprimir();
    
    printf("\nSegunda lista antes da ordenação:\n");
    l2.imprimir();
    
    printf("\nLista unida desordenada:\n");
    l1.imprimir();
    l2.imprimir();
    
    l1.ordenar();
    l2.ordenar();
    printf("\nPrimeira lista ordenada em ordem crescente:\n");
    l1.imprimir();
    
    printf("\nSegunda lista ordenada em ordem crescente:\n");
    l2.imprimir();
    
    // Juntando as duas listas
    Lista listaUnida = l1.juntar(l2);
    printf("\nLista unida ordenada:\n");
    listaUnida.imprimir();
    
    
    return 0;
}
