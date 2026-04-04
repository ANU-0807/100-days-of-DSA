#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjLists;
};

int visited[100];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjLists = malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

// DFS function
void dfs(struct Graph* graph, int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adjLists[v];

    while (temp) {
        int adj = temp->vertex;

        if (!visited[adj]) {
            dfs(graph, adj);
        }

        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int s;
    scanf("%d", &s);

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // DFS from source
    dfs(graph, s);

    return 0;
}
