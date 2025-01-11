# include <stdio.h>
# include <malloc.h>

struct student
{
	int age;
	double score;
	char name[100] ;	
};

int main(void)
{
	int n;
	struct student *p;
	int i, k;
	struct student t;
	
	printf("请输入学生的个数：");
	scanf("%d", &n);
	p = (struct student*)malloc(n*sizeof(struct student));  //这里就是创建了n个结构体，且都是以动态内存形式储存的，同时p指向这多个结构体 
	
	for(i=0; i<n; i++)  //这个for循环是用来输入学生信息的 
	{
		printf("请输入第%d个学生的信息\n", i+1) ;
		printf("age = ");
		scanf("%d", &p[i].age );  //p[0].age就是p所指向的第一个结构体里面的age信息，也就是第一个学生的age信息（一个结构体就是一个学生） 
		printf("score = ");        //结构体里面的元素就是学生的信息，这里把p[0]改成了p[i]就可以输入多个结构体（学生）的信息 
		scanf("%lf", &p[i].score);
		printf("name = ");
		scanf("%s", p[i].name);  //char定义的字符串输入的时候不用加取地址符 
	}
	
	for(i=0; i<n-1; i++)          //这里就是冒泡排序来给学生的成绩排名（参考163-冒泡排序） 
	{
		for(k=0; k<n-1-i; k++)    //p是struct student *类型，但p[0]是struct student类型 
		{
			if(p[k].score >p[k+1].score ) //p[k]指的是p所指向的那个结构体，结构体本身是不能比较大小的，所以要写成p[k].score 
			{                            //这样就变成具体比较两个结构体中的score元素的大小 
				t = p[k];
				p[k] = p[k+1];    //注意这里是交换的结构体，不只是单单交换两个结构体中的score数据，这里是把两个结构体整体给换了内存空间 
				p[k+1] = t;
			}
		}
	}
	
	printf("学生的成绩排名如下：\n");
	for(i=0; i<n; i++)                     //这个for循环用来输出排完名后的学生信息，用循环是因为要输出多个结构体内的元素（多个学生的信息） 
	{
		printf("name = %s\n", p[i].name);
		printf("age = %d\n", p[i].age );
		printf("score = %lf\n", p[i].score);
		printf("\n");
	}
	
	return 0;
}
