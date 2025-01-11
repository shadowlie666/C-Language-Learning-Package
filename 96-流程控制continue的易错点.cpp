# include <stdio.h>

int main(void)
{
	int i=0;
	int s=0; 
	
	do
	{
		if(i%2) //计算机默认0为假1为真，就是i%2取余不是0的话就可以执行if语句 
		{
			i++;
			continue;                    //这里一定要注意continue跳过的是循环的那个大括号里面的语句 
		} 								 //在这里就是do。while语句，也就是这里的continue跳过的是第11行那个大括号里面的语句，不是if里面的语句 
		i++;                             //因为if不是循环 ，所以当执行if语句里面的continue后，会执行第17行的while，第10-16行的语句被跳过了 
		s+=i;							 //如果第17行的条件成立，则会继续执行do。while循环，除非if不成立，不然第15.16行的语句就不会执行 
	}while(i<5);						 //因为只要if成立，就会执行continue，只要执行了continue，就会跳过第9行和第17行大括号里面的语句
	
	printf("i = %d, s = %d\n", i, s); 
	
	return 0; 
}
