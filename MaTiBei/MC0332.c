#include<stdio.h>
#include<math.h>
#include <string.h>

int main()
{
    char nums[25];
    gets(nums);

    int len = strlen(nums);
    long long sum = 0;

    int j = 0;
    for (int i = len-1; i >=0; --i) {
        if (nums[i] == '1')
        {
            sum += pow(2, j);
        }
        j++;
    }

    printf("%lld", sum);


    return 0;
}