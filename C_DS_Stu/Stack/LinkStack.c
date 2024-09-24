#include <stdio.h>
#include <stdlib.h>

// 实现一个链栈
typedef int datatype;
// 定义栈元素
typedef struct stacknode{
    datatype data;
    struct stacknode * next;
}StackNode;

typedef struct{
    StackNode* top;  // 定义栈顶指针
}LinkStack;

// 初始化链栈
void InitLinkStack(LinkStack* s)
{
    s->top = NULL;
}

// 判栈空
int SEmpty(LinkStack* s)
{
    if (s->top == NULL) return 1;
    else return 0;
}

// 入栈
void Push(LinkStack* s,datatype x)
{
    StackNode* node = malloc(sizeof(StackNode));
    node->data = x;
    node->next = s->top;
    s->top = node;
}

// 出栈
int Pop(LinkStack* s,datatype* x)
{
    if (SEmpty(s)) return 0;
    else
    {
        StackNode* p = s->top;
        *x = p->data;
        s->top = p->next;
        free(p);
        return 1;
    }
}

// 打印栈中元素
void ShowStack(LinkStack* s)
{
    if (SEmpty(s))
        printf("栈为空！\n");
    else
    {
        StackNode * p = s->top;
        printf("栈的元素为：");
        while (p)
        {
            printf("%6d",p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    LinkStack stack;
    InitLinkStack(&stack);
    for (int i = 0; i < 10; ++i) {
        Push(&stack,i);
    }
    ShowStack(&stack);
    return 0;
}