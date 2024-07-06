#include<stdio.h>
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);

    int arr[n+1];
    for (int i = 0;i < n;++i)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = 0;i < n;++i)
    {
        if (arr[i] >= x)
        {
            for (int j = n-1;j >= i;j--)
            {
                arr[j+1] = arr[j];
            }
            arr[i] = x;

            break;
        }

        if (i == n-1) arr[n] = x;

    }


    for (int i = 0;i < n+1;++i)
        printf("%d ",arr[i]);


    return 0;
}