#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

int cameras = 0;

// DFS function
int dfs(struct Node* root) {
    if (!root) return 2; // NULL is covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child needs camera
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // place camera here
    }

    // If any child has camera
    if (left == 1 || right == 1)
        return 2; // covered

    // Otherwise
    return 0; // needs camera
}

// Main function
int minCameraCover(struct Node* root) {
    if (dfs(root) == 0)
        cameras++;

    return cameras;
}
