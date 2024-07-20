#include <stdio.h>

#define INF 999
int V;

void print(int dist[][V],int k)
{
    printf("\nMatrix D(%d): \n",k);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("oo ");
            else
                printf("%d  ", dist[i][j]);
        }
        printf("\n");
    }
}
int min(int a,int b)
{
    return (a<b)?a:b;
}

void floyd(int dist[][V])
{
    int i, j, k;
    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j]);
    print(dist,k);
}

int main()
{
    printf("Enter the number of vertices:");
    scanf("%d",&V);
    int graph[V][V];
    printf("Enter the Weight Matrix:(Enter 999 for infinity)\n");
    for(int i=0;i<V;i++)
    {
        printf("Enter Row %d:",i+1);
        for(int j=0;j<V;j++)
        scanf("%d",&graph[i][j]);
    }
    floyd(graph);
    return 0;
}
