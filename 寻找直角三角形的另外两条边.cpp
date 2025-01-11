/*
  给定一个数(小于200)，输出在1~200内能和这个数构成直角三角形的两个数 
  2        输入两个数 
  20        第一个数是20，要在1~200内找可以与他构成直角三角形的两个数 
  12       并且这两个数要从大到小输出 
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

