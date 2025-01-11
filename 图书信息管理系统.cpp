#include <iostream>  /*���ÿ⺯��*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
typedef struct book_info { //����ͼ����Ϣ�Ľṹ������������µ�������
	char name[20];          /*����*/
	char ISBN[14];			/*ISBN*/
	char author[20];        /*������*/
	char stock[10];			/*�������*/
	char ava[10];			/*�ɽ�������*/
    char clc[10];          /*������*/
    char company[20];      /*���浥λ*/
    char date[20];          /*��������*/
    char price[10];        /*�۸�*/
    struct book_info *next;
}Booklist, *Pointer;
int num = 0;  //ȫ�ֱ����Ķ���
Pointer Head = NULL;  //ͷָ��Ϊ��
FILE *fp;  //ָ���ļ���ָ��

/*��������*/
void Insert(Pointer * Head);  /*¼�뺯��*/
void Scan(Pointer Head);  /*��ʾ����*/
void Search_name(Pointer Head);  /*�����������������Һ���*/
void Search_author(Pointer Head);  /*�����������Һ���*/
void Listbyname(Pointer *Head);  /*������������*/
void Delete(Pointer * Head);  //ɾ������
void Update(Pointer Head);  //�޸ĺ���
void Save();  //���ı��ļ���ʽ���溯��
void Read();  //�����ı��ļ�����
void Exit();  //�˳�����
int menu_select();  /*���˵�����*/

void Insert(Pointer *Head) { //¼��ͼ����Ϣ����
	char ISBN[10] ;
    char c;
    Pointer p, q, r;
    printf("\n\t\t**************** ������ͼ����Ϣ ****************\n");  /*��������*/
    printf("\n\t\t������ISBN:");
    scanf("%s", ISBN);
    p = q = *Head;  //���ISBN�Ƿ��ظ�
    while(p != NULL) {
		if(strcmp(p->ISBN, ISBN) == 0) {
			printf ("�Ѿ�����ͬ��ISBN��");
			return;
		} else {
			q = p;
			p = p->next;
		}
	}
	r = (Pointer)malloc(sizeof(Booklist));
	r->next = NULL;
	
	if(r == NULL) {
		printf("����ռ�ʧ��!");
		return;
	}
	
	if(q == NULL)
		*Head = r;
	else{
		q->next = r;
	}
	
	strcpy(r->ISBN, ISBN);
    printf("\n\t\t��������:");  //¼��ͼ����Ϣ
    scanf("%s", r->name);
    getchar();
    printf("\n\t\t����������:");
    scanf("%s", r->author);
    getchar();
    printf("\n\t\t����������:");
    scanf("%s", r->stock);
    getchar();
    printf("\n\t\t����ɽ�������:");
    scanf("%s", r->ava);
    getchar();
    printf("\n\t\t��������:");
    scanf("%s", r->clc) ;
    getchar();
    printf("\n\t\t������浥λ:");
    scanf("%s", r->company) ;
    getchar();
    printf("\n\t\t�����������:");
    gets(r->date) ;
    printf("\n\t\t����۸�:");
    scanf("%s", r->price);  
	do{
		printf("\n\t\t¼��ɹ�!!!!");
        num++;
        printf("ѡ���Ƿ����¼��(Y/N)?��");  /*����¼��ͼ����Ϣ*/
        getchar();
        scanf("%c", &c);
		if(c == 'y' || c == 'Y')
			Insert(Head);
		else {
			if(c == 'n' || c == 'N')
				return;
			else
				printf("\n\t\t�����������������!!!");
		}
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');
}

void Scan(Pointer Head) {  //��ʾͼ����Ϣ����
	Pointer p;
    p = Head;
    if(p == NULL)
		printf("��¼Ϊ��");  //����Ƿ���ͼ����Ϣ
	else {
		printf("\n\t����%d����¼",num);
		while(p != NULL) {
			printf("\n\n\t\tISBN��%-10s", p->ISBN);  //��ʾͼ����Ϣ
            printf("\n\t\t������    %-20s", p->name);
            printf("\n\t\t��������  %-20s", p->author);
            printf("\n\t\t���������  %-20s", p->stock);
            printf("\n\t\t�ɽ���������  %-20s", p->ava);
            printf("\n\t\t����ţ�  %-10s", p->clc);
            printf("\n\t\t���浥λ��%-20s", p->company);
            printf("\n\t\t����ʱ�䣺%-20s", p->date);
            printf("\n\t\t�۸�    ��%-10s", p->price);
            p = p->next;
		}
		printf("\n\t\t�밴������ص����˵�");
		return;
	}
}

void Search_name(Pointer Head) {  //�����������������Һ���
	int flag = 0;  //��Ǳ����ĳ�ֵ
    char name1[10];
    char name2[20];
    Pointer p;
    printf("\n��������Ҫ��ѯ����������������");
    scanf("%s%s", name1,name2);
    printf("\n\t\t************* �����������ҵ���Ϣ ***************");
    p = Head;
    while(p != NULL) {   
		if(strcmp(p->name, name1) == 0 && strcmp(p->author, name2) == 0) {  //���ҷ��ϵ�ͼ�� 
			printf("\n\tISBN��  %-10s", p->ISBN);
            printf("\n\t������    %-20s", p->name);
            printf("\n\t��������  %-20s", p->author);
            printf("\n\t\t���������  %-20s", p->stock);
            printf("\n\t\t�ɽ���������  %-20s", p->ava);
            printf("\n\t����ţ�  %-10s", p->clc);
            printf("\n\t���浥λ��%-20s", p->company);
            printf("\n\t����ʱ�䣺%-20s", p->date);
            printf("\n\t�۸�    ��%-10s", p->price);
            flag = 1;  //�ҵ���Ǳ�����Ϊ1
            p = p->next;  //ָ���ߵ���һ���ڵ�
		} else
			p = p->next;
	}
	if(flag == 0)
		printf("\n\t\tû����ͬ��������������¼");
	printf("\n\t\t�밴������������˵�");
	getchar();
}

/*ʵ��ͨ��ĳ���ؼ��ʲ�ѯ���������ùؼ��ʵ�����ͼ��*/ 
int Index_BF(char S[],char T[],int pos){
	int i=pos;int j=1;
	while(i<=strlen(S) && j<=strlen(T)){
		if(S[i]==T[j]){++i,++j;}
		else{i=i-j+2;j=1;}
	}
	if(j>strlen(T)) return i-strlen(T);
	else return 0;
}

void keywordsearch(Pointer *Head){
	int flag = 0;  //��Ǳ����ĳ�ֵ
    char name[10];
    Pointer p;
    printf("\n��������Ҫ��ѯ�Ĺؼ��ʣ�");
    scanf("%s", name);
    printf("\n\t\t************* �����������ҵ���Ϣ ***************");
    p = *Head;
    while(p != NULL) {   
		if(Index_BF(p->name,name,0) != 0 ) {  //���ҷ��ϵ�ͼ�� 
			printf("\n\tISBN��  %-10s", p->ISBN);
            printf("\n\t������    %-20s", p->name);
            printf("\n\t��������  %-20s", p->author);
            printf("\n\t\t���������  %-20s", p->stock);
            printf("\n\t\t�ɽ���������  %-20s", p->ava);
            printf("\n\t����ţ�  %-10s", p->clc);
            printf("\n\t���浥λ��%-20s", p->company);
            printf("\n\t����ʱ�䣺%-20s", p->date);
            printf("\n\t�۸�    ��%-10s", p->price);
            flag = 1;  //�ҵ���Ǳ�����Ϊ1
            p = p->next;  //ָ���ߵ���һ���ڵ�
		} else
			p = p->next;
	}
	if(flag == 0)
		printf("\n\t\tû����ͬ��������������¼");
	printf("\n\t\t�밴������������˵�");
	getchar();
}

void insertNode(Pointer Head){/*�Ӽ�������һ���������Ϣ�����뵽����ָ����λ��*/ 
	int index;
	Pointer p;
    Booklist *s = new Booklist;
    printf("\n��������Ҫ�����λ�ã�");
    scanf("%d", index);
    printf("\n�������������Ϣ��");
    printf("\n\t\t��������:");  //¼��ͼ����Ϣ
    scanf("%s", s->name);
    getchar();
    printf("\n\t\t����ISBN:");
    scanf("%s", s->ISBN);
    getchar();
    printf("\n\t\t����������:");
    scanf("%s", s->author);
    getchar();
    printf("\n\t\t����������:");
    scanf("%s", s->stock);
    getchar();
    printf("\n\t\t����ɽ�������:");
    scanf("%s", s->ava);
    getchar();
    printf("\n\t\t��������:");
    scanf("%s", s->clc) ;
    getchar();
    printf("\n\t\t������浥λ:");
    scanf("%s", s->company) ;
    getchar();
    printf("\n\t\t�����������:");
    gets(s->date) ;
    printf("\n\t\t����۸�:");
    scanf("%s", s->price);
	  
    p = Head;
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    if(index<len+1 && index>=0){//��������
        p = Head;
        int tag = 1;
        while(tag != index){
            p=p->next;
            tag++;
        }
        Booklist *q = new Booklist;
        if(p == Head){
            s->next = Head;
            Head = s;
        }else{
            q = Head;
            while(q->next != p){
                q = q->next;
            }
            q->next = s;
            s->next = p;
        }
    }
    return;
}

void Listbyname(Pointer *Head) {  //������������
	Pointer p, q;
    int i, j;
    char t[10];
    char c;
    if(Head == NULL) {
		printf("\n\t\tû���κ����ϣ�\n");
		return;
	}
	
	if(num == 0) {  //����Ƿ�������ݿɹ�����
		printf("\n\t\tͼ����Ϣ��¼Ϊ�գ����밴������������˵���");
        getchar();
		return;
	}
	p = q = *Head;
	for(i = 0; i < num; i++) {  //����ð������
		for(j = i + 1; j < num; j++) {
			q = p;
			p = p->next;  //ʹָ��ָ����һ�����
			if(strcmp(q->name,p->name)>0) {   //�����������Ⱥ�pָ���Ӧ����Ӧ����qָ���Ӧ���ݺ�p��q�������ݽ���        
				strcpy(t, p->ISBN);
				strcpy(p->ISBN, q->ISBN);
                strcpy(q->ISBN, t);
                strcpy(t, p->author);
                strcpy(p->author, q->author);
                strcpy(q->author, t);
                strcpy(t, p->clc);
                strcpy(p->clc, q->clc);
                strcpy(q->clc, t);
                strcpy(t, p->company);
                strcpy(p->company, q->company);
                strcpy(q->company, t);
                strcpy(t, p->date);
                strcpy(p->date, q->date);
                strcpy(q->date, t);
                strcpy(t, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, t);
                strcpy(t, p->price);
                strcpy(p->price, q->price);
                strcpy(q->price, t);
			}
		}
		q = *Head;
		p = *Head;
	}
	do {
		printf("\n\t������ɣ��Ƿ���ʾ(Y/N)?��");  /*ѯ���Ƿ���ʾ������*/
		getchar();
		scanf("%c", &c);
		if(c == 'y' || c == 'Y')
			Scan(*Head);  //��ʾ������
		else {
			if(c == 'n' || c == 'N')
				return;  //�������˵�
			else
				printf("\n\t\t�����������������!!!");  //���������ѯ��
		}
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');
}

void Delete(Pointer *Head) {  /*ɾ������*/
	int flag = 1;
    char authorname[20];
    char c, z;
    Pointer p, q;
    printf("\n\t\t******************* ͼ��ɾ�� *******************\n");
    printf("\t������Ҫɾ��ͼ�����Ϣ����������������");
    scanf("%s", authorname);
    p = q = *Head;  /*���ҷ���������ͼ��*/
    while(p != NULL && flag) {
		if(strcmp(p->author, authorname) == 0 || strcmp(p->name, authorname)) {  /*�ҵ���ͼ��*/
			printf("\t\nISBN��%-10s", p->ISBN);  //��ʾ����Ҫɾ����ͼ�����Ϣ
            printf("\t\n������%-20s", p->name);
            printf("\t\n��������%-20s", p->author);
            printf("\n\t\t���������  %-20s", p->stock);
            printf("\n\t\t�ɽ���������  %-20s", p->ava);
            printf("\t\n����ţ�%-10s", p->clc);
            printf("\t\n���浥λ��%-20s", p->company);
            printf("\t\n����ʱ�䣺%-20s", p->date);
            printf("\t\n�۸񣺣�%-10s\n", p->price);
            printf("ȷ��ɾ��?ȷ������Y��������ɾ��");  //ѯ���Ƿ�ɾ��
            getchar();
            scanf("%c", &z);
            if(z == 'Y' || z == 'y') {    
				if(p == *Head) {
					*Head = p->next;
					free(p);  /*ɾ��ͼ����Ϣ*/
				} else {
					q->next = p->next;
					free(p);
				}
				flag = 0;
			} else {
				printf("ͼ����Ϣδɾ�����������˵���");
				return;
			}
		} else {
			q = p;
			p = p->next;  /*ָ���ߵ���һ���ڵ�*/
		} 
		printf("\t\tɾ���ɹ�������\n");
	}
	
	if(flag)
		printf("\tû���ҵ�����ɾ��������!!!");
	
	do {
		printf("ѡ���Ƿ����ɾ��(Y/N)?��");  /*����ɾ��ͼ����Ϣ*/
        getchar();
        scanf("%c", &c);
        if(c == 'y' || c == 'Y')
			Delete(Head);  /*����ɾ��*/
		else {
			if(c == 'n' || c == 'N')
				return;  /*��ɾ���������˵�*/
			else
				printf("\n\t\t�����������������!!!");
		}
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');
}

void Update(Pointer Head) {  /*ͼ����Ϣ�޸ĺ���*/
	int flag = 1;
    char ISBN[10];
    char c;
    Pointer p;
    printf("\n\t\t***************** ͼ����Ϣ�޸� *****************\n");
    printf("\t������Ҫ�޸ĵ�ͼ���ISBN��");
    scanf("%s", ISBN);  /*���ҷ���������ͼ��*/
    p = Head;
    while(p != NULL && flag) {
		if(strcmp(p->ISBN, ISBN) == 0) { 
			printf("\n\t\t������ISBN:");  /*�޸�ͼ����Ϣ*/
            scanf("%s", &p->ISBN);
            printf("\n\t\t��������:");
            scanf("%s", &p->name);
            getchar();
            printf("\n\t\t����������:");
            scanf("%s", &p->author);
            getchar();
            printf("\n\t\t����������:");
    		scanf("%s", &p->stock);
    		getchar();
    		printf("\n\t\t����ɽ�������:");
    		scanf("%s", &p->ava);
    		getchar();
            printf("\n\t\t��������:");
            scanf("%s",&p->clc) ;
            getchar();
            printf("\n\t\t������浥λ:");
            scanf("%s", &p->company) ;
            getchar();
            printf("\n\t\t�����������:");
            gets(p->date);
            printf("\n\t\t����۸�:");
            scanf("%s", &p->price);
            flag = 0;
            printf("�޸ĳɹ�!!\n");
		} else
			p = p->next;  /*ָ���ߵ���һ���ڵ�*/
	}
	
	if(flag)
		printf("\n\t\tû�и�ͼ���¼!!!");
	
	do {
		printf("ѡ���Ƿ�����޸�(Y/N)?��");  /*�����޸�ͼ����Ϣ*/
        getchar();
        scanf("%c", &c);
		if(c == 'y' || c == 'Y')
			Update(Head);  /*�����޸�*/
		else {
			if(c == 'n' || c == 'N')
				return;  //���޸ģ����ز˵�
			else
				printf("\n\t\t�����������������!!!");
		}
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');  //������������ѯ��
}

void Save() {  /*���ı��ļ���ʽ����ĺ���*/

	Pointer p;
	p = Head;
    char file[20];  /*��������ļ�����·���Լ��ļ���*/
    printf("�������ļ�·�����ļ���:");
    scanf("%s", file);
    if((fp = fopen(file, "w+")) == NULL) {  /*�ж��ܷ���ļ�*/
		printf("���ܴ��ļ�!\n");
        return;
	}
	while(p != NULL) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
		        p->ISBN, p->name, p->author, p->clc, p->company, p->date, p->price);  //������д���ļ�
        p = p->next;  /*����һ�����*/
	}
	fclose(fp);  //д����ɣ��ر��ļ�
	printf("�ļ��Ѿ�����!\n");
	return;
}

void Read() {  /*�����ı��ļ��ĺ���*/
	Pointer p, q;
    int m = 0;
    char file[20];
    printf("�������ļ�·�����ļ���:");
    scanf("%s", file);  /*�����ļ�·��������*/
    if((fp = fopen(file, "r+")) == NULL) {  //����ļ��Ƿ����
		printf("���ܴ��ļ�!\n");
		return;
	}
	m = m + 1;
	if(m == 1) {
		p = (Pointer)malloc(sizeof(Booklist));  /*����һ���µ�Ԫ*/
		Head = p;  //��p�ĵ�ַ����ͷָ��Head
		fscanf(fp, "%s %s %s %s %s %s %s\n",
		       &p->ISBN, &p->name, &p->author, &p->clc, &p->company, &p->date, &p->price);  /*�ļ�����*/
		do {
			num = num + 1;  //��¼�鼮��Ϣ��
			if(num == 1)  //��������ͷ���м�Ĵ�����
				Head->next = p;
			else 
				q->next = p;
			q = p;
			p = (Pointer)malloc(sizeof(Booklist));  /*����һ���µ�Ԫ*/
			fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",
			       &p->ISBN, &p->name, &p->author, &p->clc, &p->company, &p->date, &p->price);  //�����ļ�����
		} while(!feof(fp));  //����ļ��Ƿ������������ֹͣ���룬�����������
		q->next = p;
		p->next = NULL;  //�����β����
		num = num + 1;  //��ȷ��ͼ����Ϣ��
	}
	printf("д�����ݳɹ����ɷ����������Ϣ��");
	fclose(fp);  /*�������룬�ر��ļ�*/
	return;
}

void Exit() { /*�˳�����ĺ���*/
	char c;   
	do {
		printf("\n\t\t�˳���......�Ƿ񱣴浽�ļ�(Y/N)?");  /*ѯ���Ƿ񱣴�ͼ����Ϣ����ֹ��ʧ*/
		getchar();
        scanf("%c", &c);
        if(c == 'y' || c == 'Y') {
			Save();
			exit(0);
		} else {
			if(c == 'n' || c == 'N') {
				exit(0);
			} else
				printf("\n\t\t�����������������!!!");
		}
	} while(c != 'y' && c != 'n' && c != 'Y' && c != 'N');  //���������ѯ��
}

menu_select() {  //���˵�����
	int a;
    printf("\n\t\t\t��ӭʹ��ͼ����Ϣ����ϵͳ\n\n\n\n\n\t\t  ***** �밴���������ϵͳ�˵�! ***** \n");
	getch();
	system("cls");
    printf("\t\t********************MENU*********************\n");  //���˵�
	printf("\t\t    1.  ¼��ͼ����Ϣ\n");
    printf("\t\t    2.  ���ͼ����Ϣ\n");
    printf("\t\t    3.  ����������������ѯͼ����Ϣ\n"); 
    printf("\t\t    4.  �ؼ��ʲ�ѯ����\n");
    printf("\t\t    5.  ָ��λ�ò�������\n");
    printf("\t\t    6.  ����������\n");
    printf("\t\t    7.  �����������������в���ɾ��\n");
    printf("\t\t    8.  �޸�ͼ����Ϣ\n");
    printf("\t\t    9.  �����ļ���Ϣ\n");
    printf("\t\t    10. �����ļ���Ϣ\n");
    printf("\t\t    0.  �˳�\n");
    printf("\t\t***********************************************\n");
	do {
		printf("\n\t��ѡ��������Ҫ�ķ���");
        scanf("%d",&a);
	} while(a < 0 || a > 10);
	return a;
}

int main() { //������
	system("cls");  /*����ǰ����*/
	for(;;) {
		switch(menu_select()) {
			case 1:Insert(& Head);  break;
			case 2:Scan(Head);  break;
			case 3:Search_name(Head);  break;
			case 4:keywordsearch(&Head);  break;
			case 5:insertNode(Head);  break;
			case 6:Listbyname(&Head);  break;
			case 7:Delete(&Head);  break;
			case 8:Update(Head);  break;
			case 9:Save();  break;
			case 10:Read();  break;
			case 0:Exit();
			default:
			putchar('\a');
		}
	}
	return 0;
}
