#include<stdio.h>
#define V 100
#define INF 999
int minKey(int key[],int mstSet[],int n){
    int min= INF, min_index;
    for(int v=0;v<n;v++){
        if(mstSet[v]==0 && key[v]<min){
            min=key[v];
            min_index=v;
        }
    }
    return min_index; 
}
void printMST(int parent[],int graph[V][V],int n){
    printf("\nMST:");
    printf("\nEdge\t\tWeight\n");
    for(int i=1;i<n;i++)
        printf("From %d - to %d \t%d\n",parent[i],i,graph[i][parent[i]]);
}
void primsMST(int graph[V][V],int n){
    int parent[V];
    int key[V];
    int mstSet[V];
    for(int i=0;i<n;i++){
        key[i]=INF;
        mstSet[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<n-1;count++){
        int u=minKey(key,mstSet,n);
        mstSet[u]=1;
        for(int v=0;v<n;v++){
            if(graph[u][v] && mstSet[v]==0 && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printMST(parent,graph,n);
}
int main(){
    int n;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    int graph[V][V];
    printf("enter the weight matrix(%d x %d):\n",n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        scanf("%d",&graph[i][j]);
    }
    primsMST(graph,n);
    return 0;
}