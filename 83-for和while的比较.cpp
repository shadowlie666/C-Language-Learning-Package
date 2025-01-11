# include <stdio.h> 

int main(void)
{
	int i;
	int sum = 0;

	i = 1;
	while(i<101)   
	{
		sum = sum + i;
		++i;
	}
printf("sum = %d\n", sum, i);
	
	return 0;
}

//9到13行的while语句就等价于for（i=1；i<101；++i）
//    							sum=sum+i；

//while更适合人类的思考方式，适用于我们写程序思路还不清晰的时候，使用while语句一步步推进
//for语句更加直接简洁，能让人一眼认出来这是一个单独的语句，不容易出现逻辑问题，使用for语句适用于逻辑清晰，追求代码简洁美观时使用 
 
