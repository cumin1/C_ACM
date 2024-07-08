#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c) == 3) // scanf居然有返回值，而且返回值是输入的个数
    {
        printf("%d\n",a*b%c);
    }
    return 0;
}