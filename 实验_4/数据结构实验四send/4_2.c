#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define maxn 10020
#define maxm 200020

using namespace std;
int n, m, p, q;
int input[maxn], output[maxn];

// 图的定义
// 注意，模板采用前向星的建图方法
// 你也可以选择自己的方法建图
struct edge{
	int s, t, w;
	int next;
};

struct edge e[maxm];
int head[maxn];
int tot;

// 图的建立
void init_graph(){
	tot = 0;
	memset(head, 0, sizeof(head));
}

void add_edge(int x, int y, int z){
	e[++tot].s = x;
	e[tot].t = y;
	e[tot].w = z;
	e[tot].next = head[x];
	head[x] = tot;
}

// 前向传播
void forward_propagation(){
	
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &p, &q);
	init_graph();
	int x, y, z;
	for (int i=1; i<=m; i++){
		scanf("%d%d%d", &x, &y, &z);
		add_edge(x, y, z);
	}
	for (int i=1; i<=p; i++){
		scanf("%d", &input[i]);
	}

	forward_propagation();
	
	for (int i=n-q+1; i<=n; i++){
		printf(i<n?"%d ":"%d\n", output[i]);
	}


	return 0;
}