#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    struct TreeNode* nodes[n];

    for (int i = 0; i < n; i++)
        nodes[i] = createNode(arr[i]);

    for (int i = 0; i < n; i++) {
        int l = 2*i+1, r = 2*i+2;
        if (l < n) nodes[i]->left = nodes[l];
        if (r < n) nodes[i]->right = nodes[r];
    }

    return nodes[0];
}

int isMinHeap(struct TreeNode* root) {
    if (!root) return 1;

    if (root->left && root->val > root->left->val)
        return 0;

    if (root->right && root->val > root->right->val)
        return 0;

    return isMinHeap(root->left) &&
           isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
