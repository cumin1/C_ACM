#include <stdio.h>
#include <string.h>

int BF(char *S,char *T){ // S是主串 T是子串
    int len_S = strlen(S);
    int len_T = strlen(T);

    for ( int i=0; i<len_S; i++ )
    {
        int tmp = i, flag=1;
        for ( int j=0; j<len_T; )
        {
            if ( S[tmp++]==T[j++] ) flag = 1;
            else {
                flag = 0;
                break;
            };
        }

        if (flag) return flag;
    }

    return 0;
}


int get_arrlen(int (*arr)[]) {
    return sizeof(arr)/sizeof(int);
}


//int main()
//{
//    char a = 1;
//
//    printf("%llu\n",sizeof(a));
//    printf("%d\n",a);
//
//    char b = !a;
//    printf("%llu\n",sizeof(b));
//    printf("%d\n",b);
//
//
//    return 0;
//}

//int main()
//{
//    int a = 1;
//
//    printf("%llu\n",sizeof(a++));
//
//    printf("%d\n",a);
//
//    return 0;
//}