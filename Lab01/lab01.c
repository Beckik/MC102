
/* Vicenzo Cano Cesconetto RA: 206456

O Objetivo do programa é calcular o quanto uma pessoa paga pelo serviço de
transporte em funcão da distância percorrida pelo veículo. Para facilitar o cáĺculo,
projeta-se seu movimento num plano cartesiano.
*/

 #include <stdio.h>

int main ()

{

/* Declarando variáveis de forma compacta no formato inteiro (int).*/

     int vi, xi, yi, xf, yf, t, d, v;

 /* Scaneando o valor inicial e as coordenadas da posição
 inicial e final. */

      scanf ("%d%d%d%d%d%d", &vi, &xi, &yi, &xf, &yf, &t);

/* O valor a ser pago v é calculado somando o valor incial mais a distância percorrida d.*/

    d = (xf - xi) + (yf - yi);
    v = vi + d*t;

    printf ("%d\n", v);

    return 0;
}
