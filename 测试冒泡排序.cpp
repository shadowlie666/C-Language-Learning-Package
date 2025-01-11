# include <stdio.h>

int main(void)
{
	int i, t, k, n;
	int a[5] = {2,6,55,22,33}; 
	
	scanf("%d", &n);
	for(i=0;i<n-1;i++)
	{
		for(k=0; k<n-1-i; k++)    //这里是n-1-i，不是n-1-k 
		{
			if(a[k]>a[k+1])
			{
				t = a[k];
				a[k] = a[k+1];
				a[k+1] = t;
			}
		}
	}
	for(i=0; i<5; i++)
   	    printf("%d ",a[i]);
	
	return 0;
}
