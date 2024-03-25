#include<stdio.h>

void vetor(int vet[], int tam, int **min, int **max) { //ponteiros **min e **max refenciam ponteiros *min e *max

	*min = vet; // atribuindo endereço ao ponteiro
	*max = vet; //atribuindo endereço ao ponteiro

	for(int i = 0; i < tam; i++) {
		printf("Vet %d[%d] \t Endereco: %d\n", vet[i], i+1, &vet[i]);
		if(vet[i] > **max) { //
			*max = &vet[i]; //*max armazena endereço do maior vetor
		} else if(vet[i] < **min) {
			*min = &vet[i]; //*min armazena endereço do menor vetor
		}
	}

    printf("Menor elemento: %d \t Endereco: %d", **min, *min); //**min imprime valor e *min endereço
   	printf("\nMaior elemento: %d \t Endereco: %d\n", **max, *max); //**min imprime valor e *min endereço
}

int main() {

	int tam = 10;
	int vet[10] = {10, 9, 8, 777, 6, 5, -4, 3, 2, 1};
    int *min, *max; // criando ponteiros

	vetor(vet, tam, &min, &max); // passando variáveis e endereços dos ponteiros (&min e &max são passados assim para serem modificados por **min e **max)
}
