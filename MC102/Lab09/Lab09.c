#include <stdio.h>
void main ()
{
	int v1[30], v2[30], sum[30], inv1[30], inv2[30];
	int i = 29, w = 29, id = 2, t;
	char c, op;

	for (int k = 0; k < 30; k++)
	{
		v1[k] = 0;
		v2[k] = 0;
		inv1[k] = 0;
		inv2[k] = 0;
		sum[k] = 0;
	} 

    do 
    {
    	scanf("%c", &c);
    	if ( c == '\n')
    	{
    		break;
    	}
    	v1[i] = (int)c - 48;
    	if ( i < 0)
    	{
    		printf("overflow\n");
    		return 0;
    	}
    	i = i - 1;
    }
    while (c!='\n');

    for (int n = 29; i+1 <= 29; n--, i++)
    {
    	inv1[i + 1] = v1[n];
    }

    for (int k = 0; k < 30; k++)
    {
    	printf("%d", inv1[k]);
    }

    printf("\n");

    scanf("%c", &op); 
    getchar();

    do
    {
    	scanf("%c", &c);
    	if ( c == '\n')
    	{
    		break;
    	}
    	v2[w] = (int)c - 48;
    	if ( w < 0)
    	{
    		printf("overflow\n");
    		return 0;
    	}
    	w = w - 1;
    }
    while (c!='\n');

    for (int n = 29; w+1 <= 29; n--, w++)
    {
    	inv2[w + 1] = v2[n];
    }

    for (int k = 0; k < 30; k++)
    {
    	printf("%d", inv2[k]);
    }

    printf("\n");

    if ( op == '+')
    {
    	for (int k = 29; k >= 0; k--)
    	{
    		sum[k] = sum[k] + inv1[k] + inv2[k];
    		if ( sum[k] > 9)
			{
    			sum[k] = sum[k] - 10;
    			if (k-1 < 0)
	    		{
    				printf("overflow\n");
    				return 0;
	    		}
    			sum[k-1] = sum[k-1] + 1;
			}
    	}
    }

    else
    {
    	for (int k = 0; k <= 29; k++)
    	{
    		if (inv1[k] > inv2[k])
    		{
    			id = 1;
    			break;
    		}
    		else if (inv2[k] > inv1[k])
    		{
    			id = 0;
    			break;
    		}
    		else if (k == 29)
    		{
    			id = 3;
    		}
    	}

    	if (id == 1)
    	{
	    	for (int k = 29; k >= 0; k--)
	    	{
	    		sum[k] = sum[k] + (inv1[k] - inv2[k]);
	    		if (sum[k] < 0)
	    		{
	    			sum[k] = 10 + sum[k];
	    			sum[k-1] = sum[k-1]-1;
	    		}
	    	}
    	}

    	else if (id == 0)
    	{
	    	for (int k = 29; k >= 0; k--)
	    	{
	    		sum[k] = sum[k] + (inv2[k] - inv1[k]);
	    		if (sum[k] < 0)
	    		{
	    			sum[k] = 10 + sum[k];
	    			sum[k-1] = sum[k-1]-1;
	    		}
	    	}
    	}

    	else if ( id == 3 )
    	{
    		printf("0\n");
    		return 0;
    	}
    }

    for (t = 0; t <= 29; t++)
    {
    	if (sum[t] != 0)
    	{
 			break;
    	}
    }

    if (id == 0)
    {
    	printf("-");
    	for (int k = 0; k < 30; k++)
    	{
    		if ( k+t <= 29)
    		{
    			printf("%d", sum[k+t]);
    		}
    	}
    }

    else
    {
    	for (int k = 0; k < 30; k++)
    	{
    		if ( k+t <= 29)
    		{
    			printf("%d", sum[k+t]);
    		}
    	}
    }
    printf("\n");
}
