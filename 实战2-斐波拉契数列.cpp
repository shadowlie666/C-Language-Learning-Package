# include <stdio.h> //斐波拉契数列就是0 1 1 2 3 5 8 13....每一项都是前两项的和 

int main(void)
{
	int n;  //这里的n是用来表示数列的项数的 
	int f1,f2; //这里的f1，f2是用来保存初始值，方便后面利用数列特性来递推 
	int fn; //这里的fn就是最终你要求的那个数列的项数所对应对应的值 
	int i; //这里的i是个中间变量，和n一起使用，用来限制for的循环次数，同时也限制了fn的累加次数 
	
	printf("请输入你想求这个数列的第几项：");
	scanf("%d", &n); 
	
	if(1 == n)
		printf("fn = 0", fn);
	else if(2 == n)
		printf("fn = 1", fn);
	else
		for(i = 3; i<=n; i++)
		{
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}	
		
	printf("fn = %d", fn);
	
	return 0;
}

//之所以第13行，第15行写成1 == n而不写成n == 1，是因为我们写程序时常常会写成n=1，忘记写两个等于号
//而如果写出n=1的话计算机是不会报错的，但是这样写很明显是偏离了程序目的的，但是如果你写成1=n的话程序就会报错，避免了事后找错找半天

//第18行的for循环使用思路，因为这个数列就是要让前两项相加，可以使用代数的方法来思考程序逻辑
//比如如果我输入3，那么计算机就要把第一项0和第二项1相加，给到我的第三项，那么首先要执行的就应该是fn=f1+f2
//但是很明显，如果你要求后面项的值的话一定是要多次相加前两项的，所以一定会用到循环语句for
//那么，当我求第三项的时候，for循环语句就只能循环一次，也就是f1+f2只能执行一次，多加几次的话就不是第三项的值了
//循环几次是用for循环里面的编号1和编号2决定的，并且循环几次一定是和你要求第几项的值有关，于是就必须要用到n来限制循环次数
//当n的值变大时，循环次数就要变多才能累加到后面的值，所以需要一个中间变量i使得形成一个i<次数<n类似这样的不等式，这样才能够包住次数才能够限制他 
//那么就有很多思路了，可以写出i=n；i>=3或者 i=3;i<=n或者i=2；i<n之类的来使n的值越大循环次数越多，
//至于i的初始值是根据n来决定的，可以举例来看，当n=3时，循环只能进行一次，当n=4时，循环要进行2次 ，当n=5时，循环要进行3次
//于是就可以根据你的编号2是<还是<=来判断i的初始值了

//同时还要注意，for循环里面当累加到后面的时候，使用那个项数的前两项，不是第一第二项，也就是第6项是用第4项+第5项，不会用到第一第二项
//所以执行完一次for循环，f1f2的值也应当变化，比如你要求第四项的值，那么就要循环两次，第一次循环时使用第一第二项，
//这时应当将f1变成第二项的值，把f2变成第三项的值，这样下一次循环的时候fn才能是第二第三项的值相加，fn的值才能是第四项的值 
//显然，存储第二项的变量是f2，存储第三项的变量是fn，那么就把f2赋给f1，把fn赋给f2，这样下次循环时f1+f2就变成第二第三项相加了 

//思路：将f1，f2（第一第二项）相加得第三项，再将第二第三项的值赋到f1，f2上，再将f1，f2（第二第三项）相加得第四项 
//当for的循环次数需要由我们自己控制的时候，记得定义一个中间变量来配合我们自己可以改变的那个变量，这样才能控制循环次数 
//for循环的固定循环次数可以有很多种写法  for（i=1;i<=n;i++）  ==   for(i=n;i>=1;i++)   这两种写法都是n越大循环次数越多 
