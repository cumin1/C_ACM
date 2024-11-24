#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR -1

typedef int DataType;
typedef struct StackNode{
    DataType data;
    struct StackNode* next;
}StackNode;

//初始化链栈
void Init_LinkStack(StackNode* s)
{
    s->data = (DataType)NULL;
    s->next = NULL;
}

//销毁栈操作
void DestoryStack(StackNode* s){
    s->next = NULL;
}

//判栈空
_Bool StackEmpty(StackNode* s) // 空栈说明头节点指向空
{
    if (s->next) return false;
    else return true;
}

//入栈
_Bool Push(StackNode* s,DataType e)
{
    StackNode* new_stacknode = malloc(sizeof(struct StackNode));
    if (!new_stacknode) return false;
    new_stacknode->data = e;
    new_stacknode->next = s->next;
    s->next = new_stacknode;
    return true;
}

//出栈
DataType Pop(StackNode* s)
{
    DataType elem = s->next->data;
    StackNode* tmp_node = s->next;
    s->next = s->next->next;
    free(tmp_node);
    return elem;
}

//栈的显示
void Display_LinkStack(StackNode* s){
    printf("----stack top----\n");
    while (s->next)
    {
        s = s->next;
        printf("    %6d     \n",s->data);
    }
    printf("----stack bottom----\n");
}

//查看栈顶元素
DataType GetTop(StackNode* s){
    if (!StackEmpty(s)) return s->next->data;
    else return ERROR;
}

//int main()
//{
//    StackNode stack;
//    Init_LinkStack(&stack);
//
//    for ( int i=1; i<=5; i++ )
//    {
//        Push(&stack,i*10);
//    }
//
//    int flag = 1;
//    while(flag)
//    {
//        Display_LinkStack(&stack);
//        printf("(1) push stack  (2) pop stack (3) clear stack (4) exit\n");
//        printf("please input 1~4:");
//        int code;
//        scanf("%d",&code);
//        switch (code) {
//            case 1:
//                printf("please input a number you want to push:");
//                int num;
//                scanf("%d",&num);
//                if (Push(&stack,num)){
//                    printf("push stack success\n");
//                } else{
//                    printf("something error\n");
//                }
//                break;
//            case 2:
//                printf("a number %d is pop stack",Pop(&stack));
//                break;
//            case 3:
//                DestoryStack(&stack);
//                break;
//            case 4:
//                flag = 0;
//                break;
//            default:
//                printf("input error!!!\n");
//                break;
//        }
//
//        printf("\n\n");
//    }
//
//
//    return 0;
//}
