# include <stdio.h>

int dan(int n)
{
	int i, sum;
	sum = 1;
	for(i=1; i<=n; i++)
	{
		sum = sum * i;
	}
	return sum;
}

int he(int n)
{
	int i, s=0;
	for(i=1; i<=n; i++)
	{
		s = s + dan(i);
	}
	return s;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int fas = he(n);
	printf("%d", fas);
	
	return 0;
}
