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

struct TreeNode* build(int pre[], int in[], int s, int e, int *pi) {
    if (s > e) return NULL;

    int val = pre[*pi];
    (*pi)++;

    struct TreeNode* root = createNode(val);

    if (s == e) return root;

    int idx = search(in, s, e, val);

    root->left  = build(pre, in, s, idx-1, pi);
    root->right = build(pre, in, idx+1, e, pi);

    return root;
}

void postorder(struct TreeNode* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int pi = 0;
    struct TreeNode* root = build(pre, in, 0, n-1, &pi);

    postorder(root);
    return 0;
}
