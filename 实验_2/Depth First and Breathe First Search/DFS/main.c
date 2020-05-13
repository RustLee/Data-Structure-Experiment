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
        printf("Out of memory!");
        exit(0);
    }
    sta->top = NULL;
    sta->size = 0;
    return sta;
}
int isEmpty(Stack *sta) {
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
        printf("Out of memory!");
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
    while(!isEmpty(q)) {
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

int check_vis() {
    int sum=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if(vis[i][j]==1)
                sum++;
    return sum-1;
}



int main() {
    printf("Please input the name of the file:");
    FILE *fp;
    char name[100];
    scanf(" %s",name);
    fp=fopen(name,"r");
    int o = 0;
    while (fscanf(fp,"%d%d",&n,&m)!=EOF) {
            // 可能有多组输入数据
        o ++;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                fscanf(fp," %c", &MAZE[i][j]);
        printf("--------Case #%d--------\n", o);
        DFS(MAZE, n, m);
        printf("%d positions are passable.\n",check_vis());
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if(MAZE[i][j]=='0' && vis[i][j]==1)
                    printf("$");
                else
                    printf("%c",MAZE[i][j]);
                }
            printf("\n");
        }
    }
    fclose(fp);
    return 0;
}

