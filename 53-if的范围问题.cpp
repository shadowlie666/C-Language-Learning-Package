# include <stdio.h>

int main(void)
{
	if(1>2)
	printf("aaaa\n");
	printf("bbbb\n");
	
	return 0;
}

//输出结果为bbbb，说明一个if只能控制第6行的语句，下面第7行的printf不在if语句里面，就是说1>2为假，无法输出的只有第6行的语句，第七行的语句由于不在if里面可以输出
//具体来讲就是此时程序只有两个语句，一个是if，另一个是第七行的printf
//所以，if默认只能控制一个语句 

//如果要让if控制两个语句 ，则要使用大括号
//  int main(void)
//  {
//		if(1>2)
//		{
//    		printf("aaaa\n");
//			printf("bbbb\n");
//  	}
//     return 0;
//  }

//注意格式问题，大括号一定要成双成对，if的大括号与main的大括号不能在同一竖列 
