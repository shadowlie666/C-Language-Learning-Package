# include <stdio.h>

enum xingqi      //同结构体一样，这里的enum xingqi只是一个数据类型 
{
	monday, tuesday, wednesday, thursday, friday, saturday, sunday //这里如果把monday改成monday=4，那么第11行的输出结果就变成2了 
};  //别忘记分号 

int main(void)
{
	enum xingqi day = tuesday;  //这里的day才是变量 
	printf("%d", day);   //输出结果会是1，因为默认monday是0，tuesday是1，wednesday是2.。。。 
	
	return 0;	
} 
