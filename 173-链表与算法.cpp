# include <stdio.h>
# include <malloc.h>

struct node   //这里创造的一个结构体其实就是链表的一个节点 
{
	int data;  //data变量是用来存放一个节点的有效数据的 
	struct node * pnext; //pnext变量是用来存放下一个节点的地址的,因为每个节点都是一个结构体,都是struct node类型,所以这里也要定义为struct node类型 
}; 

struct node * createlist(void)    //这个createlist函数就是用来创建链表的 
{
	int n;  //这个n表示链表个数 
	int val;  //这个val是每个节点的有效数据 
	int i;  //这个i用于for循环 
	
	struct node *phead1 = (struct node *)malloc(sizeof(struct node)); //这个phead就是头指针 
	struct node *pone = phead1;   //pone就是头结点，这里就是把头指针的地址发送给头结点 
	pone->pnext = NULL;  //头结点的地址暂时为空，等待for循环启动才会被赋予地址 
	
	printf("请输入需要生成的链表个数n=");
	scanf("%d", &n) ;
	
	for(i=0; i<n; i++)
	{
		printf("请输入第%d个节点的值:", i+1); 
		scanf("%d", &val);
		
		struct node *pnew = (struct node *)malloc(sizeof(struct node));  //这个pnew就是下一个节点 
		pnew->data = val;     //给下一个节点存放有效数据 
		pone->pnext = pnew;   //把下一个节点的地址发送给头节点 
		pnew->pnext = NULL;  //下一个节点的地址暂时为空，等下一次循环才会被赋予地址   3241
		pone = pnew;   //把后一个节点的内容给头节点 
	}
	return phead1;  // 返回头指针的地址，再for循环中，已经把每一个节点的地址都给了头结点，而头指针指向头节点，所以返回头指针就行 
}

void traverselist (struct node * phead2) //这个函数是用来输出链表的,phead2接收了phead的结构体数据 
{
	struct node *p = phead2->pnext;  //这里的指针p接收了头结点的地址 
	while( NULL != p)   //   ！=就是不等于的意思   NULL是空的意思 
	{
		printf("%d", p->data );   //因为p指向头结点，所以p->data就是头结点存储的有效数据 
		p = p->pnext ;  //此时p已经指向 头结点了，那么p->pnext就是头结点存放的地址数据，而这个地址数据是头结点的下一个节点的地址，所以这里就是 
	}					//把头结点下一个节点的地址给了p，那么p就指向了头结点的下一个节点，那么下次循环的p->data就是头结点下一个节点的有效数据了 
	return ;   //这里的return是终止这个函数的意思 
}

int main(void)
{
	struct node *phead = NULL;  //头节点的地址暂时为空，等执行createlist函数的时候会被赋予地址,保证与creatlist函数内的phead1类型一致 
	phead = createlist(); //这里就是把createlist函数的返回值给phead,也就是把副函数里的phead1地址返回给主函数的phead,这样主副函数的头指针就一样了 
	traverselist(phead);   //这里是把接收完数据的phead发送给traverselist函数处理和输出 
	
	return 0;
}















