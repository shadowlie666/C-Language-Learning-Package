# include <stdio.h>

enum xingqi      //ͬ�ṹ��һ���������enum xingqiֻ��һ���������� 
{
	monday, tuesday, wednesday, thursday, friday, saturday, sunday //���������monday�ĳ�monday=4����ô��11�е��������ͱ��2�� 
};  //�����Ƿֺ� 

int main(void)
{
	enum xingqi day = tuesday;  //�����day���Ǳ��� 
	printf("%d", day);   //����������1����ΪĬ��monday��0��tuesday��1��wednesday��2.������ 
	
	return 0;	
} 
