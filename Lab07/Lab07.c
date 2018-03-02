#include <stdio.h>
// Vicenzo Cano Cesconetto, RA: 206456
int main()
{
	// Observe que na declaração de variáveis temos duas variáveis além dos lados do triângulo.
	int a, b, c, g, w = 0;
	scanf("%d", &a);
	// Aqui se estabelece b para rodar de 1 até 1000
	for (b = 1 ;b <= 1000; b++)
	{
		// E assim se encaixa outro laço para rodar também o c de 1 até 1000
		for (c = 1; c <= 1000 ; c++ )
		{
			/* Como é obrigatório o uso do header padrão, para poder comparar o quadrado da hipotenusa com a soma dos quadrado dos catetos,
			 a variável g recebe c elevado a dois.*/
			g = c*c;
			if ( g == a*a + b*b)
			{
				// O "w" é a variável contadora de quantos ternos foram encontrados.
				printf("(%d, %d, %d)\n", a, b, c);
				w = w + 1;
			}
		}
	}
	// Se não for encontrado nenhum terno (w == 0), impreme-se "-".
	if ( w == 0)
		{
			printf("-\n");
		}

	return 0;
}
