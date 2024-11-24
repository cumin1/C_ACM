#include <stdio.h>
#define N 100

/*
 * 设计函数 int insert(int array[],int data,int m,int n)
 * 在升序排列的数组array中插入数值data并使其仍然有序，
 * 参数m表示数组当中有效数据，n表示数组长度，函数返回插入后数组的元素数量
 */

int insert(int array[],int data,int m,int n)
{
    if ( m== n ) return -1;
    int i,j;
    for (i=0; i<m; i++ )
        if (array[i] > data) break;

    if ( i == m ){
        array[i] = data;
    } else {
        for ( j=m; j>i; j-- )
            array[j] = array[j-1];

        array[i] = data;
    }
    return m+1;
}

//int main()
//{
//    int a[N] = {1,3,5,7,9};
//    int m = 5;
//    int data = 0;
//    m = insert(a,data,m,N);
//    for ( int i=0; i<m; i++ )
//        printf("%d ",a[i]);
//
//    return 0;
//}