//����һ������Ҫ���ҵ�����������������������һ����������������������С��������Ǹ�����������н�� 

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main(void)
{
	int n, i=1, k=1, m;
	
	scanf("%d", &n);
	

		for(i=1;i<n;i++)
		{
			for(k=1;k<n;k++)
			{
				if(sqrt(i*i+k*k) == (int)(sqrt(i*i+k*k)))
				{
					if(i<=k)
					{
						if(i<n && k<n && sqrt(i*i+k*k)<n)
						{
							m=sqrt(i*i+k*k);
							printf("%d %d %d\n",i, k, m);	
						}
					}		
				}
			}
		}
		
	return 0;
}
