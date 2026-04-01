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

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2*i+1, r = 2*i+2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

int isMirror(struct TreeNode* l, struct TreeNode* r) {
    if (!l && !r) return 1;
    if (!l || !r) return 0;

    return (l->val == r->val) &&
           isMirror(l->left, r->right) &&
           isMirror(l->right, r->left);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    if (isMirror(root->left, root->right))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
