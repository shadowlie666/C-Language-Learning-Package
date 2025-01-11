//输入一个数，要求找到三个数，且这三个数构成一个勾股数，且这三个数都小于输入的那个数，输出所有结果 

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
