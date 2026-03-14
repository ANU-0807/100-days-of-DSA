#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

void enqueue(int x, int n)
{
    rear = (rear + 1) % n;
    queue[rear] = x;
    size++;
}

int dequeue(int n)
{
    int val = queue[front];
    front = (front + 1) % n;
    size--;
    return val;
}

void display(int n)
{
    int i = front;

    for(int count = 0; count < size; count++)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % n;
    }
}

int main()
{
    int n,m,x;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x,n);
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        int temp = dequeue(n);
        enqueue(temp,n);
    }

    display(n);

    return 0;
}
