#include "stdio.h"

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int arr[n];
    for (int i = 0;i < n;i++)
    {
        scanf("%d ",&arr[i]);
    }

    while(m--)
    {
        char Zl;
        int num;
        scanf(" %c %d",&Zl,&num);
        if (Zl == 'L')
        {
            int i;
            for (i = 0;i < n;i++)
            {
                if (arr[i] == num)
                {
                    break;
                }

            }
            if (i == n){
                printf("%d\n",-1);
            }else {
                printf("%d\n",i);
            }
        }else if (Zl == 'R')
        {
            int j;
            for (j = n-1;j >= 0;j--)
            {
                if (arr[j] == num)
                {
                    break;
                }
            }

            printf("%d\n",j);

        }

    }

    return 0;
}