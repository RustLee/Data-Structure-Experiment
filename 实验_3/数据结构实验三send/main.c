
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char ch;
    struct Node *lchild, *rchild;
} TreeNode, *BiTree; //�������ڵ�Ľṹ��
void createBiTree(BiTree *p)//����������
{

}
void preOrderTraverse(BiTree p)//ǰ�����
{

}
void inOrderTraverse(BiTree p)//�������
{

}
void postOrderTraverse(BiTree p)//��������
{

}
BiTree* BinaryTreeFromOrderings(char inorder[], char preorder[],int inorder_index,int preorder_index, int length)
{
//�������ܣ�����ǰ�����������й���������������ظ��ڵ�
//����˵����inorder:���������ַ����飬preorder:ǰ�������ַ�����,inorder_index:��¼������������,preorder_index:��¼ǰ������������length:���г���

}
int isSymmetrical(BiTree root)
{
   //�ж���rootΪ���ڵ�Ķ������Ƿ��Ǿ���ԳƵ�
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
