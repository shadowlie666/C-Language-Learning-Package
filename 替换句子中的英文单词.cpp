# include <stdio.h>
# include <string.h>

int main(void)
{
	char ch[100];   //存放原句子 
	int i=0, p=0, j;    //p指向ch，i指向b，j指向a
	char a[7]="orange";
	char b[100];  //存放替换单词后的新句子 
	
	gets(ch);  //用来读取句子
		                       
	while(ch[p] != '\0') //字符串的结尾是\0，因为gets输入是一次性输完所有元素的，不是一个个输入的 
	{
		if(ch[p]=='a'&&ch[p+1]=='p'&&ch[p+2]=='p'&&ch[p+3]=='l'&&ch[p+4]=='e')  //找到apple单词 
		{
			for(j=0;j<6;j++)  //如果找到了apple，那么新句子就不从原句子中拿单词，改成拿orange插入进去 
			{
				b[i]=a[j];   
				i++;	
			}	
			p += 5;        //不能影响读取原句子apple后面的单词，所以要让p指回apple后面的字符 
		}
		else
		{
			b[i] = ch[p];   //如果没有找到apple，就从原句子中读取单词 
			i++;
			p++;	
		}	
	}
	b[i] = '\0';   //一个个元素复制到新数组b的话结尾是不会有\0的，如果没有\0，puts就无法输出 
	puts(b);
	
	return 0;
} 
