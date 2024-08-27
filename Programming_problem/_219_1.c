#include <stdio.h>

/*
 * 已知一个一维整形数组共有20个元素，且偶数与基数各占一半，将数组变化为2x10的二维数组
 * 且奇数和偶数各占一行
 */

int main()
{
    int i;
    int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int arr_[2][10] = {0};
    int j=0,k=0;

    for(i=0;i<20;i++){
        if (arr[i]%2){
            arr_[0][j] = arr[i];
            j++;
        }else{
            arr_[1][k] = arr[i];
            k++;
        }
    }

    // 打印结果
    printf("偶数行:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr_[1][i]);
    }
    printf("\n奇数行:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr_[0][i]);
    }
    printf("\n");

    return 0;
}