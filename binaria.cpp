#include<stdio.h>

struct No { // criando a struct di nó
    
    int valor; // criando valor
    No* prox;
    No* temp;// criando ponteiro para apontar para o próximo
    
    No() { // iniciando construtor
        valor = 0; // atribuindo valor criado igual a 0;
        prox = NULL; // atribuindo o prox como nulo
    }
    
    No(int _valor) { // iniciando construtor com passagem de parâmetro
        valor = _valor; // atribuindo ao valor o valor passado na passagem de parâmetro
        prox = NULL; // atribuindo o prox como nulo
    }
};

struct Pilha { // criando struct de pilha
    
    No* topo; // criando um No do tipo ponteiro topo
    int n; // crinando n para contar o tamanho da pilha
    
    Pilha() { // criando um construtor
        topo = NULL; // atribuindo topo como nulo
        n = 0; // atribuindo n = 0;
    }
    
    void inserir(int valor) { // criando função sem retorno com passagem de parâmetro em que se passa valor
        No* novo = new No(valor); // criando um novo No do tipo ponteiro novo
        if (topo == NULL) { // se o topo for nulo
            topo = novo; // novo no criado é atribuído ao topo
        } else { // senão 
            novo->prox = topo; // o novo aponta para o próximo, que recebe o topo
            topo = novo; // o topo atual recebe novo
        }
        n++; // incrementa a pilha
    }
    
    void remover() { // função sem retorno  para remover
        if (n == 0) return; // se n for igual a 0 retorna
        if (n == 1) { // se n for igual a 1
            delete(topo); // deleta topo
            topo = NULL; // deixa-o como nulo
            n--; // decrementa a pilha
            return; // retorna
        }
        
        No* aux = topo; //se for maioe que 1, cria no do tipo ponteiro aux, que recebe topo
        topo = topo->prox; // topo recebe o próximo de topo
        delete(aux); // deleta o aux, que recebeu topo
        n--; // decrementa lista
    }
    
    int topoPilha() {
        if (topo == NULL) return 0; // se topo for NULL, retorna 0
        return topo->valor; // se a pilha não estiver vazia, o topo aponta para valor, retornando-o
    }
    
    void imprimir() {
        No* aux = topo; // atribui ao no aux o topo
        while(aux != NULL) { // enquanto aux 
            printf("%d\n", aux->valor); // printa o valor apontado pelo aux
            aux = aux->prox; // aux recebe o próximo de aux
        }
    }
};

struct Fila {
    
    No* inicio; // cria nó do ponteiro de inicio
    No* fim; // cria nó do ponteiro de fim
    int n; // incrementa a Fila
    int soma[1000];
    
    Fila() { // cria construtor de Fila
        inicio = NULL; // inicio inicia como null
        fim = NULL; // fim inicia como null
        n = 0; // n recebe 0
    }
    
    void enfileirar(int valor) { // função sem retorno com passagem de parâmetro
        No* novo = new No(valor); // criando um objeto novo No do tipo ponteiro novo, havendo passagem de valor
        if (inicio == NULL) { // se inicio igual a NULL
            inicio = novo; // inicio recebe novo
            fim = novo; // fim recebe novo
        } else {
            fim->prox = novo; // fim aponta para o proximo que recebe o novo atual
            fim = novo; // o fim recebe novo
        }
        n++; // incrementa a fila
    }
    
    void desenfileirar() {
        No* temp;
        if (n == 0) return; // retorna se a fila for igual a 0
        if (n == 1) { // se a fila for igual a 1 
            delete(inicio); // deleta inicio
            inicio = NULL; // inicio fica nulo
            fim = NULL; // fim fica nulo
            n = 0; // tamanho da fila fica zerada 
            return; // retorna
        }
        No* aux = inicio; // cria-se um no de ponteiro aux, que recebe inicio
        inicio = inicio->prox; // inicio rcebe o próximo de inicio
        delete(aux); // apaga o aux que contém o inicio
        n--; // decrementa fila
    }
    
    int frente() { // funcao com retorno int
        if (inicio == NULL) return 0; //se inicio for igual a null retorna 0
        return inicio->valor; // senão, retorna o valor apontado pelo inicio
    }
    
    void imprimir() {
        Pilha p;
        int i = 0;
        No* aux = inicio; // atribui ao no aux o topo
        while(aux != NULL) { // enquanto aux 
            while(aux->valor > 0) {
                soma[i] = aux->valor % 2; // Calcula o resto da divisão por 2 (que é 0 ou 1)
                i++; // Incrementa o índice para armazenar o próximo dígito binário
                aux->valor = aux->valor / 2;
                
            }           
            for(int j = i-1 ; j >= 0; j--) {
                printf("%d", soma[j]); // Mostra os dígitos binários na ordem correta
            }
            printf("\n");
            
            i = 0;
            aux = aux->prox;
        }
            
    }
    
    void inverterFila() {
        
    /*Considere uma pilha P vazia e uma fila F não vazia.
    Utilizando apenas as operações inserir/enfileirar e remover/desenfileirar de 
    ambas as estruturas, escreva uma função que inverta a ordem dos elementos da fila.*/
        
        Pilha p; // cria um objeto de fila
        
        while (n > 0) { // enquanto tamanho da fila for maior que 0
            p.inserir(frente()); // inre na pilha o inicio (frente) da fila
            desenfileirar(); // apaga o elemento da fila em seguida
        }
        while (p.n > 0) { // enquanto o tamanho da pilha for maior que 0
            enfileirar(p.topoPilha()); // insere na fila o topo da fila (que seria o último elemento da lista), inertendo, desse modo
            p.remover(); // remove o elemento da pilha em seguida
        }
    }
};

int main() {
    
    // A pilha empilha os valores. Remove-se o topo da pilha; (LIFO: último a chegar, primeiro a sair)
    // A fila enfila os valores. Remove o inicio da fila; (FIFO: primeiro a chegar, primeiro a sair)
    
    Fila f; // cria um objeto de fila
    int n, m;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        f.enfileirar(m);
    }
    
    printf("\n");
    
    f.imprimir();
    
    return 0;
}