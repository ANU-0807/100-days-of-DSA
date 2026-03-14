#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1, top = -1;

void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    /* move queue -> stack */
    while(front <= rear)
    {
        push(dequeue());
    }

    /* reset queue */
    front = 0;
    rear = -1;

    /* move stack -> queue */
    while(top != -1)
    {
        enqueue(pop());
    }

    /* print reversed queue */
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
