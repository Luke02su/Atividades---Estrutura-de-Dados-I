#include<stdio.h>

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

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerInicio() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }
    
    void removerXElementosFinal(int x) { // passando x ((tamanho dos elementos a serem excluídos)) 1. Criar um método que recebe um número N e remove os N últimos elementos da lista. Caso o tamanho da lista seja menor que N, esvaziar a lista.
        if (n < x) { // n (tamanho da lista) menor que x (tamanho dos elementos a serem excluídos)
            for(int i = 0; i < n; i++) { // cont até o tamanho da lista
                removerInicio(); // apagando todos os elementos se x for maior que n
                n++; // incrementa o tamanho da lista pois nas funcoes inicio e remover é subtraído
            } 
        } else if (n >= x) { // n (tamanho da lista) maior que x ou igual x (tamanho dos elementos a serem excluídos)
            for(int i = 0; i < x; i++) { // cont até o tanto que deve ser excluido
                removerFinal(); // apagando todos os elentos da lista
            }
        }
    }
    
    void removerSegundoElemento() { // 2. Crie um método que remove o  segundo elemento da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada
        if (n <= 1) return; // se a lista for menor ou igual a 1, não faz nada

        No* primeiro = inicio; // ponteiro primeiro recebe inicio
        No* segundo = inicio->prox; // ponteiro segundo recebe o prox do inicio

        primeiro->prox = segundo->prox; // atualiza o ponteiro do primeiro elemento para pular o segundo elemento

        delete(segundo); // apaga o segundo
        n--; // decrementa o contador de elementos
    }

    void inserirFinalTamanhoLista() { // 3. Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista. 
        inserirFinal(n); // passando como parâmetro n (tamanho da lista)
    }
    
    
    void inserirVariosNumeros(int x) { // passando x (limite do cont) 4. Crie um método que receba um número N e insira na lista todos os números de 1 até N.
        for (int i = 1; i <= x; i++) {
            inserirFinal(i);
        }
    }
    
    // 5. Crie um método que insere um elemento sempre na penúltima posição da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.
    
    void inserirPenultimaPosicao() {
        if (n <= 1) return;
        
    
    }
    
    void imprimir() {
        No* aux = inicio;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
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
    //l.removerXElementosFinal(2);
    //l.removerSegundoElemento();
    //l.inserirFinalTamanh(oLista();
    //l.inserirVariosNumeros(5);
    l.imprimir();


    return 0;
}