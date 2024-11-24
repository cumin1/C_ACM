#include <stdio.h>
#include <stdlib.h>
#define MVNum 10  // 图的最大的顶点的数量

/*
 * 现在构建一个无向图
 */

typedef char VerTexType;  // 图的每个结点的类型
typedef struct MaxtrixGraph{
    VerTexType vexs[MVNum]; // 顶点表
    int arcs[MVNum][MVNum];  // 邻接矩阵
    int vexnum,arcnum;    // 定义图当前的节点数和边数
} * Graph;

Graph createMaxtrixGraph()
{
    Graph graph = malloc(sizeof(struct MaxtrixGraph));
    graph->vexnum = graph->arcnum = 0;    // 刚创建图的时候没有顶点和边
    // 由于是定义有向图 所以把矩阵中所有的值初始化为0
    for (int i=0; i<MVNum; i++)
    {
        for (int j=0; j<MVNum; j++)
        {
            graph->arcs[i][j] = 0;
        }
    }

    return graph;
}

// 添加顶点elem到图G中
void addVertex(Graph G,VerTexType elem)
{
    // 如果顶点表已满，则不能在添加顶点
    if (G->vexnum >= MVNum) return;
    G->vexs[G->vexnum] = elem;
    G->vexnum++;
}

// 定位顶点在顶点表中的位置
int Located_vex(Graph G,VerTexType elem)
{
    for (int i=0; i<G->vexnum; i++)
    {
        if (G->vexs[i] == elem) return i;
    }
    return -1; // 如果顶点表中没有顶点，则返回-1
}

// 添加边 a-b
void addEdge(Graph G, VerTexType a, VerTexType b)
{
    int i = Located_vex(G,a);
    int j = Located_vex(G,b);
    if (i!=-1 && j!=-1){
        G->arcs[i][j] = 1;    // 将该边在矩阵中的位置赋值为1
        G->arcs[j][i] = 1;
        G->arcnum++;          // 边的个数+1
    }
}

// 打印邻接矩阵
void print_MaxtrixGraph(Graph G)
{
    for ( int i = 0; i < G->vexnum; i++){
        for (int j = 0; j < G->vexnum; j++){
            printf("%d ",G->arcs[i][j]);
        }
        printf("\n");
    }
}

// 用邻接矩阵表示深度优先搜索 从顶点V开始
int visited[MVNum] = {0};
void dfs(Graph G,VerTexType v){
    int i = Located_vex(G,v);
    printf("%c ",v);
    visited[i] = 1;
    for(int w=0;w<G->vexnum;w++){
       if ((G->arcs[i][w]!=0)&&(!visited[w])){
           dfs(G,G->vexs[w]);
       }
    }
}

//int main()
//{
//    Graph g1 = createMaxtrixGraph();
//
//    // 添加顶点 'A' - 'F'
//    for (char i='A'; i <= 'F'; i++)
//    {
//        addVertex(g1,i);
//    }
//
//    // 添加边
//    addEdge(g1,'A','B');
//    addEdge(g1,'A','C');
//    addEdge(g1,'A','D');
//    addEdge(g1,'B','E');
//    addEdge(g1,'C','E');
//    addEdge(g1,'D','F');
//
//    // 打印邻接矩阵
//    printf("该图的邻接矩阵为:\n");
//    print_MaxtrixGraph(g1);
//
//    printf("深度优先遍历顺序为：");
//    dfs(g1,'B');
//
//    return 0;
//}