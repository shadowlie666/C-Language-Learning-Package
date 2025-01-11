# include <stdio.h>

struct student 
{
	int age;           //这里面的age，score之类的也是后面定义的变量的名称的一部分 
	float score;
	char sex;
};   //结构体不是函数，大括号后面记得加上分号 

int main(void)
{
	struct student a = {18,66.6,'y' };  //第一种定义方法：直接定义变量+赋值 
	struct student b;    //第二种方法，先定义变量，然后再一一赋值 
	b.age = 20;     //敲完b后敲.会弹出框框来辅助你选择要填哪一个结构体元素的值的 （如果没有提示，就先编译再继续写，每次重新打开都要编译一次）
	b.score = 80;   //记住：变量+结构体元素才是变量名称 
	b.sex = 'x';   //使用char一定不要忘记加单引号 
	printf("%d  %f  %c", b.age, b.score, b.sex);    //注意括号里面取变量是要写b.age，不是光写b，要把结构体元素加上才是一个完整的变量 
	
	a.age = 22.5f; //第一种更改方式：直接选择a中的age结构体进行更改，由于22.5系统默认为double类型，在数字后面加个f或F可以让他变成float类型 
	
	struct student *p = &a;//第二种方法：利用指针修改，注意a是struct student类型，&a就是struct student*类型，所以p也得是struct student*类型 
	p->age = 66; //p->age的含义就是对p所指向的结构体变量中的某一个元素进行操作，比如这里p->age = *p.age = a.age 
	            //也就是把p所指向的结构体a中的age的值变成了66 
	return 0;
} 
//如果不使用结构体，每个学生都要写一次5-7行的内容，很麻烦，而且程序可能会混乱，会出现执行完第一个学生的age后跳到执行第二个学生的score去了
//注意：这里的struct student是数据类型，意思是创造了一个叫student的结构体，struct student这一个整体是一个数据类型，
//第12行后面的那个a才是变量 
