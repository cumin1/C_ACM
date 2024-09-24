#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
struct CdList{
    datatype data;
    struct CdList *front,*rear;
};

// ����˫������
struct CdList* CreateCdList()
{
    struct CdList* head = malloc(sizeof(struct CdList));
    head->front = head->rear = NULL;

    struct CdList* p = head;
    int z=1,x;
    printf("\t\t����һ�����Ա�\n");
    printf("\t\t˵�������������һ���������������Ϊ\"-1\"!\n");
    while(z)
    {
        printf("\t\t����: ");
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

// ˫����Ĳ������
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

// ɾ�������i��Ԫ��
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

// ��ӡ����
void printList(struct CdList* head)
{
    struct CdList* p = head->rear;
    printf("����Ԫ��Ϊ: \n");
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