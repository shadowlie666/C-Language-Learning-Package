# include <stdio.h>

int jc(int n)
{
	if(n==0)
		return 1; //ע������ֻ�Ǽ��㵥���׳ˣ����Խ����1û��ν��������Ǽ���׳˵ĺͣ�����Ӧ��+0����ô�����Ӧ����return 0 
	else
		return n * jc(n-1);  //�����ȵݹ鷵��5*4*3*2*1*jc(0)         ��Ϊjc(0)=1 ,������˸�1����ν 
		                     //֮���Ի��������return�����Ⱥ�˳��ģ�����һֱִ�е���else��䣬���8�е�return��ִ�� 
}							//����5�е��������ִ�У�����������return���ص�ֵӦ�����ڵڰ����Ǹ�return����ֵ�ĺ��� 

int main(void)
{
	int n, result;
	scanf("%d", &n);   //����n=5 
	result = jc(n);
	printf("%d", result);
	
	return 0;
}
