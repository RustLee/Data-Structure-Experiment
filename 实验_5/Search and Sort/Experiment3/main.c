#include<stdio.h>
#include<stdlib.h>
#define MAXN 200000
typedef struct data
{
    int pos,va;
}Point;

int compare(Point a,Point b)
{
    if(a.pos == b.pos)
        return a.va > b.va;
    else
        return a.pos < b.pos;
}


void Merge_Sort(Point* a,int left,int right,Point* Pool)
{
    if(left == right)
        return;
    int mid = (left + right) >> 1,i = left,j = mid + 1,k = 0;
    Merge_Sort(a,left,mid,Pool);
    Merge_Sort(a,mid + 1,right,Pool);
    while(i <= mid && j <= right)
    {
        Pool[k++] = compare(a[i],a[j]) ? a[i++] : a[j++];
    }
    while(i <= mid) Pool[k++] = a[i++];
    while(j <= right) Pool[k++] = a[j++];
    for(i = 0;i < k;++i)
        a[left + i] = Pool[i];
}

int main()
{
    int n,m,nxt,i,l,r,size = 0;
    scanf("%d %d",&n,&m);
    Point* KeyPoints = (Point*)calloc(m * 3,sizeof(Point));
    Point* UniquePoints = (Point*)calloc(m * 3 + 2,sizeof(Point));
    Point* Pool = (Point*)calloc(m * 3,sizeof(Point));
    int* anspool =(int*)calloc(m * 6,sizeof(int));
    for(i = 0;i < m;++i)
    {
        scanf("%d %d",&l,&r);
        KeyPoints[size++] = (Point){l,1};
        KeyPoints[size++] = (Point){r,0};
        KeyPoints[size++] = (Point){r + 1,-1};
    }
    Merge_Sort(KeyPoints,0,size - 1,Pool);
    int MaxNum = 0,nowva = 0,ucnt = 0,nowadd;
    for(i = 0;i < size;i = nxt)
    {
        nxt = i,nowadd = 0;
        while(KeyPoints[i].pos == KeyPoints[nxt].pos) nowadd += KeyPoints[nxt].va,++nxt;
        nowva += nowadd;
        if(nowva > MaxNum) MaxNum = nowva;
        UniquePoints[++ucnt].pos = KeyPoints[i].pos;
        UniquePoints[ucnt].va = nowva;
    }
    UniquePoints[0] = UniquePoints[ucnt + 1] = (Point){0,0};
    int poscnt = 0;
    for(i = 1;i <= ucnt;++i)
    {
        if(UniquePoints[i].va == MaxNum && UniquePoints[i - 1].va != MaxNum)
        {
            anspool[poscnt++] = UniquePoints[i].pos;
        }
        if(UniquePoints[i].va == MaxNum && UniquePoints[i + 1].va != MaxNum)
        {
            anspool[poscnt++] = UniquePoints[i].pos;
        }
    }
    for(i = 0;i < poscnt;i += 2)
    {
        printf("No.%d from:%d to:%d\n",(i + 1) / 2,anspool[i],anspool[i + 1]);
    }
    printf("Intervals found: %d\n",poscnt / 2);
    free(KeyPoints),free(UniquePoints),free(Pool),free(anspool);
}
