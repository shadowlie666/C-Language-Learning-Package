# include <stdio.h>

int main(void)
{
	char a[66], b[66]; 
	printf("input a = ");
	gets(a);
	printf("input b = ");
	gets(b);
	printf("a = %s\n b = %s\n", a, b);
	
	return 0;
}

//涉及输入值有空格时，用gets函数输入，涉及输入值无空格时，使用scanf输入 
