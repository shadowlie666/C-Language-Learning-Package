# include <stdio.h>

int main(void)
{
	int i;
	
	printf("请输入你的成绩：");
	scanf("%d", &i);
	
	switch(i)
	{
		case 1:
			printf("你太菜了\n");             //这里的break有终止运行的意思，也就是只允许运行break上面的语句 
			break;				//而这里的case可以理解为程序的入口，符合case的哪种情况，就从哪里开始执行程序，遇到break才停止，否则继续执行下去 
		case 2:
			printf("你不太行\n");             //注意，如果没有第14行的break的话，程序是会继续从上往下执行的 
			break;							  //也就是说，当你输入1的时候，程序从第12行开始执行，但因为14行的break没有 
		case 3:								  //所以程序会把15.16行的命令也执行了。直到第17行的break才会终止程序运行 
			printf("还不错嘛\n");             //所以，当你输入1的时候，如果没有14行的break，程序会输出第13.16行的两条结果 
			break;
		case 4:
			printf("大能人啊你\n"); 
		default:
			printf("你乱说啥呢\n"); 
			break;
	}
	
	return 0;
 } 
 
 //注意一下格式问题，每个case的后面都要加上冒号，且每个case里面要记得加上break命令
 //注意break后面不要忘记加分号，最后一个default后面也要加上冒号 
