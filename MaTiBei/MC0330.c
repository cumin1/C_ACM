#include "stdio.h"

int main()
{
    int n;
    scanf("%d",&n);
    int count = 0;
    for (int i = 1;i<=n;i++)
    {
        int tmp = i;
        int sum = 0;
        while (tmp)
        {
            sum += tmp%10;
            tmp /= 10;
        }

        if (sum == 10) count++;
    }

    printf("%d\n",count);
    return 0;
}