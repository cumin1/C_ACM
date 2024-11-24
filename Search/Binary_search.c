#include <stdio.h>

// ���ֲ��� ����һ������ һ�����ҷ�Χ һ������Ŀ�� ����Ŀ�����ֵ�����
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
//    printf("����������Ҫ���ҵ�����:");
//    scanf("%d",&n);
//    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//
//    int index = binarySearch(arr,0,9,n);
//    if (index != -1) printf("%d������Ϊ%d��λ��",n, index);
//    else printf("��������û���������");
//
//    return 0;
//}
