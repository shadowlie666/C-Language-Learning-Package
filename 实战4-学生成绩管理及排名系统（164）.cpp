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
	
	printf("������ѧ���ĸ�����");
	scanf("%d", &n);
	p = (struct student*)malloc(n*sizeof(struct student));  //������Ǵ�����n���ṹ�壬�Ҷ����Զ�̬�ڴ���ʽ����ģ�ͬʱpָ�������ṹ�� 
	
	for(i=0; i<n; i++)  //���forѭ������������ѧ����Ϣ�� 
	{
		printf("�������%d��ѧ������Ϣ\n", i+1) ;
		printf("age = ");
		scanf("%d", &p[i].age );  //p[0].age����p��ָ��ĵ�һ���ṹ�������age��Ϣ��Ҳ���ǵ�һ��ѧ����age��Ϣ��һ���ṹ�����һ��ѧ���� 
		printf("score = ");        //�ṹ�������Ԫ�ؾ���ѧ������Ϣ�������p[0]�ĳ���p[i]�Ϳ����������ṹ�壨ѧ��������Ϣ 
		scanf("%lf", &p[i].score);
		printf("name = ");
		scanf("%s", p[i].name);  //char������ַ��������ʱ���ü�ȡ��ַ�� 
	}
	
	for(i=0; i<n-1; i++)          //�������ð����������ѧ���ĳɼ��������ο�163-ð������ 
	{
		for(k=0; k<n-1-i; k++)    //p��struct student *���ͣ���p[0]��struct student���� 
		{
			if(p[k].score >p[k+1].score ) //p[k]ָ����p��ָ����Ǹ��ṹ�壬�ṹ�屾���ǲ��ܱȽϴ�С�ģ�����Ҫд��p[k].score 
			{                            //�����ͱ�ɾ���Ƚ������ṹ���е�scoreԪ�صĴ�С 
				t = p[k];
				p[k] = p[k+1];    //ע�������ǽ����Ľṹ�壬��ֻ�ǵ������������ṹ���е�score���ݣ������ǰ������ṹ������������ڴ�ռ� 
				p[k+1] = t;
			}
		}
	}
	
	printf("ѧ���ĳɼ��������£�\n");
	for(i=0; i<n; i++)                     //���forѭ������������������ѧ����Ϣ����ѭ������ΪҪ�������ṹ���ڵ�Ԫ�أ����ѧ������Ϣ�� 
	{
		printf("name = %s\n", p[i].name);
		printf("age = %d\n", p[i].age );
		printf("score = %lf\n", p[i].score);
		printf("\n");
	}
	
	return 0;
}
