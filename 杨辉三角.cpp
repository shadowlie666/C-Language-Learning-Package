# include <stdio.h>    //函数目的是输出10行杨辉三角 

int main(void)
{
	int a[10][10];
	int i, k;
	
	for(i=0; i<10; i++)
	{
		for(k=0; k<=i; k++)
		{
			if(i == k || k == 0 )       //关键在要在行和列相等的时候（每一行最后一个）赋值为1，在第一列的值也要全部为1 
			{
				a[i][k] = 1;
			}
			else
			{
				a[i][k] = a[i-1][k-1] + a[i-1][k];    //算法关键就是每一项的值都是它头顶那项和它头顶左边那项的和 
			}
		}
	}
	
	for(i=0; i<10; i++)
	{
		for(k=0; k<=i; k++)
		{
			printf("%3d", a[i][k]);
		}
		printf("\n");
	}
	
	return 0;
}
