# include <stdio.h>

int main(void)
{
	int a;   //��ʾ��Ҫ�жϵ����� 
	int m;	//��ŵ���˳�������� 
	int n;   //�м�������������ÿһλ���� 
	
	printf("��������Ҫ�жϵ�����:"); 
	scanf("%d", &a);
	n = a;
	
	while(n)
	{
		m = m*10 + n%10;
		n /= 10;
	}	
	
	if(m == a)
		printf("�������ǻ�����");
	else
		printf("������ֲ��ǻ�����");
		 
	return 0;
} 
