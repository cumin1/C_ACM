#include <stdio.h>
#define MaxInt 32767 // 表示极大值，即正无穷
#define MVNum 100  // 图的最大的顶点的数量

typedef char VerTexType;  // 图的每个结点的类型
typedef int ArcType;  // 边的权值类型

typedef struct{
    VerTexType vexs[MVNum];     // 顶点表
    ArcType arcs[MVNum][MVNum];  // 邻接矩阵
    int vexnum,arcnum;    // 定义图当前的节点数和边数
} AMGraph;

int LocateVex(AMGraph* G,VerTexType data){
    for (int i = 0; i < G->vexnum; ++i)
        if (G->vexs[i] == data) return i;
    return -1;
}

void CreateUDN(AMGraph* G)
{
    // (1) 输入总顶点数和总边数
    printf("请输入这个图的总顶点数和总边数：");
    scanf("%d %d",&G->vexnum,&G->arcnum);
    // (2) 依次输入点的信息存入顶点表中
    printf("依次输入点的信息存入顶点表中:\n");
    for ( int i=0; i<G->vexnum; i++)
    {
        scanf(" %c",&G->vexs[i]);
    }
    // (3) 初始化邻接矩阵，使每个权值初始化为极大值
    for (int i=0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; ++j)
            G->arcs[i][j] = MaxInt;    // 无直接连接时设置为MaxInt

    printf("G.vexnum = %d,G.arcnum = %d\n",G->vexnum,G->arcnum);

    for (int i = 0; i < G->vexnum; ++i) {
        printf("%c ",G->vexs[i]);
    }
    printf("\n");
    while (getchar() != '\n');
    // (4) 构造邻接矩阵
    VerTexType start, end;
    int weight,i,j;
    for (int k = 0; k < G->arcnum; k++) {
        // 消耗掉可能的换行符或空格
//        while (getchar() != '\n' && getchar() != EOF);
        printf("请输入边的信息（起点 终点 权重），以空格分隔：\n");
        scanf("%c %c %d", &start, &end, &weight);
        i = LocateVex(G,start);
        j = LocateVex(G,end);     // 找到start 和 end 在邻接矩阵的位置
        printf("i = %d,j = %d\n",i,j);
        G->arcs[i][j] = weight; // 设置边的权重
        G->arcs[j][i] = G->arcs[i][j];
    }
    printf("构造图成功！\n");
}

void CreateUDG(AMGraph* G) // 创建无向图
{
    // (1) 输入总顶点数和总边数
    printf("请输入这个图的总顶点数和总边数：");
    scanf("%d %d",&G->vexnum,&G->arcnum);
    // (2) 依次输入点的信息存入顶点表中
    printf("依次输入点的信息存入顶点表中:\n");
    for ( int i=0; i<G->vexnum; i++)
    {
        scanf(" %c",&G->vexs[i]);
    }
    // (3) 初始化邻接矩阵，使每个权值初始化为0
    for (int i=0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; ++j)
            G->arcs[i][j] = 0;    // 无直接连接时设置为0

    printf("G.vexnum = %d,G.arcnum = %d\n",G->vexnum,G->arcnum);

    for (int i = 0; i < G->vexnum; ++i) {
        printf("%c ",G->vexs[i]);
    }
    printf("\n");
    while (getchar() != '\n');
    // (4) 构造邻接矩阵
    VerTexType start, end;
    int i,j;
    for (int k = 0; k < G->arcnum; k++) {
        printf("请输入边的信息（起点 终点），以空格分隔：\n");
        scanf("%c %c", &start, &end);
        i = LocateVex(G,start);
        j = LocateVex(G,end);     // 找到start 和 end 在邻接矩阵的位置
        printf("i = %d,j = %d\n",i,j);
        G->arcs[i][j] = 1; // 设置边的权重1
        G->arcs[j][i] = G->arcs[i][j];
    }
    printf("构造图成功！\n");
}

void CreateDG(AMGraph* G) // 创建有向图
{
    // (1) 输入总顶点数和总边数
    printf("请输入这个图的总顶点数和总边数：");
    scanf("%d %d",&G->vexnum,&G->arcnum);
    // (2) 依次输入点的信息存入顶点表中
    printf("依次输入点的信息存入顶点表中:\n");
    for ( int i=0; i<G->vexnum; i++)
    {
        scanf(" %c",&G->vexs[i]);
    }
    // (3) 初始化邻接矩阵，使每个权值初始化为0
    for (int i=0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; ++j)
            G->arcs[i][j] = 0;    // 无直接连接时设置为0

    printf("G.vexnum = %d,G.arcnum = %d\n",G->vexnum,G->arcnum);

    for (int i = 0; i < G->vexnum; ++i) {
        printf("%c ",G->vexs[i]);
    }
    printf("\n");
    while (getchar() != '\n');
    // (4) 构造邻接矩阵
    VerTexType start, end;
    int i,j;
    for (int k = 0; k < G->arcnum; k++) {
        printf("请输入边的信息（起点 终点 权重），以空格分隔：\n");
        scanf("%c %c ", &start, &end);
        i = LocateVex(G,start);
        j = LocateVex(G,end);      // 找到start 和 end 在邻接矩阵的位置
        printf("i = %d,j = %d\n",i,j);
        G->arcs[i][j] = 1; // 设置边的权重 1
    }
    printf("构造图成功！\n");
}

void print_arcs(AMGraph* G)
{
    for (int i = 0; i < G->vexnum; ++i) {
        for (int j = 0; j < G->vexnum; ++j) {
            printf("%d\t",G->arcs[i][j]);
        }
        printf("\n");
    }
}

//int main()
//{
//    AMGraph amGraph;
//    CreateUDN(&amGraph);
//    print_arcs(&amGraph);
//
//    return 0;
//}


