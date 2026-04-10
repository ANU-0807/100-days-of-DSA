#include <stdio.h>
#include <limits.h>

#define SIZE 100

// Min Heap structure
typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[SIZE];
int heapSize = 0;

// swap
void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// push into heap
void push(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    int i = heapSize;
    heapSize++;

    // heapify up
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];

    int i = 0;

    // heapify down
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;

        if (right < heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i)
            break;

        swap(i, smallest);
        i = smallest;
    }

    return root;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[SIZE][SIZE];

    // initialize
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = INT_MAX;

    // input edges
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        // for undirected: adj[v][u] = w;
    }

    int source;
    scanf("%d", &source);

    int dist[SIZE];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    push(source, 0);

    while (heapSize > 0) {
        HeapNode current = pop();
        int node = current.node;
        int d = current.dist;

        for (int i = 0; i < V; i++) {
            if (adj[node][i] != INT_MAX) {
                if (d + adj[node][i] < dist[i]) {
                    dist[i] = d + adj[node][i];
                    push(i, dist[i]);
                }
            }
        }
    }

    // output
    printf("Shortest distances:\n");
    for (int i = 0; i < V; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }

    return 0;
}
