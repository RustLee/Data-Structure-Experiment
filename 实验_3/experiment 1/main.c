#include <stdio.h>
#include <stdlib.h>

typedef struct BiNode
{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode;

void Creat_BiTree(BiNode* T)
{
    char ch1,ch2;
    printf("Please enter the lchild\n");
    scanf("%c",&ch1);
    getchar();
    if(ch1=='#')
        T->lchild=NULL;
    else
    {
         BiNode*lchild=(struct BiNode*)malloc(sizeof(struct BiNode));
         T->lchild=lchild;
         lchild->data=ch1;
         Creat_BiTree(T->lchild);
    }
    printf("Please enter the rchild\n");
    scanf("%c",&ch2);
    getchar();
    if(ch2=='#')
        T->rchild=NULL;
    else
    {
         BiNode*rchild=(struct BiNode*)malloc(sizeof(struct BiNode));
         T->rchild=rchild;
         rchild->data=ch2;
         Creat_BiTree(T->rchild);
    }
}
void Preorder(struct BiNode *T)
{
    if(T==NULL)
    {
        return;
    }
    printf("%c",T->data);
    Preorder(T->lchild);
    Preorder(T->rchild);
}
void Inorder(struct BiNode *T)
{

    if(T==NULL)
    {
        return;
    }
    Inorder(T->lchild);
    printf("%c",T->data);
    Inorder(T->rchild);
}
void Postorder(struct BiNode *T)
{
    if(T==NULL)
    {
        return;
    }
    Postorder(T->lchild);
    Postorder(T->rchild);
    printf("%c",T->data);
}
int main()
{
    char ch;
    struct BiNode *T;
    T=(struct BiNode*)malloc(sizeof(struct BiNode));
    printf("建立二叉树\n");
    printf("start task  Create Tree in PreOrder\n");
    scanf("%c",&ch);
    T->data=ch;
    getchar();
    Creat_BiTree(T);
    printf("\n");
    printf("先序\n");
    Preorder(T);
    printf("\n中序\n");
    Inorder(T);
    printf("\n后序\n");
    Postorder(T);
}
