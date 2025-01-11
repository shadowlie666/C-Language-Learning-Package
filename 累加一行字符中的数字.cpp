# include <stdlib.h>
# include <stdio.h>

int main(void)
{
	char ch;
	int a, sum;
	sum = 0;
	
	
	while((ch=getchar()) != '\n')
	{
		if(ch>='0'&&ch<='9')
		{
			a = ch - '0';
			sum = sum + a;
		}
		else
		continue;
	}
	printf("%d", sum);
	
	return 0;
}

