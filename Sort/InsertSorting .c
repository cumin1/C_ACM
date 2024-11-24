/*
 * 插入排序
 * 在有序序列中插入一个元素，保持序列有序有序长度不断增加。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
typedef int KeyType;

typedef struct{
    KeyType key;
    char otherinfo;
}RedType;

typedef struct{
    RedType r[MAXSIZE+1]; // 之后用到哨兵模式排序
    int length;
}SqList;

// 直接插入排序
void InsertSort(SqList *L){
    int i,j;
    for ( i=2;i<=L->length;i++ ){
        // 保存待插入元素
        RedType temp = L->r[i];

        j = i - 1;
        while (j > 0 && L->r[j].key > temp.key) {
            L->r[j + 1] = L->r[j];
            j--;
        }
        // 插入temp到正确位置
        L->r[j + 1] = temp;
    }
}

// 初始化顺序表并填充随机数
void InitializeAndFillList(SqList *L) {
    int i;
    int random_number;
    srand(time(0));

    L->length = 0; // 初始化长度为0，然后逐个添加元素
    for (i = 1; i <= MAXSIZE; i++) {
        random_number = rand() % 51; // 生成0到50之间的随机数
        L->r[i].key = random_number;
        L->r[i].otherinfo = ' '; // 其他信息字段设置为空格（或根据需要设置为其他值）
        L->length++; // 更新顺序表长度
    }
}

//int main()
//{
//    SqList sqList = {{0}, 0};
//    int i;
//
//    InitializeAndFillList(&sqList);
//    // 打印随机生成的顺序表
//    printf("随机生成顺序表：\n");
//    for (i=1;i<=MAXSIZE;i++)
//    {
//        printf("%d ",sqList.r[i].key);
//    }
//
//    printf("\n");
//
//    // 排序
//    InsertSort(&sqList);
//
//    printf("排序之后的顺序表：\n");
//    for (i=1;i<=MAXSIZE;i++)
//    {
//        printf("%d ",sqList.r[i].key);
//    }
//
//    printf("\n");
//
//    return 0;
//}


