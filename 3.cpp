#include<stdio.h>

struct Conjunto {

    void criarConjuntoVazio() {


    }

    void lerDadosConjunto() {




    }

    void uniaoDoisConjuntos() {



    }

    void intersecaoDoisConjuntos() {



    }

    void imprimirConjunto() {



    }



};

int main() {

    Conjunto c;
    int opcao;

    do{

        printf("");
        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1: {
                c.criarConjuntoVazio();
                break;
            }
            case 2: {
                c.lerDadosConjunto();
                break;
            }
            case 3: {
                c.uniaoDoisConjuntos();
                break;
            }
            case 4: {
                c.intersecaoDoisConjuntos();
                break;
            }
            case 5: {
                c.imprimirConjunto();
                break;
            }


        }

    } while(opcao != 6);

    return 0;
}
