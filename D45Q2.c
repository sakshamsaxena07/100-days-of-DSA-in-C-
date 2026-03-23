int maxDepth(struct Node* root) {
    if (!root) return 0;
    return 1 + (maxDepth(root->left) > maxDepth(root->right)
                ? maxDepth(root->left)
                : maxDepth(root->right));
}
