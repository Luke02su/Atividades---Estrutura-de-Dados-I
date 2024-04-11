#include <stdio.h>
#define TAM 10 // pré-defido o tamanho do vetor para 10

void maiorElement(int vet[], int *pont1, int *pont2) { // passando parâmetros (vetor e ponteiros de min e max)
    *pont1 = vet[0]; // recebe o vetor da posição 0
    *pont2 = vet[0];

    for(int i = 1; i < TAM; i++) { // verifica menores e maiores da posição 1 a 10 (evitando erro para captar o menor ou maior caso iniciasse com 0, pois já foi inicializada)
        if(vet[i] < *pont1) {
            *pont1 = vet[i];
        } else if(vet[i] > *pont2) {
            *pont2 = vet[i];
        }
    }
}

int main() {
    
    int vet[TAM];
    int min, max;
    
    for(int i = 0; i < TAM; i++) { // lendo vetores de 0 até 9
         scanf("%d", &vet[i]);
    }
    
    maiorElement(vet, &min, &max); // passando parâmetros (endereço) e recebendo (valor de min e max)
    
    printf("Menor elemento: %d\n", min); // imprimindo menor vetor
    printf("Maior elemento: %d", max); // imprimindo maior vetor

    return 0;
}