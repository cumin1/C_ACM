#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 现在要实现一个链表
// 链表的储存空间在内存中是不连续的
typedef int DataType;

typedef struct LinkList{
    DataType data;
    struct LinkList* next;   // 下一个结点
}LinkList;

//初始化链表
void LinkListInit(LinkList* L){
    L->data = (DataType)NULL;
    L->next = NULL;
}

//尾插
_Bool LinkListPushBack(LinkList* L, DataType x){
    LinkList* new_L = malloc(sizeof(struct LinkList));
    if (new_L==NULL) return false;

    while (L->next)
        L =  L->next;
    new_L->data = x;
    L->next = new_L;
    new_L->next = NULL;
    return true;
}

//头插
_Bool LinkListPushFront(LinkList* L, DataType x){
    LinkList* new_L = malloc(sizeof(struct LinkList));
    if (new_L==NULL) return false;

    new_L->data = x;
    new_L->next = L->next;
    L->next = new_L;
    return true;
}

// 插入操作 在第i个结点插入x
_Bool LinkListInsert(LinkList* L, int index, DataType x){
    LinkList* new_L = malloc(sizeof(struct LinkList));
    if (new_L==NULL) return false;

    new_L->data = x;
    for ( int i=1; i<index; i++){
        L = L->next;
    }

    new_L->next = L->next;
    L->next = new_L;
    return true;
}

//求单链表的长度
int LinkListLength(LinkList* L){
    int count = 0;
    while(L->next){
        L = L->next;
        count++;
    }
    return count;
}

//删除操作:将单链表中的第i个结点删除
_Bool LinkListDelete(LinkList* L, int i){
    while(--i){
        if (L==NULL) return false;
        L = L->next;
    }
    LinkList* tmp = L->next;
    L->next = L->next->next;
    free(tmp);
    return true;
}

//按位查找：查找在单链表L中第i个位置的结点
LinkList* LinkListGetElem(LinkList* L, int i){
    while (--i){
        L = L->next;
        if (L==NULL) return NULL;
    }
    L = L->next;

    return L;
}

//打印
void LinkListPrint(LinkList* L){
    printf("This list has :");
    while(L->next){
        L = L->next;
        printf("%d ",L->data);
    }
    printf("\n");
}

//int main()
//{
//    struct LinkList linkList;
//    LinkListInit(&linkList);
//    for ( int i=1; i<=10; i++ )
//    {
//        LinkListPushBack(&linkList,i*10);
//    }
//
//    for ( int i=1; i<=10; i++ )
//    {
//        LinkListPushFront(&linkList,i*10);
//    }
//
//    LinkListPrint(&linkList);
//    LinkListInsert(&linkList, 5, 111);
//    LinkListPrint(&linkList);
//    LinkListDelete(&linkList,5);
//    LinkListPrint(&linkList);
//    printf("this list's lenth is %d \n",LinkListLength(&linkList));
//    printf("this list %d index's data is %d  \n",5,LinkListGetElem(&linkList,5)->data);
//
//    return 0;
//}


