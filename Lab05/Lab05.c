
#include <stdio.h>

// Vicenzo Cano Cesconetto RA: 206456

int main(){
	/* Declarando variável que define o número de entradas "n" no formato int pois é um inteiro e o resto em float pois pode haver
	 * vírgula em seus valores. */

	int n;
	float min = 99999, max = -99999, sum = 0, v;
	
	// Scan da quantidade de entradas
	scanf("%d", &n);
	
	// Laço for pedido declarando a variável "i" contadora que vai ser incrementada até atingir "n"
	
	for (int i = 1; i <= n ; i++){
		// "v" é o valor das entrada a cada vez que rodar o for 
		scanf("%f", &v);
		// A variável acumuladora será a "sum".
		sum = v + sum;
		// Se v for menor que o mínimo ou maior que o máximo (e será na primeira entrada de "v"), o valor de "v" substituirá o mínimo ou máximo.
		if (v <= min){
			min = v;
		}
		if ( v >= max ){
			max = v;
		}
	}
	printf("%.2f\n%.2f\n%.2f\n", min, max, sum/n);

	return 0;
}
