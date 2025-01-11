# include <stdio.h>

int main(void)
{
	if(66)
	printf("aaa\n");  //会运行，因为66在计算机看来是真的语言 
	
	if(0)
	printf("bbb\n");   //不会运行，因为0在计算机看来是假 
	
	if(0==0)
	printf("ccc\n");   //会运行，因为0==0是正确的 
	
	return 0;
}

//注意：if不需要分号，但if后面一定要有括号表示你假设的内容 ，if下面那行写上假设成立的话要执行的命令 
