#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//录入学生登记的时间段，并判断输入是否合法
void registration(int start[], int finish[], int M, int N)
{
    int i;
    printf("Please enter the expected time period for each student in turn: \n");
    for (i = 0; i < M; i++)
    {
        printf("The expected period of time for %d students: \n", i + 1);
        scanf("%d", &start[i]);
        scanf("%d", &finish[i]);
        //补全判断输入是否合法代码
    }
}
//对起始时间和终止时间进行排序
void sort(/*参数自行填写*/)
{
}

//计算用餐人数最多时间段的起始时间和终止时间
void findPeriod(int start[], int finish[], int M, int N)
{
}

int main()
{
    int N, M; //分别存储时间的段数和学生的个数
    printf("Number of periods of time:  ");
    scanf("%d", &N);
    printf("Number of students:  ");
    scanf("%d", &M);
    getchar();
    int *start, *finish; //分别存储起始时间和终止时间
    start = (int *)malloc(M * (sizeof(int)));
    memset(start, 0, M);
    finish = (int *)malloc(M * (sizeof(int)));
    memset(finish, 0, M);

    registration(start, finish, M, N); //录入学生登记的时间段
    sort(/*参数自行填写*/);            //对起始时间和终止时间进行排序
    findPeriod(start, finish, M, N);   //输出用餐人数最多时间段的起始时间和终止时间
    return 0;
}
