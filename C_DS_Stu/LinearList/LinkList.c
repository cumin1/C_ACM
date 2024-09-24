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

// ͷ�巨 ��������
LinkNode* CreateLinkList()
{
    LinkNode* head,*p,*s;
    int x;
    int z=1,n=0;
    head = NULL;   // �տ�ʼ�ǿձ� ͷָ��ΪNULL
    printf("\t\t����һ�����Ա�\n");
    printf("\t\t˵�������������һ���������������Ϊ\"-1\"!\n");
    while(z)
    {
        printf("\t\t����: ");
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

// β�巨 ��������
LinkNode* CreateLinkList_()
{
    LinkNode* head,*p,*s;
    int x;
    int z=1,n=0;
    head = NULL;   // �տ�ʼ�ǿձ� ͷָ��ΪNULL
    p = head;
    printf("\t\t����һ�����Ա�\n");
    printf("\t\t˵�������������һ���������������Ϊ\"-1\"!\n");
    while(z)
    {
        printf("\t\t����: ");
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

// �����ͷ�ڵ�������� �����Ȳ�����ͷ�ڵ㣩
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

// ���㲻��ͷ�ڵ��������
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

// ����Ų��� �жϵ�ǰ����Ƿ��ǵ�i��
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

// ��ֵ����
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

// �����㷨 (ǰ��)
void InsertList(LinkList head,LinkNode* s,int x)
{
    LinkNode* q = head;
    LinkNode* p = malloc(sizeof(LinkNode));
    p->data = x;
    while(q->next != s) q = q->next;
    s->next = q->next;
    q->next = s;
}

// ��巨  �ҵ���i����� �����½��
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

// ��ӡ����
void printList(LinkNode* linkNode)
{
    printf("����Ԫ��Ϊ: \n");
    while(linkNode)
    {
        printf("%d -> ",linkNode->data);
        linkNode = linkNode->next;
    }
    printf("\n");
}

// ɾ����� ɾ��pָ��Ľ��
LinkList DeleteList(LinkList head,datatype x)
{
    if (head == NULL){
        printf("����Ϊ��\n");
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
        printf("δ�ҵ���ɾ���Ľ��\n");
        return head;
    }

    printf("ɾ����һ�����");
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