#include <stdio.h>
#include <stdlib.h>
#define INFINITY 2147483647
#define MaxNum 20

typedef int VertexType;
typedef int EdgeType;
typedef struct
{
    VertexType vexs[MaxNum];
    EdgeType edges[MaxNum][MaxNum];
    int vexnum,arcnum,m,n;
}MGraph;

void CreateGraph(MGraph *G)
{
    int i,j,k,weight;
    int t1,t2;
    printf("神经元个数 边数 输入层神经元个数 输出层神经元个数:\n");
    scanf("%d %d %d %d",&(G->vexnum),&(G->arcnum),&(G->m),&(G->n));
    printf("输入顶点的名称");//防止顶点数值与位置下标不同导致错误
    for(i=0;i<G->vexnum;i++)
    {
        getchar();
        scanf("%d",&(G->vexs[i]));
    }
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            if(i==j)
                G->edges[i][j]=0;
            else
                G->edges[i][j]=INFINITY;
        }
    }
    for(k=0;k<G->arcnum;k++)
    {
        printf("起点 终点：");
        scanf("%d %d",&t1,&t2);
        for(i=0;t1!=G->vexs[i];i++);
        for(j=0;t2!=G->vexs[j];j++);
        getchar();
        printf("权值:");
        scanf("%d",&weight);
        G->edges[i][j]=weight;
    }
    printf("起始点：");
    for(i=0;i<G->m;i++)
    {
        scanf("%d",&G->edges[i][i]);
    }

}

void Update_Matrix(MGraph G,int D[MaxNum][MaxNum])
{
    int v,w;
    for(v=0;v<G.vexnum;v++)
    {
        for(w=0;w<G.vexnum;w++)
        {
            D[v][w]=G.edges[v][w];
        }
    }
    for(v=G.m;v<G.vexnum;v++)
    {
        for(w=0;w<G.vexnum;w++)
        {
            if(D[w][v]!=INFINITY&&w<v)
            {
                D[v][v] += D[w][v]*D[w][w];
            }
        }
    }

}
void main()
{
    int i;
    MGraph G;
    CreateGraph(&G);
    int D[MaxNum][MaxNum];
    Update_Matrix(G,D);
    for(i=G.vexnum-G.n;i<G.vexnum;i++)
            printf(" %d ",D[i][i]);
}
