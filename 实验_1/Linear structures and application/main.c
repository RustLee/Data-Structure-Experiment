#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student//学生结构
{
    char num[10];
    char name[15];
    float database;
};

typedef struct Node
{
    struct Student st;//数据域
    struct Node *pNext;//指针域
}NODE, *pNode;
/*NODE等价于struct Student st
pNode等价于struct Node *pNext*/

  //主菜单
int menu()
{
	int c;
		printf("\t\t******Data Structure Performance Management******\n");
		printf("\t\t     1.Logging data\n");
        printf("\t\t     2.Insert a record\n");
        printf("\t\t     3.Delete a record\n");
		printf("\t\t     4.Researching\n");
		printf("\t\t     5.Output all record\n");
		printf("\t\t     6.Merge all class information and output\n");
		printf("\t\t     0.Exit\n");
		printf("\t\t*************************************************\n");
		printf("Please your choice:");
		scanf("%d",&c);
		while(c<0||c>6)
		{
			printf("Error!Input again please:");
			fflush(stdin);
			scanf("%d",&c);
		}
		return c;
}

//输入函数,用于输入学生信息
pNode Input(void)
{
    int numberofclass;
    NODE stu;
    pNode pHead = (pNode)malloc(sizeof(NODE));
    if(NULL == pHead)
    {
        printf("Memory allocation failed!Program determination!\n");
        exit(-1);
    }
    pNode pTail = pHead;
    pTail->pNext = NULL;
    printf("The number of students:");
    scanf("%d",&numberofclass);

    for(int i=0; i<numberofclass; i++)
    {
        printf("Student ID %d:\n", i+1);
        scanf("%s", &stu.st.num);
        printf("Student name %d:\n", i+1);
        scanf("%s", &stu.st.name);
        printf("Student performance of data structure %d:\n", i+1);
        scanf("%f", &stu.st.database);
        //为新节点分配内存
        pNode pNew = (pNode)malloc(sizeof(NODE));
        //判断内存是否为空
        if(NULL == pNew)
        {
            printf("Memory allocation failed!Program determination!\n");

            exit(-1);
        }
        pNew->st = stu.st;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

//输出学生信息
int Output(pNode pHead)
{
    pNode p = pHead->pNext;
    while(NULL != p)
    {
        printf("%s\t%s\t%.2f\t\n", p->st.num, p->st.name, p->st.database);
        p = p->pNext;
    }
    return 0;
}

//查找学生信息
int Search(pNode pHead)
{
    pNode p = pHead->pNext;
	int ch1,i,j;
	printf("1.Search by student ID\n2.Search by student name\nPlease choose ：");
	scanf("%d",&ch1);
	switch(ch1)
	{
		case 1:
        {
            char number[20]={0};
	        printf("Please input the number you want to find:\n");
	        scanf("%s",number);
            while(NULL != p)
              {
                   if(0 == strcmp(number,p->st.num))
                      {
                        printf("Search success!\n");
                        printf("ID\tName\tPerformance of Data Structure\n");
		                printf("%s\t%s\t%.2f\t\n", p->st.num, p->st.name, p->st.database);
                        return 0;
                      }
                    p = p->pNext;
              }
             printf("\nNot found!\n");break;

         }

	    case 2:
	    	{
	    	char a[20];
        	printf("Please input the name you want to find:\n");
        	scanf("%s",&a);
            while(NULL != p)
              {
                   if(0 == strcmp(a,p->st.name))
                      {
                        printf("Search success!\n");
                        printf("ID\tName\tPerformance of Data structure\n");
		                printf("%s\t%s\t%.2f\t\n", p->st.num, p->st.name, p->st.database);
                        return 0;
                      }
                    p = p->pNext;
              }
             printf("\nNot found!\n");break;
            }
            return 0;
      }
}

//删除学生信息
int Delete(pNode pHead)
{
    pNode p = pHead,q;
    int i = 0;
    struct Student stu;//学生结构
    int site;//删除结点的位置
    printf("Please enter the location of the deleted student:");
    scanf("%d",&site);
    if(NULL == p || i>site)
    {
        printf("The location of the delete node does not exist!\n");
        return;
    }
    while(NULL != p && i<site-1)
    {
        p = p->pNext;
        ++i;
    }
    q=p->pNext;
    p->pNext=p->pNext->pNext;
    free(q);
}
//增加学生信息
void Insert(pNode pHead)
{
    pNode p = pHead;
    int i = 0;
    struct Student stu;//学生结构
    int site;//插入结点的位置
    printf("Please enter the location of the insert student:");
    scanf("%d",&site);
    while(NULL != p && i<site-1)
    {
        p = p->pNext;
        i++;
    }
    if(NULL == p || i>site)
    {
        printf("The location of the insert node does not exist!\n");
        return;
    }
    printf("You will insert a student behind the %d students.\n",site-1);
    printf("Please enter the student number of the %d students:",site);
    scanf("%s",&stu.num);
    printf("Please enter the name of the %d student:",site);
    scanf("%s",&stu.name);
    printf("Please enter the data structure score for the %d students:",site);
    scanf("%f",&stu.database);
    pNode pNew = (pNode)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("Dynamic memory allocation failed, the program terminated!\n");
        exit(-1);
    }
    pNew->st = stu;
    pNode q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
}

//对学生的成绩排序
int Sort(pNode pHead)
{
    pNode p, q;
    NODE temp;

    for(p=pHead->pNext; NULL != p; p=p->pNext)
    {
        for(q=p->pNext; NULL !=q; q=q->pNext)
        {
            if(p->st.database < q->st.database)
            {
                temp.st  = p->st;
                p->st =  q->st;
                q->st = temp.st;
            }
        }
    }
	return 0;
}
//复制单链表
pNode merge(pNode la, pNode lb)
{
    pNode l = (pNode)malloc(sizeof(NODE));l->pNext=NULL;
    NODE *pa = la->pNext, *pb = lb->pNext, *pc = l;
    NODE *temp;
    if(NULL == l)
    {
        printf("Dynamic memory allocation failed, the program terminated!\n");
        exit(-1);
    }
    while (pa && pb)
    {
        temp = (pNode*)malloc(sizeof(NODE));
        if (pa->st.database >= pb->st.database)
        {
            *temp = *pa;
            pa = pa->pNext;
        }
        else
        {
            *temp = *pb;
            pb = pb->pNext;
        }
        pc->pNext = temp;
        pc = pc->pNext;
    }
    while (pa)
    {
        temp = (pNode*)malloc(sizeof(NODE));
        *temp = *pa;
        pa = pa->pNext;
        pc->pNext = temp;
        pc = pc->pNext;
    }
    while (pb)
    {
        temp = (pNode*)malloc(sizeof(NODE));
        *temp = *pb;
        pb = pb->pNext;
        pc->pNext = temp;
        pc = pc->pNext;
    }
    return l;
}
//退出程序
void Exit(pNode pHead1,pNode pHead2,pNode pHead3,pNode pHead4)
{
	free(pHead1);free(pHead2);free(pHead3);free(pHead4);
	printf("\nThanks for using!\n");
	exit(0);
}
int main()
{
    int ch1,ch2,ch3;
    pNode pHead1 = NULL;
    pNode pHead2 = NULL;
    pNode pHead3 = NULL;
    pNode all = (pNode)malloc(sizeof(NODE));all->pNext=NULL;
    pNode temp1 = (pNode)malloc(sizeof(NODE));temp1->pNext=NULL;
    pNode temp2 = (pNode)malloc(sizeof(NODE));temp2->pNext=NULL;
    while(1)
    {
        switch(menu())
        {
            case 1://输入学生信息
            {
                printf("Please enter 1 class information:\n");pHead1 = Input();  Sort(pHead1);
		        printf("Please enter 2 class information:\n");pHead2 = Input();  Sort(pHead2);
		        printf("Please enter 3 class information:\n");pHead3 = Input();  Sort(pHead3);
            }
            break;

            case 2://增加学生信息
            {
                printf("Please enter the class to be inserted:\n");
		        scanf("%d",&ch1);
		        while(ch1 <=0 || ch1>3)
	            {
		        printf("The number should be between 1-3\n");
		        printf("Please enter the class to be inserted:\n");
	            scanf("%d",&ch1);
	            char ch;while((ch = getchar()) != '\n');           //清空缓存区，防止错误输入引发无限循环//
	            }
		        switch (ch1)
		        {
		            case 1:Insert(pHead1);  Sort(pHead1);break;
		            case 2:Insert(pHead2);  Sort(pHead2);break;
		            case 3:Insert(pHead3);  Sort(pHead3);break;
		        }
            }
            break;
            case 3://删除学生信息
            {
                printf("Please enter the class to be deleted:\n");
		        scanf("%d",&ch2);
		        while(ch2 <=0 || ch2>3)
	            {
		        printf("The number should be between 1-3\n");
		        printf("Please enter the class to be deleted:\n");
	            scanf("%d",&ch2);
	            char ch;while((ch = getchar()) != '\n');           //清空缓存区，防止错误输入引发无限循环//
	            }
		        switch (ch2)
		        {
		            case 1:Delete(pHead1);  Sort(pHead1);break;
		            case 2:Delete(pHead2);  Sort(pHead2);break;
		            case 3:Delete(pHead3);  Sort(pHead3);break;
		        }
            }
            break;
            case 4://查找学生信息
            {
                 printf("Please enter the class to be searched:\n");
		        scanf("%d",&ch3);
		        while(ch3 <=0 || ch3>3)
	            {
		        printf("数The number should be between 1-3\n");
		        printf("Please enter the class to be searched:\n");
	            scanf("%d",&ch3);
	            char ch;while((ch = getchar()) != '\n');           //清空缓存区，防止错误输入引发无限循环//
	            }
		        switch (ch3)
		        {
		            case 1:Search(pHead1);break;
		            case 2:Search(pHead2);break;
		            case 3:Search(pHead3);break;
		        }
            }
            break;

			case 5://输出学生信息
            {


                printf("All student information is as follows:\n");
                printf("Class 1\nID\tName\tPerformance of Data Structure\n");Output(pHead1);
                printf("Class 2\nID\tName\tPerformance of Data Structure\n");Output(pHead2);
                printf("Class 3\nID\tName\tPerformance of Data Structure\n");Output(pHead3);
            }
            break;
            case 6://合并
            {
                temp1 = merge(pHead1, pHead2);
                all = merge(temp1, pHead3);
                free(temp1);
                free(pHead3);
                Sort(all);
                Output(all);
            }
            break;
            case 0: Exit(pHead1,pHead2,pHead3,all);break;
        }
    }
    return 0;
}
