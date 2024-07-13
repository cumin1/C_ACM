#include "stdio.h"
#include "string.h"


/*
 * 加密方法：把小码哥想传递的话看成是一个字符串A比如是“abac”，
 * 那么首先小码哥会提取出字符串A的所有长度为2的子串并且按照从左到右的顺序列出也就是 “ab”，“ba”,“ac”，
 * 然后将提取出来的子串按照从左到右的顺序拼接起来就是最终加密的字符串B“abbaac”。

格式: 输入格式：输入一个加密好的字符串B。

输出格式：输出按照题目所述方法还原加密前的字符串A。

样例 输入：abbaac
输出：abac
 */
int main() {
    char a[100];
    scanf("%s", a);

    int len = strlen(a);

    for (int i = 1; i <= len; ++i) {
        if (i % 2 == 1)
        {
            printf("%c",a[i-1]);
        }

        if (i == len)
        {
            printf("%c",a[i-1]);
        }
    }

    return 0;

}
