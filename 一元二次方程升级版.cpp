# include <stdio.h>
# include <math.h>

int main (void) 
{
	double x1, x2;
	double a, b, c;
	double delta;
	char ch;
	
	do 
	{

		printf("a = ", a);
		scanf("%lf", &a);
		printf("b = ", b);
		scanf("%lf", &b);
		printf("c = ", c);
		scanf("%lf", &c);

		delta = b*b-4*a*c;

		if(delta>0) 
		{
			x1 = ( -b+sqrt(delta) ) / (2*a);
			x2 = ( -b-sqrt(delta) ) / (2*a);
			printf("有两个实数解，x1=%lf\n x2=%lf\n", x1, x2);
		} 
		else if(delta == 0) 
		{
			x1 = x2 = -b/2*a;
			printf("有且只有一个实数解，x1 = x2 = %lf\n", x1, x2);
		} 
		else
			printf("没有实数解\n");
			
		printf("想继续吗？，请输入y或n（y表示继续，n表示不继续）：");
		scanf(" %c", &ch);  //别忘记打空格，此时若不打空格，计算机会读取到ch=回车，加个空格可以抵消这个作用 
		 
	}while('y' == ch || 'Y' == ch);

	return 0;
}
