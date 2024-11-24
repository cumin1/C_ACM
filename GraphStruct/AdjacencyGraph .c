#include <stdio.h>
#include <stdlib.h>
#define MaxVertex 5   // 定义这个图最多只能有5个结点

/*
 * 现在要用邻接表构建有向网
 */

typedef char VerTexType;

typedef struct ArcNode{    // 定义边的结构
    int nextVertex;        // 定义头顶点连接的顶点 这里是顶点数组的下标 所以是int
    int info;              // 这条边的权值
    struct ArcNode* nextNode;    // 记录下一个结点的指针
}ArcNode;

typedef struct VNode{    // 定义单个头顶点的结构
    VerTexType data;
    ArcNode* firstArc;    // 第一条边
}VNode,AjdList[MaxVertex];

typedef struct AdjacencyGraph{    // 定义整张图 由顶点数、边数、头顶点组成的数组构成
    AjdList ajdList;
    int vexnum,arcnum;    // 定义图当前的节点数和边数
} *AdjacencyGraph;

AdjacencyGraph create_AdjacencyGraph()     // 创建有向网
{
    AdjacencyGraph graph = malloc(sizeof(struct AdjacencyGraph));
    graph->vexnum = graph->arcnum = 0;
    return graph;
}

// 添加顶点
void addAdjVertex(AdjacencyGraph graph, VerTexType element)
{
    if (graph->vexnum >= MaxVertex) return;  // 如果顶点已满 则不添加
    graph->ajdList[graph->vexnum].data = element;   // 将顶点数组中元素的data赋值
    graph->ajdList[graph->vexnum].firstArc = NULL;  // 将这个顶点指向NULL
    graph->vexnum++;
}

// 定位顶点在首顶点数组的下表
int Located_VNodeList(AdjacencyGraph graph, VerTexType a)
{
    for (int i=0; i<graph->vexnum; i++)
    {
        if (graph->ajdList[i].data == a) return i;
    }
    return -1;  // 如果图中没有该顶点 则返回-1
}

// 添加边 需要知道顶点 和需要链接的顶点 还有边的权值
void addAdjEdge(AdjacencyGraph graph, VerTexType a, VerTexType b,int info)
{
    int vnode_index  = Located_VNodeList(graph,a);
    int node_index  = Located_VNodeList(graph,b);
    ArcNode* arcNode = malloc(sizeof(struct ArcNode));
    arcNode->nextVertex = node_index;
    arcNode->info = info;
    arcNode->nextNode = NULL;
    VNode* p = &graph->ajdList[vnode_index];
    if (p->firstArc == NULL){
        p->firstArc = arcNode;
        graph->arcnum++;
    }else{
        ArcNode* first_arc = p->firstArc;
        while(first_arc->nextNode)
        {
            first_arc = first_arc->nextNode;
        }
        first_arc->nextNode = arcNode;
        graph->arcnum++;
    }
}

// 打印有向网 的邻接表
void printAdjacencyGraph(AdjacencyGraph G)
{
    for(int i=0; i<G->vexnum; i++)
    {
        printf("%d : %c ",i,G->ajdList[i].data);
        ArcNode* arcNode = G->ajdList[i].firstArc;
        while(arcNode)
        {
            printf(" --> | %d | %d | ",arcNode->nextVertex,arcNode->info);
            arcNode = arcNode->nextNode;
        }
        printf("\n");
    }
}

//int main()
//{
//    AdjacencyGraph g1 = create_AdjacencyGraph();
//    for (int c = 'A'; c <= 'D' ; ++c)
//        addAdjVertex(g1, (char) c);
//
//    addAdjEdge(g1, 'A', 'B',10);   //A -> B
//    addAdjEdge(g1, 'B', 'C',20);   //B -> C
//    addAdjEdge(g1, 'C', 'D',30);   //C -> D
//    addAdjEdge(g1, 'D', 'A',40);   //D -> A
//    addAdjEdge(g1, 'C', 'A',50);   //C -> A
//
//    printAdjacencyGraph(g1);
//
//    return 0;
//}
