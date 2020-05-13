#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define maxn 1002
/*
maze�������ڴ洢�Թ�
vis���������ڱ�����ʱ�����Ѿ����ʹ��ĵ�
dir�������ڱ�ʾ�������ҷ���
n��m�ֱ��ʾ�Թ�������������
*/
char MAZE[maxn][maxn];
int vis[maxn][maxn];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
int Judge;

int LegalPosition(int x, int y) {
    /* �ж�(x,y)λ���Ƿ�Ϸ�*/
    if(x<1 || x>n || y<1 || y>m || MAZE[x][y]!='0' || vis[x][y]==1)
        return 0;
    else
        return 1;
}

typedef struct snode {
    /* ջ�д洢�Ľڵ� */
    int x; // ������
    int y; // ������
    int flag; // ��ǰ����
    struct snode *prev; // ջ����һ���ڵ��ָ��
    /* �����������Ҫ�õı��� */

} StackNode;

typedef struct {
    /* ջ */
    StackNode *top; // ջ��ָ��
    int size; // ջ�нڵ����
    /* �����������Ҫ�õı��� */

} Stack;

Stack *InitStack() {
    /* ��ʼ��ջ */
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
    /* �ж�ջ�Ƿ�Ϊ�� */
    if(sta->top)
        return 0;
    else
        return 1;
}
void Push(Stack *sta, StackNode now) {
    /* ��һ���ڵ�ѹ��ջ�� */
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
    /* ��һ���ڵ㵯��ջ */
    StackNode* p;
    p=sta->top;
    sta->top=p->prev;
    sta->size--;
    return p;
}

void DFS(char MAZE[maxn][maxn], int n, int m) {
    /*
      ������ȱ����Ĺ���
      ���ڱ������������"?"�ܵ���ĵ���
      ���������ܵ���ĵ���"$"����
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
    /* �����д洢�Ľڵ� */
    int x; // ������
    int y; // ������
    int step; // ��ǰ�������ľ���
    struct qnode *pre;//ǰһ���ڵ�
    struct qnode *pab; //��������һ���ڵ��ָ��
    /* �����������Ҫ�õı��� */

} QueueNode;

typedef struct {
    /* ���� */
    QueueNode *front; //����ָ��
    QueueNode *back; //��βָ��
    int size; // �����нڵ����
    /* �����������Ҫ�õı��� */

} Queue;

Queue *InitQueue() {
    /* ��ʼ������ */
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
    /* �ж϶����Ƿ�Ϊ�� */
    if(que->size==0)
        return 1;
    else
        return 0;
}
void EnQueue(Queue *que, QueueNode now) {
    /* ��� */
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
    /* ���� */
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
      ������ȱ����Ĺ���
      ���ڱ������������"?"�����߳��Թ������·����
      �������·����"*"����
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
            // �����ж�����������
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

