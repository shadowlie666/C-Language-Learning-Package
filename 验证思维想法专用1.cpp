# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <windows.h>
# include <conio.h>
# include <stdlib.h>

typedef struct BookText
{
	char name[20];          //����
	char ISBN[14];			//ISBN
	char author[15];        //������
	char num[10];			//�������
	char borrownum[10];		//�ɽ�������
    struct BookText *next;  //��һ����Ľڵ� 
}Book, *PBook;

PBook pbook = NULL;  //��������ͷָ��
FILE *fp;  //ָ���ļ���ָ��
int booknum = 0;

void InsertBook(PBook* book)
{
	char name[20] ; 
    char c;
    PBook p = *book, q = *book;
    int index, len=0, temp=0;
    printf("\n\t\t��������Ҫ�����λ�ã�");
    scanf("%d", &index);
    while(p!=NULL)
	{
        len++;
        p=p->next;
    }
    if(index>len)
    {
    	printf("\n\t\t����ͼ���������ȣ�Ĭ����ӵ�ĩβ"); 
	}
    p = *book;
    printf("\n\t\t����������:");
    getchar();
    scanf("%s", name);
    while(p != NULL) //�ж�ͼ���Ƿ��ѱ�¼�� 
	{
		if(strcmp(p->name, name) == 0) 
		{
			printf ("\n\t\t��ͼ���ѱ�¼��");
			printf("\n\t\t-----------�������������-----------");
			getch();
			return;
		} 
		else 
		{
			q = p;  //ʼ����q��p��ǰ��һ�� 
			p = p->next;
			if(temp == index)
				break;
			temp++;
		}
	}
	PBook pnew = (PBook)malloc(sizeof(Book));	
	pnew->next = NULL;
	if(pnew == NULL) {
		printf("\n\t\tϵͳ��������ռ�ʧ��");
		printf("\n\t\t-----------�������������-----------");
		getch();
		return;
	}
	
	if(q == NULL)   //�ж��ǲ��ǵ�һ���ڵ� 
		*book = pnew;
	else
	{
		pnew->next = p;
		q->next = pnew;
	}	
	strcpy(pnew->name, name);
    printf("\n\t\t���������ISBN:");  
    getchar();
    gets(pnew->ISBN);
    printf("\n\t\t������������:");
    gets(pnew->author);
    printf("\n\t\t�����뱾��Ŀ������:");
    gets(pnew->num);
    printf("\n\t\t�����뱾��Ŀɽ�������:");
    gets(pnew->borrownum);
    booknum++;
    printf("\n\t\t¼��ɹ�!!!!");
	do
	{
        printf("\n\t\t�Ƿ����¼��(Y/N)?��");  
        scanf("%c", &c);
		if(c == 'y' || c == 'Y')  //�����ִ�Сд�������ݴ� 
			InsertBook(&pbook);
		else if(c == 'n' || c == 'N')
		{
			printf("\n\t\t-----------�������������-----------");
			getch();
			return;
		}
		else
			printf("\n\t\t���벻�Ϸ�������������!");
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');
}

void TraverseBook(PBook pbook)
{
	PBook p = pbook;
    if(p == NULL)    //Ҫ���ж���û��ͼ����� 
		printf("\t\t��ϵͳ����ʱ��û��ͼ��");	   
	else 
	{
		while(p != NULL) 
		{
            printf("\n\t\t ������%s", p->name);
            printf("\n\t\t ISBN��%s", p->ISBN);  
            printf("\n\t\t ��������%s", p->author);
            printf("\n\t\t ���������%s", p->num);
            printf("\n\t\t �ɽ���������%s\n", p->borrownum);
            p = p->next;
		}
	}	
	printf("\n\t\t-----------�������������-----------");
	getch();
	return;
}

void FindBook(PBook pbook)
{
	int flag = 0;  //�Ƿ���ҵ����� 
    char name[20];
    char auth[15];
    PBook p = pbook;
    printf("\n\t\t��������Ҫ��ѯ��������������,�м��ÿո������");
    scanf("%s %s", name, auth);
    printf("\n\t\t-------------���ҽ��-------------\n");
    while(p != NULL) 
	{   
		if(strcmp(p->name, name) == 0 && strcmp(p->author, auth) == 0) 
		{  
			printf("\n\t\t ������%s", p->name);
            printf("\n\t\t ISBN��%s", p->ISBN);  
            printf("\n\t\t ��������%s", p->author);
            printf("\n\t\t ���������%s", p->num);
            printf("\n\t\t �ɽ���������%s", p->borrownum);
            flag = 1;  
            p = p->next;  
		} 
		else
			p = p->next;
	}
	if(flag == 0)
		printf("\n\t\t������˼��ϵͳ��û����ͬ����������������");
	printf("\n\t\t-----------�������������-----------");
	getch();	
}

bool Find(char name[],char key[]) //ͨ��BF�㷨���Ұ����ؼ��ֵ����� 
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
	if(j>strlen(key)) //��������Ҳû�ҵ��Ļ���i���ڲ��ҹ����д��ڳ��ȣ���j���ᣬ�����жϲ��ҳɹ�ֻ�ܸ���j���ж� 
		return true;
	else 
		return false;
}

void KeyFindBook(PBook *pbook) //���˲���˼·����BF������������������������һ�� 
{
	int flag = 0;  
    char key[10];
    PBook p = *pbook;
    printf("\n\t\t\t��������Ҫ��ѯ�Ĺؼ��ʣ�");
    scanf("%s", key);
    printf("\n\t\t-------------���ҽ��-------------\n");
    while(p != NULL) 
	{   
		if(Find(p->name,key)) 
		{  
			printf("\n\t\t ������%s", p->name);
            printf("\n\t\t ISBN��%s", p->ISBN);  
            printf("\n\t\t ��������%s", p->author);
            printf("\n\t\t ���������%s", p->num);
            printf("\n\t\t �ɽ���������%s\n", p->borrownum);
            flag = 1;  
            p = p->next;  
		} 
		else
			p = p->next;
	}
	if(flag == 0)
		printf("\n\t\t������˼��ϵͳ��û���ҵ��ж�Ӧ�ؼ��ֵ���");
	printf("\n\t\t-----------�������������-----------");
	getch();	
}

void DeleteBook(PBook *pbook)
{
	int flag = 1; //�Ƿ�ȷ��ɾ������,�Ƿ���ҵ����Ȿ�� 
    char nameauth[20];
    char c1, c2;
    PBook p = *pbook, q = *pbook;
    printf("\n\t\t-------------ͼ��ɾ��-------------\n");
    printf("\t\t��������Ҫɾ��ͼ�����������������");
    scanf("%s", nameauth);
    while(p != NULL && flag) 
	{
		if(strcmp(p->author, nameauth) == 0 || strcmp(p->name, nameauth) == 0) 
		{  
			printf("\n\t\t ������%s", p->name);
            printf("\n\t\t ISBN��%s", p->ISBN);  
            printf("\n\t\t ��������%s", p->author);
            printf("\n\t\t ���������%s", p->num);
            printf("\n\t\t �ɽ���������%s", p->borrownum);
            printf("\n\t\tȷ��ɾ��?ȷ������Y����������N�� ");  //ѯ���Ƿ�ɾ��
            getchar();
            scanf("%c", &c1);
            if(c1 == 'Y' || c1 == 'y') 
			{    
				if(p == *pbook) //Ҫ�ж�ɾ�����ǲ��ǵ�һ���ڵ� 
				{
					*pbook = p->next;
					free(p);  //ɾ��ͼ����Ϣ
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
				printf("ȡ��ɾ���ɹ�");
				printf("\n\t\t-----------�������������-----------");
				getch();
				return;
			}
		} 
		else 
		{
			q = p;		//ʼ�ձ���q��pǰ��һ��������ɾ������ 
			p = p->next;  
		} 
		printf("\t\tɾ���ɹ�������\n");
	}
	
	if(flag)
		printf("\t\tû���ҵ��Ȿ�飬��������ȷ������");
	
	do 
	{
		printf("\n�Ƿ����(Y/N)?��"); 
        getchar();
        scanf("%c", &c2);
        if(c2 == 'y' || c2 == 'Y')
			DeleteBook(pbook);  
		else if(c2 == 'n' || c2 == 'N')
		{
			printf("\n\t\t-----------�������������-----------");
			getch();
			return;
		}
		else
			printf("\n\t\t�����������������!!!");
	} while(c2 != 'y' && c2 != 'n' && c2 != 'Y' && c2 != 'N');	
}

void EditBook(PBook pbook)
{
	int flag = 1;
    char name[20], temp[20];
    char c;
    PBook p = pbook;
    printf("\n\t\t----------------ͼ����Ϣ�޸�----------------\n");
    printf("\t\t������Ҫ�޸ĵ�ͼ���������");
    scanf("%s", name);  
    while(p != NULL && flag) 
	{
		if(strcmp(p->name, name) == 0) //���ҵ��Ǹ�ͼ��
		{ 
			printf("\n\t\t ������%s", p->name);
            printf("\n\t\t ISBN��%s", p->ISBN);  
            printf("\n\t\t ��������%s", p->author);
            printf("\n\t\t ���������%s", p->num);
            printf("\n\t\t �ɽ���������%s", p->borrownum);
            printf("\n\t\t ��������Ҫ�޸ĵ��������ƣ�"); 
            getchar();
            scanf("%s", temp);
            if(strcmp("����", temp) == 0)
            {
            	printf("\n\t\t��������:");
            	getchar();
            	scanf("%s", &p->name);      	
			}
			else if(strcmp("ISBN", temp) == 0)
			{
				printf("\n\t\t������ISBN:");
				getchar();
	            scanf("%s", &p->ISBN);
			}
			else if(strcmp("������", temp) == 0)
            {
            	printf("\n\t\t����������:");
            	getchar();
            	scanf("%s", &p->author);         
			}
            else if(strcmp("�������", temp) == 0) 
            {
            	printf("\n\t\t����������:");
            	getchar();
    			scanf("%s", &p->num);	
			}
            else if(strcmp("�ɽ�������", temp) == 0)
            {
            	printf("\n\t\t����ɽ�������:");
            	getchar();
    			scanf("%s", &p->borrownum);	
			}
            flag = 0;
            printf("\n\t\t�޸ĳɹ�\n");
		} 
		else
			p = p->next;  
	}
	
	if(flag)
		printf("\n\t\tû����������ͼ��");
	
	do 
	{
		printf("\n\t\t�Ƿ�����޸�(Y/N)?��"); 
        getchar();
        scanf("%c", &c);
		if(c == 'y' || c == 'Y')
			EditBook(pbook);  
		else if(c == 'n' || c == 'N')
		{
			printf("\n\t\t-----------�������������-----------");
			getch();
			return;
		}
		else
			printf("\n\t\t��������ȷ����ĸ");
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N'); 	
}

void SaveBook()
{
	PBook book = pbook;
 
	if (book == NULL)
	{
		printf("\n\t\tϵͳ��û��ͼ��");
		return;
	}
	if ((fp = fopen("books2.txt", "wb")) == NULL) //��Ҫ��ͬһĿ¼�´���һ��books2.txt���ļ�
	{
		printf("\n\t\t�����ļ�ʧ��\n");
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
	printf("\t\t����ɹ�");
	printf("\n\t\t-----------�������������-----------");
	getch();
}

void ReadBook()
{
	PBook p, q;
    char file[50];
    printf("\n\t\t�������ı��ĵ����ڵ��ļ�·��:");
    getchar();
    scanf("%s", file);  
    fp = fopen(file, "r");
    if(fp == NULL) 
	{  
		printf("\n\t\t���ܴ��ļ�!\n");
		printf("\n\t\t-----------�������������-----------");
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
			       &q->name, &q->ISBN, &q->author, &q->num, &q->borrownum);  //�����ļ�����
			p->next = q;
			p = q;
			booknum++;
		} while(!feof(fp));  //����ļ��Ƿ���� 
		p->next = NULL;  
	}
	printf("\n\t\tд�����ݳɹ�");
	fclose(fp);  
	printf("\n\t\t-----------�������������-----------");
	getch();
	return;	
}

void Exit()
{
	char c;   
	do {
		printf("\n\t\t�Ƿ񱣴浽�ļ���ȥ(Y/N)?");  
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
			printf("\n\t\t��������ȷ����ĸ");
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');  //���������ѯ��	
}

int Menu()
{
	int i = 1;
    printf("\n\t\t\t\t\t��ӭʹ��ͼ����Ϣ����ϵͳ\n\n\n\n");
    printf("\t\t\t\t------------------�˵�------------------\n");  //���˵�
	printf("\t\t\t\t  1.  �ֶ�¼��ͼ����Ϣ��ָ��λ��\n"); 
    printf("\t\t\t\t  2.  ��ȡ����ͼ����Ϣ\n");  
    printf("\t\t\t\t  3.  ������������������ͼ��\n"); 
    printf("\t\t\t\t  4.  ͨ�������ؼ��ʲ�������\n");
    printf("\t\t\t\t  5.  �����������������в��Ҳ�ɾ��ͼ��\n");
    printf("\t\t\t\t  6.  �޸�ͼ����Ϣ\n");
    printf("\t\t\t\t  7.  �����ļ���Ϣ\n");
    printf("\t\t\t\t  8.  �ӵ����ж���ͼ����Ϣ\n"); 
    printf("\t\t\t\t  9.  �˳�ϵͳ\n ");
    
    printf("\n\t\t\t��ѡ��������Ҫ�ķ���������ţ���");
	scanf("%d", &i);
    while(true)
    {
    	if(i>=1 && i<=9)
			return i;
		else 
		{
			printf("\t\t\t��������ȷ�����:");
			scanf("%d", &i);
		}
	}  
}

int main(void)
{
	while(true)
	{
		system("cls"); //���� 
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

