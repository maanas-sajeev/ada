//Dijktras
#include <stdio.h>

#define INF 99

int cost[10][10], n, result[10][2], weight[10];

void dijkstra(int cost[10][10], int s);

int main() {
    int i, j, s;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost adjacency matrix (use %d for infinity):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }
    
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    
    dijkstra(cost, s);
    
    printf("Shortest path tree:\n");
    for (i = 0; i < n; i++) {
        if (i != s) {
            printf("(%d, %d) with weight %d\n", result[i][0], result[i][1], weight[result[i][1]]);
        }
    }
    
    return 0;
}

void dijkstra(int cost[10][10], int s) {
    int d[10], p[10], visited[10];
    int i, j, min, u;

    // Initialize distances, predecessors, and visited array
    for (i = 0; i < n; i++) {
        d[i] = INF;
        visited[i] = 0;
        p[i] = -1;
    }
    
    d[s] = 0;
    
    for (i = 0; i < n - 1; i++) {
        min = INF;
        u = -1;

        // Find the vertex with the smallest distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1) break; // No more vertices to process

        visited[u] = 1;

        // Update the distances of the neighbors of the chosen vertex
        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INF && d[u] + cost[u][j] < d[j]) {
                d[j] = d[u] + cost[u][j];
                p[j] = u;
            }
        }
    }

    // Save the results
    for (i = 0; i < n; i++) {
        result[i][0] = p[i];
        result[i][1] = i;
        weight[i] = d[i];
    }
}
