# include <stdio.h>

int main(void)
{
	int i;
	int sum = 0; //注意要初始化变量，不然计算机会默认为变量的值为1 
	for(i=3; i<=10; i++)
	{                               //if默认只能控制一个语句，也就是第12行的printf不归他管，i从3开始每次加1，但是要注意 
		if(i%3 == 0)                //for循环里面包括两个语句，一个是if一个是printf ，if语句不一定会再次执行，但是printf一定会随着for的循环再次执行， 
			sum = sum + i;          //也就是说i=3时，会执行if语句，sum的值变为3，当i+1变为4时，if语句不执行，但printf仍执行，会把sum=3再输出一遍 
		else;                       //一直到i加到6时，才会再次执行if语句，这时候sum的值会变为9，之后i为78的时候仍会不断输出sum=9 
	printf("sum = %d\n", sum, i);
		
	}
	
	return 0;
}




