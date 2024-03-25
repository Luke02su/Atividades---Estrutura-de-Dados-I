#include<stdio.h>

int maiorEndereco(int *p1, int *p2) {
	
	printf("\nEndereco da primeira variavel: %d\n", p1); // imprime o endereco da variável apontada (&p1 seria o endereço do ponteiro)
	printf("Endereco da segunda variavel: %d\n\n", p2); // imprime o endereco da variável apontada (&p2 seria o endereço do ponteiro)
	
	if(p1 > p2) {
		printf("Maior endereco: %d\nValor: %d", p1, *p1); // imprime o endereco da variável apontada e o valor dela
	} else {
		printf("Maior endereco: %d\nValor: %d", p2, *p2); // imprime o endereco da variável apontada e o valor dela
	}
}

int main() {
	
	int x, y;
	
	printf("Primeira variavel: ");
	scanf("%d", &x);
	//printf("%d", &x); seria uma forma de imprimir ao endereco da variavel, mas sem armazená-lo em um ponteiro
	
	printf("Segunda variavel: ");
	scanf("%d", &y);
	//printf("%d", &y); seria uma forma de imprimir ao endereco da variavel, mas sem armazená-lo em um ponteiro
	
	int *p1 = &x; // atribui endereco e o valor ao ponteiro;
	int *p2 = &y;  // atribui endereco e o valor ao ponteiro;
	
	maiorEndereco(p1, p2);
	
	return 0;
}
