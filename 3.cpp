#include<stdio.h>

struct Conjunto {
	
	int tamanho1;
	int ele1[100];
	int tamanho2;
	int ele2[100];
	int i, j, k;
	int vazio=0;
	int contConj=0;
	int encontrado;
	int ele;
	int duplicado;

    void criarConjuntoVazio() {
    	printf("\nConjunto vazio criado.\n\n");
    	vazio++;
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
		contConj++;
		printf("\n");
    }

    void uniaoDoisConjuntos() {
    	
    	if(contConj == 0) {
    		printf("\nNenhum conjunto cadastrado\n\n");
    		return;
		}
		
       	printf("\nUniao dos conjuntos A e B: ");
        printf("{ ");
        for (i = 0; i < tamanho1; i++) {
        	if(ele1[i] != ele1[i-1]) {
            	printf("%d ", ele1[i]);
			}
        }

        for (j = 0; j < tamanho2; j++) {
            ele = ele2[j];
            encontrado = 0;
            for (k = 0; k < tamanho1; k++) {
                if (ele1[k] == ele) {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("%d ", ele);
            }
        }
        printf("}");
        printf("\n\n");
    }

    void intersecaoDoisConjuntos() {
    	
    	if(contConj == 0) {
    		printf("\nNenhum conjunto cadastrado\n\n");
    		return;
		}
    	
    	printf("\nIntersecao dos conjuntos A e B: ");
    	printf("{ ");
		for(i = 0; i < tamanho1; i++) {
			for(j = 0; j < tamanho2; j++) {
				if(ele1[i] == ele2[j]) {
					duplicado = 0;
              		for (k = 0; k < i; k++) {
                  		if (ele1[i] == ele1[k]) {
                        	duplicado = 1;
                        	break;
                    	}
               		}
              		if (!duplicado) {
                    	printf("%d ", ele1[i]);
              		}
          	 	}
			}
		}
		printf("}");
		printf("\n\n");
	}

    void imprimirConjunto() {
    	
    	if(contConj == 0 && vazio == 0) {
    		printf("\nNenhum conjunto cadastrado\n\n");
    		return;
		}
		
		if(vazio > 0) {
    		printf("\nConjunto vazio: { }\n");
		}

		if(contConj > 0) {
			printf("Conjunto A: ");
			printf("{ ");
			for(i = 0; i < tamanho1; i++) {
				printf("%d ", ele1[i]);
			}
			printf("}");
	
			printf("\nConjunto B: ");
			printf("{ ");
			for(j = 0; j < tamanho2; j++) {
				printf("%d ", ele2[j]);
			}
			printf("}");
		printf("\n\n");	
		}
	}
};

int main() {

    Conjunto c;
    int opcao;

    do{

        printf("1. Criar um conjunto vazio\n2. Ler os dados de dois conjuntos\n3. Fazer a uniao de dois conjuntos\n4. Fazer a intersecao de dois conjuntos\n5. Imprimir conjuntos\n6. Sair do programa\n\n");
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
