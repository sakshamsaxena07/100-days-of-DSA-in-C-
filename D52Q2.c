#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// LCA Function (core logic)
struct Node* lowestCommonAncestor(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->val == p || root->val == q)
        return root;

    struct Node* left = lowestCommonAncestor(root->left, p, q);
    struct Node* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;

    return (left != NULL) ? left : right;
}
