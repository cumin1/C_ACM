#include <stdio.h>

/*
 * 编写程序求s = (2*2)/(1*3) + (4*4)/(3*5) + .... + (2n)^2 / (2n-1)(2n+1) 前10项的和
 *
 */

int main()
{
    double sum = 0;
    for (int i=1; i<=10; i++){
        sum += (double)((2*i)*(2*i)) / ((2*i - 1)*(2*i + 1));
    }

    printf("%lf\n",sum);

    return 0;
}
