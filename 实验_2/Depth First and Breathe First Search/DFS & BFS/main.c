#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define maxn 1002
/*
maze数组用于存储迷宫
vis数组用于在遍历的时候标记已经访问过的点
dir数组用于表示上下左右方向
n和m分别表示迷宫的行数和列数
*/
char MAZE[maxn][maxn];
int vis[maxn][maxn];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
int Judge;

int LegalPosition(int x, int y) {
    /* 判断(x,y)位置是否合法*/
    if(x<1 || x>n || y<1 || y>m || MAZE[x][y]!='0' || vis[x][y]==1)
        return 0;
    else
        return 1;
}

typedef struct snode {
    /* 栈中存储的节点 */
    int x; // 行坐标
    int y; // 列坐标
    int flag; // 当前方向
    struct snode *prev; // 栈中上一个节点的指针
    /* 可自由添加需要用的变量 */

} StackNode;

typedef struct {
    /* 栈 */
    StackNode *top; // 栈顶指针
    int size; // 栈中节点个数
    /* 可自由添加需要用的变量 */

} Stack;

Stack *InitStack() {
    /* 初始化栈 */
    Stack* sta = (Stack *)malloc(sizeof(Stack));
    if(!sta) {
        printf("Memory allocation failed!");
        exit(0);
    }
    sta->top = NULL;
    sta->size = 0;
    return sta;
}
int isEmpty_S(Stack *sta) {
    /* 判断栈是否为空 */
    if(sta->top)
        return 0;
    else
        return 1;
}
void Push(Stack *sta, StackNode now) {
    /* 將一个节点压入栈中 */
    StackNode* p=(StackNode*)malloc(sizeof(StackNode));
    if(!p) {
        printf("Memory allocation failed!");
        exit(0);
    }
    p->x=now.x;
    p->y=now.y;
    p->flag=now.flag;
    p->prev=sta->top;
    sta->top=p;
    sta->size++;
}
StackNode *Pop(Stack *sta) {
    /* 將一个节点弹出栈 */
    StackNode* p;
    p=sta->top;
    sta->top=p->prev;
    sta->size--;
    return p;
}

void DFS(char MAZE[maxn][maxn], int n, int m) {
    /*
      深度优先遍历的过程
      请在本过程中求出从"?"能到达的点数
      并将所有能到达的点用"$"覆盖
    */
    Stack *q = InitStack();
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(MAZE[i][j]=='?') {
                StackNode sn;
                sn.x=i;
                sn.y=j;
                sn.flag=0;
                sn.prev=NULL;
                Push(q,sn);
                break;
            }
    while(!isEmpty_S(q)) {
        StackNode* p=Pop(q);
        int x,y,flag;
        flag=p->flag;
        x=p->x;
        y=p->y;
        vis[x][y]=1;
        if(LegalPosition(x+dir[flag][0],y+dir[flag][1])) {
            Push(q,*p);
            StackNode sn;
            sn.x=x+dir[flag][0];
            sn.y=y+dir[flag][1];
            sn.flag=0;
            sn.prev=NULL;
            Push(q,sn);
        }
        else if(flag<3) {
            StackNode sn;
            sn.x=x;
            sn.y=y;
            sn.flag=flag+1;
            sn.prev=NULL;
            Push(q,sn);
        }
        free(p);
    }
}

int Check_Visit() {
    int sum=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if(vis[i][j]==1)
                sum++;
    return sum-1;
}



int TargetLocation(int x,int y) {
    if(x==1 || x==n || y==1 || y==m)
        return 1;
    else
        return 0;
}


typedef struct qnode {
    /* 队列中存储的节点 */
    int x; // 行坐标
    int y; // 列坐标
    int step; // 当前点与起点的距离
    struct qnode *pre;//前一个节点
    struct qnode *pab; //队列中下一个节点的指针
    /* 可自由添加需要用的变量 */

} QueueNode;

typedef struct {
    /* 队列 */
    QueueNode *front; //队首指针
    QueueNode *back; //队尾指针
    int size; // 队列中节点个数
    /* 可自由添加需要用的变量 */

} Queue;

Queue *InitQueue() {
    /* 初始化队列 */
    Queue* que = (Queue *)malloc(sizeof(Queue));
    if(!que) {
        printf("Memory allocation failed!");
        exit(0);
    }
    que->front = NULL;
    que->back = NULL;
    que->size = 0;
}
int isEmpty_Q(Queue *que) {
    /* 判断队列是否为空 */
    if(que->size==0)
        return 1;
    else
        return 0;
}
void EnQueue(Queue *que, QueueNode now) {
    /* 入队 */
    QueueNode* p=(QueueNode*)malloc(sizeof(QueueNode));
    if(!p) {
        printf("Memory allocation failed!");
        exit(0);
    }
    *p=now;
    if(isEmpty_Q(que)) {
        que->front=que->back=p;
    } else {
        que->back->pab=p;
        que->back=p;
    }
    que->size++;
}
QueueNode *DeQueue(Queue *que) {
    /* 出队 */
    QueueNode* p;
    p=que->front;
    que->front=p->pab;
    que->size--;
    return p;
}

void GetPath(QueueNode* p) {
    while(p) {
        vis[p->x][p->y]++;
        p=p->pre;
    }
}

void BFS(char MAZE[maxn][maxn], int n, int m) {
    /*
      广度优先遍历的过程
      请在本过程中求出从"?"出发走出迷宫的最短路长度
      并将最短路径用"*"覆盖
    */
    Queue *q = InitQueue();
    memset(vis, 0, sizeof(vis));
    Judge=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(MAZE[i][j]=='?') {
                QueueNode qn;
                qn.x=i;
                qn.y=j;
                qn.step=0;
                qn.pab=qn.pre=NULL;
                EnQueue(q,qn);
                break;
            }
    while(!isEmpty_Q(q)) {
        QueueNode* p=DeQueue(q);
        int x,y;
        x=p->x;
        y=p->y;
        vis[x][y]=1;
        if(TargetLocation(x,y)) {
            printf("Need %d steps.\n\n",p->step+1);
            GetPath(p);
            Judge=1;
            break;
        }
        for(int k=0; k<4; k++)
            if(LegalPosition(x+dir[k][0],y+dir[k][1])) {
                QueueNode qn;
                qn.x=x+dir[k][0];
                qn.y=y+dir[k][1];
                qn.pre=p;
                qn.pab=NULL;
                qn.step=p->step+1;
                EnQueue(q,qn);
            }
    }

}

int main() {
    FILE *fp;
    fp=fopen("maze.in","r");
    int o = 0;
    while (fscanf(fp,"%d%d",&n,&m)!=EOF) {
            // 可能有多组输入数据
        o ++;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                fscanf(fp," %c", &MAZE[i][j]);
        printf("--------Case #%d--------\n", o);
        DFS(MAZE, n, m);
        printf("%d positions are passable.\n\n",Check_Visit());
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if(MAZE[i][j]=='0' && vis[i][j]==1)
                    printf("$");
                else
                    printf("%c",MAZE[i][j]);
                }
            printf("\n");
        }
        printf("\n\n");
        BFS(MAZE, n, m);
            if(Judge) {
                for (int i=1; i<=n; i++){
                    for (int j=1; j<=m; j++) {
                        if(MAZE[i][j]=='0' && vis[i][j]==2)
                            printf("*");
                        else
                            printf("%c",MAZE[i][j]);
                    }
                    printf("\n");

                }
                printf("\n");
            }
            else
            {
                for (int i=1; i<=n; i++){
                    for (int j=1; j<=m; j++)
                    {
                        printf("%c",MAZE[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
                printf("Impossible!\n\n");
            }
    }
    fclose(fp);
    return 0;
}

