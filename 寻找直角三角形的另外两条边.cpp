/*
  ����һ����(С��200)�������1~200���ܺ����������ֱ�������ε������� 
  2        ���������� 
  20        ��һ������20��Ҫ��1~200���ҿ�����������ֱ�������ε������� 
  12       ������������Ҫ�Ӵ�С��� 
*/
# include <stdio.h>

int main(void)
{
	int i, k, n, a[100], p=0;
	
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]); 
	}
	while(p<n)
	{
		for(i=1;i<200;i++)
		{
			for(k=1;k<200;k++)
			{
				if(i*i + k*k == a[p]*a[p])
				{
					if(i>k)
						printf("%d %d\n", i, k);
				}
				if(i*i + a[p]*a[p] == k*k)
				{
					if(i>k)
						printf("%d %d\n", i, k);
				}
				if(a[p]*a[p] + k*k == i*i)
				{
					if(i>k)
						printf("%d %d\n", i, k);
				}	
			}
		}
		printf("\n");
		p++;
	}
	
	
	return 0;
}

