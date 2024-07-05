#include "stdio.h"
#include "math.h"


int main()
{
    long long n;
    scanf("%lld",&n);
    int x = 1;

    int cha = abs(1-n);

    while(1)
    {
        int num = pow(2,x);
        int tmp = abs(num-n);
        if (tmp > cha){
            printf("%d\n",(int)pow(2,x-1));
            break;
        }
        cha = tmp;
        x++;
    }


    return 0;
}