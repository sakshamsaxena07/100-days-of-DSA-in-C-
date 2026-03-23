int countLeaves(struct Node* root) {
    if (!root) return 0;

    if (!root->left && !root->right)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}
