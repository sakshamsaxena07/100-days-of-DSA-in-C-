struct Node* search(struct Node* root, int val) {
    if (!root || root->data == val)
        return root;

    if (val < root->data)
        return search(root->left, val);

    return search(root->right, val);
}
