# include <stdio.h> 

int main(void)
{
	int i;
	int sum = 0;

	i = 1;
	while(i<101)   
	{
		sum = sum + i;
		++i;
	}
printf("sum = %d\n", sum, i);
	
	return 0;
}

//9��13�е�while���͵ȼ���for��i=1��i<101��++i��
//    							sum=sum+i��

//while���ʺ������˼����ʽ������������д����˼·����������ʱ��ʹ��while���һ�����ƽ�
//for������ֱ�Ӽ�࣬������һ���ϳ�������һ����������䣬�����׳����߼����⣬ʹ��for����������߼�������׷�����������ʱʹ�� 
 
