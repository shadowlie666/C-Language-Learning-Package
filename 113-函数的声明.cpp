# include <stdio.h>

void fas(void);          //由于程序是从上往下执行的，因此程序在解析gas函数的时候会发现一个fas，但fas的定义在下面 
                        //所以这里要在第三行加一个函数的声明，告诉计算机我这里的fas是个函数，后面会有解释 
void gas(void)
{
	fas();
}
                         //计算机读代码的时候是先从最上面读取的，也就是他会先看懂你上面的函数是什么东西 
void fas(void)			//但他不会执行你定义的函数，他会先从main函数开始执行 
{						//也就是从上往下解析，但从main函数开始执行 
	printf("ahh\n");
}

int main(void)           //一定要搞清楚执行顺序，一个先执行的函数中出现了后执行的函数的名字，就要对后执行的函数进行声明 
{
	gas();
	
	return 0;
}

//注意的点1：函数的声明一定要保证返回值和形参要一样，也就是第三行和第十行要一样，不能第三行 void fas(void) 第10行就int fas（void） 
//第三行要配合第十行写，因为第十行的才是主函数，第三行只是声明
//注意的点2：函数的声明一定要在后面加上分号，但定义函数的时候不要加上分号 
