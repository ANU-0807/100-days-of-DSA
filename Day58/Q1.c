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

int search(int in[], int s, int e, int val) {
    for (int i = s; i <= e; i++)
        if (in[i] == val) return i;
    return -1;
}

struct TreeNode* build(int in[], int post[], int s, int e, int *pi) {
    if (s > e) return NULL;

    int val = post[*pi];
    (*pi)--;

    struct TreeNode* root = createNode(val);

    if (s == e) return root;

    int idx = search(in, s, e, val);

    root->right = build(in, post, idx+1, e, pi);
    root->left  = build(in, post, s, idx-1, pi);

    return root;
}

void preorder(struct TreeNode* root) {
    if (!root) return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int pi = n-1;
    struct TreeNode* root = build(in, post, 0, n-1, &pi);

    preorder(root);
    return 0;
}
