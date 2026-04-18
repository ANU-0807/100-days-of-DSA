#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int visited[MAX];

// Node for adjacency list
typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAX];

// Add edge
void addEdge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;

    node = (Node*)malloc(sizeof(Node));
    node->v = u;
    node->next = adj[v];
    adj[v] = node;
}

// DFS
void dfs(int u) {
    visited[u] = 1;

    Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->v]) {
            dfs(temp->v);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Start DFS from node 1
    dfs(1);

    // Check if all visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}
