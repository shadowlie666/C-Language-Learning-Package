# include <stdio.h>
# include <malloc.h>

struct node   //���ﴴ���һ���ṹ����ʵ���������һ���ڵ� 
{
	int data;  //data�������������һ���ڵ����Ч���ݵ� 
	struct node * pnext; //pnext���������������һ���ڵ�ĵ�ַ��,��Ϊÿ���ڵ㶼��һ���ṹ��,����struct node����,��������ҲҪ����Ϊstruct node���� 
}; 

struct node * createlist(void)    //���createlist��������������������� 
{
	int n;  //���n��ʾ������� 
	int val;  //���val��ÿ���ڵ����Ч���� 
	int i;  //���i����forѭ�� 
	
	struct node *phead1 = (struct node *)malloc(sizeof(struct node)); //���phead����ͷָ�� 
	struct node *pone = phead1;   //pone����ͷ��㣬������ǰ�ͷָ��ĵ�ַ���͸�ͷ��� 
	pone->pnext = NULL;  //ͷ���ĵ�ַ��ʱΪ�գ��ȴ�forѭ�������Żᱻ�����ַ 
	
	printf("��������Ҫ���ɵ��������n=");
	scanf("%d", &n) ;
	
	for(i=0; i<n; i++)
	{
		printf("�������%d���ڵ��ֵ:", i+1); 
		scanf("%d", &val);
		
		struct node *pnew = (struct node *)malloc(sizeof(struct node));  //���pnew������һ���ڵ� 
		pnew->data = val;     //����һ���ڵ�����Ч���� 
		pone->pnext = pnew;   //����һ���ڵ�ĵ�ַ���͸�ͷ�ڵ� 
		pnew->pnext = NULL;  //��һ���ڵ�ĵ�ַ��ʱΪ�գ�����һ��ѭ���Żᱻ�����ַ   3241
		pone = pnew;   //�Ѻ�һ���ڵ�����ݸ�ͷ�ڵ� 
	}
	return phead1;  // ����ͷָ��ĵ�ַ����forѭ���У��Ѿ���ÿһ���ڵ�ĵ�ַ������ͷ��㣬��ͷָ��ָ��ͷ�ڵ㣬���Է���ͷָ����� 
}

void traverselist (struct node * phead2) //���������������������,phead2������phead�Ľṹ������ 
{
	struct node *p = phead2->pnext;  //�����ָ��p������ͷ���ĵ�ַ 
	while( NULL != p)   //   ��=���ǲ����ڵ���˼   NULL�ǿյ���˼ 
	{
		printf("%d", p->data );   //��Ϊpָ��ͷ��㣬����p->data����ͷ���洢����Ч���� 
		p = p->pnext ;  //��ʱp�Ѿ�ָ�� ͷ����ˣ���ôp->pnext����ͷ����ŵĵ�ַ���ݣ��������ַ������ͷ������һ���ڵ�ĵ�ַ������������� 
	}					//��ͷ�����һ���ڵ�ĵ�ַ����p����ôp��ָ����ͷ������һ���ڵ㣬��ô�´�ѭ����p->data����ͷ�����һ���ڵ����Ч������ 
	return ;   //�����return����ֹ�����������˼ 
}

int main(void)
{
	struct node *phead = NULL;  //ͷ�ڵ�ĵ�ַ��ʱΪ�գ���ִ��createlist������ʱ��ᱻ�����ַ,��֤��creatlist�����ڵ�phead1����һ�� 
	phead = createlist(); //������ǰ�createlist�����ķ���ֵ��phead,Ҳ���ǰѸ��������phead1��ַ���ظ���������phead,��������������ͷָ���һ���� 
	traverselist(phead);   //�����ǰѽ��������ݵ�phead���͸�traverselist������������ 
	
	return 0;
}















