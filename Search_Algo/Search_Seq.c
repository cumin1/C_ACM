#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct {    // 定义顺序表的结构体
    ElemType *list;   // 地址
    int len;
} SSTable;

void init_STable(SSTable *table){
    table->list = malloc(sizeof(ElemType) * 10);
    table->len = 0;
}

void append_elem(SSTable *table,ElemType elem){
    table->list[table->len] = elem;
    table->len++;
}

int Search_Seq(SSTable *table,ElemType data){
    for (int i = 0; i < table->len; ++i) {
        if (table->list[i] == data) return i;
    }

    return -1;  // 没有元素则返回-1
}

int Search_Seq_reverse(SSTable *table,ElemType data){
    for (int i = table->len; i >= 0; --i) {
        if (table->list[i] == data) return i;
    }

    return -1;  // 没有元素则返回-1
}

int Search_Binary(SSTable *table,ElemType data,int low,int high){
    int mid = (low+high)/2;
    if (table->list[mid] == data) return mid;
    if (table->list[mid] > data) return Search_Binary(table,data,low,mid);
    if (table->list[mid] < data) return Search_Binary(table,data,mid,high);

    return -1; // 如果没有查找到，则返回-1
}

//int main()
//{
//    SSTable S_Table;
//    init_STable(&S_Table);
//    for (int i=1;i<=10;i++)
//        append_elem(&S_Table,i);
//
//    int search_index = Search_Seq(&S_Table,5);
//    printf("search index is %d\n",search_index);
//
//    int binary_index = Search_Binary(&S_Table,5,0,S_Table.len-1);
//    printf("binary_index is %d\n",binary_index);
//
//    return 0;
//}