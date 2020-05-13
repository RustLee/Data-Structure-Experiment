#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 999
#define N 999

void Sort(char num[M][N],int n)
{
    int i=0,j=0,k=0;
    char sortNum[M][N];
    char tmp[M];
    for(i=0;i<n;i++)
        strcpy(sortNum[i],num[i]);
    for(i=0;i<n;i++)
    {
        while(strlen(sortNum[i])<3)
        {
            j=strlen(sortNum[i]);
            sortNum[i][j]=sortNum[i][j-1];
			sortNum[i][j+1]='\0';
        }
    }
    for(i=0;i<=n-1;i++)
    {
        k=i;
        for(j=i+1;j<=n-1;j++)
            if(atoi(sortNum[j])>atoi(sortNum[k]))
                k=j;
        if(k!=i)
        {
            strcpy(tmp,sortNum[i]);
            strcpy(sortNum[i],sortNum[k]);
            strcpy(sortNum[k],tmp);
            strcpy(tmp,num[i]);
            strcpy(num[i],num[k]);
            strcpy(num[k],tmp);
        }
    }
}

int main()
{
    int n=0;
    char num[M][N]={0};
    int i=0,j=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",num[i]);
    }
    Sort(num,n);
    for(j=0;j<n;j++)
    {
        printf("%s",num[j]);
    }
}
