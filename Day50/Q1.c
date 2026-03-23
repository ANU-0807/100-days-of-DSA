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

int searchBST(struct Node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->val == key)
        return 1;

    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    scanf("%d", &key);

    struct Node* root = buildTree(arr, n);

    if (searchBST(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
