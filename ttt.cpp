#include<string>
#include<iostream>

using namespace std;

struct No { // criando a struct di nó
    
    string valor; // criando valor
    No* prox;
    No* temp;// criando ponteiro para apontar para o próximo
    
    No() { // iniciando construtor
        valor = "NULL"; // atribuindo valor criado igual a 0;
        prox = NULL; // atribuindo o prox como nulo
    }
    
    No(string _valor) { // iniciando construtor com passagem de parâmetro
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
    
    void inserir(string valor) { // criando função sem retorno com passagem de parâmetro em que se passa valor
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
    
    string topoPilha() {
        if (topo == NULL) return "NULL"; // se topo for NULL, retorna 0
        return topo->valor; // se a pilha não estiver vazia, o topo aponta para valor, retornando-o
    }
    
    void parenteses() {
        int cont = 0;
        No* aux = topo; // atribui ao no aux o topo
        while(aux != NULL) { // enquanto aux 
            for(char c : aux->valor) {
                if (c == '(') {
                    if(c == ')') {
                        cont++;
                    }
                    cont++;
                }
                
                aux = aux->prox; // aux recebe o próximo de aux
            }
                  if (cont % 2 == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        }
    }
};





int main() {
    
    // A pilha empilha os valores. Remove-se o topo da pilha; (LIFO: último a chegar, primeiro a sair)
    // A fila enfila os valores. Remove o inicio da fila; (FIFO: primeiro a chegar, primeiro a sair)
    
    Pilha p;
    string s;
    int n = 1;
    
    for(int i; i < n; i++) {
        cin >> s;
        p.inserir(s);
    }
    
    p.parenteses();

    
    return 0;
}