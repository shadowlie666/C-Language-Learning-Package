# include <stdio.h>
# include <math.h>

int main(void)
{
	
	double d, x, y;
	int i, n;
	
	scanf("%d", &n);   //���˼��� 	
	
	for(i=0;i<n;i++)
	{
		scanf("%c %lf", &dir, &dis);   //�����޷����������ݵ�ʱ�� �����������ݸ�a���飬��ż�������ݸ�b���� ������������������Ͳ�һ���� 
		if(dir = 'E')                 //��������ʹ��ÿ�θ�����������ֵ��Ȼ��ֱ�Ӷ����������ݽ��в������´�ѭ���ٰ��������ݸ������������� 
			x += dis;
		if(dir = 'W')
			x -= dis;
		if(dir = 'N')
			y += dis;
		if(dir = 'S')
			y -= dis;
		
	}
	d = sqrt((x*x) + (y*y));
	printf("%.2f", d);
	
	
	return 0; 
}

//��������˿��ܿ���ʵ�ָ��������齻�渳ֵ�Ĵ��루ab����洢�����ݵ��������Ͳ�һ���� 
//char a[100];
//	double b[100]; 
/*
	char p,c[100];
	while((p=getchar()) == '\n')
		continue;
	while((a[i]=getchar()) != '\n'&&(scanf("%lf",&b[i])) != '\n')
	{
		while((c[i]=getchar()) == '\n')
			continue;
			i++;
		if((i+1) == n)
			break; 
	}
*/ 

/*
		for(i=0;i<n;i++)
	{
		a[i] = getchar();
		scanf("%lf", b[i]);
		if(a[i] == '\n')
		{
			i++;
			break;	
		} 
		while(a[i] != '\n')
		{
			a[i] = getchar();
			i++;
		}
	} 
