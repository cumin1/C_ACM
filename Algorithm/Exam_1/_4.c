#include <stdio.h>
#include <string.h>
#define N 100

/*
 * 编写程序，让用户输入一个字符串，将其首尾的连续空格(包括制表位 \t ) 都去掉并输出
 * 例： 用户输入 "    abc   123  45  ",则输出 "abc   123  45"
 */

void del_t(char * str)
{
    int i=0,k=0;
    int j = strlen(str)-1;

    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[j] == ' ' || str[j] == '\t')
        j--;
    while(i<=j)
    {
        str[k] = str[i];
        k++;
        i++;
    }
}

//int main()
//{
//    char str[N] = {0};
//    printf("please input a string:");
//    gets(str);
//    del_t(str);
//    puts(str);
//    return 0;
//}