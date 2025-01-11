# include <stdio.h>

int main(void)
{
	int i = 6;
	int j = 9;
	int t;
	
	t = i;
	i = j;
	j = t;
	
	printf("i = %d, j = %d\n", i, j);
	
	return 0;
}

//互换两个数字的时候，要使用中间变量，第九行到第十一行的代码建议直接背下来
//理解，相当于i是可乐，j是雪碧，要把可乐和雪碧交换，要先找个空杯子t，
//先把可乐i倒进空杯子t（先把i赋给t），再把雪碧j倒进可乐瓶i中（再把j赋给i），最后再把杯子t中的可乐倒进雪碧瓶j中(最后把t赋给j)
//即t = i,i = j,j = t 
