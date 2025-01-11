# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int i, j, k, n;
	scanf("%d", &n);
	for(i=0; i<2*n+1; i++)
	{
		for(k=0; k<abs(n-i); k++)
			printf(" ");
		for(j=0; j<(2*n+1-2*abs(n-i)); j++)
			printf("*");
		printf("\n");
	}
	
	return 0;
}

//ÊäÈë3
//Êä³ö   
/*   	  *
  		 ***
 		*****
	   *******
 	    *****
  		 ***
   		  * 
