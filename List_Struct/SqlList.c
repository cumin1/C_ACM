#include <stdio.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length; // 线性表当前长度
}SqlList;

typedef SqlList * L; // 这个结构的指针类型

void InitList(L sqlList){
    sqlList->length = 0;
}

int getElem(L sqlList,int i,int * e){
    if (sqlList->length == 0) return 0;
    if (sqlList->length >= i){
        *e = sqlList->data[i-1];
        return 1;
    }

    return 0;
}

int ListInsert(L sqlList,int i,ElemType e){
    if (i > sqlList->length+1) return 0;

    for (int j=sqlList->length;j>=i-1;j--){
        sqlList->data[j] = sqlList->data[j-1];
    }

    sqlList->data[i-1] = e;
    sqlList->length++;
    return 1;
}

//int main(){
//    SqlList sqlList;
//
//    InitList(&sqlList);
//
//    return 0;
//}