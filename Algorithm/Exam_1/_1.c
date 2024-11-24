#include <stdio.h>

/*
 * 设计函数int gcd(int a,int b),计算两个正整数的最大公约数
 */

int gcd(int a,int b)
{
    while (a!=b){
        if(a>b) a = a-b;
        else if (a<b) b = b-a;
    }

    return a;
}

//int main()
//{
//    int a,b,c;
//    printf("please input two number:");
//    scanf("%d %d",&a,&b);
//
//    c = gcd(a,b);
//
//    printf("%d and %d the great common divisor is %d\n",a,b,c);
//
//    return 0;
//}
