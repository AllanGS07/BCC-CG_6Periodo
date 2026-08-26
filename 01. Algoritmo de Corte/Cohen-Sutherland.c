#include <stdio.h>

typedef int ForaPP;

const int DENTRO = 0b0000;
const int ESQUERDA = 0b0001;
const int DIREITA = 0b0010;
const int BAIXO = 0b0100;
const int CIMA = 0b1000;

float xmin;
float xmax;
float ymin;
float ymax;
int contadorIteracoes = 0;

ForaPP VerificarCorte(double x, double y)
{
    ForaPP codigoFora = DENTRO;

    if (x < xmin){
        codigoFora |= ESQUERDA;
    }
    else if (x > xmax){
        codigoFora |= DIREITA;
    }

    if (y < ymin){
        codigoFora |= BAIXO;
    }
    else if (y > ymax){
        codigoFora |= CIMA;
    }

    return (codigoFora);
}

void EscalonarPontos(double *xa, double *ya, double *xb, double *yb){
    double centroX = (xmin + xmax) / 2.0;
    double centroY = (ymin + ymax) / 2.0;

    while (VerificarCorte(*xa, *ya) != DENTRO || VerificarCorte(*xb, *yb) != DENTRO){
        *xa = (*xa - centroX) * 0.9 + centroX;
        *ya = (*ya - centroY) * 0.9 + centroY;
        *xb = (*xb - centroX) * 0.9 + centroX;
        *yb = (*yb - centroY) * 0.9 + centroY;
        contadorIteracoes++;
    }
}

void MoverPontos(double *xa, double *ya, double *xb, double *yb, double deslocamentoX, double deslocamentoY){
    *xa += deslocamentoX;
    *ya += deslocamentoY;
    *xb += deslocamentoX;
    *yb += deslocamentoY;
}

void AjustarPontosMovidos(double *xa, double *ya, double *xb, double *yb){
    double centroX = (xmin + xmax) / 2.0;
    double centroY = (ymin + ymax) / 2.0;

    contadorIteracoes = 0;
    while (VerificarCorte(*xa, *ya) != DENTRO || VerificarCorte(*xb, *yb) != DENTRO){
        if (VerificarCorte(*xa, *ya) != DENTRO){
            *xa = (*xa - centroX) * 0.9 + centroX;
            *ya = (*ya - centroY) * 0.9 + centroY;
        }
        if (VerificarCorte(*xb, *yb) != DENTRO){
            *xb = (*xb - centroX) * 0.9 + centroX;
            *yb = (*yb - centroY) * 0.9 + centroY;
        }
        contadorIteracoes++;
    }
}

int CohenSutherland(double *xa, double *ya, double *xb, double *yb)
{
    ForaPP codigoForaA = VerificarCorte(*xa, *ya);
    ForaPP codigoForaB = VerificarCorte(*xb, *yb);
    int retorno = 0;

    while (1)
    {
        if (!(codigoForaA | codigoForaB)){
            retorno = 1;
            break;
        } else if (codigoForaA & codigoForaB){
            break;
        } else{
            double x, y;
            ForaPP fora = codigoForaA != DENTRO ? codigoForaA : codigoForaB;

            if (fora & CIMA){
                x = *xa + (*xb - *xa) * (ymax - *ya) / (*yb - *ya);
                y = ymax;
            }
            else if (fora & BAIXO){
                x = *xa + (*xb - *xa) * (ymin - *ya) / (*yb - *ya);
                y = ymin;
            }
            else if (fora & DIREITA){
                y = *ya + (*yb - *ya) * (xmax - *xa) / (*xb - *xa);
                x = xmax;
            }
            else if (fora & ESQUERDA){
                y = *ya + (*yb - *ya) * (xmin - *xa) / (*xb - *xa);
                x = xmin;
            }

            if (fora == codigoForaA){
                *xa = x;
                *ya = y;
                codigoForaA = VerificarCorte(*xa, *ya);
            }
            else{
                *xb = x;
                *yb = y;
                codigoForaB = VerificarCorte(*xb, *yb);
            }
        }
    }
    return retorno;
}

void MostrarReta(const char *titulo, double xa, double ya, double xb, double yb){
    printf("\n-- %s --\n", titulo);
    printf("Pa: (%.2lf, %.2lf)\n", xa, ya);
    printf("Pb: (%.2lf, %.2lf)\n", xb, yb);
}

int main(){
    double xa, xb, ya, yb;
    int opcao;

    printf("Digite a coordenada X minima da sua tela: "); fflush(stdout); scanf(" %f", &xmin);
    printf("Digite a coordenada X maxima da sua tela: "); fflush(stdout); scanf(" %f", &xmax);
    printf("Digite a coordenada Y minima da sua tela: "); fflush(stdout); scanf(" %f", &ymin);
    printf("Digite a coordenada Y maxima da sua tela: "); fflush(stdout); scanf(" %f", &ymax);

    printf("Digite a coordenada X do ponto A da sua reta: "); fflush(stdout); scanf(" %lf", &xa);
    printf("Digite a coordenada X do ponto B da sua reta: "); fflush(stdout); scanf(" %lf", &xb);
    printf("Digite a coordenada Y do ponto A da sua reta: "); fflush(stdout); scanf(" %lf", &ya);
    printf("Digite a coordenada Y do ponto B da sua reta: "); fflush(stdout); scanf(" %lf", &yb);

    do {
        double xap = xa, yap = ya;
        double xbp = xb, ybp = yb;

        printf("\nEscolha uma operacao:\n");
        printf("1 - Cortar reta\n");
        printf("2 - Mover reta\n");
        printf("3 - Escalonar reta\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);

        if (opcao == 1){
            int visivel = CohenSutherland(&xap, &yap, &xbp, &ybp);

            if (visivel == 1){
                MostrarReta("RESULTADO DO RECORTE", xap, yap, xbp, ybp);
            }
            else{
                printf("\nA reta esta totalmente FORA da janela de visualizacao.\n");
            }
        }
        else if (opcao == 2){
            double deslocamentoX, deslocamentoY;

            printf("Digite o deslocamento em X: ");
            scanf(" %lf", &deslocamentoX);
            printf("Digite o deslocamento em Y: ");
            scanf(" %lf", &deslocamentoY);

            MoverPontos(&xap, &yap, &xbp, &ybp, deslocamentoX, deslocamentoY);
            AjustarPontosMovidos(&xap, &yap, &xbp, &ybp);

            MostrarReta("RESULTADO DO MOVIMENTO", xap, yap, xbp, ybp);
            printf("A nova reta esta dentro do PP, com fator de margem de 10%%.\n");
            printf("Iteracoes de ajuste: %d\n", contadorIteracoes);
        }
        else if (opcao == 3){
            contadorIteracoes = 0;
            EscalonarPontos(&xap, &yap, &xbp, &ybp);

            MostrarReta("RESULTADO DA ESCALONACAO", xap, yap, xbp, ybp);
            printf("Iteracoes realizadas: %d\n", contadorIteracoes);
        }
        else if (opcao != 0){
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}