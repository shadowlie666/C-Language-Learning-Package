# include <stdio.h>

int main(void)
{
	char ch;
	int a = 0;
	int sum = 0;
	
	
	while((ch=getchar()) != '\n')   //����\nֹͣѭ�����߼����ȸ�ch��ֵ���ֲ�����ֹͣѭ���������ch��ֵӦ����\n�����ǿո���ַ� 
	{ 
		if(ch == ' ' && a==1)
		{
			sum += 1;
		}
		if(ch == ' ')                //ֻҪǰһ�����ַ�����һ���ǿո񣬾���sum+1 
			a = 0;           //���ǰһ�����ַ�������a=1����ch�Ǹ��ո���a=1ʱ�����ж�ch�ǿո񣬻�û�����ü���a���0��ʱ�򣩣���sum+1 
		else
			a = 1;
	}
	
	if(ch == '\n')                 //������û�пո�Ļ���sum���ټ�һ�Σ���������Ҫ�ӻ��� 
		printf("%d", sum+1);
	else
		printf("%d", sum);
	
	return 0;
}
