# include <stdio.h>

int jc(int n)
{
	if(n==0)
		return 1; //注意这里只是计算单个阶乘，所以结果乘1没所谓，但如果是计算阶乘的和，最后就应当+0，那么这里就应当是return 0 
	else
		return n * jc(n-1);  //这里先递归返回5*4*3*2*1*jc(0)         因为jc(0)=1 ,最后结果乘个1无所谓 
		                     //之所以会出现两个return是有先后顺序的，由于一直执行的是else语句，则第8行的return先执行 
}							//而第5行的语句最后才执行，则第五行这个return返回的值应当跟在第八行那个return返回值的后面 

int main(void)
{
	int n, result;
	scanf("%d", &n);   //假设n=5 
	result = jc(n);
	printf("%d", result);
	
	return 0;
}
