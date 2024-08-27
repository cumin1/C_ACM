#include <stdio.h>

/*
 * 编写递归程序，根据公式Cnm = C(n-1)m + C(n-1)(m-1), Cn0=Cnn=1,计算组合数C42和C65
 */

int ZuHeShu(int n,int m){
    if (m==0) return 1;
    if (n==m) return 1;
    return ZuHeShu(n-1,m) + ZuHeShu(n-1,m-1);
}

int main()
{
    printf("%d,%d\n", ZuHeShu(4,2), ZuHeShu(6,5));

    return 0;
}