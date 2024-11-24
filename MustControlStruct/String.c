#include <stdio.h>
#include <stdbool.h>
#define MAXLEN 255

typedef struct{
    char data[MAXLEN+1];
    int len; // 存储当前串的长度
} String;

void StrAssign(String* s)   // 串的赋值
{
    printf("please input a len:");
    scanf("%d",&s->len);
    getchar();
    printf("please input a string:");
    for ( int i=0; i<s->len; i++ )
        s->data[i] = getchar();

    s->data[s->len] = '\0';
    getchar();

    printf("\n");
}

int StrLength(String* s)  // 求串长
{
    return s->len;
}

_Bool StrCompare(String* S,String* T)  // 串比较 如果不相同返回false
{
    if (S->len != T->len) return false;
    else {
        for ( int i=0; i<S->len; i++ )
        {
            if (S->data[i] != T->data[i]) return false;
        }
    }

    return true;
}

_Bool Concat(String* S1,String* S2)  // 串拼接 将s2拼接到s1上
{

    for ( int i=0; i< S2->len; i++ )
    {
        S1->data[S1->len + i] = S2->data[i];
    }
    S1->len += S2->len;
    S1->data[S1->len] = '\0';

    return true;
}

// 将S从第pos位起len个长度的子串用Sub返回
String SubString(String* S, int pos, int len)
{
    pos--;
    String new_str;
    new_str.len = len;
    for ( int i=0; i<len; i++ )
    {
        new_str.data[i] = S->data[pos];
        pos++;
    }

    return new_str;
}

// 串拷贝 将str1的数据拷贝到new_str中
void StrCopy(String* new_str,String* str1)
{
    new_str->len = str1->len;
    for ( int i=0; i<=str1->len; i++ )
    {
        new_str->data[i] = str1->data[i];
    }
}

// 判断空串
_Bool StrEmpty(String* str)
{
    if (str->len == 0) return true;
    else return false;
}

// 插入子串   在主串S的pos位置上插入子串T  // 12345  2  678
void StrInsert(String* S, int pos, String* T)
{
    for ( int i=S->len+T->len; i>=pos-1 + T->len; i--)
    {
        S->data[i] = S->data[i-T->len];
    }

    for ( int i=0; i<T->len; i++)
    {
        S->data[pos-1+i] = T->data[i];
    }

    S->len += T->len;
}

void PrintString(String* s)  // 输出串
{
    char* p = s->data;
    while(*p != '\0')
    {
        printf("%c",*p);
        p++;
    }
    printf("\n");
}

//int main()
//{
//    String str1,str2;
//    StrAssign(&str1);
//    StrAssign(&str2);
//    PrintString(&str1);
//    printf("this string's len is %d \n",StrLength(&str1));

//    printf("str1 and str2 is %d\n",StrCompare(&str1,&str2));
//
//    Concat(&str1,&str2);
//    PrintString(&str1);

//    String str3 = SubString(&str1, 2, 3);
//    String str3;
//    StrCopy(&str3,&str1);
//    PrintString(&str3);

//    String T;
//    StrAssign(&T);
//    StrInsert(&str1,2,&T);
//    PrintString(&str1);

//    return 0;
//}


