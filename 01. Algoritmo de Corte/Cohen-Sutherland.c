#include <stdio.h>

typedef int ForaPP;

const int DENTRO   = 0b0000;
const int ESQUERDA = 0b0001;
const int DIREITA  = 0b0010;
const int BAIXO    = 0b0100;
const int CIMA     = 0b1000;

float xmin;
float xmax;
float ymin;
float ymax;

ForaPP VerificarCorte(double x, double y)
{
    ForaPP codigoFora = DENTRO;

    if (x < xmin) {
        codigoFora |= ESQUERDA;
    }
    else if (x > xmax) {
        codigoFora |= DIREITA;
    }

    if (y < ymin) {
        codigoFora |= BAIXO;
    }
    else if (y > ymax) {
        codigoFora |= CIMA;
    }

    return (codigoFora);
}

int CohenSutherland(double *xa, double *ya, double *xb, double *yb)
{
    ForaPP codigoForaA = VerificarCorte(*xa, *ya);
    ForaPP codigoForaB = VerificarCorte(*xb, *yb);
    int retorno = 0;

    while (1) {
        if (!(codigoForaA | codigoForaB)) {
            retorno = 1;
            break;
        } else if (codigoForaA & codigoForaB) {
            break;
        } else {
            double x, y;

            ForaPP fora = codigoForaB > codigoForaA ? codigoForaB : codigoForaA;

            if (fora & CIMA) {
                x = *xa + (*xb - *xa) * (ymin - *ya) / (*yb - *ya);
                y = ymin;
            } else if (fora & BAIXO) {
                x = *xa + (*xb - *xa) * (ymax - *ya) / (*yb - *ya);
                y = ymax;
            } else if (fora & DIREITA) {
                y = *ya + (*yb - *ya) * (xmax - *xa) / (*xb - *xa);
                x = xmax;
            } else if (fora & ESQUERDA) {
                y = *ya + (*yb - *ya) * (xmin - *xa) / (*xb - *xa);
                x = xmin;
            }

            if (fora == codigoForaA) {
                *xa = x;
                *ya = y;
                codigoForaA = VerificarCorte(*xa, *ya);
            } else {
                *xb = x;
                *yb = y;
                codigoForaB = VerificarCorte(*xb, *yb);
            }
        }
    }
    return retorno;
}

int main(){
    double xa, xb, ya, yb;

    printf("Digite a coordernada X minima da sua tela: "); fflush(stdout); scanf(" %f", &xmin);
    printf("Digite a coordernada X maxima da sua tela: "); fflush(stdout); scanf(" %f", &xmax);
    printf("Digite a coordernada Y minima da sua tela: "); fflush(stdout); scanf(" %f", &ymin);
    printf("Digite a coordernada Y maxima da sua tela: "); fflush(stdout); scanf(" %f", &ymax);

    printf("Digite a coordernada X do ponto A da sua reta: "); fflush(stdout); scanf(" %lf", &xa);
    printf("Digite a coordernada X do ponto B da sua reta: "); fflush(stdout); scanf(" %lf", &xb);
    printf("Digite a coordernada Y do ponto A da sua reta: "); fflush(stdout); scanf(" %lf", &ya);
    printf("Digite a coordernada Y do ponto B da sua reta: "); fflush(stdout); scanf(" %lf", &yb);

    double xap = xa, yap = ya;
    double xbp = xb, ybp = yb;

    int visivel = CohenSutherland(&xap, &yap, &xbp, &ybp);

    printf("\n--- RESULTADO ---\n");
    if (visivel == 1) {
        printf("Reta visivel (total ou parcialmente).\n");
        printf("Ponto A original: (%.2lf, %.2lf)  ->  Pa processado: (%.2lf, %.2lf)\n", xa, ya, xap, yap);
        printf("Ponto B original: (%.2lf, %.2lf)  ->  Pb processado: (%.2lf, %.2lf)\n", xb, yb, xbp, ybp);
    } else {
        printf("A reta esta totalmente FORA da janela de visualizacao.\n");
    }

    return 0;
}