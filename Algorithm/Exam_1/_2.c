#include <stdio.h>

/*
 * 找出三位数中各位数字之和等于10的数，每行输出10个，并输出满足条件的树的个数
 */

void find_ten()
{
    int a,b,c,count = 0;
    for ( int i=100; i<=999; i++ )
    {
        int a = i/100;
        int b = i/10%10;
        int c = i%10;

        if ( (a+b+c) == 10 )
        {
            printf("%d\t",i);
            count++;
            if ( count%10 == 0 ) printf("\n");

        }
    }
}

//int main()
//{
//    find_ten();
//    return 0;
//}