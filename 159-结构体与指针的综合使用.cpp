# include <stdio.h>
#include <string.h>

struct student
{
	int age;
	char name[5];
	char sex;
}; 

void inputstudent(struct student *b)  //这里改变*b就是改变a 
{										//这个函数的目的就是通过指针让a的值改变 
	b->age = 20;
	strcpy(b->name,"张三");
	(*b).sex = 'F'; 
}

void outputstudent(struct student c)  //这里的c已经接收了a的值，执行完上面那个函数后a的值就已经改过了，所以这里输出c就是输出改过后的a的值 
{										//c只起到接受a的值然后输出的作用，不用对a的值进行更改，所以可以不用指针 
	printf("%d   %s    %c", c.age, c.name, c.sex);
}

int main(void)
{
	struct student a;
	inputstudent (&a);   //这里就是利用inputstudent函数修改结构体a的值 
	outputstudent(a);   //发送修改后的a的值，利用outputstudent函数输出a 
	
	return 0;
}
//当然，第18行那里还是用指针比较好，因为指针只占4字节，但结构体中的内容显然不止4字节，如果把a的内容发送给c的话肯定内存会大，运行会慢
//所以发送a的地址给c的话运行速度更快，占用内存更小，是要将输出改成（*c）.age即可 
