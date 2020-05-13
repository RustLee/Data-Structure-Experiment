
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char ch;
    struct Node *lchild, *rchild;
} TreeNode, *BiTree; //定义树节点的结构体
void createBiTree(BiTree *p)//建立二叉树
{

}
void preOrderTraverse(BiTree p)//前序遍历
{

}
void inOrderTraverse(BiTree p)//中序遍历
{

}
void postOrderTraverse(BiTree p)//后续遍历
{

}
BiTree* BinaryTreeFromOrderings(char inorder[], char preorder[],int inorder_index,int preorder_index, int length)
{
//函数功能：根据前序与中序序列构造二叉树，并返回根节点
//参数说明：inorder:中序序列字符数组，preorder:前序序列字符数组,inorder_index:记录中序序列索引,preorder_index:记录前序序列索引，length:序列长度

}
int isSymmetrical(BiTree root)
{
   //判断以root为根节点的二叉树是否是镜像对称的
}

void task1(){
printf("start task (1) Create Tree in PreOrder\n");
    BiTree bt;
    createBiTree(&bt);
    printf("preOrderTraverse\n");
    preOrderTraverse(bt);
    printf("\n");
    printf("inOrderTraverse\n");
    inOrderTraverse(bt);
    printf("\n");
    printf("inOrderTraverse\n");
    postOrderTraverse(bt);
    printf("\n");
}
void task2_3(){
 printf("start task (2) Input the preOrder and inOrder Sequence ,Then build the tree\n");
    char pr[100];
    char in[100];
    printf("please input the preorder seqence\n");




    printf("please input the inorder seqence\n");



    BiTree bt;
    bt=BinaryTreeFromOrderings(in, pr,0,0,strlen(pr));

    printf("preOrderTraverse\n");
    preOrderTraverse(bt);
    printf("\n");
    printf("inOrderTraverse\n");
    inOrderTraverse(bt);
    printf("\n");
    printf("inOrderTraverse\n");
    postOrderTraverse(bt);
    printf("\n");
    printf("start task (3):whether the tree is symmetrical?\n");
    if(isSymmetrical(bt)==1)
    {
        printf("It's mirror symmetrical");
    }
    else
    {
        printf("It's not mirror symmetrical");
    }
}

int main()
{

    task1();
    task2_3();
    return 0;
}
