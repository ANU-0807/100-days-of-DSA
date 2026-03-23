#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
            i++;
        }

        if (i < n) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
            i++;
        }
    }

    return root;
}

int findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val) {
            root = root->left;
        }
        else if (p > root->val && q > root->val) {
            root = root->right;
        }
        else {
            return root->val;
        }
    }
    return -1; // not found (shouldn't happen if valid input)
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n);

    printf("%d", findLCA(root, p, q));

    return 0;
}
