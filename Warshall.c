#include <stdio.h>

int V;

void print(int dist[][V],int k)
{
    printf("\nMatrix R(%d): \n",k);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf("%d  ", dist[i][j]);
        printf("\n");
    }
}

void warshall(int dist[][V])
{
    int i, j, k;
    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] =  dist[i][j]||(dist[i][k] && dist[k][j]);
    print(dist,k);
}

int main()
{
    printf("Enter the number of vertices:");
    scanf("%d",&V);
    int graph[V][V];
    printf("Enter the Adjacency Matrix:\n");
    for(int i=0;i<V;i++)
    {
        printf("Enter Row %d:",i+1);
        for(int j=0;j<V;j++)
        scanf("%d",&graph[i][j]);
    }
    warshall(graph);
    return 0;
}
