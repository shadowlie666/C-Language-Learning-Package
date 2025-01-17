 # include <stdio.h>   //程序目的是将比指定位置数字大的放到后面，比指定数字小的放到前面，指定数字放在中间 

int main(void)
{
	int a[5] = {5, 9, 2, 6, 4};  //这里假设指定数字是第四个数字 
	int t;
	
	t = a[3];
	a[3] = a[0];    //先将指定位置的数字换到第一个去 
	a[0] = t;
	
	int key = a[0];
	int i = 0;
	int k = 4;
	
	while(i<k)
	{
		while(i<k && a[k]>key)   //从后往前找，比它大的元素就留着不动，然后指定数换到已经确定比它大的元素的前面 
			k -= 1;          //若最后那个数比指定数小，那这个第二层while就不会执行，会直接把这个比它小的数和指定数换位置，让比它小的数到前面去 
		a[i] = a[k];
		
		while(i<k && a[i]<key) //从前往后找，比它小的元素就留着不动，然后让这个指定数换到已经确定比它小的元素的后面 
			i += 1;    //若最前面那个数比指定数大，那这个第二层while就不会执行，会直接把这个比它大的数和指定数换位置 
		a[k] = a[i];   //让比它大的数到后面去，指定数去到前面 
		a[i] = key;   //最后记得将指定数放到它们中间去 
	}
	
	for(i=0; i<5; i++)
		printf("%d", a[i]);
	
	return 0;
}
