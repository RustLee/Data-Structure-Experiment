#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void swap(int *p, int *q) //将p所在的地址指向的值和q地址所指向的值交换
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// 请实现排序算法
int *resort(int nums[], int n)
{
}

int main()
{
    int n;
    int i;
    int *nums;

    // 输入
    scanf("%d", &n);
    nums = (int *)malloc(n * (sizeof(int)));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    // 排序
    int *a = resort(nums, n);

    // 输出
    printf("排序后\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}
