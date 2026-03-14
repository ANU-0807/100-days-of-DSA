#include <stdio.h>

#define MAX 100

int deque[MAX];
int front=-1,rear=-1;

int isEmpty()
{
    return front==-1;
}

void push_front(int x)
{
    if(isEmpty())
        front=rear=0;
    else
        front=(front-1+MAX)%MAX;

    deque[front]=x;
}

void push_back(int x)
{
    if(isEmpty())
        front=rear=0;
    else
        rear=(rear+1)%MAX;

    deque[rear]=x;
}

void pop_front()
{
    if(isEmpty()) return;

    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
}

void pop_back()
{
    if(isEmpty()) return;

    if(front==rear)
        front=rear=-1;
    else
        rear=(rear-1+MAX)%MAX;
}

void display()
{
    if(isEmpty()) return;

    int i=front;

    while(1)
    {
        printf("%d ",deque[i]);
        if(i==rear) break;
        i=(i+1)%MAX;
    }
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    pop_front();
    pop_back();

    display();
}S
