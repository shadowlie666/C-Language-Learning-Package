# include <stdio.h>
# include <math.h>

int main(void)
{
	
	double d, x, y;
	int i, n;
	
	scanf("%d", &n);   //走了几次 	
	
	for(i=0;i<n;i++)
	{
		scanf("%c %lf", &dir, &dis);   //由于无法让输入数据的时候 第奇数个数据给a数组，第偶数个数据给b数组 （两个数组的数据类型不一样） 
		if(dir = 'E')                 //所以这里使用每次给两个变量赋值，然后直接对这两个数据进行操作，下次循环再把其他数据赋给这两个变量 
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

//下面给出了可能可以实现给两个数组交替赋值的代码（ab数组存储的数据的数据类型不一样） 
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
