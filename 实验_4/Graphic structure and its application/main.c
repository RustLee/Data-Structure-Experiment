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
    int vexnum,arcnum;
}MGraph;

void CreateGraph(MGraph *G)
{
    int i,j,k,weight;
    int t1,t2;
    printf("点数 边数:");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
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

}

void ShortestPath(MGraph G,int D[MaxNum][MaxNum])
{
    int v,w,k;
    for(v=0;v<G.vexnum;v++)
    {
        for(w=0;w<G.vexnum;w++)
        {
            D[v][w]=G.edges[v][w];
        }
    }
    for(k=0;k<G.vexnum;k++)
    {
        for(v=0;v<G.vexnum;v++)
        {
            for(w=0;w<G.vexnum;w++)
            {
                if(D[v][k]!=INFINITY&&D[k][w]!=INFINITY)
                {
                    if(D[v][w]>(D[v][k]+D[k][w]))
                    {
                        D[v][w]=D[v][k]+D[k][w];
                    }
                }
            }
        }
    }
}
void main()
{
    int j,ret;
    MGraph G;
    printf("出发点：");
    scanf("%d",&ret);
    CreateGraph(&G);
    int D[MaxNum][MaxNum];
    ShortestPath(G,D);
    for(j=0;j<G.vexnum;j++)
            printf(" %d ",D[ret-1][j]);
}
