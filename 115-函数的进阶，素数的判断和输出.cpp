# include <stdio.h>

bool sushu1(int m)  //������������ж�m�Ƿ��Ǹ�������������������ԭ������sushu2�������� 
{					//�����m��ʵ���൱��sushu2�е�p��m=p����Ϊsushu2���ǰ�p����m�ģ�������p��ֵ�ľ��Ǻ������ƺ��������ڵ��β� 
	int i;
	
	for(i=2; i<m; i++)
	{
		if(0 == m%i)
			break;
	}
	if(i == m)
		return true;    //һ��Ҫע�⣺�������return���ظ�sushu2��������Ļ�����ô�����ķ���ֵ�Ͳ���дvoid 
	else
		return false;
}

void sushu2(int k)  //��������������һ����Χ�ڵ�����������Ҫ��������Ǹ�sushu1һ���� 
{
	int p;     //�����p���Ǵ洢��Χ�ڵ��������֣�����forѭ��һ�δμ� 
	
	for(p=2; p<k; p++)      //k�����Ǹ���Χk=n 
		if(sushu1(p))     //������ǽ���Χ�ڵ����������õ�sushu1������ȥ�ж��ǲ������� 
			printf("%d\n", p);
		else
			continue;
}

int main(void)
{
	int n;   //�����n�����Ǹ���Χ��Ҳ����������1~n��Χ�ڵ��������� 
	printf("������������ķ�Χ�ڵ�������1-"); 
	scanf("%d", &n);
	sushu2(n);     //������ǰ�n��ֵ����sushu2���������Ҳ���ǰ�n����sushu2�е�k 
	
	return 0;
}
