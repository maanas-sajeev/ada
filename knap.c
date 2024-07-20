#include<stdio.h>
int max(int a,int b)
{
    return(a>b)?a:b;
}
void main()
{
    int n,w;
    printf("enter the number of items:");
    scanf("%d",&n);
    printf("enter the weight capacity:");
    scanf("%d",&w);
    int weight[n],value[n];
    for(int i=0;i<n;i++)
    {
        printf("enter the weight and value of item %d:",i+1);
        scanf("%d%d",&weight[i],&value[i]);
    }
    int m[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0||j==0)
                m[i][j]=0;
            else
            {
                if(j-weight[i-1]>=0)
                    m[i][j]=max(m[i-1][j],value[i-1]+m[i-1][j-weight[i-1]]);
                else
                    m[i][j]=m[i-1][j];
            }
        }
    }
    printf("\n");
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    int max=0,i,j;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<w+1;j++)
            if(m[i][j]>max)
            {
                max=m[i][j];
                break;
            }
    }
    printf("\nMaximum value possible: %d",max);
    int val=max,weigh=w;
    for(i=n;i>=0,val>0;i--)
    {
        while(m[i][j]==m[i-1][j])
            i--;
        printf("\n Possible item %d\tweight%d\tvalue%d",i,weight[i-1],value[i-1]);
        val-=value[i-1];
        weigh-=weight[i-1];
    }
}