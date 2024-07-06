#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int arr[1000000];

    int index = 0;
    int count = 1;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 0; j < i; ++j) {
            arr[index] = count;
            index++;
        }
        count++;
    }
    printf("%d\n",arr[n-1]);

    return 0;
}