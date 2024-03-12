#include<stdio.h>

struct Conjunto {
	
	int tamanho1;
	int ele1[100];
	int tamanho2;
	int ele2[100];
	int i, j;
	int vazio=0;

    void criarConjuntoVazio() {
    	
    }

    void lerDadosConjunto() {
	
		printf("\nDigite o tamanho do conjunto A: ");
		scanf("%d%*c", &tamanho1);
		for(i = 0; i < tamanho1; i++) {
			scanf("%d%*c", &ele1[i]);
		}

		printf("\nDigite o tamanho do conjunto B: ");
		scanf("%d%*c", &tamanho2);
		for(j = 0; j < tamanho2; j++) {
			scanf("%d%*c", &ele2[j]);
		}
    }

    void uniaoDoisConjuntos() {
		
		printf("\nUniao dos conjuntos A e B:\n");
		for(i = 0; i < tamanho1; i++) {
			printf("%d ", ele1[i]);
		}
		
		for(j = 0; j < tamanho2; j++) {
			printf("%d ", ele2[j]);
		}

    }

    void intersecaoDoisConjuntos() {
    	
    	printf("\nIntersecao dos conjuntos A e B:\n");
		for(i = 0; i < tamanho1; i++) {
			for(j = 0; j < tamanho2; j++) {
				if(ele1[i] == ele2[j]) {
					printf("%d ", ele1[i]);
				}
			}
		}
		printf("\n");
    }

    void imprimirConjunto() {

		printf("\nConjunto A: ");
		for(i = 0; i < tamanho1; i++) {
			printf("%d ", ele1[i]);
		}
		printf("\nConjunto B: ");
		for(j = 0; j < tamanho2; j++) {
			printf("%d ", ele2[j]);
		}
		printf("\n");	
	}
};

int main() {

    Conjunto c;
    int opcao;

    do{

        printf("1. Criar um conjunto vazio\n2. Ler os dados de um conjunto\n3. Fazer a uniao de dois conjuntos\n4. Fazer a intersecao de dois conjuntos\n5. Imprimir um conjunto\n\n");
        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1: {
                c.criarConjuntoVazio();
                break;
            }
            case 2: {
                c.lerDadosConjunto();
                break;
            }
            case 3: {
                c.uniaoDoisConjuntos();
                break;
            }
            case 4: {
                c.intersecaoDoisConjuntos();
                break;
            }
            case 5: {
                c.imprimirConjunto();
                break;
            }
        }

    } while(opcao != 6);
    
    printf("\n");

    return 0;
}
