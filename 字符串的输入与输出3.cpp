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

//�漰����ֵ�пո�ʱ����gets�������룬�漰����ֵ�޿ո�ʱ��ʹ��scanf���� 
