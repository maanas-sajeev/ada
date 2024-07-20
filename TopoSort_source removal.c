#include<stdio.h>
//source removal
void main()
{
    int n,c=0,f=1;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    int g[n][n];
    printf("Enter the adjacency matrix row-wise:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);

    int m[n];
    for(int i=0;i<n;i++)
        m[i]=0;
    while(c<n)
    {
        for(int i=0;i<n;i++)
        {
            f=1;
            if(m[i]==1)
                continue;
            for(int j=0;j<n;j++)
            {
                if(g[j][i]!=0)
                {
                    f=0;continue;
                }
            }
            if(f)
            {
                m[i]=1;
                printf("%d ->",i+1);
                for(int k=0;k<n;k++)
                    g[i][k]=0;
                c++;
            }
        }
    }
}
