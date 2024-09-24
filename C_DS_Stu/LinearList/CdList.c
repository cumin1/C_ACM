#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
struct CdList{
    datatype data;
    struct CdList *front,*rear;
};

// 创建双向链表
struct CdList* CreateCdList()
{
    struct CdList* head = malloc(sizeof(struct CdList));
    head->front = head->rear = NULL;

    struct CdList* p = head;
    int z=1,x;
    printf("\t\t建立一个线性表\n");
    printf("\t\t说明：请逐个输入一个整数，结束标记为\"-1\"!\n");
    while(z)
    {
        printf("\t\t输入: ");
        scanf("%d",&x);
        if (x!=-1){
            struct CdList* newNode = malloc(sizeof(struct CdList));
            newNode->data = x;
            newNode->front = p;
            newNode->rear = NULL;
            p->rear = newNode;
            p = p->rear;
        } else{
            z = 0;
        }
    }
    return head;
}

// 双链表的插入操作
void InsertCdList(struct CdList* head,int index,datatype x)
{
    if (index < 1) return;
    struct CdList* p = head;
    while (--index)
    {
        if (!p) return;
        p = p->rear;
    }
    struct CdList* newNode = malloc(sizeof(struct CdList));
    newNode->data = x;
    p->rear->front = newNode;
    newNode->rear = p->rear;
    p->rear = newNode;
    newNode->front = p;
}

// 删除链表第i个元素
void DeleteCdList(struct CdList* head,int index)
{
    struct CdList* p = head;
    while(--index)
    {
        if (!p) return;
        p = p->rear;
    }
    struct CdList* del_p = p->rear;
    p->rear = p->rear->rear;
    del_p->rear->front = p;
    free(del_p);
}

// 打印链表
void printList(struct CdList* head)
{
    struct CdList* p = head->rear;
    printf("链表元素为: \n");
    printf("head <--> ");
    while(p)
    {
        printf("%d <--> ",p->data);
        p = p->rear;
    }
    printf("\n");
}

int main()
{
    struct CdList* cdlist = CreateCdList();
    printList(cdlist);
    InsertCdList(cdlist,2,10);
    printList(cdlist);
    DeleteCdList(cdlist,2);
    printList(cdlist);
    return 0;
}