#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXQSIZE 100  //最大队列长度
#define ERROR -1

typedef int DataType;

typedef struct SQueue{
    DataType * base;
    int front,rear;   //保存数组的头尾下标
} SQueue;

//初始化队列
//_Bool InitQueue(SQueue* queue)
//{
//    queue->base = malloc(sizeof(DataType) * MAXQSIZE);
//    if (!queue->base) return false;
//    queue->front = queue->rear = 0;
//    return true;
//}

//判断队空
//_Bool QueueEmpty(SQueue* queue)
//{
//    if ( queue->front == queue->rear ) return true;
//    else return false;
//}

//判断队满
_Bool QueueFull(SQueue* queue)
{
    if ( (queue->rear + 1)%MAXQSIZE == queue->front ) return true;
    else return false;
}

//入队
//void EnQueue(SQueue* queue,DataType e)
//{
//    if (!QueueFull(queue)) return;
//    queue->base[queue->rear] = e;
//    queue->rear = ++queue->rear%MAXQSIZE;
//}

//出队
//DataType DeQueue(SQueue* queue)
//{
//    if (QueueEmpty(queue)) return ERROR;
//    DataType elem = queue->base[queue->front];
//    queue->front = (queue->front+1)%MAXQSIZE;
//    return elem;
//}

// 查看队列元素个数
int QueueLength(SQueue* queue)
{
    return (queue->rear - queue->front + MAXQSIZE) % MAXQSIZE;
}

// 查看队列的对头元素
//DataType GetHead(SQueue* queue){
//    if (!QueueEmpty(queue)) {
//        return queue->base[queue->front];
//    }
//
//    return ERROR;
//}

// 打印队列所有元素
void PrintQueue(SQueue* queue){
    printf("queue head | ");
    int index = queue->front;
    while (index != queue->rear)
    {
        printf("%d ",queue->base[index]);
        index = ++index%MAXQSIZE;
    }
    printf(" | queue tail\n");
}

//int main()
//{
//    SQueue queue;
//    InitQueue(&queue);
//    for ( int i=1; i<=99; i++ )
//    {
//        EnQueue(&queue,i);
//    }
//
//    PrintQueue(&queue);
//
//    printf("dequeue elem is %d\n",DeQueue(&queue));
//
//    EnQueue(&queue,123);
//
//    PrintQueue(&queue);
//
//    printf("%d \n",queue.front);
//    printf("%d \n",queue.rear);
//
//    printf("this queue'len is %d \n",QueueLength(&queue));
//
//    return 0;
//}