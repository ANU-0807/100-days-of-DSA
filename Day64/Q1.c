#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
bool visited[MAX];
int n; // number of vertices

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) { // if edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle detected
            }
        }
    }
    return false;
}

int main() {
    int e, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // initialize matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
