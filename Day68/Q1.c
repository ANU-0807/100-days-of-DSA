#include <stdio.h>

#define MAX 100

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;   // directed edge
        indegree[v]++;
    }

    // queue
    int queue[MAX];
    int front = 0, rear = 0;

    // push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int topo[MAX];
    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // check for cycle
    if (count != V) {
        printf("Cycle exists. Topological sort not possible\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}
