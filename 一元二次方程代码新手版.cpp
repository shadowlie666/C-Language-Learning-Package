# include <stdio.h>
# include <math.h> 
 
 int main (void)
 { 
 int a = 1;
 int b = 2;
 int c = 3;
 float delta;  //float用的是单精度，他是个小数实际上用都double替换float更好，双精度 
 float x1;
 float x2;
 delta = b*b-4*a*c;  //注意编程时不能省略乘号，计算机和数学不一样，两个字符挨一块时不表示相乘 
 
   if (delta>0)
    { 
    	x1 = (-b+sqrt(delta) / (2*a));  //sqrt是第二行中引入的math.h工具，表示根号的意思 
    	x2 = (-b-sqrt(delta) / (2*a));
    	printf("该方程有两个解，x1 = %f,x2 = %f\n",x1,x2);  //这里的\n表示换行，使输出结果单独成行，更加整洁 
    }
    
    else if (delta == 0)
    {
   	   x1 = (-b)/(2*a);
 	   x2 = x1;
 	   printf("该方程只有一个解,x1=x2=%f\n",x1,x2);
    } 
    
     else if(delta<0)
     {
  	   printf("该方程没有解\n");
    }
      
	  return 0; 
  } 
  
  /*
  总结，敲代码前先练好基本规范
  
  #include <stdio.h>
  
  int main(void)
  {
  ......
  
  	return o;
  } 
  
  */ 
