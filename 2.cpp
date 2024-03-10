#include<stdio.h>

struct Loja {
	
	char nome[10][100];
	char cargo[10][100];
	double salarioBase[10];
	double beneficios[10];
	double descontos[10];
	double salarioLiquido[10];
	int qtdFunc=0;
	int i=0;
	
	void cadastrar() {
		
		if(qtdFunc >= 10) {
			printf("\nMaximo de funcionarios cadastrados (10).\n\n");
			return;
		} 
		  	printf("\nDigite um nome: ");
	        scanf(" %[^\n]%*c", nome[qtdFunc]);
            printf("Digite o cargo: ");
            scanf(" %[^\n]%*c", cargo[qtdFunc]);
	        printf("Digite o salario base: ");
	        scanf("%lf%*c", &salarioBase[qtdFunc]);
	        printf("Digite os beneficios: ");
	        scanf("%lf%*c", &beneficios[qtdFunc]);
			printf("Digite os descontos: ");
			scanf("%lf%*c", &descontos[qtdFunc]);
			
			printf("\n");
			
			qtdFunc++;
	}
	
	void imprimir() {
		
		if(qtdFunc == 0) {
			printf("\nNenhum funcionario cadastrado.\n\n");
		}
		
		calcularSalarioLiquido();
		
		for(i = 0; i < qtdFunc; i++) {
            printf("\nNome: %s\n", nome[i]);
	        printf("Cargo: %s\n", cargo[i]);
			printf("Salario base: %.2lf\n", salarioBase[i]);
            printf("Beneficios: %.2lf\n", beneficios[i]);
		    printf("Descontos: %.2lf\n", descontos[i]);
		    printf("Salario liquido: %.2lf\n\n", salarioLiquido[i]);
		}
	}

	void calcularSalarioLiquido() {
		for(i = 0; i < qtdFunc; i++) {
		    salarioLiquido[i] = (salarioBase[i] + beneficios[i]) - descontos[i];
		}
	}
	
	void mediaSalarial() {
		
		if(qtdFunc == 0) {
			printf("\nNenhum salario cadastrado para calcular a media salarial.\n\n");
			return;
		}
		
		double media=0;
		calcularSalarioLiquido();
		
		for(i = 0; i < qtdFunc; i++) {
			media = (salarioLiquido[i] + salarioLiquido[i-1]) / qtdFunc;
		}
		printf("\nMedia salarial da loja: %.2lf\n\n", media);	
	}
	
	void maiorSalario() {
		
		if(qtdFunc == 0) {
			printf("\nNenhum salario cadastrado para calcular o maior salario.\n\n");
			return;
		}
		
		int maior=0;
		int posicao=0;
		calcularSalarioLiquido();
		
		for(i = 0; i < qtdFunc; i++) {
			if(salarioLiquido[i] > maior) {
				maior = salarioLiquido[i];
				posicao = i;
			}
		}
		 printf("Nome: %s\n", nome[posicao]);
   		 printf("Cargo: %s\n", cargo[posicao]);
		 printf("Salario base: %.2lf\n", salarioBase[posicao]);
         printf("Beneficios: %.2lf\n", beneficios[posicao]);
         printf("Descontos: %.2lf\n", descontos[posicao]);
         printf("Salario liquido: %.2lf\n", salarioLiquido[posicao]);	
         
         printf("\n");
	}
	
};

int main() {
	
	Loja l;
	int opcao;
	
	do {
		printf("1. Cadastrar funcionario\n2. Listar funcionario(s)\n3. Media salarial da loja\n4. Funcionario com maior salario\n5. Sair do programa\n\n");
		scanf("%d%*c", &opcao);
		
		switch(opcao) {
			case 1: {
				l.cadastrar(); 
				break;
			}
			case 2:  {
		        l.imprimir();
		        break;
			}
		    case 3:  {
		        l.mediaSalarial();
		        break;
		 	}
	 		 case 4: {
	 		 	l.maiorSalario();
	 		 	break;
 		    } 
		}
	} while (opcao != 5);
	
	return 0;
}
