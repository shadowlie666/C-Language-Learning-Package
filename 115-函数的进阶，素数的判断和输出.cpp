# include <stdio.h>

bool sushu1(int m)  //这个函数用于判断m是否是个素数，并把素数还给原函数（sushu2）待处理 
{					//这里的m其实就相当与sushu2中的p，m=p，因为sushu2中是把p用于m的，而接收p的值的就是函数名称后面括号内的形参 
	int i;
	
	for(i=2; i<m; i++)
	{
		if(0 == m%i)
			break;
	}
	if(i == m)
		return true;    //一定要注意：如果用了return返回给sushu2这个函数的话，那么函数的返回值就不能写void 
	else
		return false;
}

void sushu2(int k)  //这个函数用于输出一定范围内的所有素数，要配合上面那个sushu1一起用 
{
	int p;     //这里的p就是存储范围内的所有数字，利用for循环一次次加 
	
	for(p=2; p<k; p++)      //k就是那个范围k=n 
		if(sushu1(p))     //这里就是将范围内的所有数字用到sushu1函数中去判断是不是素数 
			printf("%d\n", p);
		else
			continue;
}

int main(void)
{
	int n;   //这里的n就是那个范围，也就是你想求1~n范围内的所有素数 
	printf("请输入你想求的范围内的素数是1-"); 
	scanf("%d", &n);
	sushu2(n);     //这里就是把n的值用于sushu2这个函数，也就是把n赋给sushu2中的k 
	
	return 0;
}
