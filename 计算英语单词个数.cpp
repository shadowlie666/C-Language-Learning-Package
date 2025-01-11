# include <stdio.h>

int main(void)
{
	char ch;
	int a = 0;
	int sum = 0;
	
	
	while((ch=getchar()) != '\n')   //遇到\n停止循环，逻辑是先给ch赋值后发现不对再停止循环，故最后ch的值应该是\n而不是空格或字符 
	{ 
		if(ch == ' ' && a==1)
		{
			sum += 1;
		}
		if(ch == ' ')                //只要前一个是字符，后一个是空格，就让sum+1 
			a = 0;           //如果前一个是字符，就让a=1，当ch是个空格，且a=1时（先判断ch是空格，还没有来得及将a变成0的时候），让sum+1 
		else
			a = 1;
	}
	
	if(ch == '\n')                 //如果最后没有空格的话，sum会少加一次，所以这里要加回来 
		printf("%d", sum+1);
	else
		printf("%d", sum);
	
	return 0;
}
