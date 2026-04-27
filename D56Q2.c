int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;

    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int isSymmetric(struct Node* root) {
    return isMirror(root, root);
}
