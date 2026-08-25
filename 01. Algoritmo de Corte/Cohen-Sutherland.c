#include <stdio.h>

/* typedef int ForaPP;

const int ESQUERDA = 0b0001;
const int DIREITA = 0b0010;
const int CIMA = 0b1000;
const int BAIXO = 0b0100;
const int DENTRO = 0b0000; */

float xmin;
float xmax;
float ymin;
float ymax;

/* ForaPP VerificarCorte (double x, double y){

} */

int main (){

    printf("Digite a coordernada X mínima da sua tela: "); fflush(stdout); scanf(" %f", &xmin);
    printf("Digite a coordernada X máxima da sua tela: "); fflush(stdout); scanf(" %f", &xmax);
    printf("Digite a coordernada Y mínima da sua tela: "); fflush(stdout); scanf(" %f", &ymin);
    printf("Digite a coordernada Y máxima da sua tela: "); fflush(stdout); scanf(" %f", &ymax);

    printf("\nA coordernada X mínima da sua tela é: %.2f\n", xmin);
    printf("A coordernada X máxima da sua tela é: %.2f\n", xmax);
    printf("A coordernada Y mínima da sua tela é: %.2f\n", ymin);
    printf("A coordernada Y máxima da sua tela é: %.2f\n", ymax);

    return 0;
}