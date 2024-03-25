#include<stdio.h>

int main() {
	
	int i;
	float vet[10] = {12.2, 32.3, 31.0, 1.2, 231.2, 5632.9, 31.98, 0.32, 9.7, 10.21}; // 10 elementos float
	float *p = vet; // vet atribui valor e endereco ao ponteiro p;
	
	for(i = 0; i < 10; i++) {
		printf("Vetor[%d] = %.2f \tPosicao: %d\n", i+1, vet[i], p);
		p++; // incrementa a posicao dos ponteiros (4 bytes)
	}
	
	return 0;
}
