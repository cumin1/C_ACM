#include <stdio.h>

// 构造稀疏矩阵
// 首先得有一个三元顺序表，而这个三元顺序表需要用二维数组去构建
#define ElemType int //矩阵内的数据类型
#define MAXSIZE 100   //矩阵内最大元素个数

//三元组结构
typedef struct Triple
{
    int i;  //元素所在行
    int j;  //元素所在列
    ElemType e;  //元素值
}Triple;

//稀疏矩阵
typedef struct SMatrix
{
    Triple data[MAXSIZE]; // 0 三元组，存放有效数据
    int mu; //稀疏矩阵行数
    int nu; //稀疏矩阵列数
    int tu; //非零元素个数
}SMatrix;


//int main()
//{
//    Triple t1 = {1,1,34};
//    Triple t2 = {2,2,12};
//    Triple t3 = {3,3,67};
//    Triple triple_arr[3] = {t1,t2,t3};
//
//    SMatrix sMatrix = {(int) triple_arr, 5, 5, 3};
//
//    return 0;
//}