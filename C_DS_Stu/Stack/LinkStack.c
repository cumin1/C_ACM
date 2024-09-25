#include <stdio.h>
#include <stdlib.h>

// ʵ��һ����ջ
typedef int datatype;
// ����ջԪ��
typedef struct stacknode{
    datatype data;
    struct stacknode * next;
}StackNode;

typedef struct{
    StackNode* top;  // ����ջ��ָ��
}LinkStack;

// ��ʼ����ջ
void InitLinkStack(LinkStack* s)
{
    s->top = NULL;
}

// ��ջ��
int SEmpty(LinkStack* s)
{
    if (s->top == NULL) return 1;
    else return 0;
}

// ��ջ
void Push(LinkStack* s,datatype x)
{
    StackNode* node = malloc(sizeof(StackNode));
    node->data = x;
    node->next = s->top;
    s->top = node;
}

// ��ջ
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

// ��ӡջ��Ԫ��
void ShowStack(LinkStack* s)
{
    if (SEmpty(s))
        printf("ջΪ�գ�\n");
    else
    {
        StackNode * p = s->top;
        printf("ջ��Ԫ��Ϊ��");
        while (p)
        {
            printf("%6d",p->data);
            p = p->next;
        }
        printf("\n");
    }
}

// ����ת��
void Conversion(int n)
{
    printf("ʮ��������%d ת����Ķ�������Ϊ�� ",n);
    LinkStack s;
    int x;
    s.top = NULL;
    do {
        x = n%2;
        n = n/2;
        Push(&s,x);
    } while (n);
    while (Pop(&s,&x))
    {
        printf("%d",x);
    }
}

// ʮ����ת16����
void Concersion_x(int n)
{
    printf("ʮ��������%d ת�����ʮ��������Ϊ�� ",n);
    LinkStack s;
    int x;
    s.top = NULL;
    do {
        x = n%16;
        n /= 16;
        Push(&s,x);
    } while (n);
    while (Pop(&s,&x))
    {
        printf("%d",x);
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
    Concersion_x(138);
    return 0;
}