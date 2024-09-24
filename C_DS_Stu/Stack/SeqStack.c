#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10
// 实现一个链栈
typedef int datatype;
typedef struct{
    datatype data[MAXLEN];
    int top;
}SeqStack;

// 创建顺序栈
SeqStack * CreateSeqStack()
{
    SeqStack * sq;
    sq = (SeqStack*) malloc(sizeof(SeqStack));
    sq->top = -1;
    return sq;
}

// 判断栈空
int SEmpty(SeqStack* s)
{
    if (s->top == -1) return 1;
    else return 0;
}

// 判断栈满
int SFull(SeqStack* s)
{
    if (s->top == MAXLEN-1) return 1;
    else return 0;
}

// 元素入栈
int Push(SeqStack* s,datatype x)
{
    if (s->top == MAXLEN-1) return 0;
    s->top++;
    s->data[s->top] = x;
    return 1;
}

// 元素出栈
int Pop(SeqStack* s,datatype* x)
{
    if (SEmpty(s)) return 0;
    else {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}

// 读栈顶元素
int ReadTop(SeqStack* s,datatype* x)
{
    if (SEmpty(s)) return 0;
    else {
        *x = s->data[s->top];
        return 1;
    }
}

int main()
{
    SeqStack* stack = CreateSeqStack();
    datatype x;
    for (int i = 0; i < 10; ++i) {
        Push(stack,i);
    }
    for (int i = 0; i < 10; ++i) {
        ReadTop(stack,&x);
        printf("%d ",x);
        Pop(stack,&x);
    }
    return 0;
}