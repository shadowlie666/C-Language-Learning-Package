# include <stdio.h>

int main(void)
{
	int i;
	scanf("m%d" ,&i);    //这里的m是一个非输入控制符，用在scanf中的话计算机只能识别数字，m无法识别，因此输入时应当输入m123计算机才能输出                                                                 */ 
	printf("i=%d\n" ,i);   // 为123，毕竟输出printf的那里只有%d，没有带m，非输入控制符都是原样输入，不能由人工输入改变，也就是我们输入的数字只能改变%d 
	                        //不能改变m 
	return 0;
}
