#include <stdio.h>
#include <stdlib.h>

// 排序
void sortColors(int nums[], int n)
{

}

int main()
{
    int nums[100];
    int n = 10, i = 0;
    printf("please input n:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        printf("please input %d number:\n", i);
        scanf("%d", &nums[i]);
    }
    sortColors(nums, n);
    for (i = 0; i < n; i++)
    {
        printf("%d\n", nums[i]);
    }
}