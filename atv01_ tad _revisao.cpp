#include<stdio.h>
#define MAX_LIVROS 10

struct Livro {
    
    char autor[100], titulo[100];
    int numPaginas;
    
    void ler () {
        printf("Autor: \n");
        scanf("%s", autor);
        printf("Titulo: \n");
        scanf("%s", titulo);
        printf("Numero de paginas: \n");
        scanf("%d", &numPaginas);
    }
    
    void imprimir () {
        printf("Autor: %s\n", autor);
        printf("Titulo: %s\n", titulo);
        printf("Numero de paginas: %d\n", numPaginas);
    }
};

struct Biblioteca {
    
    Livro livros[MAX_LIVROS];
    int qtdLivros = 0;
  
    void ler () {
        if (qtdLivros >= MAX_LIVROS) {
            printf("Biblioteca cheia.\n");
            return;
        }
        livros[qtdLivros].ler();
        qtdLivros++;
    }
  
    void imprimir () {
      
        if (qtdLivros == 0) {
            printf("Biblioteca vazia.\n");
            return;
        }
      
        for (int i = 0; i < qtdLivros; i++) {
            livros[i].imprimir();
        }
    }
  
    void maiorPagina () {
      
        int maiorNumPaginas = livros[0].numPaginas;
        int livro = 0;
         
        if (qtdLivros == 0) {
              printf("Biblioteca vazia.\n");
              return;
        }
         
        for (int i = 1; i < qtdLivros; i++) {
            if (maiorNumPaginas < livros[i].numPaginas) {
                maiorNumPaginas = livros[i].numPaginas;
                livro = i;
            }
        }
     livros[livro].imprimir();
    }
};

int main () {
    
    Biblioteca b;
    int opcao;
    
    do {
        
        printf("1. Ler livro.\n");
        printf("2. Imprimir livros.\n");
        printf("3. Imprimir livro c/ maior numero de paginas.\n");
        printf("4. Sair\n");
           
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                b.ler();
                break;
            
            case 2:
                b.imprimir();
                break;
            
            case 3:
                b.maiorPagina();
                break;
        }
    } while (opcao != 4);
    
    return 0;
}