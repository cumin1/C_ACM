#include <stdio.h>
#include <stdlib.h>

/*
 * 验证性实验2 线性表子系统
 */

typedef struct linknode
{
    char data;
    struct linknode* next;
}linnode;

linnode* head;
int n;

// 建立线性表
void CreateList()
{
    n = 0;
    linnode *p,*s;  // s 表示新结点
    char x;
    int z = 1;
    head = malloc(sizeof(linnode));
    p = head;
    printf("\n\t\t请逐个输入结点, 以 'x' 为结束标记! \n");
    printf("\n");
    while(z)
    {
        printf("\t\t输入一个字符数据，并按回车： ");
        scanf("%c",&x);
        getchar();
        if (x != 'x')
        {
            s = malloc(sizeof(linnode));
            n++;
            s->data = x;
            p->next = s;
            s->next = NULL;
            p = s;
        }
        else z = 0;
    }
}

// 在第i个位置插入元素
void InsList(int i,char x)
{
    linnode *p,*s;
    p = head;
    int j = 0;
    while(p!=NULL && j<i)
    {
        p = p->next;
        j++;
    }
    if (p!=NULL)
    {
        s = malloc(sizeof(linnode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        n++;
    }
    else printf("\n\t\t线性表为空或插入位置超出! \n");
}

// 根据值删除结点元素
void DelList(char x) {
    linnode *p, *q;
    if (head == NULL) {
        printf("\n\t\t链表为空！");
        return;
    }

    // 检查头节点是否就是要删除的节点
    if (head->data == x) {
        p = head;
        head = head->next;
        free(p);
        n--;
        printf("\n\t\t结点 %c 已经被删除（头节点）！", x);
        return;
    }

    q = head;
    p = head->next;
    while (p != NULL && p->data != x) {
        q = p;
        p = p->next;
    }
    if (p != NULL) {
        q->next = p->next;
        free(p);
        n--;
        printf("\n\t\t结点 %c 已经被删除！", x);
    } else {
        printf("\n\t\t抱歉！ 没有找到您要删除的结点.");
    }
}

// 打印链表
void ShowList()
{
    linnode *p = head;
    printf("\n\t\t显示线性表所有元素: ");
    if (head->next==NULL||p==NULL)
        printf("\n\t\t链表为空！");
    else
    {
        printf("\n\t\t");
        while(p->next!=NULL)
        {
            printf("%5c",p->next->data);
            p = p->next;
        }
    }
}

// 按值查找链表
void SearchList(char x)
{
    linnode *p;
    int i = 1;
    if (head == NULL)
    {
        printf("\n\t\t链表下溢！");
        return;
    }
    if (head->next == NULL)
    {
        printf("\n\t\t线性表为空! ");
        return;
    }
    p = head->next;
    while (p!=NULL && p->data!=x)
    {
        p = p->next;
        i++;
    }
    if (p!=NULL)
    {
        printf("\n\t\t在表的第 %d 个位置找到值为 %c 的结点！",i,x);
    }
    else printf("\n\t\t抱歉！未找到值为 %c 的结点！",x);
}


void main()
{
    head = NULL;
    int choice,i,j=1;
    char x;
    while (j)
    {
        printf("\n");
        printf("\n\t\t           线性表子系统           ");
        printf("\n\t\t********************************");
        printf("\n\t\t        1------建    表          ");
        printf("\n\t\t        2------插    入          ");
        printf("\n\t\t        3------删    除          ");
        printf("\n\t\t        4------显    示          ");
        printf("\n\t\t        5------查    找          ");
        printf("\n\t\t        6------求 表  长          ");
        printf("\n\t\t        0------返    回          ");
        printf("\n\t\t  请选择菜单号 (0--6): ");
        scanf("%d",&choice);
        getchar();
        if (choice == 1) CreateList();
        else if (choice == 2)
        {
            printf("\n\t\t请输入插入的位置 i 和插入的数据(输入格式：i,x): ");
            scanf("%d,%c",&i,&x);
            InsList(i,x);
        }
        else if (choice == 3)
        {
            printf("\n\t\t请输入要删除的数值： ");
            scanf("%c",&x);
            DelList(x);
        }
        else if (choice == 4)
        {
            if (head==NULL) printf("\n\t\t请先建立线性表！ ");
            else ShowList();
        }
        else if (choice == 5)
        {
            printf("\n\t\t请输入要查找的元素： ");
            scanf("%c",&x);
            SearchList(x);
        }
        else if (choice == 6)
        {
            printf("\n\t\t线性表长度为: %d",n);
        }
        else if (choice == 0) j = 0;
        else printf("\n\t\t输入错误！请重新输入！");
    }
}