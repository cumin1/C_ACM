//
// Created by Fuhao on 2024/9/17.
//
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct linknode{
    datatype data;
    struct linknode *next;
}LinkNode,*LinkList;

// 头插法 建立链表
LinkNode* CreateLinkList()
{
    LinkNode* head,*p,*s;
    int x;
    int z=1,n=0;
    head = NULL;   // 刚开始是空表 头指针为NULL
    printf("\t\t建立一个线性表\n");
    printf("\t\t说明：请逐个输入一个整数，结束标记为\"-1\"!\n");
    while(z)
    {
        printf("\t\t输入: ");
        scanf("%d",&x);
        if(x!=-1)
        {
            s = (LinkNode*) malloc(sizeof(LinkNode));
            n++;
            s->data = x;
            s->next = head;
            head = s;
        }
        else z = 0;
    }
    return head;
}

// 尾插法 建立链表
LinkNode* CreateLinkList_()
{
    LinkNode* head,*p,*s;
    int x;
    int z=1,n=0;
    head = NULL;   // 刚开始是空表 头指针为NULL
    p = head;
    printf("\t\t建立一个线性表\n");
    printf("\t\t说明：请逐个输入一个整数，结束标记为\"-1\"!\n");
    while(z)
    {
        printf("\t\t输入: ");
        scanf("%d",&x);
        if(x!=-1)
        {
            s = (LinkNode*) malloc(sizeof(LinkNode));
            s->data = x;
            s->next = NULL;
            if (!head) head = s;
            else p->next = s;
            p = s;
            n++;
        }
        else z = 0;
    }
    return head;
}

// 计算带头节点的链表长度 （长度不包括头节点）
int LenList1(LinkNode* L)
{
    LinkNode *p = L;
    int n = 0;
    while (L->next)
    {
        p = p->next;
        n++;
    }
    return n;
}

// 计算不带头节点的链表长度
int LenList2(LinkNode* L)
{
    LinkNode *p = L;
    int n = 0;
    if (p == NULL) return -1;
    n = 1;
    while (p->next)
    {
        p = p->next;
        n++;
    }

    return n;
}

// 按序号查找 判断当前结点是否是第i个
LinkNode* SearchList1(LinkList L,int i)
{
    LinkNode* p = L;
    int j = 0;
    while (p->next != NULL && j<i)
    {
        p = p->next;
        j++;
    }
    if (j==i) return p;
    else return NULL;
}

// 按值查找
LinkNode* SearchList2(LinkList L,datatype x)
{
    LinkNode* p = L;
    while(p->next)
    {
        if(p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

// 插入算法 (前插)
void InsertList(LinkList head,LinkNode* s,int x)
{
    LinkNode* q = head;
    LinkNode* p = malloc(sizeof(LinkNode));
    p->data = x;
    while(q->next != s) q = q->next;
    s->next = q->next;
    q->next = s;
}

// 后插法  找到第i个结点 插入新结点
void InsertList_2(LinkList head,int i,datatype x)
{
    LinkNode *p = head;
    for (int j = 0; j<i-1 ; j++)
    {
        if (p->next == NULL) return;
        p = p->next;
    }

    LinkNode* s = malloc(sizeof(LinkNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
}

// 打印链表
void printList(LinkNode* linkNode)
{
    printf("链表元素为: \n");
    while(linkNode)
    {
        printf("%d -> ",linkNode->data);
        linkNode = linkNode->next;
    }
    printf("\n");
}

// 删除结点 删除p指向的结点
LinkList DeleteList(LinkList head,datatype x)
{
    if (head == NULL){
        printf("链表为空\n");
        return head;
    }
    LinkNode *p,*q;
    q = head;
    while(q->next->data != x && q->next)
    {
        q = q->next;
    }

    if (q->next == NULL)
    {
        printf("未找到待删除的结点\n");
        return head;
    }

    printf("删除了一个结点");
    p = q->next;
    q->next = p->next;
    free(p);
    return head;
}

int main()
{
    LinkNode* linkNode = CreateLinkList_();
    printList(linkNode);

    InsertList_2(linkNode,2,10);
    printList(linkNode);

    DeleteList(linkNode,10);
    printList(linkNode);
    return 0;
}