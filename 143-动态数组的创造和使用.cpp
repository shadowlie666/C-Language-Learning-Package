# include <stdio.h>
# include <malloc.h>

int main(void)
{
	int n;
	int i;
	int *p;
	
	printf("����������Ԫ�صĸ�����");
	scanf("%d", &n); 
	p = (int*)malloc(4*n);
	for(i=0; i<n; ++i)
		scanf("%d\n", &p[i]);
	printf("����n��Ԫ�طֱ���\n"); 
	for(i=0; i<n; ++i)
		printf("%d   ", p[i]);
	free(p); 
	
	return 0;
} 
