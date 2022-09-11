#include<stdio.h>//ͷ�ļ�
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef struct student//�ṹ��
{
    int score;
    char name[50];
    int num;
    struct student *next;
} linklist;
VOID KillConsoleCloseButton(VOID);
int pwdmodify(void);
void map(void);
void set(void);
void linksort(linklist *p);
void linksortnum(linklist *p);
linklist *create(int n);
void print(linklist *head);
void change(linklist *h);
void del(linklist *add, int n);
void insert(linklist *add, int n);
int count(linklist *add);
int outlist(linklist *add);
linklist *nixu(linklist *add);
void output(linklist *p);
linklist *read(void);
linklist *find(linklist *add, char value[]);
int pwdcheck(char pass[]);
int check(void);
int is_pwd_right(char pwd[]);
int pwdmodify(void);
int regist(void);
void choice(void);

char pwd[20];
linklist *add=NULL,*tadd=NULL,*tp=NULL,*tfind=NULL;
int t=-1,n;

int main()
{
    set();
    int buttonID=MessageBox(NULL, "��ӭ����ѧ���ɼ�����ϵͳ", "20��ҽ��2����˼Զ",  MB_YESNO);
    if(buttonID==7)
    {
        MessageBox(NULL, "�ڴ��´μ���^_^", "ERROR(INFITY)",MB_ICONHAND);
        return 1;
    }
    if(regist()==1)
        return 1;
    system("cls");
    do
        choice();
    while (t != 0);
    return 0;
}
void map(void)//��ͼ�ν���
{
            printf("                             \t  ******************\n");
        printf("                             \t  *ѧ���ɼ�����ϵͳ*\n");
        printf("                             \t  ******************\n");
        printf("                     -----------------------------------------------");
        printf("\n                    |0.�˳�\t\t1.����\t\t2.����      |");
        printf("\n\n                    |3.ɾ��\t\t4.�޸�����\t5.��ʾ      |\n\n");
        printf("                    |6.ͳ����Ϣ����\t7.����\t\t8.���ɼ�����|");
        printf("\n\n                    |9.��ѧ�Ž���\t10.������������ԭ���ĩβ   |");
        printf("\n\n                    |11.����\t\t12.��txt�ļ������ͬĿ¼    |");
        printf("\n\n                    |13.��dat�ļ������ͬĿ¼\t14.��ȡdat�ļ�      |\n");
        printf("\n                    |15.����������\t16.�޸�ϵͳ����             |\n");
        printf("                     -----------------------------------------------\n");
        printf("�����������Խ��в���^_^\n");
}
void set(void)//����
{
    system("color 2");
    system("mode con cols=95 lines=35");
    SetConsoleTitle("ѧ���ɼ�����ϵͳ");
    SetFileAttributes("lsy's date.dat", FILE_ATTRIBUTE_NORMAL);
}
void choice(void)//ѡ��ѡ��
{
        map();
        scanf("%d", &t);
        fflush(stdin);
        switch (t)
        {
        case 1:
        {
            puts("������Ҫ¼���ѧ����Ϣ����^_^");
            printf(">>>");
            scanf("%d", &n);
            puts("����������^_^");
            puts(">>>ѧ��   ����  �ɼ�");
            add = create(n);
            break;
        }
            case 2:
                {
                puts("����������λ�ã��������롰5����ʾ�ڵ�5�����ݺ�������µ����ݣ�");
                printf(">>>");
                scanf("%d", &n);
                insert(add, n);
                break;
                }
            case 3:
                {
                puts("������Ҫɾ�����ݵ����");
                printf(">>>");
                scanf("%d", &n);
                del(add, n);
                break;
                }
            case 4:
                {
                change(add);
                break;
                }
            case 5:
                {
                    system("cls");
                    if(add!=NULL)
                    {
                        printf("����Ϊ��������\n");
                        print(add);
                    }
                        else printf("�Ҳ���ѧ����Ϣ����ȷ���Ƿ�����ȷ����ѧ����Ϣ�⣡\n\n\n");
                        break;
                }
            case 6:
                puts("���е�������");
                printf(">>>%d\n", count(add));
                break;
            case 7:
                add = nixu(add);
                break;
            case 8:
                system("cls");
                linksort(add);
                print(add);
                break;
            case 9:
                system("cls");
                linksortnum(add);
                print(add);
                break;
            case 10:
                puts("������Ҫ¼���ѧ����Ϣ����^_^");
                printf(">>>");
                scanf("%d", &n);
                puts("����������^_^");
                puts(">>>ѧ��   ����  �ɼ�");
                tadd = create(n);
                tp=add;
                while(tp->next!=NULL)
                    tp = tp->next;
                tp->next = tadd->next;
                break;
            case 11:
                system("cls");
                break;
            case 12:
                if(outlist(add)==1)
                {
                    system("cls");
                    puts("�ļ���ʧ�ܣ�");
                }
                else
                {
                    system("cls");
                    puts("����ɹ���");
                }
                break;
            case 13:
                if(add!=NULL)
                    output(add);
                else
                    printf("�Ҳ�������\n");
                break;
            case 14:
                system("cls");
                tadd = read();
                if(tadd!=NULL)
                {
                    printf("����Ϊ�ļ��е����ݣ�����Ը������ݲ����½�ʱճ����ʵ�ֽ��ļ��е����ݵ���ϵͳ��Ч����>>>\n");
                    while (tadd->next->next != NULL)
                    {
                        tadd = tadd->next;
                        printf("%d %s %d\n", tadd->num, tadd->name, tadd->score);
                    }
                }    
                break;
            case 15:
                printf(">>>������Ҫ��ѯ��ѧ������\n");
                char value[50];
                scanf("%s", value);
                if(add!=NULL)
                {
                tfind = find(add,value);
                if(tfind->next!=NULL)
                {
                    system("cls");
                    printf("����Ϊ�ڿ����ҵ�����Ϣ��\n");
                    print(tfind);
                    free(tfind);
                }
                else
                {
                    printf("�Ҳ�����ͬѧ����Ϣ��\n");
                }
                }
                else
                    printf("�Ҳ����⣡\n");
                break;
            case 0:
                SetFileAttributes("lsy's date.dat", FILE_ATTRIBUTE_HIDDEN);
                break;
            case 16:
                do
                {
                    do
                    {
                    printf(">>>�����������\n>>>");
                    scanf("%s", pwd);
                    } while (is_pwd_right(pwd) != 0);
                }while(pwdmodify()!=0);
                break;
            default:
                system("cls");
                puts("��������ȷ��������ִ�в���!!!");
                break;
        }
}
void linksort(linklist *p)//�ɼ���������
{              
	int tnum,tscore,k=0,i=1;
    char tname[50];
    linklist *p1;
	p1=p->next;
	while(i!=0)
    {
	    while(p1->next!=NULL)
        {
	        if(p1->score<p1->next->score) 
            {
	           tnum=p1->num;
	           p1->num=p1->next->num;
	           p1->next->num=tnum;
               tscore=p1->score;
	           p1->score=p1->next->score;
	           p1->next->score=tscore;
               strcpy(tname, p1->name);
               strcpy(p1->name,p1->next->name);
               strcpy(p1->next->name,tname);
	           k++;
	        }
	        p1=p1->next;
	    }
	    p1=p->next;
	    if(k>0)
            k=0;
	    else 
            i=0;
	}
}
void linksortnum(linklist *p)//ѧ�Ž�������
{              
	int tnum,tscore,k=0,i=1;//i��k�൱������ָʾflag
    char tname[50];
    linklist *p1;
	p1=p->next;
	while(i!=0)
    {
	    while(p1->next!=NULL)
        {
	        if(p1->num>p1->next->num) 
            {
	           tnum=p1->num;//��������ڵ��Ա������
	           p1->num=p1->next->num;
	           p1->next->num=tnum;
	           tscore=p1->score;
	           p1->score=p1->next->score;
	           p1->next->score=tscore;
               strcpy(tname, p1->name);
               strcpy(p1->name,p1->next->name);
               strcpy(p1->next->name,tname);
               k++;//��ʾ������
	        }
	        p1=p1->next;//�ƶ��±�
	    }
	    p1=p->next;//ð��һ����Ա���±������׽ڵ�
	    if(k>0)//�����������������δ��������k��λ
			k=0;
	    else 
            i=0;//k=0����ʾû�н�������������ɣ�����ѭ��
	}
}
linklist* create(int n)//������
{
    linklist *head, *node, *end;
    head = (linklist *)malloc(sizeof(linklist));
    end=head;
    for (int i = 0; i < n;i++)
    {
        node = (linklist *)malloc(sizeof(linklist));
        scanf("%d %s %d", &node->num,node->name,&node->score);
        fflush(stdin);
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
void print(linklist*head)//������ʾ
{
    while(head->next!=NULL)
    {
        head = head->next;
        printf("%d\t%s\t%d\n",head->num,head->name,head->score);
    }
}
void change(linklist* h)//�����޸�
{
    puts("������Ҫ�޸ĵ����ݵ�λ�ã��������롰5����ʾ�޸ĵ�5�����ݣ�");
    int n,choice,flag=1;
    scanf("%d", &n);
    linklist *t = h;
    int i = 0;
    char tname[50];
    while(i<n && t!=NULL)
    {
        t = t->next;
        i++;
    }
    if(t!=NULL)
    {
        while(flag)
        {
        puts("��ѡ��Ҫ�޸ĵ�����");
        puts("0.�����޸�  1.ѧ��  2.����  3.�ɼ�");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
                flag = 0;
                break;
            case 1:
                puts("��������ѧ��");
                scanf("%d", &t->num);
                flag = 1;
                break;
            case 2:
                puts("������������");
                scanf("%s", tname);
                strcpy(t->name, tname);
                flag = 1;
                break;
            case 3:
                puts("�������³ɼ�");
                scanf("%d", &t->score);
                flag = 1;
                break;
            default:
                puts("��������ȷ�����֣�");
                break;
        }
        }
    }
    else
        printf("�Ҳ������ݣ�\n");
}
void del(linklist* add,int n)//ɾ������
{ 
    linklist *t = add, *in;
    int i = 0;
    while(i<n && t!=NULL)
    {
        in = t;
        t = t->next;
        i++;
    }
    if(t!=NULL)
    {
        in->next = t->next;
        free(t);
    }
    else
        puts("�ڵ㲻���ڣ���������ȷ�ڵ����!");
}
void insert(linklist* add,int n)//��������
{
    linklist *t = add,*into;
    int i = 0;
    while(i<n&&t!=NULL)
    {
        t = t->next;
        i++;
    }
    if(t!=NULL)
    {
        into = (linklist *)malloc(sizeof(linklist));
        puts("����������");
        puts(">>>ѧ��   ����  �ɼ�");
        scanf("%d%s%d", &into->num,into->name,&into->score);
        into->next = t->next;
        t->next = into;
    }
    else
        puts("�ڵ㲻���ڣ���������ȷ�ڵ���ţ�");
}
int count(linklist* add)//���ݸ�������
{
    linklist *t = add;
    int cnt = 0;
    if(t!=NULL)
    {
    while(t->next!=NULL)
    {
        t = t->next;
        cnt++;
    }
    }
    else
    {
        puts("�Ҳ������ݣ���ȷ���Ƿ�����ȷ�����⣡\n");
        return 0;
    }
    return cnt;
}
int outlist(linklist* add)//���txt�ļ�
{
    linklist *p = add->next;
    FILE *fp = fopen("ѧ����Ϣ.txt", "wt+");
    if(fp==NULL)
    {
        return 1;
    }
    if(fp!=NULL)
        fprintf(fp, "ѧ��\t����\t�ɼ�\n");
    while(p)
    {
        fprintf(fp, "%d\t%s\t%d\n", p->num, p->name, p->score);
        p = p->next;
    }
    fclose(fp);
    return 0;
}
linklist* nixu(linklist* add)//����
{
    linklist *t = add->next, *tmp;
    linklist *pb = t->next;
    t->next = NULL;
    while(pb!=NULL)
    {
        tmp = pb;
        pb = pb->next;
        tmp->next = t;
        t = tmp;
    }
    linklist *end;
    end = (linklist *)malloc(sizeof(linklist));
    end->next = t;
    add = end;
    return add;
}
void output(linklist *p)//���dat�ļ�
{
    p = p->next;
	FILE *fp;
    char name[50];
    printf("�������ļ���\n");
    scanf("%s", name);
    strcat(name, ".dat");
    fp = fopen(name, "wb");
    if(fp==NULL)
    {
        printf("���ļ�ʧ�ܣ�n");
        return;
    }
    while (p!= NULL)
    {
        fwrite(p, sizeof(linklist), 1, fp);
        p = p->next;
    }
	if((fclose(fp))==0)
        printf("����ɹ���\n");
    else
    {
        printf("�ر��ļ�ʱ����\n");
        exit(0);
    }
 }
linklist* read(void)//��ȡdat�ļ�
 {
     FILE *fp;
     linklist* end=NULL,*node,*tadd;
     char name[50];
     printf("������Ҫ�򿪵��ļ���\n");
     scanf("%s", name);
     strcat(name, ".dat");
     fp = fopen(name, "rb");
     if(fp!=NULL)
     {
     tadd=(linklist*)malloc(sizeof(linklist));
     end=tadd;
     while(!feof(fp))
     {
     node=(linklist*)malloc(sizeof(linklist));
     fread(node,sizeof(linklist),1,fp);
     end->next=node;
     end=node;
     }
     end->next=NULL;
     fclose(fp);
     return tadd;
     }
     else
     {
        printf("���ļ�ʱ�����������飡\n");
        return NULL;
     }
 }
linklist* find(linklist* add,char value[])//����������
{
    linklist *p,*newadd,*node,*t;
    newadd = (linklist *)malloc(sizeof(linklist));
    t = newadd;
    newadd->next = NULL;
    for(p=add->next;p!=NULL;p=p->next)
    {
        if(strcmp(p->name,value)==0)
        {
            node = (linklist *)malloc(sizeof(linklist));
            node->num = p->num;
            strcpy(node->name,p->name);
            node->score = p->score;
            t->next = node;
            t = node;
        }
    }
    t->next = NULL;
    return(newadd);
}
int pwdcheck(char pass[])//����Ϸ��Լ��
 {
    int k = strlen(pass);
    int flag = 0;
    int flag1 = 0;
    if(k<6)
        return 1;
    for (int j = 0; pass[j] != '\0';j++)
    {
        if(pass[j]>='A'&&pass[j]<='z')
            flag = 1;
        if(pass[j]>='0'&&pass[j]<='9')
            flag1 = 1; 
    }
    if(flag==1&&flag1==0)
        return 2;
    if(flag==0&&flag1==1)
        return 3;
    return 0;
}
int is_pwd_right(char pwd[])//�������
{
    FILE *fp;
    fp = fopen("lsy's date.dat","rb");
        char tpwd[50];
        fread(tpwd, sizeof(pwd), 1, fp);
        rewind(fp);
        fread(tpwd, sizeof(char) * strlen(tpwd), 1, fp);
        if(strcmp(pwd,tpwd)==0)
        {
            fclose(fp);
            return 0;
        }
        fclose(fp);
        return 1;
}
int check(void)//�״�ʹ�ü��
{
    int flag;
    FILE *fp;
    fp = fopen("lsy's date.dat", "rb");
    if(fp==NULL)
    {
        fclose(fp);
        return 1;
    }    
    else
        fread(&flag, sizeof(int), 1, fp);
    if(flag==2)
    {
        fclose(fp);
        return 2;
    }
    fclose(fp);
    return 3;    
}
int pwdmodify(void)//�����޸�
{
    FILE *fp;
    fp = fopen("lsy's date.dat", "wb");
    if(fp!=NULL)
    {
        printf("������������\n");
        printf(">>>");
        char pwd[20];
        do
        {
        scanf("%s", pwd);
        switch(pwdcheck(pwd))
        {
            case 1:
                system("cls");
                printf("����̫�̣����������룡\n");
                break;
            case 2:
                system("cls");
                printf("����ȱ�����֣����������룡\n");
                break;
            case 3:
                system("cls");
                printf("����ȱ����ĸ�����������룡\n");
                break;
            default:
                break;
        }
        } while (pwdcheck(pwd) != 0);
        if((fwrite(pwd, sizeof(pwd), 1, fp))==1)
        {
            system("cls");
            printf("�޸ĳɹ���\n");
            return 0;
        }
        else
        {
            printf("д��ʱ����\n");
            return 2;
        } 
    }
    else
    {
        printf("�޸�ʱ�������������ԣ�\n");
        return 1;
    }
}
int regist(void)//ע�����½
{
    if(check()==1)
    {
        printf("\n\n�״�ʹ������������^_^\n\n����Ҫ������6λ��Ҫ������ĸ��������\n");
        printf(">>>����������\n");
        do
        {
        scanf("%s", pwd);
        switch(pwdcheck(pwd))
        {
            case 1:
                system("cls");
                printf("����̫�̣����������룡\n");
                break;
            case 2:
                system("cls");
                printf("����ȱ�����֣����������룡\n");
                break;
            case 3:
                system("cls");
                printf("����ȱ����ĸ�����������룡\n");
                break;
            default:
                break;
        }
        } while (pwdcheck(pwd) != 0);
        FILE *fp;
        fp = fopen("lsy's date.dat", "wb");
        if(fp!=NULL)
        {
            fwrite(pwd, sizeof(pwd), 1, fp);
            if(fclose(fp)==0)
                printf("�������óɹ���\n"); 
            else
            {   
                MessageBox(NULL, "SORRY������д��ʱ���������´򿪳���", "ERROR",  MB_OK);
                return 1;
            }
        }
        else
        {
            MessageBox(NULL, "SORRY~������д��ʱ���������´򿪳���", "ERROR",  MB_OK);
            return 1;
        }    
    }
    else
    {
        do
        {
            system("cls");
            printf(">>>����������\n>>>");
            scanf("%s", pwd);
        } while (is_pwd_right(pwd) != 0);
    }
    return 0;
}