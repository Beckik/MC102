#include <stdio.h>
// Vicenzo Cano Cesconetto RA: 206456
int main()
{
/*Declaração de variáveis no formato int pois são inteiros podendo algumas serem negativas. */
	int t, c, f, sum = 0, i;
	scanf("%d %d", &t, &c);
// "i" é minha variável contadora.
	for (i = 1; i <= t; i++)
	{
		// sum é minha variável acumuladora.
		scanf("%d", &f);
		sum = f + sum;
		// Se já der para escapar antes do tempo esgotar (se tivermos combustível >= ao necessário), o fazemos usando o break.
		if (sum >= c )
        {
            break;
        }
	}
	// Se a saldo no condutor for maior ou igual a quantidade para fazer a dobra, sim é impresso.
	if (sum >= c )
	{
		printf("sim\n%d\n", i);
	}
	// Caso contrário, não é impresso.
	if ( sum < c)
	{
		printf("nao\n%d\n", t+1);
	}
	return 0;
}
