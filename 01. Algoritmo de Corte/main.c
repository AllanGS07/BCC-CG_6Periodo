#include <stdio.h>

int main(void)
{
    float ya, yb, xa, xb;
    float xmax, xmin, ymax, ymin;
    float m, xp1, yp1, xp2, yp2;

    printf("Digite a coordernada X mínima da sua tela: "); fflush(stdout); scanf(" %f", &xmin);
    printf("Digite a coordernada X máxima da sua tela: "); fflush(stdout); scanf(" %f", &xmax);
    printf("Digite a coordernada Y mínima da sua tela: "); fflush(stdout); scanf(" %f", &ymin);
    printf("Digite a coordernada Y máxima da sua tela: "); fflush(stdout); scanf(" %f", &ymax);

    printf("Digite a coordernada X do ponto A da sua reta: "); fflush(stdout); scanf(" %f", &xa);
    printf("Digite a coordernada X do ponto B da sua reta: "); fflush(stdout); scanf(" %f", &xb);
    printf("Digite a coordernada Y do ponto A da sua reta: "); fflush(stdout); scanf(" %f", &ya);
    printf("Digite a coordernada Y do ponto B da sua reta: "); fflush(stdout); scanf(" %f", &yb);

    if (xa == xb){
        xp1 = xa;

        if (ya < ymin){
            yp1 = ymin;
        } else if (ya > ymax){
            yp1 = ymax;
        } else {
            yp1 = ya;
        }
    }
    else if (ya == yb){
        yp1 = ya;

        if (xa < xmin){
            xp1 = xmin;
        } else if (xa > xmax){
            xp1 = xmax;
        } else {
            xp1 = xa;
        }
    } 
    else {
        m = (yb - ya) / (xb - xa);
        if (xa < xmin){
            yp1 = m * (xmin - xa) + ya;
            xp1 = xmin;
        } else if (xa > xmax){
            yp1 = m * (xmax - xa) + ya;
            xp1 = xmax;
        } else if (ya < ymin){
            xp1 = ((ymin - ya) / m) + xa;
            yp1 = ymin;
        } else if (ya > ymax){
            xp1 = ((ymax - ya) / m) + xa;
            yp1 = ymax;
        } else {
            xp1 = xa;
            yp1 = ya;
        }
    }

    printf("\nCoordenada de corte: P1 = (%.2f, %.2f)\n", xp1, yp1);
    fflush(stdout);

//-------------------------------------------------------------------------------------------------------------------------------------------------------//

    if (xb == xa){
        xp2 = xb;

        if (yb < ymin){
            yp2 = ymin;
        } else if (yb > ymax){
            yp2 = ymax;
        } else {
            yp2 = yb;
        }
    }
    else if (yb == ya){
        yp2 = yb;

        if (xb < xmin){
            xp2 = xmin;
        } else if (xb > xmax){
            xp2 = xmax;
        } else {
            xp2 = xb;
        }
    } 
    else {
        m = (ya - yb) / (xa - xb);
        if (xb < xmin){
            yp2 = m * (xmin - xb) + yb;
            xp2 = xmin;
        } else if (xb > xmax){
            yp2 = m * (xmax - xb) + yb;
            xp2 = xmax;
        } else if (yb < ymin){
            xp2 = ((ymin - yb) / m) + xb;
            yp2 = ymin;
        } else if (yb > ymax){
            xp2 = ((ymax - yb) / m) + xb;
            yp2 = ymax;
        } else {
            xp2 = xb;
            yp2 = yb;
        }
    }

    printf("\nCoordenada de corte: P2 = (%.2f, %.2f)\n", xp2, yp2);
    fflush(stdout);

    return (0);
}