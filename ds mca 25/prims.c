#include <stdio.h>

#define INF 999999

int main() {
    int n;

    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    
    printf("Enter the cost adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter wight of edge %d-->%d\t",i,j);
            scanf("%d", &cost[i][j]);
            if(cost[i][j]<0)
            {
            printf("\nInvalid Entry\n");
            j--;
            continue;
            }
            else
            if (cost[i][j] == 0) cost[i][j] = INF;  
        }
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;   

    int edges = 0;
    int mincost = 0;

    printf("\nEdges in MST:\n");

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]==1) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -- %d  (cost = %d)\n", u, v, min);
        visited[v] = 1;
        mincost += min;
        edges++;
    }

    printf("\nMinimum cost of MST = %d\n", mincost);

    return 0;
}
