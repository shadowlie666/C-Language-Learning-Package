# include<stdio.h>
# include<math.h>

int main(void)
{
int a=1;
int b=5;
int c=2;
float x1;
float x2;
float delta;
delta=b*b-4*a*c;

if (delta>0)
{
x1=(-b)+sqrt(delta)/2*a;
x2=(-b)-sqrt(delta)/2*a;
printf("�÷����������⣬x1=%f,x2=%f\n",x1,x2);
} 
else if(delta==0)
{
	x1=x2=(-b)/2*a;
	printf("�÷���ֻ��һ���⣬x1=x2=%f\n",x1,x2);
}
else if(delta<0)
{
	printf("�÷���û�н�\n");
}

}
