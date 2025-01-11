# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int i, j, k, n, p;
	
	scanf("%d", &n);
	for(i=0; i<2*n-1; i++)
	{
		p = 1;
		for(k=0; k<abs(n-i-1); k++)
			printf(" ");
		for(j=0; j<(2*n-1-2*abs(n-i-1)); j++)
			{
				printf("%d", p);
				if(j<n-abs(n-i-1)-1)
					p++;
				else
					p--;
			}
		printf("\n");
		
	}
	
	return 0;
}
