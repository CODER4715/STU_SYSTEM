#include<stdio.h>//头文件
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef struct student//结构体
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
    int buttonID=MessageBox(NULL, "欢迎进入学生成绩管理系统", "20级医信2班罗思远",  MB_YESNO);
    if(buttonID==7)
    {
        MessageBox(NULL, "期待下次见面^_^", "ERROR(INFITY)",MB_ICONHAND);
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
void map(void)//主图形界面
{
            printf("                             \t  ******************\n");
        printf("                             \t  *学生成绩管理系统*\n");
        printf("                             \t  ******************\n");
        printf("                     -----------------------------------------------");
        printf("\n                    |0.退出\t\t1.创建\t\t2.插入      |");
        printf("\n\n                    |3.删除\t\t4.修改数据\t5.显示      |\n\n");
        printf("                    |6.统计信息数量\t7.逆序\t\t8.按成绩降序|");
        printf("\n\n                    |9.按学号降序\t10.建立并连接至原库的末尾   |");
        printf("\n\n                    |11.清屏\t\t12.以txt文件输出至同目录    |");
        printf("\n\n                    |13.以dat文件输出至同目录\t14.读取dat文件      |\n");
        printf("\n                    |15.按姓名查找\t16.修改系统密码             |\n");
        printf("                     -----------------------------------------------\n");
        printf("请输入数字以进行操作^_^\n");
}
void set(void)//设置
{
    system("color 2");
    system("mode con cols=95 lines=35");
    SetConsoleTitle("学生成绩管理系统");
    SetFileAttributes("lsy's date.dat", FILE_ATTRIBUTE_NORMAL);
}
void choice(void)//选项选择
{
        map();
        scanf("%d", &t);
        fflush(stdin);
        switch (t)
        {
        case 1:
        {
            puts("请输入要录入的学生信息条数^_^");
            printf(">>>");
            scanf("%d", &n);
            puts("请输入数据^_^");
            puts(">>>学号   姓名  成绩");
            add = create(n);
            break;
        }
            case 2:
                {
                puts("请输入插入的位置（例如输入“5”表示在第5条数据后面插入新的数据）");
                printf(">>>");
                scanf("%d", &n);
                insert(add, n);
                break;
                }
            case 3:
                {
                puts("请输入要删除数据的序号");
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
                        printf("以下为库中数据\n");
                        print(add);
                    }
                        else printf("找不到学生信息，请确认是否已正确创建学生信息库！\n\n\n");
                        break;
                }
            case 6:
                puts("库中的总条数");
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
                puts("请输入要录入的学生信息条数^_^");
                printf(">>>");
                scanf("%d", &n);
                puts("请输入数据^_^");
                puts(">>>学号   姓名  成绩");
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
                    puts("文件打开失败！");
                }
                else
                {
                    system("cls");
                    puts("输出成功！");
                }
                break;
            case 13:
                if(add!=NULL)
                    output(add);
                else
                    printf("找不到数据\n");
                break;
            case 14:
                system("cls");
                tadd = read();
                if(tadd!=NULL)
                {
                    printf("以下为文件中的数据，你可以复制数据并在新建时粘贴以实现将文件中的数据导入系统的效果！>>>\n");
                    while (tadd->next->next != NULL)
                    {
                        tadd = tadd->next;
                        printf("%d %s %d\n", tadd->num, tadd->name, tadd->score);
                    }
                }    
                break;
            case 15:
                printf(">>>请输入要查询的学生姓名\n");
                char value[50];
                scanf("%s", value);
                if(add!=NULL)
                {
                tfind = find(add,value);
                if(tfind->next!=NULL)
                {
                    system("cls");
                    printf("以下为在库中找到的信息：\n");
                    print(tfind);
                    free(tfind);
                }
                else
                {
                    printf("找不到该同学的信息！\n");
                }
                }
                else
                    printf("找不到库！\n");
                break;
            case 0:
                SetFileAttributes("lsy's date.dat", FILE_ATTRIBUTE_HIDDEN);
                break;
            case 16:
                do
                {
                    do
                    {
                    printf(">>>请输入旧密码\n>>>");
                    scanf("%s", pwd);
                    } while (is_pwd_right(pwd) != 0);
                }while(pwdmodify()!=0);
                break;
            default:
                system("cls");
                puts("请输入正确的数字以执行操作!!!");
                break;
        }
}
void linksort(linklist *p)//成绩降序排序
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
void linksortnum(linklist *p)//学号降序排序
{              
	int tnum,tscore,k=0,i=1;//i，k相当于两个指示flag
    char tname[50];
    linklist *p1;
	p1=p->next;
	while(i!=0)
    {
	    while(p1->next!=NULL)
        {
	        if(p1->num>p1->next->num) 
            {
	           tnum=p1->num;//逐个交换节点成员的内容
	           p1->num=p1->next->num;
	           p1->next->num=tnum;
	           tscore=p1->score;
	           p1->score=p1->next->score;
	           p1->next->score=tscore;
               strcpy(tname, p1->name);
               strcpy(p1->name,p1->next->name);
               strcpy(p1->next->name,tname);
               k++;//表示交换过
	        }
	        p1=p1->next;//移动下标
	    }
	    p1=p->next;//冒泡一个成员后将下标移至首节点
	    if(k>0)//如果交换过表明排序未结束，将k复位
			k=0;
	    else 
            i=0;//k=0，表示没有交换，即排序完成，跳出循环
	}
}
linklist* create(int n)//链表创建
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
void print(linklist*head)//链表显示
{
    while(head->next!=NULL)
    {
        head = head->next;
        printf("%d\t%s\t%d\n",head->num,head->name,head->score);
    }
}
void change(linklist* h)//数据修改
{
    puts("请输入要修改的数据的位置（例如输入“5”表示修改第5条数据）");
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
        puts("请选择要修改的数据");
        puts("0.结束修改  1.学号  2.姓名  3.成绩");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
                flag = 0;
                break;
            case 1:
                puts("请输入新学号");
                scanf("%d", &t->num);
                flag = 1;
                break;
            case 2:
                puts("请输入新名字");
                scanf("%s", tname);
                strcpy(t->name, tname);
                flag = 1;
                break;
            case 3:
                puts("请输入新成绩");
                scanf("%d", &t->score);
                flag = 1;
                break;
            default:
                puts("请输入正确的数字！");
                break;
        }
        }
    }
    else
        printf("找不到数据！\n");
}
void del(linklist* add,int n)//删除数据
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
        puts("节点不存在，请输入正确节点序号!");
}
void insert(linklist* add,int n)//插入数据
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
        puts("请输入数据");
        puts(">>>学号   姓名  成绩");
        scanf("%d%s%d", &into->num,into->name,&into->score);
        into->next = t->next;
        t->next = into;
    }
    else
        puts("节点不存在，请输入正确节点序号！");
}
int count(linklist* add)//数据个数计数
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
        puts("找不到数据！请确认是否已正确创建库！\n");
        return 0;
    }
    return cnt;
}
int outlist(linklist* add)//输出txt文件
{
    linklist *p = add->next;
    FILE *fp = fopen("学生信息.txt", "wt+");
    if(fp==NULL)
    {
        return 1;
    }
    if(fp!=NULL)
        fprintf(fp, "学号\t姓名\t成绩\n");
    while(p)
    {
        fprintf(fp, "%d\t%s\t%d\n", p->num, p->name, p->score);
        p = p->next;
    }
    fclose(fp);
    return 0;
}
linklist* nixu(linklist* add)//逆序
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
void output(linklist *p)//输出dat文件
{
    p = p->next;
	FILE *fp;
    char name[50];
    printf("请输入文件名\n");
    scanf("%s", name);
    strcat(name, ".dat");
    fp = fopen(name, "wb");
    if(fp==NULL)
    {
        printf("打开文件失败！n");
        return;
    }
    while (p!= NULL)
    {
        fwrite(p, sizeof(linklist), 1, fp);
        p = p->next;
    }
	if((fclose(fp))==0)
        printf("输出成功！\n");
    else
    {
        printf("关闭文件时出错！\n");
        exit(0);
    }
 }
linklist* read(void)//读取dat文件
 {
     FILE *fp;
     linklist* end=NULL,*node,*tadd;
     char name[50];
     printf("请输入要打开的文件名\n");
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
        printf("打开文件时发生错误，请检查！\n");
        return NULL;
     }
 }
linklist* find(linklist* add,char value[])//按姓名查找
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
int pwdcheck(char pass[])//密码合法性检查
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
int is_pwd_right(char pwd[])//密码核验
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
int check(void)//首次使用检测
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
int pwdmodify(void)//密码修改
{
    FILE *fp;
    fp = fopen("lsy's date.dat", "wb");
    if(fp!=NULL)
    {
        printf("请输入新密码\n");
        printf(">>>");
        char pwd[20];
        do
        {
        scanf("%s", pwd);
        switch(pwdcheck(pwd))
        {
            case 1:
                system("cls");
                printf("密码太短，请重新输入！\n");
                break;
            case 2:
                system("cls");
                printf("密码缺少数字，请重新输入！\n");
                break;
            case 3:
                system("cls");
                printf("密码缺少字母，请重新输入！\n");
                break;
            default:
                break;
        }
        } while (pwdcheck(pwd) != 0);
        if((fwrite(pwd, sizeof(pwd), 1, fp))==1)
        {
            system("cls");
            printf("修改成功！\n");
            return 0;
        }
        else
        {
            printf("写入时出错！\n");
            return 2;
        } 
    }
    else
    {
        printf("修改时发生错误，请重试！\n");
        return 1;
    }
}
int regist(void)//注册与登陆
{
    if(check()==1)
    {
        printf("\n\n首次使用请设置密码^_^\n\n密码要求不少于6位，要既有字母又有数字\n");
        printf(">>>请输入密码\n");
        do
        {
        scanf("%s", pwd);
        switch(pwdcheck(pwd))
        {
            case 1:
                system("cls");
                printf("密码太短，请重新输入！\n");
                break;
            case 2:
                system("cls");
                printf("密码缺少数字，请重新输入！\n");
                break;
            case 3:
                system("cls");
                printf("密码缺少字母，请重新输入！\n");
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
                printf("密码设置成功！\n"); 
            else
            {   
                MessageBox(NULL, "SORRY，密码写入时出错，请重新打开程序！", "ERROR",  MB_OK);
                return 1;
            }
        }
        else
        {
            MessageBox(NULL, "SORRY~，密码写入时出错，请重新打开程序！", "ERROR",  MB_OK);
            return 1;
        }    
    }
    else
    {
        do
        {
            system("cls");
            printf(">>>请输入密码\n>>>");
            scanf("%s", pwd);
        } while (is_pwd_right(pwd) != 0);
    }
    return 0;
}