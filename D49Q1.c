struct Node* insert(struct Node* root, int val) {
    if (!root) {
        struct Node* n = malloc(sizeof(struct Node));
        n->data = val;
        n->left = n->right = NULL;
        return n;
    }

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
