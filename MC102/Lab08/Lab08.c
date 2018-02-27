#include <stdio.h>

/* Vicenzo Cano Cesconetto, RA = 206456. */

int main ()
{
	// Declarando id como char pois é só uma letra; h como int pois será um inteiro.
	char id;
	int h;
	// Scaneado id e h.
	scanf("%c %d", &id, &h);
	// Tudo depende se h >= 2 pois se não for já printa entrada invalidade (ver else lá em baixo).
	if ( h >= 2)
	{
		// Se id for Q ou q é um quadrado.
		if ( id == 'q' || id == 'Q')
		{
			// i é a contadora que conta a quantidade de . a serem impressos na borda de comprimento 2*h-1+4.
			for (int i = 0; i < ((2*h-1)+4); i++)
			{
				printf(".");
			}
			// Desce com newline para colocar o recheio do quadro.
			printf("\n");
			// Esse é o for das linhas "l" que serão iguais ao scan de h.
			for (int l = 0; l < h; l++)
			{
				// A borda lateral (vertical) da esquerda tem um expaço até os ateriscos.
				printf(". ");
				// Esse for é o de print de * e um espaço contíguo.
				for (int i = 0; i < h; i++)
				{
					printf("* ");
				}
				// Para finalizar essa linha entra um . com newline para ir para a próxima linha.
				printf(".\n");
			}
				// Borda inferior que é igual a superior
			for ( int i = 0; i < ((2*h-1)+4); i++)
			{
				printf(".");
			}
			// Newline para finalizar como pedido no enunciado
			printf("\n");
		}
		// Se id for T ou t temo o triângulo.
		else if ( id == 't' || id == 'T')
        {
        	// Borda supeior de mesmo tamanho do quadrado
        	for ( int i = 0 ; i < ((2*h-1)+4) ; i++)
        	{
        		printf(".");
        	}
        	// Newline para irmos para as linhas do recheio do quadro.
        	printf("\n");
        	// Recheio com contadora l de linhas.
			for (int l = 1; l <= h; l++)
			{
				printf(".");
				/* A quantidade de espaços a serem impressos é = Tamanho da borda (((2*h-1)+4)) menos a quantidade de asteriscos
				com seus espacos contíguos (isso é igual ao número da linha do recheio do quadro) e tudo isso dividido por dois
				já que é um antes dos asteriscos e outro depois de mesmo comprimento. */
	        	for (int i = 1; i <= (((((2*h-1)+4))-(2*l))/2) ; i++)
	        	{
	        		printf(" ");
	        	}
	        	// Print de * com espaço contíguo, sendo que quantidade de * é igual ao número da linha.
	        	for (int i = 0; i < l; ++i)
	        	{
	        		printf("* ");
	        	}
	        	// O espaço do outro lado dos asteriscos mas com um a menos já que vai haver um espaço depois do último *
	        	// que precisa haver para haver espaço entre os asteriscos.
	        	for (int i = 1; i <= ((((((2*h-1)+4))-(2*l))/2)-1) ; i++)
	        	{
	        		printf(" ");
	        	}
	        	// Acabamento lateral, colocamos um ponto e newline
	        	printf(".\n");
	        }
	        // Borda inferior
        	for ( int i = 0 ; i < ((2*h-1)+4) ; i++ )
        	{
        		printf(".");
        	}
        	// Newline pedido no enunciado.
        	printf("\n");
	    }
	    // Id do losango que deve ser ímpar.
	    else if ( (id == 'l' || id == 'L') &&  ((h%2) != 0))
	    {
	    	// Borda superior.
	    	for ( int i = 0 ; i < (h+4) ; i++)
        	{
        		printf(".");
        	}
        	// Newline para printar agora as linhas de recheio
        	printf("\n");
        	// Note que essa parte é interessante pois a linha mais longa é uma função maior inteiro com y = h/2, ou seja,
        	// será h/2 + 1/2. Contudo isso considera numeros com a linha numérica partindo do zero, mas l = 1 no início,
        	// então para ser printado a quantidade certa de linhas, adiciona-se 1 a mais = 3/2. Lembrando que esse for é 
        	// da parte de cima do losango, ou seja, ele é das linhas da parte superior.
        	for (int l = 1; l <= ((h/2)+3/2); l++)
        	{
        		// Toda linha começa com ponto.
        		printf(".");
        		// A quantidade espaços segue as mesma lógica do triângulo.
        		for (int i = 1; i <= (((h + 4) - 2*l)/2) ; i++)
	        	{
	        		printf(" ");
	        	}
	        	// A quantidade de asterisco é igual ao número da linha.
	        	for (int i = 0; i < l; ++i)
	        	{
	        		printf("* ");
	        	}
	        	// Outro espaço, depois dos asteriscos.
	        	for (int i = 1; i <= ((((h + 4) - 2*l)/2)-1) ; i++)
	        	{
	        		printf(" ");
	        	}
	        	// Ponto do fim da linha mais newline.
        		printf(".\n");
        	}
        	// Parte inferior do losango. O número da primeira linha da parte inferior é a segunda com mais *.
        	// Assim, ela começa com um a menos de onde terminou a parte superior, 3/2 -1 = 1/2. Note também
        	// que invés de incrementar l ele é decrescido para chegar ao fim do triângulo invertido que é
        	// a parte inferior do losango.
        	for ( int l = ((h/2)-(1/2)); l > 0 ; l--)
        	{
        		printf(".");

        		for (int i = 1; i <= (((h + 4) - 2*l)/2) ; i++)
	        	{
	        	// Espaços antes do asterisco.
	        		printf(" "); 
	        	}
	        	// Print de asteriscos.
	        	for (int i = 0; i < l; i++)
	        	{
	        		printf("* ");
	        	}
	        	// Espaços depois dos asteriscos.
	        	for (int i = 1; i <= ((((h + 4) - 2*l)/2)-1) ; i++)
	        	{
	        		printf(" ");
	        	}
	        	// Fim de linha com . e newline para ir para a próxima.
        		printf(".\n");
        	}
        	// Borda inferior.
			for ( int i = 0 ; i < (h+4) ; i++)
			{
			    printf(".");
			}
			// Newline pedido no enunciado.
			printf("\n");
	    }
	    // Se o id não for de quadrado, triângulo ou losango, a entra é invalida.
	    else
	    {
	    	printf("entrada invalida\n");
	    }
	}
	// Aqui está o print de entrada invalida se h < 2
	else
	{
		printf("entrada invalida\n");
	}

	return 0;
}