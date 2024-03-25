#include<stdio.h>

void partIntPartFra(float *pNum, float *a, float *b) { // desde que seja em ordem, o nome das variaveis pode mudar
	
	//*partInt e *partFra, a partir do endereço, obtêm o endreço e o valor
	
	*a = (int)*pNum; // converte float int
	*b = *pNum - *a;
	
	//*a == partInt
    //*b == partFra
    //a == &partInt
    //b == &partFra
    
}

int main() {
	
	float num = 3.2;
	float *pNum = &num;
	float partInt, partFra;
	
	partIntPartFra(pNum, &partInt, &partFra); // passa ponteiro p, endereco de partInt e partFra
	
	printf("Numero: %.2f \t\tEndereco: %d\n", *pNum, pNum); // imprime o valor do ponteiro e o seu endereço
	printf("Parte inteira: %.0f\tEndereco: %d\n", partInt, &partInt); // imprime o valor da variavel e seu endereço
	printf("Parte fracionaria: %.2f\tEndereco: %d\n", partFra, &partFra); // imprime o valor da variavel e seu endereço
	
	return 0;
}
