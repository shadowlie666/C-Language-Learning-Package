# include <stdio.h>
# include <math.h> 
 
 int main (void)
 { 
 int a = 1;
 int b = 2;
 int c = 3;
 float delta;  //float�õ��ǵ����ȣ����Ǹ�С��ʵ�����ö�double�滻float���ã�˫���� 
 float x1;
 float x2;
 delta = b*b-4*a*c;  //ע����ʱ����ʡ�Գ˺ţ����������ѧ��һ���������ַ���һ��ʱ����ʾ��� 
 
   if (delta>0)
    { 
    	x1 = (-b+sqrt(delta) / (2*a));  //sqrt�ǵڶ����������math.h���ߣ���ʾ���ŵ���˼ 
    	x2 = (-b-sqrt(delta) / (2*a));
    	printf("�÷����������⣬x1 = %f,x2 = %f\n",x1,x2);  //�����\n��ʾ���У�ʹ�������������У��������� 
    }
    
    else if (delta == 0)
    {
   	   x1 = (-b)/(2*a);
 	   x2 = x1;
 	   printf("�÷���ֻ��һ����,x1=x2=%f\n",x1,x2);
    } 
    
     else if(delta<0)
     {
  	   printf("�÷���û�н�\n");
    }
      
	  return 0; 
  } 
  
  /*
  �ܽᣬ�ô���ǰ�����û����淶
  
  #include <stdio.h>
  
  int main(void)
  {
  ......
  
  	return o;
  } 
  
  */ 
