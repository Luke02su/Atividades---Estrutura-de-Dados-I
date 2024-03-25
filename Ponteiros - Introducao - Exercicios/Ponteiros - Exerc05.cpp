#include<stdio.h>

void funcao(int vet[], int tam, int **min, int **max) {	
	
	*min = &vet[0];
	*max = &vet[0];
	
	for(int i = 0; i < tam; i++) {
		printf("Vet %d[%d] \t Endereco: %d\n", vet[i], i+1, &vet[i]);
		if(vet[i] > **max) {
			*max = &vet[i];
		} else if(vet[i] < **min) {
			*min = &vet[i];
		}
	}

    printf("Menor elemento: %d \t Endereco: %d", **min, *min);
   	printf("\nMaior elemento: %d \t Endereco: %d\n", **max, *max);
}

int main() {
	
	int tam = 10;
	int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *min, *max;
	
	funcao(vet, tam, &min, &max);
}
