#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->size = n;
    q->arr = (int*)malloc(n * sizeof(int));
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = x;
}

void display(Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    int n, x;
    scanf("%d", &n);

    Queue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    display(q);

    free(q->arr);
    free(q);
    return 0;
}
