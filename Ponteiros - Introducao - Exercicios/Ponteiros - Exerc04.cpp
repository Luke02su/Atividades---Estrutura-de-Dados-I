#include<stdio.h>
#include<math.h>
#define pi 3.14

void areaVolumeSE (double *p1, double *p2, double *p3) { //parÂmetros passados
	
	*p2 = (4 * pi) * pow(*p1, 2); // calculo para ponteiro *p2 que retornará para A
    *p3 = (4/3 * pi) * pow(*p1, 3); // calculo para ponteiro *p3 que retornará para B
    
    //*p2 == A
    //*p3 == B
    //p2 == &A
    //p3 == &B
    
   // printf("\n%d\n", p2);
   // printf("%d\n", p3);
    
   // printf("\n%.2lf\n", *p2);
   // printf("%.2lf\n", *p3);
}

int main() {
	
	double r;
	double *p1 = &r;
	double A, B;
	
	printf("Digite o raio da esfera: ");
	scanf("%lf", &r);
	
	areaVolumeSE(p1, &A, &B); //passa ponteiro e os endereços de a e b
	
	printf("\nRaio da esfra: %.2lf \t\t\tEndereco: %d\n", *p1, p1); // imprime o valor do ponteiro e o seu endereço
	printf("Area da superficie da esfera: %.2lf \tEndereco: %d\n", A, &A);  // imprime o valor da variavel e seu endereço
	printf("Volume da superficie da esfera: %.2lf \tEndereco: %d", B, &B);  // imprime o valor da variavel e seu endereço
	
	return 0;
}
