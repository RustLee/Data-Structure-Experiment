#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MaxData 100

typedef char TElemType;
typedef struct TNode *Position;
typedef Position BiTree;
struct TNode{
    TElemType Data;
    BiTree lchild;
    BiTree rchild;
};

int FindRoot(TElemType InOrd[],int star,int end,char key)
{
    int i;
    for(i=star;i<=end;i++)
        if(InOrd[i]==key)
            return i;
    return -1;
}

BiTree BuildTree(char PreOrd[],int PreStar,int PreEnd,char InOrd[],int InStar,int InEnd)
{
    int root;
    if(InStar>InEnd)
        return NULL;
    BiTree BT=(BiTree)malloc(sizeof(struct TNode));
    BT->Data=PreOrd[PreStar];
    root=FindRoot(InOrd,InStar,InEnd,PreOrd[PreStar]);
    BT->lchild=BuildTree(PreOrd,PreStar+1,PreStar+(root-InStar),InOrd,InStar,root-1);
    BT->rchild=BuildTree(PreOrd,PreStar+(root-InStar)+1,PreEnd,InOrd,root+1,InEnd);
    return BT;
}

void Postorder_Traversal(BiTree BT)
{
    if(BT){
        Postorder_Traversal(BT->lchild);
        Postorder_Traversal(BT->rchild);
        printf("%c",BT->Data);
    }
}

bool IsMirror(BiTree x,BiTree y)
{
    bool ret=true;
    if(x==NULL&&y==NULL)
        return true;
    if((x==NULL&&y!=NULL)||(x!=NULL&&y==NULL))
        return false;
  //if(x->Data!=y->Data)
  //    return false;
    ret=IsMirror(x->lchild,y->rchild);
    if(ret==false)
        return ret;
    ret=IsMirror(x->rchild,y->lchild);
    return ret;
}

int main()
{
    int length,i,j;
    BiTree BT;
    TElemType Msg[MaxData];
    TElemType PreOrd[MaxData/2];
    TElemType InOrd[MaxData/2];
    printf("Preorder Traversal,Inorder Traversal\n");
    scanf("%s",Msg);
    length=strlen(Msg);
    for(i=0;i<length/2;i++)
    {
        PreOrd[i] = Msg[i];
    }
    PreOrd[i]='\0';
    for(j=0;i<length;j++)
    {
        i++;
        InOrd[j]=Msg[i];
    }
    InOrd[j]='\0';

    BT = BuildTree(PreOrd,0,length/2-1,InOrd,0,length/2-1);
    printf("Postorder Traversal:");
    Postorder_Traversal(BT);
    if(IsMirror(BT->lchild,BT->rchild))
        printf("\nIt's a mirror BiTree.");
    else
        printf("\nIt's not a mirror BiTree.");
    return 0;

}
