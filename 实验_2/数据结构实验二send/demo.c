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
char maze[maxn][maxn];
int vis[maxn][maxn];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m;

int LegalPosition(int x, int y){
/* 判断(x,y)位置是否合法*/

}

typedef struct snode{
/* 栈中存储的节点 */
	int x; // 行坐标
	int y; // 列坐标
	int flag; // 当前方向
	struct snode *prev; // 栈中上一个节点的指针
/* 可自由添加需要用的变量 */

}StackNode;

typedef struct {
/* 栈 */
	StackNode *top; // 栈顶指针
	int size; // 栈中节点个数
/* 可自由添加需要用的变量 */

}Stack;

Stack *InitStack(){
/* 初始化栈 */
	Stack* sta = (Stack *)malloc(sizeof(Stack));
	sta->top = NULL;
	sta->size = 0;
}
int isEmpty(Stack *sta){
/* 判断栈是否为空 */

}
int Push(Stack *sta, StackNode now){
/* 將一个节点压入栈中 */

}
StackNode *Pop(Stack *sta){
/* 將一个节点弹出栈 */

}

void DFS(char maze[maxn][maxn], int n, int m){
/*
  深度优先遍历的过程
  请在本过程中求出从"?"能到达的点数
  并将所有能到达的点用"$"覆盖
*/ 
	Stack *q = InitStack();
	memset(vis, 0, sizeof(vis));

}


typedef struct qnode{
/* 队列中存储的节点 */
	int x; // 行坐标
	int y; // 列坐标
	int step; // 当前点与起点的距离
	struct qnode *succ; //队列中下一个节点的指针
/* 可自由添加需要用的变量 */

}QueueNode;

typedef struct {
/* 队列 */
	QueueNode *front; //队首指针
	QueueNode *back; //队尾指针
	int size; // 队列中节点个数
/* 可自由添加需要用的变量 */

}Queue;

Queue *InitQueue(){
/* 初始化队列 */
	Queue* que = (Queue *)malloc(sizeof(Queue));
	que->front = NULL;
	que->back = NULL;
	que->size = 0;
}
int isEmpty(Queue *que){
/* 判断队列是否为空 */

}
int EnQueue(Queue *que, QueueNode now){
/* 入队 */

}
QueueNode *DeQueue(Queue *que){
/* 出队 */

}


void BFS(char maze[maxn][maxn], int n, int m){
/*
  广度优先遍历的过程
  请在本过程中求出从"?"出发走出迷宫的最短路长度
  并将最短路径用"*"覆盖
*/ 
	Queue *q = InitQueue();
	memset(vis, 0, sizeof(vis));


}


int main()
{
/* 从文件maze.in中读入 */
	// freopen("maze.in","r",stdin);
	int o = 0;
	while (scanf("%d%d",&n,&m)!=EOF){
	// 可能有多组输入数据
		o += 1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf(" %c", &maze[i][j]);
		printf("--------Case #%d--------\n", o);
		DFS(maze, n, m);
		BFS(maze, n, m);
	}
	// fclose(stdin);
	return 0;
}
