#include<stdio.h>

struct Data {
    
    int dia=0;
    int mes=0;
    int ano=0;
    int idade=0;
    int dataAtual = 2024;
    
    void calcularIdade() {
        idade = dataAtual - ano;
    }
    
};

struct Cliente {
	
	char nome[50][100];
	char sexo[50];
	int qtdCliente=0;
	Data data[50];
		
	void ler() {
		
		if(qtdCliente >= 10) {
			printf("\nMaximo de clientes cadastrados (50).\n\n");
			return;
		}
		
		printf("\nNome: ");
		scanf(" %[^\n]%*c", nome[qtdCliente]);
        printf("Data de nascimento: ");
	   	scanf("%d%*c", &data[qtdCliente].dia);
		scanf("%d%*c", &data[qtdCliente].mes);
		scanf("%d%*c", &data[qtdCliente].ano);
		printf("Sexo: ");
		scanf(" %c%*c", &sexo[qtdCliente]);
		
		printf("\n");
		
		data[qtdCliente].calcularIdade();
		qtdCliente++;
	}
	
	void imprimir() {
	
        if(qtdCliente == 0) {
        	printf("\nNenhum cliente cadastrado para ser impresso.\n\n");
        	return;
		}
		
		for(int i = 0; i < qtdCliente; i++) {
            printf("\nNome: %s\n", nome[i]);
  	        printf("Data de nascimento: %d/%d/%d\n", data[i].dia, data[i].mes, data[i].ano);
            printf("Idade: %d\n", data[i].idade);
            printf("Sexo: %c\n\n", sexo[i]);
        }
    }
};

int main() {
	
	Cliente c;
	int opcao;
	
	do {
	    printf("1. Cadastrar cliente.\n2. Listar clientes\n3. Sair do programa\n\n");
	    scanf("%d%*c", &opcao);
	    
		switch(opcao) {
			case 1: {
				c.ler();
				break;
			}
		case 2: {
				c.imprimir();
				break;
			}
		}
	} while(opcao != 3);
	
	return 0;
}
