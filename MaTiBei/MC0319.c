#include<stdio.h>
int main()
{
    int l,r;
    scanf("%d %d",&l,&r);
    int count=0;

    for(int i=l;i<=r;i++)
    {
        int tmp_1 = i;
        while(tmp_1)
        {
            int tmp;
            tmp = tmp_1%10;
            if (tmp == 2) count++;
            tmp_1/=10;
        }
    }

    printf("%d\n",count);

    return 0;
}