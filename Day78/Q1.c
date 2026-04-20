#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with large values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int visited[MAX] = {0};
    int key[MAX];

    // Initialize keys
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
    }

    key[1] = 0; // Start from node 1
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;

        // Find minimum key vertex not visited
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update neighbors
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}
