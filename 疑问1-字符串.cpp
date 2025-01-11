# include <stdio.h>
# include <math.h>

int main (void) 
{
	double x1, x2;
	double a, b, c;
	double delta;
	char ch[5];
	
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
			
		printf("想继续吗？请输入yes或no：");
		scanf(" %s", &ch);
		 
	}while("yes" == ch || "Yes" == ch);

	return 0;
}


//为什么输入yes后无法再次循环 
