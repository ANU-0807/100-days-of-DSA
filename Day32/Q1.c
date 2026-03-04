#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

void pop() {
    if(top != -1)
        top--;
}

int main() {
    int n, m, val;

    scanf("%d", &n);

    // Push elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
