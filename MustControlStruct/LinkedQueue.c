#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;

//结点结构
typedef struct QueueNode{
    DataType data;
    struct QueueNode * next;
} QueueNode;

//队列结构
typedef struct LinkedQueue{
    QueueNode * front;
    QueueNode * rear;
} LinkedQueue;

//初始化队列
void Init_LinkedQueue(LinkedQueue * q)
{
    QueueNode* q_node = malloc(sizeof(QueueNode));
    q_node->data = (DataType)NULL;
    q_node->next = NULL;
    q->front = q->rear = q_node;
}

//判断队空
_Bool LinkedQueueIsEmpty(LinkedQueue * q)
{
    if (q->front->next == NULL) return true;
    else return false;
}

//入队
void EnLinkedQueue(LinkedQueue* linkedQueue,DataType e)
{
    QueueNode* new_node = malloc(sizeof(QueueNode));
    new_node->data = e;
    new_node->next = NULL;
    linkedQueue->rear->next = new_node;
    linkedQueue->rear = new_node;
}

//出队
DataType DeLinkedQueue(LinkedQueue* linkedQueue)
{
    if (LinkedQueueIsEmpty(linkedQueue)) return -1; // 如果队空 则不能出队
    DataType elem = linkedQueue->front->next->data;
    QueueNode * tmp = linkedQueue->front->next;
    linkedQueue->front->next = tmp->next;
    free(tmp);
    return elem;
}

//销毁队列
void DestoryLinkedQueue(LinkedQueue* linkedQueue)
{
    while (linkedQueue)
    {
        QueueNode* p = linkedQueue->front;
        linkedQueue->front = linkedQueue->front->next;
        free(p);
    }
}

//打印链队
void PrintLinkedQueue(LinkedQueue* linkedQueue)
{
    QueueNode* first_node = linkedQueue->front->next;
    printf("queue head: ");
    while(first_node != NULL)
    {
        printf("%d ",first_node->data);
        first_node = first_node->next;
    }
    printf(" :queue tail\n");
}

//int main()
//{
//    LinkedQueue linkedQueue;
//    Init_LinkedQueue(&linkedQueue);
//
//    for ( int i=1; i<=5; i++ )
//    {
//        EnLinkedQueue(&linkedQueue,i*10);
//    }
//
//    PrintLinkedQueue(&linkedQueue);
//
//    printf("dequeue once the elem is %d \n", DeLinkedQueue(&linkedQueue));
//    printf("dequeue once the elem is %d \n", DeLinkedQueue(&linkedQueue));
//    printf("dequeue once the elem is %d \n", DeLinkedQueue(&linkedQueue));
//    printf("dequeue once the elem is %d \n", DeLinkedQueue(&linkedQueue));
//    printf("dequeue once the elem is %d \n", DeLinkedQueue(&linkedQueue));
//    printf("dequeue once the elem is %d \n", DeLinkedQueue(&linkedQueue));
//
//    PrintLinkedQueue(&linkedQueue);
//
//    return 0;
//}