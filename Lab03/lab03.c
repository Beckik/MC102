
/* Vicenzo Cano Cesconetto RA: 206456 */

/* O objetivo do programa é calcular o volume de combustível no caminhão e assim, baseado na demanda dos postos, responder se o posto será abastecido ou não. */

#include <stdio.h>

int main ()

{

    float d, h, a ,b, c, v;

    scanf("%f%f%f%f%f", &d,&h,&a,&b,&c);

/* Cálculo do volume da carga e subsequente conversão para litros, já que as entradas serão em metros, dando o resultado em metros cúbicos.*/

    v = 3.14 * (d*d/4) * h;
    v = v * 1000;

/* Se o volume da carga for maior ou igual a demanda do posto A ele é abastecido e é impresso a mensagem de abastecimento; assim é subtraído, do volume da carga, o volume recebido pelo posto.
Caso contrário, a mensagem de não abastecimento é impressa e o volume da carga continua inalterada*/

    if (v >= a) {

            printf("posto A foi reabastecido\n");

            v = v-a;

                }

    else {
            printf("posto A nao foi reabastecido\n");
         }

/* Aqui o volume presente no agora no caminhão é comparado à demanda de B e assim dada a resposta de status e resultado de volume em um processo igual ao feito no posto A*/

    if (v>=b) {
                printf("posto B foi reabastecido\n");
                v = v- b;
              }

    else {
                printf("posto B nao foi reabastecido\n");
         }

/* O processo se repete para oposto C */

    if (v>=c) {
                printf("posto C foi reabastecido\n");
                v = v - c;
              }

    else printf("posto C nao foi reabastecido\n");

/* Pedido de retorno 0 para confirmação de êxito.*/

return 0;

}
