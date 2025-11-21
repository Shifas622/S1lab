#include <stdio.h>

#define MAX 100
#define INF 1000000

int n, e;
int edges[MAX][3]; 
int parent[MAX];


int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}


void union_sets(int u, int v) {
    parent[find(u)] = find(v);
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int mst_weight = 0;
    printf("Edges in MST:\n");

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1, v = -1, idx = -1;

        for (int i = 0; i < e; i++) {
            if (edges[i][2] < min) {
                int set_u = find(edges[i][0]);
                int set_v = find(edges[i][1]);
                if (set_u != set_v) {
                    min = edges[i][2];
                    u = edges[i][0];
                    v = edges[i][1];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            printf("%d - %d : %d\n", u, v, edges[idx][2]);
            mst_weight += edges[idx][2];
            union_sets(u, v);
            edges[idx][2] = INF; 
        }
    }

    printf("Total weight of MST: %d\n", mst_weight);
    return 0;
}
