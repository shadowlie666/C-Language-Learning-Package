# include <stdio.h>

int main(void)
{
	int f1, f2;
	int n, i;
	int fn;
	
	f1 = 0;
	f2 = 1;
	
	printf("����������鿴�����еĵڼ��");
	scanf("%d", &n); 
	
	if(1 == n)
	{
		printf("fn = 0\n", fn);
	}
	else if(2 == n)
	{
		printf("fn = 1\n", fn);
	}
	else
	{
		for(i = 2; i<n; i++)
		{
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
		printf("fn = %d", fn);
	}
	
	return 0;
}
