#include<stdio.h>

/*
 * 给出3个正整数，判断这3个整数是否相邻，是输出“TRUE”，否则输出“FALSE”。
 *
 * 输入：1 3 2
 */


int main()
{
    int arr[3];
    for (int i=0;i<3;i++)
    {
        scanf("%d ",&arr[i]);
    }

    for (int i=0;i<2;i++)
    {
        if (arr[i] > arr[i+1])
        {
            int tmp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = tmp;
        }
    }

    if(arr[0]+1 == arr[2]-1 && arr[0]+1 == arr[1])
    {
        printf("TRUE");
    }else{
        printf("FALSE");
    }

    return 0;
}