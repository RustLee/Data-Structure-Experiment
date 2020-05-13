#include <stdio.h>
#include <stdlib.h>

void Swap(int *var1, int *var2)
{
      int temp = *var1;
      *var1 = *var2;
      *var2 = temp;
}
void Shuffle(int *array,int N)
{
    int current = 0;
    int end = N-1;
    int begin = 0;
    while(current<=end)
    {
        if(array[current] ==0)
        {
            Swap(&array[current],&array[begin]);
            current++;
            begin++;
        }
        else if(array[current] == 1)
        {
            current++;
        }
        else
        {//array[current] =2
            Swap(&array[current],&array[end]);
            end--;
        }
      }
}

int main()
{
    int N;
    printf("please input N:");
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    Shuffle(a,N);
    printf("\n");
    for(int i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
