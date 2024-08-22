#include <string>
#include <iostream>

using namespace std;

struct No {
    string valor;
    No* prox;
    
    No() {
        valor = "NULL";
        prox = NULL;
    }
    
    No(string _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Fila {
    No* inicio;
    No* fim;
    int n;
    
    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }
    
    void enfileirar(string valor) {
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
    
    void desenfileirar() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }
    
    string frente() {
        if (inicio == NULL) return "NULL";
        return inicio->valor;
    }
    
    void diamantes() {
        No* aux = inicio;
        int cont = 0;
        int total = 0;
        while (aux != NULL) {
            for(char c : aux->valor) {
                if(c == '<') {
                    cont++;
                    
                } else if (cont > 0 && c == '>') {
                    cont--;
                    total++;
                }
            }
            
        printf("%d\n", total);
        cont = 0;
        total = 0;
        
        aux = aux->prox; 
        }
    }
};

int main() {
    Fila f;
    string s;
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        f.enfileirar(s);
    }

    f.diamantes();

    return 0;
}
