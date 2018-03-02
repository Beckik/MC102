#include <stdio.h>

int main () {

	// Vicenzo Cano Cesconetto
	/* RA: 206456 */
	// Os vetores armazenam os preços dos papeis para cada empresa. Os l<> armezenam o lucro e l<>ant armazenam o lucro que não tiver interseção e for o mais alto.
	float vet1[15], vet2[15], vet3[15], vet4[15], l1, l2, l3, l4, lctotal, lanttotal = 0, l1ant = 0, l2ant = 0, l3ant = 0, l4ant = 0;
	int d = 0, dc1, dc2, dc3, dc4, dv1, dv2, dv3, dv4, dcomp1, dcomp2, dcomp3, dcomp4, dvenda4, dvenda3, dvenda2, dvenda1, x = 0, y = 0, z = 0, a = 0;
	// d é o número de dias e dc<> é o dia de compra enquanto dv<> é o dia de venda. dvenda<> e dcomp<> são os dias de compra e vendo do lucro que for impresso.
	// Scaneamos a quantidade de dias e os valores do papeis.

	scanf("%d", &d);

	do { 
		scanf("%f", &vet1[x]);
		x++;
	}
	while (x < d);

	do { 
		scanf("%f", &vet2[y]);
		y++;
	}
	while (y < d);

	do { 
		scanf("%f", &vet3[z]);
		z++;
	}
	while (z < d);

	do { 
		scanf("%f", &vet4[a]);
		a++;
	}
	while (a < d);

	/* 8 fors faz a complexidade ser de d^8 mas temos que testar todas as possibilidades de lucro e intersções a serem descartadas.
	Todos os dias de compra e venda de todas as empresas serão combinadas com os dias de compra e venda de todas as outras empresas.
	O dia de compra começa com zero (por que o vetor não vai de 1 até 15 como os dias) e vai até no máximo 14.
	O dia de venda tem que ser necessariamente, no mínimo um dia a mais que a compra, senão não há lucro. 
	*/
	for ( dc1 = 0; dc1 < d; dc1++) {
		for (dv1 = dc1 + 1; dv1 < d; dv1++) {
			for ( dc2 = 0; dc2 < d; dc2++) {
				for (dv2 = dc2 + 1; dv2 < d; dv2++) {
					for (dc3 = 0; dc3 < d; dc3++) {
						for (dv3 = dc3 + 1; dv3 < d ; dv3++) {
							for ( dc4 = 0; dc4 < d; dc4++) {
								for (dv4 = dc4 +1; dv4 < d; dv4++) {
									/* O que é lucro senão delta preço das ações da empresa <>, então estabelecemos o lucro como a varição do preço no dia de venda
									e de compra (que são posições nos vetores)*/

									l4 = vet4[dv4] - vet4[dc4];
									l3 = vet3[dv3] - vet3[dc3];
									l2 = vet2[dv2] - vet2[dc2];
									l1 = vet1[dv1] - vet1[dc1];

									// Se houver alguma dessas várias inteseções abaixo, ficamos com o lucro maior e damos zero para o menor lucro.

									if (!(dc1 >= dv2 || dv1 <= dc2)) {

										if ( l1 > l2) {
											l2 = 0;
										}

										else {
											l1 =0;
										}
									}

									if (!(dc1 >= dv3 || dv1 <= dc3)) {

										if ( l1 > l3) {
											l3 = 0;
										}

										else {
											l1 =0;
										}
									}

									if (!(dc1 >= dv4 || dv1 <= dc4)) {

										if ( l1 > l4) {
											l4 = 0;
										}

										else {
											l1 =0;
										}
									}

									if (!(dc2 >= dv3 || dv2 <= dc3)) {

										if ( l2 > l3) {
											l3 = 0;
										}

										else {
											l2 =0;
										}
									}

									if (!(dc2 >= dv4 || dv2 <= dc4)) {

										if ( l2 > l4) {
											l4 = 0;
										}

										else {
											l2 =0;
										}
									}

									if (!(dc3 >= dv4 || dv3 <= dc4)) {

										if ( l3 > l4) {
											l4 = 0;
										}

										else {
											l3 =0;
										}
									}

									/* Se um lucro for negativo e não for eliminado pelas interseções, ele é eliminado agora.*/

									if ( l4 < 0) {
										l4 = 0;
									}
									if ( l3 < 0) {
										l3 = 0;
									}
									if ( l2 < 0) {
										l2 = 0;
									}
									if ( l1 < 0) {
										l1 = 0;
									}

									// O que é o lucro total senão o conjunto dos lucros.

									lctotal = l1 + l2 + l3 + l4;

									/* O lanttotal é o lucro a ser impresso, que é a maior possiblidade de lucro.*/

									if (lctotal > lanttotal) {

										dcomp4 = dc4;
										dcomp3 = dc3;
										dcomp2 = dc2;
										dcomp1 = dc1;
										dvenda1 = dv1;
										dvenda2 = dv2;
										dvenda3 = dv3;
										dvenda4 = dv4;
										l4ant = l4;
										l3ant = l3;
										l2ant = l2;
										l1ant = l1;
										lanttotal = lctotal;
									}
								}
							}
						}
					}
				}
			}
		}
	}
    // Se o lucro em questão for maior que zero, ou seja, só não é zero que nos deixamos ser maior que zero, será printada.
	if ( l1ant > 0) {

		printf("acao 1: compra %d, venda %d, lucro %.2f\n", dcomp1 + 1, dvenda1 + 1, l1ant);
	}

	if ( l2ant > 0) {

		printf("acao 2: compra %d, venda %d, lucro %.2f\n", dcomp2 + 1, dvenda2 + 1, l2ant);
	}

	if ( l3ant > 0) {

		printf("acao 3: compra %d, venda %d, lucro %.2f\n", dcomp3 + 1, dvenda3 + 1, l3ant);
	}

	if ( l4ant > 0) {

		printf("acao 4: compra %d, venda %d, lucro %.2f\n", dcomp4 + 1, dvenda4 + 1, l4ant);
	}

	printf("Lucro: %.2f\n", lanttotal);
}
