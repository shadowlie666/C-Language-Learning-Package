/*
	����һ����������������������ӣ�����1*���������������ӵĺͣ�������
*/ 
# include <stdio.h>

int main(void)
{
	int n, i, k, sum=0;
	int a[100];
	
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	for(i=0;i<n;i++)
	{
		for(k=1;k<a[i];k++)
		{
			if(a[i]%k == 0)
				sum += k;	
		}	
		printf("%d", sum);
	}	
	
	return 0;
} 
