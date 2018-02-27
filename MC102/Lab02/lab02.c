
/* Vicenzo Cano Cesconetto RA: 206456

O objetivo do programa é calcular quanto tempo deve ser esperado para acionar
o micro-explosivo após a bomba ter sido solta pela nave imperial. Assim, o
empuxo leva a bomba a se deslocar também horizontalmente e a ser desviada
uma distância d da base rebelde, caindo na base imperial.
*/

#include <stdio.h>

 int main()


 {

/*Declarando variávei no formato float para poder ter números depois da vígula */

 float h, vb, d, T, t, s, G;

 /* Scaneando variáveis no formato float para termos operações que tem resultado
 com números após a vírgula.*/

 scanf("%f%f%f%f", &h, &vb, &d, &T);

 /* Eu sei que o tempo s é a distancia h percorrida com velocidade vb
G é o tempo necessário para percorrer d com a velocidade adquirida
pela explosão que insere força T.*/

s = h/vb;
G = d/T;
t = s - G;

/* Comando oferecido no site da Susy */

printf("%.3f\n", t);

/* Pedindo para o programa retornar zero para saber que tudo ocorreu
perfeitamente */

return 0;

 }
