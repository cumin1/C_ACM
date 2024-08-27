#include <stdio.h>

/*
 * 编写函数，将字符串中的字母大小写转换，即小写变大写，大写变小写，其余字符不变
 */

void ConvertString(char* str)
{
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z'){
            *str+=32;
        }else if (*str >= 'a' && *str <= 'z'){
            *str-=32;
        }
        str++;
    }
}

int main()
{
    char str[] = "abcABC123";
    ConvertString(str);
    printf("%s\n",str);

    return 0;
}