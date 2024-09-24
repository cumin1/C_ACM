//
// Created by Fuhao on 2024/9/17.
// 线性表的顺序存储

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10

typedef int datatype;

typedef struct{
    datatype data[MAXLEN];
    int last;
}SeqList;

// 初始化顺序表
SeqList* CreateSeqList()
{
    SeqList* Lq;
    Lq = (SeqList*)malloc(sizeof(SeqList));
    Lq->last = -1;   // 空表的last为-1
    return Lq;
}

// 顺序表在第i个元素插入元素
int InsertList(SeqList* Lq,int i,datatype elem)
{
    // 如果顺序表已满 则返回错误
    if (Lq->last == MAXLEN-1)
    {
        printf("插入 %d,但是顺序表已满！\n",elem);
        return -1;
    }
    // 如果插入的索引出错 返回0
    if (i > Lq->last+2 || i < 1)
    {
        printf("错误的索引!\n");
        return 0;
    }
    for (int j = Lq->last; j >= i-1; --j) {
        Lq->data[j+1] = Lq->data[j];
    }
    Lq->data[i-1] = elem;
    Lq->last++;
    return 1;
}

// 删除顺序表中第i个元素
int DeleteList(SeqList* Lq,int i)
{
    if (i < 1 || i > Lq->last+2){
        printf("不存在第 %d 个元素!\n",i);
        return -1;
    }
    printf("删除第%d个元素: %d\n",i,Lq->data[i-1]);
    for (int j = i-1; j < Lq->last; ++j) {
        Lq->data[j] = Lq->data[j+1];
    }
    Lq->last--;
    return 1;
}

// 按值查找
int LocationSeqList(SeqList* Lq,datatype elem)
{
    printf("查找%d\n",elem);
    for (int i = 0; i <= Lq->last; ++i) {
        if (Lq->data[i] == elem) return i+1;
    }
    printf("没找到\n");
    return -1;
}

// 打印顺序表所有元素
void printSeqList(SeqList* Lq)
{
    printf("顺序表元素为:\n");
    for (int i = 0; i <= Lq->last; ++i) {
        printf("%d ",Lq->data[i]);
    }
    printf("\n");
}

int main()
{
    SeqList* L = CreateSeqList();
    for (int i = 1; i <= 11; ++i) {
        InsertList(L,i,i*10);
    }
    printSeqList(L);
    DeleteList(L,2);
    printSeqList(L);
    printf("位置:%d\n",LocationSeqList(L,40));
    printf("位置:%d\n",LocationSeqList(L,110));
    return 0;
}

