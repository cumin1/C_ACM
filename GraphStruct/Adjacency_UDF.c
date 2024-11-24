#include <stdio.h>
#include <stdlib.h>
#define MaxVertex 10   // 定义这个图最多只能有多少个结点

/*
 * 邻接表 构建无向图
 */

typedef char VerTexType;

// 定义边结构
typedef struct UDF_arc{
    int index_vex;
    struct UDF_arc* next_arc;
}UDF_arc;

// 定义顶点表元素的结构
typedef struct UDF_VexNode{
    VerTexType data;
    UDF_arc * first_node;
}UDF_VexNode,UDF_AdjList[MaxVertex];

// 图结构
typedef struct Adjacency_UDF_Graph{
    UDF_VexNode UDF_AdjList[MaxVertex];
    int vexnum;    // 顶点数量
    int arcnum;    // 边数量
} * UDF_Graph;

// 创建无向图
UDF_Graph Create_Adjacency_UDF_Graph()
{
    UDF_Graph G = malloc(sizeof(struct Adjacency_UDF_Graph));
    G->vexnum = G->arcnum = 0;
    return G;
}

// 添加顶点
void addVex_UDF(UDF_Graph G,VerTexType vex)
{
    if (G->vexnum >= MaxVertex) return;
    G->UDF_AdjList[G->vexnum].data = vex;
    G->UDF_AdjList[G->vexnum].first_node = NULL;
    G->vexnum++;
}

// 定位元素所在顶点表的下表
int Located_index(UDF_Graph G,VerTexType elem)
{
    for (int i = 0; i < G->vexnum; ++i) {
        if (G->UDF_AdjList[i].data == elem) return i;
    }
    return -1;
}

// 添加边
void addArc_UDF(UDF_Graph G,VerTexType arc1,VerTexType arc2)
{
    int index_1 = Located_index(G,arc1);
    int index_2 = Located_index(G,arc2);

    UDF_arc* arcNode = malloc(sizeof(struct UDF_arc));
    arcNode->index_vex = index_2;
    arcNode->next_arc = NULL;

    if (!G->UDF_AdjList[index_1].first_node)
    {
        G->UDF_AdjList[index_1].first_node = arcNode;
    }else{
        UDF_arc* tmp_node = G->UDF_AdjList[index_1].first_node;
        while (tmp_node->next_arc)
        {
            tmp_node = tmp_node->next_arc;
        }
        tmp_node->next_arc = arcNode;
    }
    G->arcnum++;

    UDF_arc* arcNode_2 = malloc(sizeof(struct UDF_arc));
    arcNode_2->index_vex = index_1;
    arcNode_2->next_arc = NULL;

    if (!G->UDF_AdjList[index_2].first_node)
    {
        G->UDF_AdjList[index_2].first_node = arcNode_2;
    }else{
        UDF_arc* tmp_node_2 = G->UDF_AdjList[index_1].first_node;
        while (tmp_node_2->next_arc)
        {
            tmp_node_2 = tmp_node_2->next_arc;
        }
        tmp_node_2->next_arc = arcNode_2;
    }
    G->arcnum++;
}

// 打印无向图的邻接表
void print_UDF_Adj(UDF_Graph G)
{
    for(int i=0; i<G->vexnum; i++)
    {
        printf("%d : %c ",i,G->UDF_AdjList[i].data);
        UDF_arc* arcNode = G->UDF_AdjList[i].first_node;
        while(arcNode)
        {
            printf(" --> | %d ",arcNode->index_vex);
            arcNode = arcNode->next_arc;
        }
        printf("\n");
    }
}

// 邻接表表示的图的深度优先搜索  从elem开始
int Visited[MaxVertex] = {0};
void dfs_UDF_adj(UDF_Graph G,VerTexType elem)
{
    int index = Located_index(G,elem);
    printf("%c ",elem);
    Visited[index] = 1;

    UDF_arc* first = G->UDF_AdjList[index].first_node;

    while (first)
    {
        if (!Visited[first->index_vex])
        {
            dfs_UDF_adj(G,G->UDF_AdjList[first->index_vex].data);
        }
        first = first->next_arc;
    }
}

typedef int T;   //这里将顶点下标作为元素

struct QueueNode {
    T element;
    struct QueueNode * next;
};

typedef struct QueueNode * QNode;

struct Queue{
    QNode front, rear;
};

typedef struct Queue * LinkedQueue;

_Bool initQueue(LinkedQueue queue){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue, T element){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

_Bool isEmpty(LinkedQueue queue){
    return queue->front == queue->rear;
}

T pollQueue(LinkedQueue queue){
    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->rear == node) queue->rear = queue->front;
    free(node);
    return e;
}

/**
 * 广度优先遍历
 * @param graph 图
 * @param startVertex 起点顶点下标
 * @param targetVertex 目标顶点下标
 * @param visited 已到达过的顶点数组
 * @param queue 辅助队列
 */
void bfs(UDF_Graph graph, int startVertex, int targetVertex, int * visited, LinkedQueue queue) {
    offerQueue(queue, startVertex);  //首先把起始位置顶点丢进去
    visited[startVertex] = 1;   //起始位置设置为已走过
    while (!isEmpty(queue)) {
        int next = pollQueue(queue);
        printf("%c ", graph->UDF_AdjList[next].data);  //从队列中取出下一个顶点，打印
        UDF_arc* node = graph->UDF_AdjList[next].first_node;    //同样的，把每一个分支都遍历一下
        while (node) {
            if(!visited[node->index_vex]) {   //如果没有走过，那么就直接入队
                offerQueue(queue, node->index_vex);
                visited[node->index_vex] = 1;   //入队时就需要设定为1了
            }
            node = node->next_arc;
        }
    }
}

//int main()
//{
//    UDF_Graph g1 = Create_Adjacency_UDF_Graph();
//    for (int c = 'A'; c <= 'F' ; ++c)
//        addVex_UDF(g1, (char) c);
//
//    for (int i=0;i<g1->vexnum;i++)
//    {
//        printf("%c ",g1->UDF_AdjList[i].data);
//    }
//
//    addArc_UDF(g1,'A','B');
//    addArc_UDF(g1,'A','C');
//    addArc_UDF(g1,'A','D');
//    addArc_UDF(g1,'B','E');
//    addArc_UDF(g1,'C','E');
//    addArc_UDF(g1,'D','F');
//
//    printf("该图的邻接表为：\n");
//    print_UDF_Adj(g1);
//
//    printf("该图的深度优先遍历顺序：");
//    dfs_UDF_adj(g1,'B');
//
//    printf("\n");
//
//    printf("该图的广度优先遍历顺序：");
//    int arr[g1->vexnum];
//    struct Queue queue;
//    initQueue(&queue);
//    for (int i = 0; i < g1->vexnum; ++i) arr[i] = 0;
//    bfs(g1, 0, 5, arr, &queue);
//
//    return 0;
//}
