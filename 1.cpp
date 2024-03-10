#include<stdio.h>
#include<time.h>

struct Data {

 	int dia=0;
    int mes=0;
    int ano=0;
    int idade=0;

    void calcularIdade() {

        time_t t = time(nullptr); // Obter a data atual
        struct tm *dataAtual = localtime(&t); // Obter a data atual

        int diaAtual = dataAtual->tm_mday;
        int mesAtual = dataAtual->tm_mon + 1;
        int anoAtual = dataAtual->tm_year + 1900;

    	idade = anoAtual - ano;
  	        if(mesAtual < mes || (mesAtual == mes && diaAtual < dia)) {
                idade -= 1;
		}
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

		printf("\nDigite o nome: ");
		scanf(" %[^\n]%*c", nome[qtdCliente]);
        printf("Digite a data de nascimento (de espacos e nao inclua 0 antecedendo dia e mes): ");
	   	scanf("%d%*c", &data[qtdCliente].dia);
		scanf("%d%*c", &data[qtdCliente].mes);
		scanf("%d%*c", &data[qtdCliente].ano);
		do {
		       printf("Digite o sexo (H ou M): ");
			   scanf(" %c%*c", &sexo[qtdCliente]);
		} while (sexo[qtdCliente] != 'H' && sexo[qtdCliente] != 'M');

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
