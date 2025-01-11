# include <stdio.h>

int main(void)
{
	if(3>2)
		printf("aaa\n");  //这里的printf是在if语句里面的，与main语句是间接关系 
	else
		printf("bbb\n");
	printf("ccc\n");   //由于这里的printf与main是直接关系，与第6.8行的不一样，所以两者的printf不能在同一竖列 
	
	return 0;
}

//else的意思就是否则，与if连用，就是如果if括号内的关系不成立，就执行else的命令
//else与if一样，都默认只能控制一个语句，即第七行的else只能控制第八行的语句，不能控制第九行的语句是否执行，如果要控制多个语句，就要用大括号
//一个语句的概念是：如果这个语句是一定会执行的，那么他就是一个语句
//在这里就有两个语句，一个是if。。else的语句，一个是第九行的printf语句
//由于if不是一定执行的，else也不是一定执行的，但if和else放在一起，他们一定会执行其中一个，那么就可以把if。。else看成是一个语句 
