#include <stdio.h>
#include <stdlib.h>
#define MaxVertex 10   // �������ͼ���ֻ���ж��ٸ����

/*
 * �ڽӱ� ��������ͼ
 */

typedef char VerTexType;

// ����߽ṹ
typedef struct UDF_arc{
    int index_vex;
    struct UDF_arc* next_arc;
}UDF_arc;

// ���嶥���Ԫ�صĽṹ
typedef struct UDF_VexNode{
    VerTexType data;
    UDF_arc * first_node;
}UDF_VexNode,UDF_AdjList[MaxVertex];

// ͼ�ṹ
typedef struct Adjacency_UDF_Graph{
    UDF_VexNode UDF_AdjList[MaxVertex];
    int vexnum;    // ��������
    int arcnum;    // ������
} * UDF_Graph;

// ��������ͼ
UDF_Graph Create_Adjacency_UDF_Graph()
{
    UDF_Graph G = malloc(sizeof(struct Adjacency_UDF_Graph));
    G->vexnum = G->arcnum = 0;
    return G;
}

// ��Ӷ���
void addVex_UDF(UDF_Graph G,VerTexType vex)
{
    if (G->vexnum >= MaxVertex) return;
    G->UDF_AdjList[G->vexnum].data = vex;
    G->UDF_AdjList[G->vexnum].first_node = NULL;
    G->vexnum++;
}

// ��λԪ�����ڶ������±�
int Located_index(UDF_Graph G,VerTexType elem)
{
    for (int i = 0; i < G->vexnum; ++i) {
        if (G->UDF_AdjList[i].data == elem) return i;
    }
    return -1;
}

// ��ӱ�
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

// ��ӡ����ͼ���ڽӱ�
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

// �ڽӱ��ʾ��ͼ�������������  ��elem��ʼ
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

typedef int T;   //���ｫ�����±���ΪԪ��

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
 * ������ȱ���
 * @param graph ͼ
 * @param startVertex ��㶥���±�
 * @param targetVertex Ŀ�궥���±�
 * @param visited �ѵ�����Ķ�������
 * @param queue ��������
 */
void bfs(UDF_Graph graph, int startVertex, int targetVertex, int * visited, LinkedQueue queue) {
    offerQueue(queue, startVertex);  //���Ȱ���ʼλ�ö��㶪��ȥ
    visited[startVertex] = 1;   //��ʼλ������Ϊ���߹�
    while (!isEmpty(queue)) {
        int next = pollQueue(queue);
        printf("%c ", graph->UDF_AdjList[next].data);  //�Ӷ�����ȡ����һ�����㣬��ӡ
        UDF_arc* node = graph->UDF_AdjList[next].first_node;    //ͬ���ģ���ÿһ����֧������һ��
        while (node) {
            if(!visited[node->index_vex]) {   //���û���߹�����ô��ֱ�����
                offerQueue(queue, node->index_vex);
                visited[node->index_vex] = 1;   //���ʱ����Ҫ�趨Ϊ1��
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
//    printf("��ͼ���ڽӱ�Ϊ��\n");
//    print_UDF_Adj(g1);
//
//    printf("��ͼ��������ȱ���˳��");
//    dfs_UDF_adj(g1,'B');
//
//    printf("\n");
//
//    printf("��ͼ�Ĺ�����ȱ���˳��");
//    int arr[g1->vexnum];
//    struct Queue queue;
//    initQueue(&queue);
//    for (int i = 0; i < g1->vexnum; ++i) arr[i] = 0;
//    bfs(g1, 0, 5, arr, &queue);
//
//    return 0;
//}
