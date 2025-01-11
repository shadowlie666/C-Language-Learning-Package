# include <stdio.h>
# include <malloc.h>

int main(void)
{
	int n;
	int i;
	int *p;
	
	printf("请输入数组元素的个数：");
	scanf("%d", &n); 
	p = (int*)malloc(4*n);
	for(i=0; i<n; ++i)
		scanf("%d\n", &p[i]);
	printf("则这n个元素分别是\n"); 
	for(i=0; i<n; ++i)
		printf("%d   ", p[i]);
	free(p); 
	
	return 0;
} 
