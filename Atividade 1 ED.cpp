#include<stdio.h>
#include<stdlib.h>

struct Livro {
	
	char titulo[20], autor[20];
	int pagina;
	
	void lerDados() {
		
		printf("Digite o titulo do livro: \n");
		scanf("%s", &titulo);
		printf("Digite o nome do autor: \n");
		scanf("%s", &autor);
		printf("Digite a quantidade de paginas: \n");
		scanf("%d", &pagina);
	}
	
	void imprimirDados() {
		
		printf("Titulo: %s\n", titulo);
		printf("Autor: %s\n", autor);
		printf("Quantidade de paginas: %d\n", pagina);
	
	}
};

struct Biblioteca {
	
	int qtdLivros=0;
	int contLivros=0;
	int opcao;
	int maior=0;

	Livro dados[10];
	
	void lerLivros() {
		
		printf("Digite quantos livros deseja ler -- ate 10: \n");
		scanf("%d", &qtdLivros);
		qtdLivros += contLivros;
		if(qtdLivros <= 10) {
			for(int i = 0; i < qtdLivros; i++) {
				dados[i].lerDados();
				contLivros++;	
			}
		} else {
			printf("Nao eh possivel ler mais do que dez (10) livros.\n");
			imprimirMenu();
		}
	}
	
	void lerNovoLivro() {
	
		if(qtdLivros < 10) {
		printf("Escolha uma opcao:\n1 - Ler mais livros.\n2 - Retornar\n"); 
			scanf("%d", &opcao);
			switch(opcao) {
				case 1: {
					lerLivros();
					imprimirMenu();
					break;
				}
				case 2: {
					imprimirMenu();
					break;
				}
			}
		}
	}
		
	void imprimirLivros() {
		
		if(qtdLivros <= 10) {
			for(int i = 0; i < qtdLivros; i++) {
				dados[i].imprimirDados();
				if (dados[i].pagina > maior) {
                    maior = dados[i].pagina;
                }
			}
		} else {
			printf("Nao ha livros registrados.\n");
		}
		imprimirMenu();
	}

	void imprimirMaiorPagina() {
		
		if(qtdLivros <= 10) {
		printf("Livro com o maior numero de paginas:\n");
			for (int i = 0; i < qtdLivros; i++) {
				if (dados[i].pagina > maior) {
                    maior = dados[i].pagina;
                }
			}
            for (int i = 0; i < qtdLivros; i++) {
					if (dados[i].pagina == maior) {
                    dados[i].imprimirDados();
                }
			}
		} else {
			printf("Nao ha livros registrados.\n");
		}
		imprimirMenu();
	}

	void imprimirMenu() {
	
		int selecao, pagina;
	
		printf("1 - Registar livros\n2 - Imprimir todos os livros\n3 - Imprimir livro com o maior numero de paginas\n4 - Sair do programa.\n");
		scanf("%d", &selecao);
		switch(selecao) {
			case 1: {
				lerLivros();
				lerNovoLivro();
				break;
			} case 2: { 
				imprimirLivros();
				break;
			} case 3: {
				imprimirMaiorPagina();
				break;
			} case 4: {
				system("pause");
				break;
			}
		}		
	}
};
	
int main() {

	Biblioteca b;
	
	b.imprimirMenu();
	
	return 0;
}
