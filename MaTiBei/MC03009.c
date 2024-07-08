#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);


    int arr[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    long long sum=0;
    for (int i=0;i<n;i++)
    {
        sum += arr[i];
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            sum += (arr[i]&arr[j]) + (arr[i] | arr[j]);
        }
    }



    printf("%lld",sum);

    return 0;
}