#include <stdio.h>

// 二分查找 给定一个数组 一个查找范围 一个查找目标 返回目标数字的索引
int binarySearch(int arr[],int first,int end,int target){
    int mid = (first+end)/2;
    if (mid == first || mid == end) return -1;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearch(arr,first,mid,target);
    if (arr[mid] < target) return binarySearch(arr,mid,end,target);
}

//int main()
//{
//    int n;
//    printf("请输入你需要查找的数字:");
//    scanf("%d",&n);
//    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//
//    int index = binarySearch(arr,0,9,n);
//    if (index != -1) printf("%d在索引为%d的位置",n, index);
//    else printf("该数组中没有这个数字");
//
//    return 0;
//}
