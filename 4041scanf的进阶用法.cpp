# include <stdio.h>

int main(void)
{
	int i,k,p;

	
	printf("请输入三个数字，中间用空格隔开\n");   //这里的printf是有提示的作用，也就是告诉用户你应该怎么做，他会比scanf先执行，也就是用户先看提示再输数字 
	scanf("%d %d %d", &i, &k, &p);    //如何区别开三个变量，关键在你的scanf的三个%d怎么写的，如果我这的三个%d中间用的是逗号，那么输入时也应该 
	printf("i=%d，k=%d，p=%d\n" , i, k, p);  //输入12，33，55也就是三个数字之间的空格要变成逗号，因为逗号也是非输入控制符，要原样输入 
	
	return 0;
}

// 重要提醒：scanf里面的逗号一定是用英文的逗号
// 注意，运用int，char等定义时要一次定义完，要写成int i，k     不能写出int i，int k 
