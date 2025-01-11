# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <windows.h>
# include <conio.h>
# include <stdlib.h>

typedef struct BookText
{
	char name[20];          //书名
	char ISBN[14];			//ISBN
	char author[15];        //作者名
	char num[10];			//库存数量
	char borrownum[10];		//可借阅数量
    struct BookText *next;  //下一个书的节点 
}Book, *PBook;

PBook pbook = NULL;  //书的链表的头指针
FILE *fp;  //指向文件的指针
int booknum = 0;

void InsertBook(PBook* book)
{
	char name[20] ; 
    char c;
    PBook p = *book, q = *book;
    int index, len=0, temp=0;
    printf("\n\t\t请输入需要插入的位置：");
    scanf("%d", &index);
    while(p!=NULL)
	{
        len++;
        p=p->next;
    }
    if(index>len)
    {
    	printf("\n\t\t超出图书总数长度，默认添加到末尾"); 
	}
    p = *book;
    printf("\n\t\t请输入书名:");
    getchar();
    scanf("%s", name);
    while(p != NULL) //判断图书是否已被录入 
	{
		if(strcmp(p->name, name) == 0) 
		{
			printf ("\n\t\t该图书已被录入");
			printf("\n\t\t-----------按下任意键继续-----------");
			getch();
			return;
		} 
		else 
		{
			q = p;  //始终让q在p的前面一个 
			p = p->next;
			if(temp == index)
				break;
			temp++;
		}
	}
	PBook pnew = (PBook)malloc(sizeof(Book));	
	pnew->next = NULL;
	if(pnew == NULL) {
		printf("\n\t\t系统出错，分配空间失败");
		printf("\n\t\t-----------按下任意键继续-----------");
		getch();
		return;
	}
	
	if(q == NULL)   //判断是不是第一个节点 
		*book = pnew;
	else
	{
		pnew->next = p;
		q->next = pnew;
	}	
	strcpy(pnew->name, name);
    printf("\n\t\t请输入书的ISBN:");  
    getchar();
    gets(pnew->ISBN);
    printf("\n\t\t请输入作者名:");
    gets(pnew->author);
    printf("\n\t\t请输入本书的库存数量:");
    gets(pnew->num);
    printf("\n\t\t请输入本书的可借阅数量:");
    gets(pnew->borrownum);
    booknum++;
    printf("\n\t\t录入成功!!!!");
	do
	{
        printf("\n\t\t是否继续录入(Y/N)?：");  
        scanf("%c", &c);
		if(c == 'y' || c == 'Y')  //不区分大小写，增加容错 
			InsertBook(&pbook);
		else if(c == 'n' || c == 'N')
		{
			printf("\n\t\t-----------按下任意键继续-----------");
			getch();
			return;
		}
		else
			printf("\n\t\t输入不合法，请重新输入!");
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');
}

void TraverseBook(PBook pbook)
{
	PBook p = pbook;
    if(p == NULL)    //要先判断有没有图书遍历 
		printf("\t\t该系统中暂时还没有图书");	   
	else 
	{
		while(p != NULL) 
		{
            printf("\n\t\t 书名：%s", p->name);
            printf("\n\t\t ISBN：%s", p->ISBN);  
            printf("\n\t\t 作者名：%s", p->author);
            printf("\n\t\t 库存数量：%s", p->num);
            printf("\n\t\t 可借阅数量：%s\n", p->borrownum);
            p = p->next;
		}
	}	
	printf("\n\t\t-----------按下任意键继续-----------");
	getch();
	return;
}

void FindBook(PBook pbook)
{
	int flag = 0;  //是否查找到该书 
    char name[20];
    char auth[15];
    PBook p = pbook;
    printf("\n\t\t请输入需要查询的书名和作者名,中间用空格隔开：");
    scanf("%s %s", name, auth);
    printf("\n\t\t-------------查找结果-------------\n");
    while(p != NULL) 
	{   
		if(strcmp(p->name, name) == 0 && strcmp(p->author, auth) == 0) 
		{  
			printf("\n\t\t 书名：%s", p->name);
            printf("\n\t\t ISBN：%s", p->ISBN);  
            printf("\n\t\t 作者名：%s", p->author);
            printf("\n\t\t 库存数量：%s", p->num);
            printf("\n\t\t 可借阅数量：%s", p->borrownum);
            flag = 1;  
            p = p->next;  
		} 
		else
			p = p->next;
	}
	if(flag == 0)
		printf("\n\t\t不好意思，系统里没有相同书名和作者名的书");
	printf("\n\t\t-----------按下任意键继续-----------");
	getch();	
}

bool Find(char name[],char key[]) //通过BF算法查找包含关键字的书名 
{
	int i=0, j=0;
	while(i<=strlen(name) && j<=strlen(key))
	{
		if(name[i]==key[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j>strlen(key)) //如果到最后也没找到的话，i会在查找过程中大于长度，而j不会，所以判断查找成功只能根据j来判断 
		return true;
	else 
		return false;
}

void KeyFindBook(PBook *pbook) //除了查找思路用了BF，其他与书名和作者名查找一样 
{
	int flag = 0;  
    char key[10];
    PBook p = *pbook;
    printf("\n\t\t\t请输入需要查询的关键词：");
    scanf("%s", key);
    printf("\n\t\t-------------查找结果-------------\n");
    while(p != NULL) 
	{   
		if(Find(p->name,key)) 
		{  
			printf("\n\t\t 书名：%s", p->name);
            printf("\n\t\t ISBN：%s", p->ISBN);  
            printf("\n\t\t 作者名：%s", p->author);
            printf("\n\t\t 库存数量：%s", p->num);
            printf("\n\t\t 可借阅数量：%s\n", p->borrownum);
            flag = 1;  
            p = p->next;  
		} 
		else
			p = p->next;
	}
	if(flag == 0)
		printf("\n\t\t不好意思，系统里没有找到有对应关键字的书");
	printf("\n\t\t-----------按下任意键继续-----------");
	getch();	
}

void DeleteBook(PBook *pbook)
{
	int flag = 1; //是否确认删除操作,是否查找到了这本书 
    char nameauth[20];
    char c1, c2;
    PBook p = *pbook, q = *pbook;
    printf("\n\t\t-------------图书删除-------------\n");
    printf("\t\t请输入你要删除图书的书名或作者名：");
    scanf("%s", nameauth);
    while(p != NULL && flag) 
	{
		if(strcmp(p->author, nameauth) == 0 || strcmp(p->name, nameauth) == 0) 
		{  
			printf("\n\t\t 书名：%s", p->name);
            printf("\n\t\t ISBN：%s", p->ISBN);  
            printf("\n\t\t 作者名：%s", p->author);
            printf("\n\t\t 库存数量：%s", p->num);
            printf("\n\t\t 可借阅数量：%s", p->borrownum);
            printf("\n\t\t确定删除?确定请输Y，否则输入N： ");  //询问是否删除
            getchar();
            scanf("%c", &c1);
            if(c1 == 'Y' || c1 == 'y') 
			{    
				if(p == *pbook) //要判断删除的是不是第一个节点 
				{
					*pbook = p->next;
					free(p);  //删除图书信息
				}
				else 
				{
					q->next = p->next;
					free(p);
				}
				flag = 0;
			} 
			else 
			{
				printf("取消删除成功");
				printf("\n\t\t-----------按下任意键继续-----------");
				getch();
				return;
			}
		} 
		else 
		{
			q = p;		//始终保持q在p前面一个，方便删除操作 
			p = p->next;  
		} 
		printf("\t\t删除成功！！！\n");
	}
	
	if(flag)
		printf("\t\t没有找到这本书，请输入正确的书名");
	
	do 
	{
		printf("\n是否继续(Y/N)?："); 
        getchar();
        scanf("%c", &c2);
        if(c2 == 'y' || c2 == 'Y')
			DeleteBook(pbook);  
		else if(c2 == 'n' || c2 == 'N')
		{
			printf("\n\t\t-----------按下任意键继续-----------");
			getch();
			return;
		}
		else
			printf("\n\t\t输入错误，请重新输入!!!");
	} while(c2 != 'y' && c2 != 'n' && c2 != 'Y' && c2 != 'N');	
}

void EditBook(PBook pbook)
{
	int flag = 1;
    char name[20], temp[20];
    char c;
    PBook p = pbook;
    printf("\n\t\t----------------图书信息修改----------------\n");
    printf("\t\t请输入要修改的图书的书名：");
    scanf("%s", name);  
    while(p != NULL && flag) 
	{
		if(strcmp(p->name, name) == 0) //查找到那个图书
		{ 
			printf("\n\t\t 书名：%s", p->name);
            printf("\n\t\t ISBN：%s", p->ISBN);  
            printf("\n\t\t 作者名：%s", p->author);
            printf("\n\t\t 库存数量：%s", p->num);
            printf("\n\t\t 可借阅数量：%s", p->borrownum);
            printf("\n\t\t 请输入你要修改的数据名称："); 
            getchar();
            scanf("%s", temp);
            if(strcmp("书名", temp) == 0)
            {
            	printf("\n\t\t输入书名:");
            	getchar();
            	scanf("%s", &p->name);      	
			}
			else if(strcmp("ISBN", temp) == 0)
			{
				printf("\n\t\t请输入ISBN:");
				getchar();
	            scanf("%s", &p->ISBN);
			}
			else if(strcmp("作者名", temp) == 0)
            {
            	printf("\n\t\t输入作者名:");
            	getchar();
            	scanf("%s", &p->author);         
			}
            else if(strcmp("库存数量", temp) == 0) 
            {
            	printf("\n\t\t输入库存数量:");
            	getchar();
    			scanf("%s", &p->num);	
			}
            else if(strcmp("可借阅数量", temp) == 0)
            {
            	printf("\n\t\t输入可借阅数量:");
            	getchar();
    			scanf("%s", &p->borrownum);	
			}
            flag = 0;
            printf("\n\t\t修改成功\n");
		} 
		else
			p = p->next;  
	}
	
	if(flag)
		printf("\n\t\t没有搜索到该图书");
	
	do 
	{
		printf("\n\t\t是否继续修改(Y/N)?："); 
        getchar();
        scanf("%c", &c);
		if(c == 'y' || c == 'Y')
			EditBook(pbook);  
		else if(c == 'n' || c == 'N')
		{
			printf("\n\t\t-----------按下任意键继续-----------");
			getch();
			return;
		}
		else
			printf("\n\t\t请输入正确的字母");
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N'); 	
}

void SaveBook()
{
	PBook book = pbook;
 
	if (book == NULL)
	{
		printf("\n\t\t系统中没有图书");
		return;
	}
	if ((fp = fopen("books2.txt", "wb")) == NULL) //需要在同一目录下创建一个books2.txt的文件
	{
		printf("\n\t\t创建文件失败\n");
		getchar();
		return;
	}
	while (book)
	{
		fprintf(fp, "%s %s %s %s %s\n",
		       &book->name, &book->ISBN, &book->author, &book->num, &book->borrownum);		
		book = book->next;
	}
	printf("\n");
	fclose(fp);
	printf("\t\t保存成功");
	printf("\n\t\t-----------按下任意键继续-----------");
	getch();
}

void ReadBook()
{
	PBook p, q;
    char file[50];
    printf("\n\t\t请输入文本文档所在的文件路径:");
    getchar();
    scanf("%s", file);  
    fp = fopen(file, "r");
    if(fp == NULL) 
	{  
		printf("\n\t\t不能打开文件!\n");
		printf("\n\t\t-----------按下任意键继续-----------");
		getch();
		return;
	}
	else 
	{
		p = (PBook)malloc(sizeof(Book));  
		pbook = p;  
		fscanf(fp, "%s %s %s %s %s\n",
		       &p->name, &p->ISBN, &p->author, &p->num, &p->borrownum); 
		booknum++;
		do 
		{
			q = (PBook)malloc(sizeof(Book));  
			fscanf(fp,"%s %s %s %s %s\n",
			       &q->name, &q->ISBN, &q->author, &q->num, &q->borrownum);  //读入文件数据
			p->next = q;
			p = q;
			booknum++;
		} while(!feof(fp));  //检查文件是否读完 
		p->next = NULL;  
	}
	printf("\n\t\t写入数据成功");
	fclose(fp);  
	printf("\n\t\t-----------按下任意键继续-----------");
	getch();
	return;	
}

void Exit()
{
	char c;   
	do {
		printf("\n\t\t是否保存到文件中去(Y/N)?");  
		getchar();
        scanf("%c", &c);
        if(c == 'y' || c == 'Y') 
		{
			SaveBook();
			exit(0);
		} 
		else if(c == 'n' || c == 'N')
		{
			exit(0);
		}
		else
			printf("\n\t\t请输入正确的字母");
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');  //错误则继续询问	
}

int Menu()
{
	int i = 1;
    printf("\n\t\t\t\t\t欢迎使用图书信息管理系统\n\n\n\n");
    printf("\t\t\t\t------------------菜单------------------\n");  //主菜单
	printf("\t\t\t\t  1.  手动录入图书信息至指定位置\n"); 
    printf("\t\t\t\t  2.  获取所有图书信息\n");  
    printf("\t\t\t\t  3.  按书名和作者名查找图书\n"); 
    printf("\t\t\t\t  4.  通过其他关键词查找书名\n");
    printf("\t\t\t\t  5.  按书名或作者名进行查找并删除图书\n");
    printf("\t\t\t\t  6.  修改图书信息\n");
    printf("\t\t\t\t  7.  保存文件信息\n");
    printf("\t\t\t\t  8.  从电脑中读入图书信息\n"); 
    printf("\t\t\t\t  9.  退出系统\n ");
    
    printf("\n\t\t\t请选择您所需要的服务（输入序号）：");
	scanf("%d", &i);
    while(true)
    {
    	if(i>=1 && i<=9)
			return i;
		else 
		{
			printf("\t\t\t请输入正确的序号:");
			scanf("%d", &i);
		}
	}  
}

int main(void)
{
	while(true)
	{
		system("cls"); //清屏 
		switch(Menu())
		{
			case 1:
				InsertBook(&pbook);
				break;
			case 2:
				TraverseBook(pbook);
				break;
			case 3:
				FindBook(pbook);
				break;
			case 4:
				KeyFindBook(&pbook);
				break;
			case 5:
				DeleteBook(&pbook);
				break;
			case 6:
				EditBook(pbook);
				break;
			case 7:
				SaveBook();
				break;
			case 8:
				ReadBook();
				break;
			case 9:
				Exit();
				break;
			default:
				putchar('\a');
		}
	}
	
	return 0;
}

