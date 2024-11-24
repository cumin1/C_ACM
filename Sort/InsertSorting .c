/*
 * ��������
 * �����������в���һ��Ԫ�أ����������������򳤶Ȳ������ӡ�
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
    RedType r[MAXSIZE+1]; // ֮���õ��ڱ�ģʽ����
    int length;
}SqList;

// ֱ�Ӳ�������
void InsertSort(SqList *L){
    int i,j;
    for ( i=2;i<=L->length;i++ ){
        // ���������Ԫ��
        RedType temp = L->r[i];

        j = i - 1;
        while (j > 0 && L->r[j].key > temp.key) {
            L->r[j + 1] = L->r[j];
            j--;
        }
        // ����temp����ȷλ��
        L->r[j + 1] = temp;
    }
}

// ��ʼ��˳�����������
void InitializeAndFillList(SqList *L) {
    int i;
    int random_number;
    srand(time(0));

    L->length = 0; // ��ʼ������Ϊ0��Ȼ��������Ԫ��
    for (i = 1; i <= MAXSIZE; i++) {
        random_number = rand() % 51; // ����0��50֮��������
        L->r[i].key = random_number;
        L->r[i].otherinfo = ' '; // ������Ϣ�ֶ�����Ϊ�ո񣨻������Ҫ����Ϊ����ֵ��
        L->length++; // ����˳�����
    }
}

//int main()
//{
//    SqList sqList = {{0}, 0};
//    int i;
//
//    InitializeAndFillList(&sqList);
//    // ��ӡ������ɵ�˳���
//    printf("�������˳���\n");
//    for (i=1;i<=MAXSIZE;i++)
//    {
//        printf("%d ",sqList.r[i].key);
//    }
//
//    printf("\n");
//
//    // ����
//    InsertSort(&sqList);
//
//    printf("����֮���˳���\n");
//    for (i=1;i<=MAXSIZE;i++)
//    {
//        printf("%d ",sqList.r[i].key);
//    }
//
//    printf("\n");
//
//    return 0;
//}


