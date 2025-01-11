# include <stdio.h>

int main(void)
{
	int n, t=-1, s=0;
	
	scanf("%d", &n);   //3 
	do
	{
		s += t;
		t -= 2;
	}while(t != n);
	printf("%d %d", s, t);  //-4, 3
	
	return 0;
}

//注意这里，数字溢出的循环，假设一个数字一直加1，它的循环就是  负数->0->正数->负数      减一同理，就是循环反着来而已 
