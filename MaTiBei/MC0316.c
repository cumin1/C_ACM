#include "stdio.h"
#include "string.h"

/*
 *
输入 ： 一行一个字符串，只包含小写字母，长度不超过100。
输出格式：出现次数最多的小写字母。
 如果有多个小写字母出现的次数一样多，则输出ASCII码值最小的那个字母。
 */
int main(void)
{
    char str[100];
    scanf("%s",str);

    int count[26] = {0}; // 必须初始化为全0
    for(int i=0;i< strlen(str);i++)
    {
        count[str[i] - 'a']++;
    }

    int max = 0;
    int max_char;
    for (int i=0;i<26;i++)
    {
        if(count[i] > max)
        {
            max = count[i];
            max_char = 'a' + i;
        }
    }

    printf("%c",max_char);



    return 0;
}