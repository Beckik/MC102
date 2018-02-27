/* Vicenzo Cano Cesconetto RA: 206456
 O objetivo do programa é receber o peso das quatro cargas a serem colocadas na nave, e usando o valor de seus pesos, equilibrá-las no veículo*/

#include <stdio.h>

int main ()

{
    /* Declarando as cargas como inteiros.*/

     int c1, c2, c3, c4;

    scanf("%d%d%d%d", &c1,&c2,&c3,&c4);

    /* Calculando todas as possiblidades de disposição dos pesos para equilibrar as cargas */

    if (c1 + c2 == c3 + c4 || c1 + c3 == c2 + c4 || c1 + c4 == c2 + c3 || c1 == c2 +c3 + c4 || c2 == c1+c3+c4 || c3 == c4+c2+c1 || c4 == c1+c2+c3)
    {  printf("sim\n");}

    else { printf("nao\n");}

    return 0;
}
