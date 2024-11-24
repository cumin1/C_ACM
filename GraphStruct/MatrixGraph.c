#include <stdio.h>
#include <stdlib.h>
#define MVNum 10  // ͼ�����Ķ��������

/*
 * ���ڹ���һ������ͼ
 */

typedef char VerTexType;  // ͼ��ÿ����������
typedef struct MaxtrixGraph{
    VerTexType vexs[MVNum]; // �����
    int arcs[MVNum][MVNum];  // �ڽӾ���
    int vexnum,arcnum;    // ����ͼ��ǰ�Ľڵ����ͱ���
} * Graph;

Graph createMaxtrixGraph()
{
    Graph graph = malloc(sizeof(struct MaxtrixGraph));
    graph->vexnum = graph->arcnum = 0;    // �մ���ͼ��ʱ��û�ж���ͱ�
    // �����Ƕ�������ͼ ���԰Ѿ��������е�ֵ��ʼ��Ϊ0
    for (int i=0; i<MVNum; i++)
    {
        for (int j=0; j<MVNum; j++)
        {
            graph->arcs[i][j] = 0;
        }
    }

    return graph;
}

// ��Ӷ���elem��ͼG��
void addVertex(Graph G,VerTexType elem)
{
    // ����������������������Ӷ���
    if (G->vexnum >= MVNum) return;
    G->vexs[G->vexnum] = elem;
    G->vexnum++;
}

// ��λ�����ڶ�����е�λ��
int Located_vex(Graph G,VerTexType elem)
{
    for (int i=0; i<G->vexnum; i++)
    {
        if (G->vexs[i] == elem) return i;
    }
    return -1; // ����������û�ж��㣬�򷵻�-1
}

// ��ӱ� a-b
void addEdge(Graph G, VerTexType a, VerTexType b)
{
    int i = Located_vex(G,a);
    int j = Located_vex(G,b);
    if (i!=-1 && j!=-1){
        G->arcs[i][j] = 1;    // ���ñ��ھ����е�λ�ø�ֵΪ1
        G->arcs[j][i] = 1;
        G->arcnum++;          // �ߵĸ���+1
    }
}

// ��ӡ�ڽӾ���
void print_MaxtrixGraph(Graph G)
{
    for ( int i = 0; i < G->vexnum; i++){
        for (int j = 0; j < G->vexnum; j++){
            printf("%d ",G->arcs[i][j]);
        }
        printf("\n");
    }
}

// ���ڽӾ����ʾ����������� �Ӷ���V��ʼ
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
//    // ��Ӷ��� 'A' - 'F'
//    for (char i='A'; i <= 'F'; i++)
//    {
//        addVertex(g1,i);
//    }
//
//    // ��ӱ�
//    addEdge(g1,'A','B');
//    addEdge(g1,'A','C');
//    addEdge(g1,'A','D');
//    addEdge(g1,'B','E');
//    addEdge(g1,'C','E');
//    addEdge(g1,'D','F');
//
//    // ��ӡ�ڽӾ���
//    printf("��ͼ���ڽӾ���Ϊ:\n");
//    print_MaxtrixGraph(g1);
//
//    printf("������ȱ���˳��Ϊ��");
//    dfs(g1,'B');
//
//    return 0;
//}