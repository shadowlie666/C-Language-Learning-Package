# include <stdio.h>
# include <math.h>

int main(void)
{
	double x1, x2;
	double delta;
	double a, b, c;
	char ch;
	
	do
	{
		printf("a = ");
		scanf("%lf", &a);
		printf("b = ");
		scanf("%lf", &b);
		printf("c = ");
		scanf("%lf", &c);
		
		delta = b*b - 4*a*c;	
		
		if(delta>0)
		{
			x1 = (-b + sqrt(delta))/2*a;
			x2 = (-b - sqrt(delta))/2*a;
			printf("�÷����������⣬x1 = %lf�� x2 = %lf\n", x1, x2);
		}
		else if(0 == delta)
		{
			x1 = x2 =-b / 2*a;
			printf("�÷�����һ���⣬x1 = x2 = %lf\n",x1, x2);
		}
		else
			printf("�÷���û�н�\n"); 
		
		printf("���������Ļ�������y��Y:  ");
		scanf(" %c", &ch);
		 
	}while(ch == 'y'|| ch == 'Y');

	return 0;
} 
