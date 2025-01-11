# include <stdio.h>

int main(void)
{
	int a;   //表示你要判断的数字 
	int m;	//存放调换顺序后的数字 
	int n;   //中间变量，用于提出每一位数字 
	
	printf("请输入你要判断的数字:"); 
	scanf("%d", &a);
	n = a;
	
	while(n)
	{
		m = m*10 + n%10;
		n /= 10;
	}	
	
	if(m == a)
		printf("该数字是回文数");
	else
		printf("这个数字不是回文数");
		 
	return 0;
} 
