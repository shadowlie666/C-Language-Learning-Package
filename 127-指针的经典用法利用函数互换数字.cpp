# include <stdio.h>

void huhuan(int *p, int *k)  //这里结合第19行就相当于执行了p=&a，k=&b的语句，也就是指针p指向了a，指针k指向了b 
{
	int t;        //灵魂：指针是可以跨函数使用的，比如这里指针p指向了a，指针k指向了b，那么就相当于*p=a，*k=b 
				  //那么在huhuan函数里面改变*p和*k，同时也会改变主函数里面的ab，二者是同步改变的 
	t = *p;
	*p = *k;   //注意：*p和*k是int类型的，p和k是int*类型的，由于要交换ab，所以这里要改变的是*p和*k，所以t要定义为同类型的int类型，不能写成int*t 
	*k = t;
				//这里就体现了指针的优点，打破了自定义函数return返回值的诸多限定条件，使得函数更加好用 
	return;
}

int main(void)
{
	int a = 3;
	int b = 5;
	
	huhuan(&a, &b);    //这里的取地址符不要漏 
	printf("a=%d, b=%d\n", a, b);
	
	return 0;
}

//void huhuan（int p， intk）    这样写是错误的，你只是在huhuan函数里面把pk的值互换了，并没有改变主函数ab的值 
// int t						  并且该函数返回值是void，运行的结果也不能返回到主函数去 
// t=p,p=k,k=p                       也就是说无论这里怎么改变，都无法影响到主函数的变量ab

//void huhuan（int *p，int*k）    这样写也是错误的，虽然指针p指向了a，指针k指向了b，但是执行函数的过程中 
//int t							   同样的你只改变了huhuan函数里面的pk值，但是pk只是huhuan函数的变量，不会影响到主函数的ab 
// t=p,p=k,k=p                     要想影响到ab，必须是*p和*k才可以 
