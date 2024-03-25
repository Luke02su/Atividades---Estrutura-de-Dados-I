#include<stdio.h>
#include<math.h>
#define pi 3.14

void areaVolumeSE (double *p1, double *p2, double *p3) { //par�metros passados

	*p2 = (4 * pi) * pow(*p1, 2); // calculo para ponteiro *p2 que retornar� para A
    *p3 = (4/3 * pi) * pow(*p1, 3); // calculo para ponteiro *p3 que retornar� para B

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

	areaVolumeSE(p1, &A, &B); //passa endere�o do ponteiro p1 e os endere�os de a e b

	printf("\nRaio da esfera: %.2lf \t\t\tEndereco: %d\n", *p1, p1); // imprime o valor do ponteiro e o seu endere�o (retorna r e &r)
	printf("Area da superficie da esfera: %.2lf \tEndereco: %d\n", A, &A);  // imprime o valor da variavel e seu endere�o (retorna *p2 e p2)
	printf("Volume da superficie da esfera: %.2lf \tEndereco: %d\n", B, &B);  // imprime o valor da variavel e seu endere�o (retorna *p3 e p3)

	return 0;
}
