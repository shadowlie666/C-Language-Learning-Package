# include <stdio.h>

int main(void)
{
    char ch;
	int i,a;
	int sum = 0;
	char as[100];
	
	scanf("%d", i);
	while((ch=getchar()) != '\n')
	{
		a = ch - '0';
		printf("%d", a);
		sum += a;
	}
	printf("%d", sum);
	
	return 0;
}
