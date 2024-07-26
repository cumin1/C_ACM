#include <stdbool.h>
#include "string.h"

typedef struct stack
{
    char elem[10001];
    int top;
}Stack,*pStack;

int push(pStack a,int data)
{
    a->top++;
    a->elem[a->top]=data;
    return 1;
}

bool pop(pStack a)
{
    if(a->top==-1)
    {
        return false;
    }

    a->top--;

    return true;
}

int pair(char a,char b)
{
    if((a=='('&&b==')')||(a=='{'&&b=='}')||(a=='['&&b==']'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isValid(char* s) {
    int len=strlen(s);
    Stack a={{0},-1};
    bool flag=true;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            push(&a,s[i]);
        }
        else if(s[i]==')'||s[i]==']'||s[i]=='}')
        {
            if(a.top==-1)
            {
                flag=false;
                break;
            }
            if(pair(a.elem[a.top],s[i])==0)
            {
                flag=false;
                break;
            }
            else
            {
                flag=pop(&a);
                if(flag==false)
                {
                    break;
                }
            }
        }
    }
    if(a.top!=-1)
    {
        flag=false;
    }

    return flag;

}
