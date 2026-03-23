struct Node* LCA(struct Node* root, int p, int q) {
    if (!root) return NULL;

    if (p < root->data && q < root->data)
        return LCA(root->left, p, q);

    if (p > root->data && q > root->data)
        return LCA(root->right, p, q);

    return root;
}
