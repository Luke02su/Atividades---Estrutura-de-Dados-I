#include<stdio.h>

struct Livro { // 2 funções void
	
	char titulo[20], autor[20];
	int pagina;
	
	void lerDados() {
		
		printf("\nDigite o titulo do livro: ");
		scanf(" %[^\n]%*c", titulo);
		printf("Digite o nome do autor: ");
		scanf(" %[^\n]%*c", autor);
		printf("Digite a quantidade de paginas: ");
		scanf("%d", &pagina);
	}
	
	void imprimirDados() {
		
		printf("\nTitulo: %s\n", titulo);
		printf("Autor: %s\n", autor);
		printf("Quantidade de paginas: %d\n", pagina);
	}
};

struct Biblioteca {
	
	int i;
	int qtdLivros=0;
	int contLivros=0;
	int opcao=0;
	int maior=0;
	Livro dados[10];
	
	void lerLivros() {
        printf("\nDigite quantos livros deseja ler -- ate 10: ");
        scanf("%d", &qtdLivros);
        if (contLivros + qtdLivros <= 10) {
         	for (i = contLivros; i < contLivros + qtdLivros; i++) {
            	dados[i].lerDados();
    		}
        contLivros += qtdLivros;
    	} else {
          printf("\nNao eh possivel ler mais do que dez (10) livros.\n");
    }
}

		
	void imprimirLivros() {
		
		if(contLivros <= 10 && contLivros > 0) {
			printf("\nTodos os livros impressos:\n");
			for(i = 0; i < contLivros; i++) {
				dados[i].imprimirDados();
			}
		} else {
			printf("\nNao ha livros para imprimir.\n");
		}
	}

	void imprimirMaiorPagina() {
		
		maior=0;
		if(contLivros <= 10 && contLivros > 0) {
			printf("\nLivro com o maior numero de paginas:\n");
			for (i = 0; i < contLivros; i++) {
				if (dados[i].pagina > maior) {
                    maior = dados[i].pagina;
                }
			}
            for (i = 0; i < contLivros; i++) {
				if (dados[i].pagina == maior) {
                    dados[i].imprimirDados();
                }
			}
		} else {
			printf("\nNao ha livros registrados.\n");
		}
	}
};
	
int main() { //a struct biblioteca, que contém a struct livro, retorna para main

	Biblioteca b;
	int selecao=0;
	
	do { // é necessário o laço de repetição para o menu retornar
		printf("1 - Registar livros\n2 - Imprimir todos os livros\n3 - Imprimir livro com o maior numero de paginas\n4 - Sair do programa.\n\n");
		printf("Selecao: ");
		scanf("%d%*c", &selecao);
		
		switch(selecao) {
			case 1: {
				b.lerLivros();
				break;
			} case 2: { 
				b.imprimirLivros();
				break;
			} case 3: {
				b.imprimirMaiorPagina();
				break;
			}	
		}
		printf("\n");
	} while(selecao != 4);
	
	return 0;
}
