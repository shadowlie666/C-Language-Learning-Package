# include <stdio.h>
#include <string.h>

struct student
{
	int age;
	char name[5];
	char sex;
}; 

void inputstudent(struct student *b)  //����ı�*b���Ǹı�a 
{										//���������Ŀ�ľ���ͨ��ָ����a��ֵ�ı� 
	b->age = 20;
	strcpy(b->name,"����");
	(*b).sex = 'F'; 
}

void outputstudent(struct student c)  //�����c�Ѿ�������a��ֵ��ִ���������Ǹ�������a��ֵ���Ѿ��Ĺ��ˣ������������c��������Ĺ����a��ֵ 
{										//cֻ�𵽽���a��ֵȻ����������ã����ö�a��ֵ���и��ģ����Կ��Բ���ָ�� 
	printf("%d   %s    %c", c.age, c.name, c.sex);
}

int main(void)
{
	struct student a;
	inputstudent (&a);   //�����������inputstudent�����޸Ľṹ��a��ֵ 
	outputstudent(a);   //�����޸ĺ��a��ֵ������outputstudent�������a 
	
	return 0;
}
//��Ȼ����18�����ﻹ����ָ��ȽϺã���Ϊָ��ֻռ4�ֽڣ����ṹ���е�������Ȼ��ֹ4�ֽڣ������a�����ݷ��͸�c�Ļ��϶��ڴ������л���
//���Է���a�ĵ�ַ��c�Ļ������ٶȸ��죬ռ���ڴ��С����Ҫ������ĳɣ�*c��.age���� 
