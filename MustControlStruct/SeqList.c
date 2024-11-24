#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 现在要构建一个顺序表
// 顺序表是用一块连续的内存存储数据的
typedef int DataType;

typedef struct SeqList{
    DataType* array;
    int size;      //数据的个数
    int capacity;    //容量大小
}SeqList;

//初始化
_Bool SeqListInit(SeqList* ps){
    ps->size = 0;
    ps->capacity = 20;
    ps->array = malloc(sizeof(DataType) * ps->capacity);
    if (ps->array == NULL) return false;
    return true;
}

//检查是否需要扩容
_Bool SeqListCheckCapacity(SeqList* ps){
    if (ps->size >= ps->capacity) return true;
    return false;
}

//扩容
SeqList* SeqListCapacity(SeqList* ps){
    int newCapacity = ps->capacity*2;
    DataType* new_array = realloc(ps->array, newCapacity*sizeof(DataType));
    ps->capacity = newCapacity;
    ps->array = new_array;
    return ps;
}

//尾插
void SeqListPushBack(SeqList* ps, DataType x){
    if (SeqListCheckCapacity(ps)) ps = SeqListCapacity(ps);
    ps->array[ps->size] = x;
    ps->size++;
}

//头插
void SeqListPushFront(SeqList* ps, DataType x){
    if (SeqListCheckCapacity(ps)) ps = SeqListCapacity(ps);
    for (int i=ps->size; i > 0; i--){
        ps->array[i] = ps->array[i-1];
    }
    ps->array[0] = x;
    ps->size++;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, DataType x){
    if (SeqListCheckCapacity(ps)) ps = SeqListCapacity(ps);
    for (int i=ps->size; i > pos; i--){
        ps->array[i] = ps->array[i-1];
    }
    ps->array[pos] = x;
    ps->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos){
    for (int i=pos;i<ps->size-1;i++){
        ps->array[i] = ps->array[i+1];
    }
    ps->size--;
}

// 顺序表查找 返回x元素在顺序表上第一次出现的位置
int SeqListFind(SeqList* ps, DataType x){
    for (int i=0;i<ps->size;i++){
        if (ps->array[i] == x) return i;
    }

    return -1;
}

//打印
void SeqListPrint(SeqList* ps){
    printf("This SeqList has: ");
    for ( int i=0; i < ps->size; i++ ){
        printf("%d ",ps->array[i]);
    }
    printf("\n");
}



//int main()
//{
//    struct SeqList seqList;
//    SeqListInit(&seqList);
//
//    for(int i=1;i<=10;i++){
//        SeqListPushBack(&seqList,i*10);
//    }
//    for(int i=10;i>=0;i--){
//        SeqListPushFront(&seqList,i*10);
//    }
//
//    SeqListInsert(&seqList,3,111);
//    SeqListPrint(&seqList);
//
//    SeqListErase(&seqList,3);
//    SeqListPrint(&seqList);
//
//    printf("the element %d is %d of index in the list.\n",50,SeqListFind(&seqList,50));
//
//    printf("%d ",seqList.size);
//    printf("%d ",seqList.capacity);
//
//    return 0;
//}