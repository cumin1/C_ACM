//
// Created by Fuhao on 2024/9/17.
// ���Ա��˳��洢

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10

typedef int datatype;

typedef struct{
    datatype data[MAXLEN];
    int last;
}SeqList;

// ��ʼ��˳���
SeqList* CreateSeqList()
{
    SeqList* Lq;
    Lq = (SeqList*)malloc(sizeof(SeqList));
    Lq->last = -1;   // �ձ��lastΪ-1
    return Lq;
}

// ˳����ڵ�i��Ԫ�ز���Ԫ��
int InsertList(SeqList* Lq,int i,datatype elem)
{
    // ���˳������� �򷵻ش���
    if (Lq->last == MAXLEN-1)
    {
        printf("���� %d,����˳���������\n",elem);
        return -1;
    }
    // ���������������� ����0
    if (i > Lq->last+2 || i < 1)
    {
        printf("���������!\n");
        return 0;
    }
    for (int j = Lq->last; j >= i-1; --j) {
        Lq->data[j+1] = Lq->data[j];
    }
    Lq->data[i-1] = elem;
    Lq->last++;
    return 1;
}

// ɾ��˳����е�i��Ԫ��
int DeleteList(SeqList* Lq,int i)
{
    if (i < 1 || i > Lq->last+2){
        printf("�����ڵ� %d ��Ԫ��!\n",i);
        return -1;
    }
    printf("ɾ����%d��Ԫ��: %d\n",i,Lq->data[i-1]);
    for (int j = i-1; j < Lq->last; ++j) {
        Lq->data[j] = Lq->data[j+1];
    }
    Lq->last--;
    return 1;
}

// ��ֵ����
int LocationSeqList(SeqList* Lq,datatype elem)
{
    printf("����%d\n",elem);
    for (int i = 0; i <= Lq->last; ++i) {
        if (Lq->data[i] == elem) return i+1;
    }
    printf("û�ҵ�\n");
    return -1;
}

// ��ӡ˳�������Ԫ��
void printSeqList(SeqList* Lq)
{
    printf("˳���Ԫ��Ϊ:\n");
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
    printf("λ��:%d\n",LocationSeqList(L,40));
    printf("λ��:%d\n",LocationSeqList(L,110));
    return 0;
}

