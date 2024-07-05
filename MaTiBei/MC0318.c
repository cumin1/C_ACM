#include "stdio.h"

/*
 * 输入格式：
第一行输入一个正整数n；
第二行输入n个非负整数，不大于1000。

输出格式：
在一行中先后输出奇数的个数、偶数的个数。
 */
int main()
{
    int n;
    scanf("%d", &n);
    int ji = 0,ou = 0;

    for (int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);

        if (tmp%2==0) ou++;
        else ji++;
    }

    printf("%d %d",ji,ou);


    return 0;
}
