#include <stdio.h>
#define MaxInt 32767 // ��ʾ����ֵ����������
#define MVNum 100  // ͼ�����Ķ��������

typedef char VerTexType;  // ͼ��ÿ����������
typedef int ArcType;  // �ߵ�Ȩֵ����

typedef struct{
    VerTexType vexs[MVNum];     // �����
    ArcType arcs[MVNum][MVNum];  // �ڽӾ���
    int vexnum,arcnum;    // ����ͼ��ǰ�Ľڵ����ͱ���
} AMGraph;

int LocateVex(AMGraph* G,VerTexType data){
    for (int i = 0; i < G->vexnum; ++i)
        if (G->vexs[i] == data) return i;
    return -1;
}

void CreateUDN(AMGraph* G)
{
    // (1) �����ܶ��������ܱ���
    printf("���������ͼ���ܶ��������ܱ�����");
    scanf("%d %d",&G->vexnum,&G->arcnum);
    // (2) ������������Ϣ���붥�����
    printf("������������Ϣ���붥�����:\n");
    for ( int i=0; i<G->vexnum; i++)
    {
        scanf(" %c",&G->vexs[i]);
    }
    // (3) ��ʼ���ڽӾ���ʹÿ��Ȩֵ��ʼ��Ϊ����ֵ
    for (int i=0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; ++j)
            G->arcs[i][j] = MaxInt;    // ��ֱ������ʱ����ΪMaxInt

    printf("G.vexnum = %d,G.arcnum = %d\n",G->vexnum,G->arcnum);

    for (int i = 0; i < G->vexnum; ++i) {
        printf("%c ",G->vexs[i]);
    }
    printf("\n");
    while (getchar() != '\n');
    // (4) �����ڽӾ���
    VerTexType start, end;
    int weight,i,j;
    for (int k = 0; k < G->arcnum; k++) {
        // ���ĵ����ܵĻ��з���ո�
//        while (getchar() != '\n' && getchar() != EOF);
        printf("������ߵ���Ϣ����� �յ� Ȩ�أ����Կո�ָ���\n");
        scanf("%c %c %d", &start, &end, &weight);
        i = LocateVex(G,start);
        j = LocateVex(G,end);     // �ҵ�start �� end ���ڽӾ����λ��
        printf("i = %d,j = %d\n",i,j);
        G->arcs[i][j] = weight; // ���ñߵ�Ȩ��
        G->arcs[j][i] = G->arcs[i][j];
    }
    printf("����ͼ�ɹ���\n");
}

void CreateUDG(AMGraph* G) // ��������ͼ
{
    // (1) �����ܶ��������ܱ���
    printf("���������ͼ���ܶ��������ܱ�����");
    scanf("%d %d",&G->vexnum,&G->arcnum);
    // (2) ������������Ϣ���붥�����
    printf("������������Ϣ���붥�����:\n");
    for ( int i=0; i<G->vexnum; i++)
    {
        scanf(" %c",&G->vexs[i]);
    }
    // (3) ��ʼ���ڽӾ���ʹÿ��Ȩֵ��ʼ��Ϊ0
    for (int i=0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; ++j)
            G->arcs[i][j] = 0;    // ��ֱ������ʱ����Ϊ0

    printf("G.vexnum = %d,G.arcnum = %d\n",G->vexnum,G->arcnum);

    for (int i = 0; i < G->vexnum; ++i) {
        printf("%c ",G->vexs[i]);
    }
    printf("\n");
    while (getchar() != '\n');
    // (4) �����ڽӾ���
    VerTexType start, end;
    int i,j;
    for (int k = 0; k < G->arcnum; k++) {
        printf("������ߵ���Ϣ����� �յ㣩���Կո�ָ���\n");
        scanf("%c %c", &start, &end);
        i = LocateVex(G,start);
        j = LocateVex(G,end);     // �ҵ�start �� end ���ڽӾ����λ��
        printf("i = %d,j = %d\n",i,j);
        G->arcs[i][j] = 1; // ���ñߵ�Ȩ��1
        G->arcs[j][i] = G->arcs[i][j];
    }
    printf("����ͼ�ɹ���\n");
}

void CreateDG(AMGraph* G) // ��������ͼ
{
    // (1) �����ܶ��������ܱ���
    printf("���������ͼ���ܶ��������ܱ�����");
    scanf("%d %d",&G->vexnum,&G->arcnum);
    // (2) ������������Ϣ���붥�����
    printf("������������Ϣ���붥�����:\n");
    for ( int i=0; i<G->vexnum; i++)
    {
        scanf(" %c",&G->vexs[i]);
    }
    // (3) ��ʼ���ڽӾ���ʹÿ��Ȩֵ��ʼ��Ϊ0
    for (int i=0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; ++j)
            G->arcs[i][j] = 0;    // ��ֱ������ʱ����Ϊ0

    printf("G.vexnum = %d,G.arcnum = %d\n",G->vexnum,G->arcnum);

    for (int i = 0; i < G->vexnum; ++i) {
        printf("%c ",G->vexs[i]);
    }
    printf("\n");
    while (getchar() != '\n');
    // (4) �����ڽӾ���
    VerTexType start, end;
    int i,j;
    for (int k = 0; k < G->arcnum; k++) {
        printf("������ߵ���Ϣ����� �յ� Ȩ�أ����Կո�ָ���\n");
        scanf("%c %c ", &start, &end);
        i = LocateVex(G,start);
        j = LocateVex(G,end);      // �ҵ�start �� end ���ڽӾ����λ��
        printf("i = %d,j = %d\n",i,j);
        G->arcs[i][j] = 1; // ���ñߵ�Ȩ�� 1
    }
    printf("����ͼ�ɹ���\n");
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


