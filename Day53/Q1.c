#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    int map[2000][100];   // store nodes for each HD
    int count[2000] = {0};

    struct Pair queue[MAX];
    int front = 0, rear = 0;

    int offset = 1000; // shift for negative HD

    queue[rear++] = (struct Pair){root, 0};

    int minHD = 0, maxHD = 0;

    while (front < rear) {
        struct Pair p = queue[front++];
        struct Node* curr = p.node;
        int hd = p.hd;

        int idx = hd + offset;

        map[idx][count[idx]++] = curr->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            queue[rear++] = (struct Pair){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct Pair){curr->right, hd + 1};
    }

    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
