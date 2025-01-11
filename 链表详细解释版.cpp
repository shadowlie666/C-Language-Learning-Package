#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;    //这个是用来存放每个节点的有效数据的 
	struct node *pnext;     //这个指针存储的是下一个节点的地址 
};

struct node* createlist(void)     //创建列表不用接收主函数的参数 
{
	int i, val, n;
	struct node *phead1 = (struct node*)malloc(sizeof(struct node));
	struct node *pone = phead1;  //这里是让头指针与头结点相等，后面让头结点指向首节点、中间节点、尾节点，这样返还头指针就相当于返回所有节点了 
	pone->pnext = NULL;   //初始化头结点的地址域，后面再让他指向下一节点 
	
	printf("请输入需要生成的列表个数：");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("请输入第%d个节点的数据：", i+1);
		scanf("%d", &val);
		
		struct node* pnew = (struct node*)malloc(sizeof(struct node));  
		pnew->data = val;      //将数据放入新节点的数据域，注意头结点是不存放有效数据的，第一个有效数据放在首节点 
		pone->pnext = pnew;    //让头结点的指针域指向首节点，这样就可以通过头结点找到首节点了 
		pnew->pnext = NULL;    //让首节点的指针域为空，下一次循环时再让他指向下一个节点 
		pone = pnew;	      //这里让首节点成为下一次循环的头结点，这样下一次循环的时候pnew就是首节点后面那个节点 
	}  //也就是这次循环pone是头结点，pnew是首节点，下次循环的时候pone就变成首节点，pnew就是首节点的下一个节点 
	return phead1;      //于是就形成的phead1=pone->pnew1->pnew2.....->尾节点  的链条 
}

void outputlist(struct node *phead2)    //输出链表不需要返还数据给主函数 
{
	struct node *p = phead2->pnext; //这里是先让一个指针指向头结点的下一个节点也就是首节点，因为如果直接让p指向头结点的话，下面输出的时候 
	while(NULL != p)                //输出的是头结点的下一个节点也就是首节点的数据，但是首节点是不存放有效数据的，所以p应该指向头结点 
	{
		printf("%d", p->data);     //第一次循环输出头结点的下一个节点也就是首节点的有效数据 
		p = p->pnext;      //每次循环都让p指向下一个节点，而下一个节点的地址已经保存在每一个节点的地址域了 
	}
	return;
}

int main(void)
{
	struct node *phead = NULL;    //这里头指针只起一个指向作用，没有存放数据，故不用分配动态内存 
	phead = createlist();      
	outputlist(phead);
	
	return 0;
} 

//为什么创建链表的时候不直接返回头结点，而选择返回头指针
//因为头结点是不需要存储有效数据的，所以不需要分配动态内存，这也意味着函数执行完毕头结点的内存就会释放，如果返回头结点的话
//返回后头结点的内存就没了，这样就无法发送头结点的地址到输出链表的函数上去，所以必须返回分配了动态内存的头指针

//为什么不一开始就给头结点分配动态内存？然后直接返回头结点? 
//因为后续算法需要pone和pnew两个变量相互循环调用，如果把动态内存给了pone，那么后续返回pone实际上返回的是倒数第二个链表区域的地址了，
//返回的不是第一个链表区域的地址 
