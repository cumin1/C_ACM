#include "stdio.h"

/*
 * 定义了一种“与7有关数”，这种数需要满足这两个条件之一：
1.能被7整除；
2.数位中至少有一位是7。

比如14能被7整除，17有一位为7，这两个数都是与7有关的数。

很明显“与7无关数”就是上面两种条件都不满足，现在给一个参数n ，求出1~n中所有“与7无关数”的总和。

格式
输入格式：一行一个整数n
输出格式：1~n中所有“与7无关数”的总和
 */
int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int flag = 0;
        for (int j = i; j > 0; j /= 10)
        {
            if ((j % 10 == 7))
            {
                flag = 1;
                break;
            }
        }
        if (!flag && !(i % 7 == 0))
        {
            sum += i;
        }


    }

    printf("%d", sum);

    return 0;
}